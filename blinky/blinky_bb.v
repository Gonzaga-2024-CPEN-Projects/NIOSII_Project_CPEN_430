
module blinky (
	audio_0_external_interface_BCLK,
	audio_0_external_interface_DACDAT,
	audio_0_external_interface_DACLRCK,
	clk_clk,
	leds_external_connection_export,
	reset_reset_n,
	switches_external_connection_export);	

	input		audio_0_external_interface_BCLK;
	output		audio_0_external_interface_DACDAT;
	input		audio_0_external_interface_DACLRCK;
	input		clk_clk;
	output	[1:0]	leds_external_connection_export;
	input		reset_reset_n;
	input	[1:0]	switches_external_connection_export;
endmodule
