
module blinky (
	clk_clk,
	grn_leds_external_connection_export,
	keys_external_connection_export,
	randoms_external_connection_export,
	red_leds_external_connection_export,
	reset_reset_n,
	sev_seg_0_external_connection_export,
	sev_seg_1_external_connection_export,
	sev_seg_2_external_connection_export,
	sev_seg_3_external_connection_export,
	sev_seg_4_external_connection_export,
	sev_seg_5_external_connection_export,
	sev_seg_6_external_connection_export,
	sev_seg_7_external_connection_export,
	switches_external_connection_export);	

	input		clk_clk;
	output	[7:0]	grn_leds_external_connection_export;
	input	[2:0]	keys_external_connection_export;
	input	[31:0]	randoms_external_connection_export;
	output	[16:0]	red_leds_external_connection_export;
	input		reset_reset_n;
	output	[6:0]	sev_seg_0_external_connection_export;
	output	[6:0]	sev_seg_1_external_connection_export;
	output	[6:0]	sev_seg_2_external_connection_export;
	output	[6:0]	sev_seg_3_external_connection_export;
	output	[6:0]	sev_seg_4_external_connection_export;
	output	[6:0]	sev_seg_5_external_connection_export;
	output	[6:0]	sev_seg_6_external_connection_export;
	output	[6:0]	sev_seg_7_external_connection_export;
	input	[17:0]	switches_external_connection_export;
endmodule
