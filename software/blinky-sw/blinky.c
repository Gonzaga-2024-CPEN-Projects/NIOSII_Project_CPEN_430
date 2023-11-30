#include <sys/alt_stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include <stdio.h>
#include <string.h>


char cardValues[52] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K','A',
					   '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A',
					   '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A',
					   '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
int cardDeck[52] = {0};
int bankRoll = 1000;
int dealerSum = 0; 
int playerSum = 0; 
int gamesPlayed = 0;  

// Hardware Initialization 
void update_GLED(int);
void update_RLED(int);
void init_SevenSeg(void); 
void init_Switches(void);
void init_Keys(void);
void init_LCD(void); 

// Game State
void readSwitches(void); 
void play(void); // SW0
void dispInstructions(void); // SW1
void dispBankroll(int); //SW2

// Game Flow
void gameInitialization(void); // set deck and 
void playerBet(void); // Read Value from Switches, Wait for KEY0 to be pressed
void dealInitialCards(void); 
void playerTurn(void);
int playerBust(void);
void dealerTurn(void);
int dealerBust(void);
int determineResult(void);
void delay(int); 

// Game Functionality
int generateRandomCard(void); // Hardware Random Number Generator
void updateDeck(int); // Array of Flags - Set Flag when card is selected
void resetDeck(void); 
int translateCardValue(int); 
void displayPlayerSum(void); // seven segment HEX7 and HEX6
void displayDealerSum(void); // seven segment HEX5 and HEX4
int sevenSegmentConversion(int);
void endRound(int, int);

// Player Actions
void hit(void); // KEY3
void stay(void); // KEY2

int main()
{
	alt_putstr("Ciao from Nios II!\n");
	printf("start program\n");
	int KEY_PRESS;
	int SWITCHES;
	init_SevenSeg();
	while(1) {
		gameInitialization();
		KEY_PRESS = IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
		SWITCHES = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
		while (SWITCHES == 1) {
			playRound();
			delay(2100000);
			init_SevenSeg();
			SWITCHES = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
		}

		update_GLED(KEY_PRESS);
		update_RLED(SWITCHES);

	}
	return 0;
}

/************************************************************
 Hardware Initialization
*************************************************************/ 
//key_data input is directly from reading
//Example function call: update_GLED(IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE));
void update_GLED(int key_data){
	if(key_data == 3){
		IOWR_ALTERA_AVALON_PIO_DATA(GRN_LEDS_BASE, 0x40);
	}
	else if(key_data == 5){
		IOWR_ALTERA_AVALON_PIO_DATA(GRN_LEDS_BASE, 0x10);
	}
	else if(key_data == 6){
		IOWR_ALTERA_AVALON_PIO_DATA(GRN_LEDS_BASE, 0x4);
	}
	else{
		IOWR_ALTERA_AVALON_PIO_DATA(GRN_LEDS_BASE, 0x00);
	}

	return;
} 

//update the red leds with the switch states, pass in raw switch reading
//Example function call: update_RLED(IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE));
void update_RLED(int switch_data) {
	IOWR_ALTERA_AVALON_PIO_DATA(RED_LEDS_BASE, switch_data);
	return;
}
void init_SevenSeg(void) {
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 191);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 191);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 191);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 191);

	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_4_BASE, 0xC7);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_5_BASE, 0xA1);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_6_BASE, 0xC7);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_7_BASE, 0x8C);
	return;
} 
void init_Switches(void) {
	// NOTSURE IF WE NEED THIS
	return;
}
void init_Keys(void) {
	// NOTSURE IF WE NEED THIS
	return;
}
void init_LCD(void) {
	// TBD
	return;
}

