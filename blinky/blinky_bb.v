
module blinky (
	clk_clk,
	leds_external_connection_export,
	reset_reset_n,
	switches_external_connection_export,
	sev_seg_0_external_connection_export);	

	input		clk_clk;
	output	[1:0]	leds_external_connection_export;
	input		reset_reset_n;
	input	[1:0]	switches_external_connection_export;
	output	[6:0]	sev_seg_0_external_connection_export;
endmodule
