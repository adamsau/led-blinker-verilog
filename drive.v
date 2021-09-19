module drive(input i_clk, output reg o_drive);
	reg [2:0] cnt = 3'b00;

	always @(posedge i_clk)
	begin
		if (cnt == 0)
		 	o_drive = !o_drive;
		cnt <= (cnt + 1) % 4;
	end
			
endmodule