/************************************************************
 Game State
*************************************************************/ 
void readSwitches(void) {
	// play if SW0 = 1
	// display instructions if SW1 = 1 
	// display bankroll if SW2 = 1
	return;
}
void playRound(void) {
	int result;

	// PlayerBet
	// Display first three cards
	dealInitialCards();
	// Player Turn
	playerTurn();
	// Player Bust or Dealer Turn
	if (playerBust() == 0) {
		dealerTurn();
	}
	// Determine Result
	result = determineResult();
	playerSum = 0;
	dealerSum = 0;
	char msg[10];
	itoa(result, msg, 10);
	alt_putstr(msg);
	alt_putstr(" <-- RESULT [0 = lost; 1 = win] \n\n");
	// Update Bankroll
	// Reset Deck or Begin Next Round
	return;
} 
void dispInstructions(void) {
	// DISPLAY TO LCD
	return;
} 
void dispBankroll(int bankRoll) {
	// DISPLAY TO LCD
	return;
} 


/************************************************************
 Game Flow
*************************************************************/ 
void gameInitialization(void) {
	bankRoll = 1000;
	dealerSum = 0; 
	playerSum = 0; 
	gamesPlayed = 0; 
}  
void playerBet(void) {
	// Wait for KEY0 to be pressed
	// Read Values on Switch
	// Translate Values to DEC.
	return;
} 
void dealInitialCards(void) {
	// Dealer First Card Shown
	resetDeck(); 
	int tempCard = generateRandomCard(); 
	while(cardDeck[tempCard] == 1) {
		tempCard = generateRandomCard(); 
	}
	updateDeck(tempCard);
	int cardValue = translateCardValue(tempCard);
	char msg[10];
	itoa(cardValue, msg, 10);
	alt_putstr(msg);
	alt_putstr(" DEALER CARD \n");
	dealerSum = dealerSum + cardValue; 
	displayDealerSum();
	// Player First Two Cards
	for (int i = 0; i < 2; i++) {
		tempCard = generateRandomCard(); 
		while(cardDeck[tempCard] == 1) {
			tempCard = generateRandomCard(); 
		}
		updateDeck(tempCard);
		cardValue = translateCardValue(tempCard);
		itoa(cardValue, msg, 10);
		alt_putstr(msg);
		alt_putstr(" PLAYER CARD \n");
		playerSum = playerSum + cardValue;
		if (playerSum == 22) {
			playerSum = 12;
		}
		displayPlayerSum();
		delay(1200000);
	}
	return;
} 
void playerTurn(void) {
	int KEY_PRESS;
	while(1) {
		KEY_PRESS = IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
		if (KEY_PRESS == 3) {
			while(KEY_PRESS == 3){
				KEY_PRESS = IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
			}
			hit();
			if (playerSum >= 21) {
				return;
			}
		}

		if (KEY_PRESS == 5) {
			while(KEY_PRESS == 5){
				KEY_PRESS = IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
			}
			stay();
			return;
		}
	}
	return;
} 
int playerBust(void) {
	// Check if Player sum <= 21
	int busted = 0;
	if (playerSum > 21) {
		busted = 1; 
	}
	return busted;
} 
void dealerTurn(void) {
	// Automatic cycle
	// Implement wait time for each card
	int card;
	while(1) {
		card = generateRandomCard();
		while(cardDeck[card] == 1) {
			card = generateRandomCard();
		}
		updateDeck(card);
		int cardValue = translateCardValue(card);
		char msg[10];
		itoa(cardValue, msg, 10);
		alt_putstr(msg);
		alt_putstr(" DEALER CARD \n");
		// Update playerSum
		dealerSum = dealerSum + cardValue;
		displayDealerSum();
		if (dealerSum >= 17) {
			return;
		}
		delay(1000000);
	}
	return; 
} 
int dealerBust(void) {
	// Check if Dealer sum <= 21
	int busted = 0;
	if (dealerSum > 21) {
		busted = 1; 
	}
	return busted;
}
int determineResult(void) {
	if (playerBust() == 1) {
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 0x92); // S
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0x92); // S
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0xC0); // O
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0xC7); // L
	}
	else if (dealerBust() == 1 || (playerSum > dealerSum)) {
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 0xFF);
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0x80); // B
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0xC1); // U
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0xA1); // d
		return 1;
	}
	else if (playerSum == dealerSum) {
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 0x89); // H
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0x92); // S
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0xC1); // U
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0x8C); // P
		return 2; 
	}
	else {
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 0x92); // S
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0x92); // S
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0xC0); // O
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0xC7); // L
		return 0;
	}
}
void delay(int delay) {
	int count = 0; 
	while(count < delay) {
		count++;
	}
	return; 
}


