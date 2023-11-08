
module blinky (
	buttons_external_connection_export,
	clk_clk,
	leds_external_connection_export,
	reset_reset_n,
	switches_external_connection_export);	

	input	[2:0]	buttons_external_connection_export;
	input		clk_clk;
	output	[1:0]	leds_external_connection_export;
	input		reset_reset_n;
	input	[17:0]	switches_external_connection_export;
endmodule
