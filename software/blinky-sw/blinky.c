#include <sys/alt_stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include <stdio.h>


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
void init_GLED(void); // Reflect Key Input
void init_RLED(void); // Reflect Switch Input
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
int playerBust(int);
void dealerTurn(void); 
int dealerBust(int);
int determineResult(int, int); 
void delay(int); 

// Game Functionality
int generateRandomCard(void); // Hardware Random Number Generator
void updateDeck(int); // Array of Flags - Set Flag when card is selected
void resetDeck(void); 
int translateCardValue(int); 
void displayPlayerSum(int); // seven segment HEX7 and HEX6
void displayDealerSum(int); // seven segment HEX5 and HEX4
char* sevenSegmentConversion(int); 
void endRound(int, int);

// Player Actions
void hit(void); // KEY3
void stay(void); // KEY2

int main()
{
	alt_putstr("Ciao from Nios II!\n");
	printf("start program\n");
	int KEY_PRESS;
	// int delay;
	// int led_pattern=0x0;
	// int card_val;
	
	while(1) {
		init_SevenSeg(); 
		KEY_PRESS = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
		// Test HIT
		if (KEY_PRESS == "1000") {
			hit(); 
		}

		// Test STAY
		if (KEY_PRESS == "0100") {
			stay(); 
		}

		if (KEY_PRESS == "0010") {
			init_SevenSeg(); 
		}
	}
	return 0;
}

/************************************************************
 Hardware Initialization
*************************************************************/ 
void init_GLED(void) {
	// Initialize to Match KEYS (specifically the green led that is in the middle of each key)
	return;
} 
void init_RLED(void) {
	// Initialize to Match SWITCHES
	return;
}
void init_SevenSeg(void) {
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 0xDF);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0xDF);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0xDF);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0xDF);

	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_4_BASE, 0xC7);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_5_BASE, 0xA1);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_6_BASE, 0xC7);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_7_BASE, 0x9C);
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
void play(void) {
	gameInitialization(); 
	while(1) {
		// PlayerBet
		// Display first three cards
		// Player Turn
		// Player Bust or Dealer Turn
		// Dealer Bust or Compare Sums
		// Update Bankroll
		// Reset Deck or Begin Next Round
	}
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
	int cardValue = translateCardValue(cardValues[tempCard]);
	dealerSum = dealerSum + cardValue; 

	// Player First Two Cards
	for (int i = 0; i < 2; i++) {
		tempCard = generateRandomCard(); 
		while(cardDeck[tempCard] == 1) {
			tempCard = generateRandomCard(); 
		}
		updateDeck(tempCard);
		cardValue = translateCardValue(cardValues[tempCard]);
		playerSum = dealerSum + cardValue;
	}
	return;
} 
void playerTurn(void) {
	// Wait for Key Press (hit or stay)
	// Calculate
	// Bust?
	// Wait for Key Press...
	return;
} 
int playerBust(int playerSum) {
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
	return; 
} 
int dealerBust(int dealerSum) {
	// Check if Dealer sum <= 21
	int busted = 0;
	if (dealerSum > 21) {
		busted = 1; 
	}
	return busted;
}
int determineResult(int playerSum, int dealerSum) {
	if (playerBust(playerSum) == 1) {
		return 0; 
	}
	else if (dealerBust(dealerSum) == 1) {
		return 1;
	}
	else if (playerSum == dealerSum) {
		return 2; 
	}
	else if (playerSum > dealerSum) {
		return 1; 
	}
	else {
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
	int cardValue = (int)(cardValues[cardIdx] - '0'); 
	if (cardValue > 11) {
		cardValue = 10; 
	}
	return cardValue; 
}
void displayPlayerSum(int playerSum) {
	// display to HEX7 and HEX6
	int ones = playerSum % 10; 
	int tens = playerSum / 10; 
	char hexVal[4] = sevenSegmentConversion(ones); 
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_6_BASE, hexVal);
	hexVal[4] = sevenSegmentConversion(tens); 
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_7_BASE, hexVal);

	return;
} 
void displayDealerSum(int dealerSum) {
	// display to HEX5 and HEX4
	int ones = dealerSum % 10; 
	int tens = dealerSum / 10; 
	char hexVal[4] = sevenSegmentConversion(ones); 
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_4_BASE, hexVal);
	hexVal[4] = sevenSegmentConversion(tens); 
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_5_BASE, hexVal);
	return;
} 
char* sevenSegmentConversion(int digit) {
	char hexVal[4]; 
	switch(digit) {
		case 9: //00010010
			hexVal = '0x90';
			break; 
		case 8: 
			hexVal = '0x80';
			break; 
		case 7:
			hexVal = '0xF8';
			break; 
		case 6: 
			hexVal = '0x82';
			break; 
		case 5: 
			hexVal = '0x92';
			break; 
		case 4: 
			hexVal = '0x99';
			break; 
		case 3: 
			hexVal = '0xB0';
			break; 
		case 2: 
			hexVal = '0xA4';
			break; 
		case 1: 
			hexVal = '0xF9';
			break; 
		case 0:
			hexVal = '0xC0';
			break; 
		default: 
			break; 
	}
	char* ptr = hexVal; 
	return ptr;
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
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0xC1);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0xF9);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0x89);
	// Generate Random Card
	int card = generateRandomCard(); 

	// Check and Update Deck
	while(cardDeck[card] == 1) {
		card = generateRandomCard(); 
	}
	updateDeck(card);

	// Char to Int
	int cardValue = translateCardValue(cardValues[card]);

	// Update playerSum
	playerSum = playerSum + cardValue;
	displayPlayerSum(playerSum);
	return;
} 
void stay(void) { // Nothing Happens
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 0x91);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0x88);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0xC1);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0x92);
	displayPlayerSum(playerSum);
	return;
}
