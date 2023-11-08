
module blinky (
	clk_clk,
	reset_reset_n,
	switches_external_connection_export,
	leds_external_connection_export);	

	input		clk_clk;
	input		reset_reset_n;
	input	[1:0]	switches_external_connection_export;
	output	[1:0]	leds_external_connection_export;
endmodule
