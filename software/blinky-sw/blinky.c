#include <sys/alt_stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "altera_up_avalon_character_lcd.h"

int main()
{
	int switch_data;
	int delay;
	int led_pattern=0x0;
	alt_putstr("Ciao 13\n");
	alt_putstr("Ciao from Nios III!\n");


	alt_up_character_lcd_dev* char_lcd_dev;
	 /*open the Character LCD port*/

	char_lcd_dev = alt_up_character_lcd_open_dev("/dev/character_lcd");
	alt_putstr("Ciao 2\n");
	if (char_lcd_dev == NULL)
		alt_putstr("Error: could not open character LCD device\n");
	else
		alt_putstr("Opened character LCD device\n");
//	/* Initialize the character display */
//	alt_up_character_lcd_init(char_lcd_dev);
//	/* Write "Welcome to" in the first row */
//	alt_up_character_lcd_string(char_lcd_dev, "Welcome to");
//	/* Write "the DE2 board" in the second row */
//	char second_row[] = "the DE2 board\0";
//	alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 1);
//	alt_up_character_lcd_string(char_lcd_dev, second_row);

//	while(1) {
//			switch_data = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
//			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, switch_data & led_pattern);
//			delay = 0;
//			while(delay < 200000) {
//				delay++;
//			}
//			led_pattern ^= switch_data; // toggle LEDs on selected switches
//	}



	return 0;
}
