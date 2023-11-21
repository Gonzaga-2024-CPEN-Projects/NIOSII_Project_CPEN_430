set_location_assignment PIN_Y2 -to clk
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to clk

set_location_assignment PIN_M23 -to reset_n
set_instance_assignment -name IO_STANDARD "2.5 V" -to reset_n


set_location_assignment PIN_Y23 -to sw_n
set_instance_assignment -name IO_STANDARD "2.5 V" -to sw

set_location_assignment PIN_E21 -to leds[0]
set_location_assignment PIN_E22 -to leds[1]
set_instance_assignment -name IO_STANDARD "2.5 V" -to leds[0] 
set_instance_assignment -name IO_STANDARD "2.5 V" -to leds[1] 

set_location_assignment PIN_AB28 -to switches[0]
set_location_assignment PIN_AC28 -to switches[1] 
set_instance_assignment -name IO_STANDARD "2.5 V" -to switches[0] 
set_instance_assignment -name IO_STANDARD "2.5 V" -to switches[1] 
set_location_assignment PIN_G19 -to rled 
set_instance_assignment -name IO_STANDARD "2.5 V" -to rled

set_location_assignment PIN_G18 -to sev_seg_0[0]
set_location_assignment PIN_F22 -to sev_seg_0[1]
set_location_assignment PIN_E17 -to sev_seg_0[2]
set_location_assignment PIN_L26 -to sev_seg_0[3]
set_location_assignment PIN_L25 -to sev_seg_0[4]
set_location_assignment PIN_J22 -to sev_seg_0[5]
set_location_assignment PIN_H22 -to sev_seg_0[6]