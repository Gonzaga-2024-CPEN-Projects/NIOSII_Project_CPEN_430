#include <sys/alt_stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include <stdio.h>
int main()
{
	int switch_data;
	int delay;
	int led_pattern=0x0;
	alt_putstr("Ciao from Nios II!\n");
	int random_num;
	int tmp;
	int card_val;
	printf("start program\n");
	while(1) {
			switch_data = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);

			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, switch_data & led_pattern);
			delay = 0;
			while(delay < 200000) {
				delay++;
			}
			led_pattern ^= switch_data; // toggle LEDs on selected switches
			random_num = IORD_ALTERA_AVALON_PIO_DATA(RANDOMS_BASE);
			IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, random_num);


			char msg[10];

			card_val = abs(random_num %52);

			itoa(card_val, msg, 10);

			alt_putstr(msg);
			alt_putstr("\n");


	}
	return 0;
}
