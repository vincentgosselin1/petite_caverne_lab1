
module system (
	buttons_i_export,
	clk_clk,
	leds_o_export,
	reset_reset_n,
	sseg_i_iv_export,
	sseg_v_vi_export,
	switches_i_export);	

	input	[3:0]	buttons_i_export;
	input		clk_clk;
	output	[1:0]	leds_o_export;
	input		reset_reset_n;
	output	[31:0]	sseg_i_iv_export;
	output	[31:0]	sseg_v_vi_export;
	input	[9:0]	switches_i_export;
endmodule
