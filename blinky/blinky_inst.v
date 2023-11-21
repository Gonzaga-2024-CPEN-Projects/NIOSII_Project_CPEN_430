	blinky u0 (
		.clk_clk                              (<connected-to-clk_clk>),                              //                           clk.clk
		.leds_external_connection_export      (<connected-to-leds_external_connection_export>),      //      leds_external_connection.export
		.randoms_external_connection_export   (<connected-to-randoms_external_connection_export>),   //   randoms_external_connection.export
		.reset_reset_n                        (<connected-to-reset_reset_n>),                        //                         reset.reset_n
		.sev_seg_0_external_connection_export (<connected-to-sev_seg_0_external_connection_export>), // sev_seg_0_external_connection.export
		.switches_external_connection_export  (<connected-to-switches_external_connection_export>)   //  switches_external_connection.export
	);

