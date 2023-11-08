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

set_location_assignment PIN_M21 -to buttons[0]
set_location_assignment PIN_N21 -to buttons[1]
set_location_assignment PIN_R24 -to buttons[2]


set_instance_assignment -name IO_STANDARD "2.5 V" -to buttons[0]
set_instance_assignment -name IO_STANDARD "2.5 V" -to buttons[1]
set_instance_assignment -name IO_STANDARD "2.5 V" -to buttons[2]

