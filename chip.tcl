set_location_assignment PIN_Y2 -to clk
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to clk

set_location_assignment PIN_M23 -to reset_n
set_instance_assignment -name IO_STANDARD "2.5 V" -to reset_n


set_location_assignment PIN_Y23 -to sw_n
set_instance_assignment -name IO_STANDARD "2.5 V" -to sw

set_location_assignment PIN_E21 -to leds[0]
set_location_assignment PIN_E22 -to leds[1]
set_location_assignment PIN_E25 -to leds[2]
set_instance_assignment -name IO_STANDARD "2.5 V" -to leds[0] 
set_instance_assignment -name IO_STANDARD "2.5 V" -to leds[1] 
set_instance_assignment -name IO_STANDARD "2.5 V" -to leds[2] 

set_location_assignment PIN_AB28 -to switches[0]
set_location_assignment PIN_AC28 -to switches[1] 
set_location_assignment PIN_AC27 -to switches[2] 
set_instance_assignment -name IO_STANDARD "2.5 V" -to switches[0] 
set_instance_assignment -name IO_STANDARD "2.5 V" -to switches[1] 
set_instance_assignment -name IO_STANDARD "2.5 V" -to switches[2] 
set_location_assignment PIN_G19 -to rled 
set_instance_assignment -name IO_STANDARD "2.5 V" -to rled

set_location_assignment PIN_M5 -to lcd_data[7]
set_location_assignment PIN_M3 -to lcd_data[6]
set_location_assignment PIN_K2 -to lcd_data[5]
set_location_assignment PIN_K1 -to lcd_data[4]
set_location_assignment PIN_K7 -to lcd_data[3]
set_location_assignment PIN_L2 -to lcd_data[2]
set_location_assignment PIN_L1 -to lcd_data[1]
set_location_assignment PIN_L3 -to lcd_data[0]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to lcd_data[7]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to lcd_data[6]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to lcd_data[5]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to lcd_data[4]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to lcd_data[3]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to lcd_data[2]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to lcd_data[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to lcd_data[0]
set_location_assignment PIN_L4 -to lcd_en
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to lcd_en
set_location_assignment PIN_M1 -to lcd_rw
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to lcd_rw
set_location_assignment PIN_M2 -to lcd_rs
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to lcd_rs
set_location_assignment PIN_L5 -to lcd_on
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to lcd_on
set_location_assignment PIN_L6 -to lcd_blon
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to lcd_blon
set_instance_assignment -name PARTITION_HIERARCHY root_partition -to | -section_id Top