/************************************************************
 Game Functionality
*************************************************************/ 
int generateRandomCard(void) {
	int random_num = IORD_ALTERA_AVALON_PIO_DATA(RANDOMS_BASE);
	return abs(random_num %52);
} 
void updateDeck(int cardIdx) {
	// set 0 -> 1 in cardDeck array
	cardDeck[cardIdx] = 1; 
	return;
} 
void resetDeck(void) {
	// set all indicies of cardDeck array back to 0
	for (int i = 0; i < 52; i++) {
		cardDeck[i] = 0; 
	}
	return;
} 
int translateCardValue(int cardIdx) {
	int cardValue = cardValues[cardIdx] - 48;
	if (cardValue == 17) {
		cardValue = 11;
	}
	else if (cardValue > 11) {
		cardValue = 10; 
	}
	return cardValue; 
}
void displayPlayerSum(void) {
	// display to HEX7 and HEX6
	int ones = playerSum % 10; 
	int tens = playerSum / 10; 
	int hexVal;
	hexVal = sevenSegmentConversion(ones);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_6_BASE, hexVal);
	hexVal = sevenSegmentConversion(tens);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_7_BASE, hexVal);
	return;
} 
void displayDealerSum(void) {
	// display to HEX5 and HEX4
	int ones = dealerSum % 10; 
	int tens = dealerSum / 10; 
	int hexVal;
	hexVal = sevenSegmentConversion(ones);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_4_BASE, hexVal);
	hexVal = sevenSegmentConversion(tens);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_5_BASE, hexVal);
	return;
} 
int sevenSegmentConversion(int digit) {
	int hexVal;
	switch(digit) {
		case 9: //00010010
			hexVal = 0x90;
			break; 
		case 8:
			hexVal = 0x80;
			break;
		case 7:
			hexVal = 0xF8;
			break;
		case 6:
			hexVal = 0x82;
			break;
		case 5:
			hexVal = 0x92;
			break;
		case 4:
			hexVal = 0x99;
			break;
		case 3:
			hexVal = 0xB0;
			break;
		case 2:
			hexVal = 0xA4;
			break;
		case 1:
			hexVal = 0xF9;
			break;
		case 0:
			hexVal = 0xC0;
			break;
		default: 
			break; 
	}
	return hexVal;
}
void endRound(int result, int playerBet) {
	// display message on LCD
	if (result == 2) { // PUSH
		// Display "PUSH"
		// Bankroll Doesn't Change
		return;
	}
	else if (result == 1) { // WIN
		// Display "PLAYER WINS!"
		bankRoll = bankRoll - playerBet; 
		return; 
	}
	else { // LOSE
		// Display "DEALER WINS!"
		bankRoll = bankRoll + playerBet;
		return; 
	}
	return;
}


/************************************************************
 Player Actions
*************************************************************/ 
void hit(void) {
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 0xFF);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0x87);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0xCF);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0x89);
	// Generate Random Card
	int card = generateRandomCard();

	// Check and Update Deck
	while(cardDeck[card] == 1) {
		card = generateRandomCard(); 
	}
	updateDeck(card);

	// Char to Int
	int cardValue = translateCardValue(card);
	char msg[10];
	itoa(cardValue, msg, 10);
	alt_putstr(msg);
	alt_putstr(" PLAYER CARD \n");
	// Update playerSum
	playerSum = playerSum + cardValue;
	displayPlayerSum();
	return;
} 
void stay(void) { // Nothing Happens
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 0x91);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0x88);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0x87);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0x92);
	return;
}
