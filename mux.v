module mux(input a, input b, input c, input d, input [1:0] sel, output reg out);

always @(a, b, c, d, sel)
	case (sel)
		2'b00:out = a;
		2'b01:out = b;
		2'b10:out = c;
		2'b11:out = d;
	endcase

endmodule
