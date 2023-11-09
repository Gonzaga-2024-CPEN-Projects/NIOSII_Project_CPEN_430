
module blinky (
	clk_clk,
	lcd_external_interface_DATA,
	lcd_external_interface_ON,
	lcd_external_interface_BLON,
	lcd_external_interface_EN,
	lcd_external_interface_RS,
	lcd_external_interface_RW,
	leds_external_connection_export,
	reset_reset_n,
	switches_external_connection_export);	

	input		clk_clk;
	inout	[7:0]	lcd_external_interface_DATA;
	output		lcd_external_interface_ON;
	output		lcd_external_interface_BLON;
	output		lcd_external_interface_EN;
	output		lcd_external_interface_RS;
	output		lcd_external_interface_RW;
	output	[2:0]	leds_external_connection_export;
	input		reset_reset_n;
	input	[2:0]	switches_external_connection_export;
endmodule
