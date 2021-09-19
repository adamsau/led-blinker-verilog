module top(input i_clk, input i_sw0, input i_sw1, output o_led);
	wire [3:0] q_net;
	wire[1:0] sw_combine = {1'b1, i_sw0} << 1 + i_sw1;
	drive drv[3:0] (.i_clk(i_clk), .o_drive(q_net));	
	mux mx(.a(q_net[0]), .b(q_net[1]), .c(q_net[2]), .d(q_net[3]), .sel(sw_combine), .out(o_led));

endmodule
