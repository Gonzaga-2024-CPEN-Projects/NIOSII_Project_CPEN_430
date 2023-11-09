#include <sys/alt_stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
int main()
{
	int buttons_data;
	int delay;
	alt_putstr("Ciao from Nios II!\n");
	while(1) {
			buttons_data = IORD_ALTERA_AVALON_PIO_DATA(BUTTONS_BASE);
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, buttons_data);
			delay = 0;
			while(delay < 200000) {
				delay++;
			}
			if (!(buttons_data & 0x4)) {
				alt_putstr("Ciao from Nios II!\n");
			}
	}
	return 0;
}
