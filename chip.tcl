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

set_location_assignment PIN_M24 -to sev_seg_1[0]
set_location_assignment PIN_Y22 -to sev_seg_1[1]
set_location_assignment PIN_W21 -to sev_seg_1[2]
set_location_assignment PIN_W22 -to sev_seg_1[3]
set_location_assignment PIN_W25 -to sev_seg_1[4]
set_location_assignment PIN_U23 -to sev_seg_1[5]
set_location_assignment PIN_U24 -to sev_seg_1[6] 

set_location_assignment PIN_AA25 -to sev_seg_2[0]
set_location_assignment PIN_AA26 -to sev_seg_2[1]
set_location_assignment PIN_Y25 -to sev_seg_2[2]
set_location_assignment PIN_W26 -to sev_seg_2[3]
set_location_assignment PIN_Y26 -to sev_seg_2[4]
set_location_assignment PIN_W27 -to sev_seg_2[5]
set_location_assignment PIN_W28 -to sev_seg_2[6] 

set_location_assignment PIN_V21 -to sev_seg_3[0]
set_location_assignment PIN_U21 -to sev_seg_3[1]
set_location_assignment PIN_AB20 -to sev_seg_3[2]
set_location_assignment PIN_AA21 -to sev_seg_3[3]
set_location_assignment PIN_AD24 -to sev_seg_3[4]
set_location_assignment PIN_AF23 -to sev_seg_3[5]
set_location_assignment PIN_Y19 -to sev_seg_3[6] 

set_location_assignment PIN_AB19 -to sev_seg_4[0]
set_location_assignment PIN_AA19 -to sev_seg_4[1]
set_location_assignment PIN_AG21 -to sev_seg_4[2]
set_location_assignment PIN_AH21 -to sev_seg_4[3]
set_location_assignment PIN_AE19 -to sev_seg_4[4]
set_location_assignment PIN_AF19 -to sev_seg_4[5]
set_location_assignment PIN_AE18 -to sev_seg_4[6] 

set_location_assignment PIN_AD18 -to sev_seg_5[0]
set_location_assignment PIN_AC18 -to sev_seg_5[1]
set_location_assignment PIN_AB18 -to sev_seg_5[2]
set_location_assignment PIN_AH19 -to sev_seg_5[3]
set_location_assignment PIN_AG19 -to sev_seg_5[4]
set_location_assignment PIN_AF18 -to sev_seg_5[5]
set_location_assignment PIN_AH18 -to sev_seg_5[6] 

set_location_assignment PIN_AA17 -to sev_seg_6[0]
set_location_assignment PIN_AB16 -to sev_seg_6[1]
set_location_assignment PIN_AA16 -to sev_seg_6[2]
set_location_assignment PIN_AB17 -to sev_seg_6[3]
set_location_assignment PIN_AB15 -to sev_seg_6[4]
set_location_assignment PIN_AA15 -to sev_seg_6[5]
set_location_assignment PIN_AC17 -to sev_seg_6[6] 

set_location_assignment PIN_AD17 -to sev_seg_7[0]
set_location_assignment PIN_AE17 -to sev_seg_7[1]
set_location_assignment PIN_AG17 -to sev_seg_7[2]
set_location_assignment PIN_AH17 -to sev_seg_7[3]
set_location_assignment PIN_AF17 -to sev_seg_7[4]
set_location_assignment PIN_AG18 -to sev_seg_7[5]
set_location_assignment PIN_AA14 -to sev_seg_7[6] 
