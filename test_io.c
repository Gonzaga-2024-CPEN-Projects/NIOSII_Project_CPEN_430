/*
 * test_io.c
 *
 *  Created on: Nov 7, 2023
 *      Author: iflury
 */
#include <sys/alt_stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
int main()
{
	int button_data;
	int delay;
//	int led_pattern=0x0;
	alt_putstr("Ciao from Nios II!\n");
	while(1) {
			button_data = IORD_ALTERA_AVALON_PIO_DATA(BUTTONS_BASE);
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, button_data);
			delay = 0;
			while(delay < 200000) {
				delay++;
			}
	}
	return 0;
}


