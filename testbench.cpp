#include <verilated.h>          // Defines common routines
#include <iostream>             // Need std::cout
#include <ostream>

#include "Vtop.h"               // From Verilating "top.v"
#include "verilated_fst_c.h"


int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);   // Remember args
		const std::unique_ptr<VerilatedContext> ctxp{new VerilatedContext};	
    Vtop *top = new Vtop;             // Create model

		Verilated::traceEverOn(true);
    VerilatedFstC* tfp = new VerilatedFstC;
    top->trace(tfp, 99);  // Trace 99 levels of hierarchy
    tfp->open("simu.fst");

		top->i_sw0 = 1;
		top->i_sw1 = 0;

		vluint64_t main_time;
    while ((main_time = ctxp->time()) <= 100) {
        if ((main_time % 10) == 1) {
            top->i_clk = 1;       // Toggle clock
        }
        if ((main_time % 10) == 6) {
            top->i_clk = 0;
        }
        top->eval();            // Evaluate model
				tfp->dump(main_time);
        ctxp->timeInc(1);            // Time passes...
    }

    top->final();               // Done simulating
    tfp->close(); 
		//    // (Though this example doesn't get here)
    delete top;
		std::cout << "ok." << std::endl;
}
