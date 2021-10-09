compile:
	verilator -Wall -cc -exe --build --trace-fst testbench.cpp top.v
