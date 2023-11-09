	blinky u0 (
		.clk_clk                             (<connected-to-clk_clk>),                             //                          clk.clk
		.lcd_external_interface_DATA         (<connected-to-lcd_external_interface_DATA>),         //       lcd_external_interface.DATA
		.lcd_external_interface_ON           (<connected-to-lcd_external_interface_ON>),           //                             .ON
		.lcd_external_interface_BLON         (<connected-to-lcd_external_interface_BLON>),         //                             .BLON
		.lcd_external_interface_EN           (<connected-to-lcd_external_interface_EN>),           //                             .EN
		.lcd_external_interface_RS           (<connected-to-lcd_external_interface_RS>),           //                             .RS
		.lcd_external_interface_RW           (<connected-to-lcd_external_interface_RW>),           //                             .RW
		.leds_external_connection_export     (<connected-to-leds_external_connection_export>),     //     leds_external_connection.export
		.reset_reset_n                       (<connected-to-reset_reset_n>),                       //                        reset.reset_n
		.switches_external_connection_export (<connected-to-switches_external_connection_export>)  // switches_external_connection.export
	);

