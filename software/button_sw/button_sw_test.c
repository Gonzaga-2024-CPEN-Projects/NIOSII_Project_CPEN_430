#include <sys/alt_stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
int main()
{
	int switch_data;
	int buttons_data;
	int delay;
	alt_putstr("Ciao from Nios II!\n");
	while(1) {
			switch_data = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
			buttons_data = IORD_ALTERA_AVALON_PIO_DATA(BUTTONS_BASE);

			if (switch_data & 0x10000) {
				IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, 0x03);
			} else {
				IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, 0x00);
			}

			if (!buttons_data) {
				alt_putstr("Ciao from Nios II!\n");
			}

			delay = 0;
			while(delay < 200000) {
				delay++;
			}
	}
	return 0;
}
