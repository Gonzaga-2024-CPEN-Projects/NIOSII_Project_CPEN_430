#include <sys/alt_stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include <stdio.h>
#include <string.h>

// Deck of cards
char cardValues[52] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K','A',
					   '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A',
					   '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A',
					   '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

// Track cards pulled from deck
int cardDeck[52] = {0};

// Game Variables
int bankRoll = 10000;
int currentBet = 0; 
int dealerSum = 0; 
int playerSum = 0; 
int gamesPlayed = 0;
int cardsDealt = 0;
int ace_flag = 0;
int blackjack = 0;

// Hardware Initialization 
void update_GLED(int);
void update_RLED(int);
void init_SevenSeg(void); 
void init_LCD(void); 

// Game State
void play(void); // SW0
void dispInstructions(void); // SW1
void dispBankroll(); // Display each round

// Game Flow
void resetGameVariables(void);
void playerBet(void);
void dealInitialCards(void); 
void playerTurn(void);
int playerBust(void);
void dealerTurn(void);
int dealerBust(void);
int determineResult(void);
void delay(int); 

// Game Functionality
int generateRandomCard(void); // Hardware Random Number Generator
void updateDeck(int); // Update cardDeck[]
void resetDeck(void); 
int translateCardValue(int); // Handle 'T', 'J', 'Q', 'K'
void displayPlayerSum(void); // seven segment HEX7 and HEX6
void displayDealerSum(void); // seven segment HEX5 and HEX4
int sevenSegmentConversion(int); // Display digit on seven segment

// Player Actions
void hit(void); // KEY3
void stay(void); // KEY2

int main()
{
	alt_putstr("WELCOME TO NIOS II BLACKJACK\n");
	int KEY_PRESS;
	int SWITCHES;
	init_SevenSeg();
	while(1) {
		KEY_PRESS = IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
		SWITCHES = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
		update_RLED(SWITCHES);
		update_GLED(KEY_PRESS);

		// Play State
		while ((SWITCHES & 0x01) == 1) {
			if (bankRoll == 0) {
				// DISPLAY TO LCD
				alt_putstr("Game Over...\nPress RESET to play again!\n");
				return 0;
			} else {
				playRound();
				delay(2500000);
				init_SevenSeg();
				SWITCHES = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
			}
		}
		// Instruction State
		while (SWITCHES == 2) {
			// DISPLAY TO LCD
			dispInstructions();
			return 0;
		}
	}
	return 0;
}

/************************************************************
 Hardware Initialization
*************************************************************/ 
// GREEN LEDS reflect KEY input
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
//RED LEDS reflect SWITCH input
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
void init_LCD(void) {
	// TBD
	return;
}

/************************************************************
 Game State
*************************************************************/ 
void playRound(void) {
	int result;
	gamesPlayed++; 
	playerBet(); 
	// Display 2 Player Cards, 1 Dealer Card
	dealInitialCards();
	playerTurn();
	if (playerBust() == 0) {
		dealerTurn();
	}
	// Compare playerSum and dealerSum. Update bankRoll.
	result = determineResult();
	dispBankroll(); 
	resetGameVariables();
	return;
} 
void dispInstructions(void) {
	// DISPLAY TO LCD
	alt_putstr("BLACKJACK PAYS 3 to 2\nDEALER MUST HIT ON SOFT 17\n");
	return;
} 
void dispBankroll(void) {
	// DISPLAY TO LCD
		char msg[10];
		itoa(bankRoll, msg, 10);
		alt_putstr("BANKROLL: ");
		alt_putstr(msg);
		alt_putstr("\n");
		return;
} 

/************************************************************
 Game Flow
*************************************************************/ 
void resetGameVariables(void) {
	dealerSum = 0; 
	playerSum = 0; 
	ace_flag = 0;
	blackjack = 0;
	currentBet = 0;
}  
void playerBet(void) {
	int KEY_PRESS; 
	// DISPLAY TO LCD
	alt_putstr("\nPLACE YOUR BET TO BEGIN!\n");
	while(1) {
		KEY_PRESS = IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
		update_RLED(IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE));
		// Enter Bet
		if (KEY_PRESS == 3) {
			while(KEY_PRESS == 3){
				KEY_PRESS = IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
				update_GLED(KEY_PRESS);
			}
			update_GLED(KEY_PRESS);
			currentBet = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
			// ALL IN
			if (currentBet > bankRoll) {
				currentBet = bankRoll;
			}
			// DISPLAY TO LCD
			char msg[10];
			itoa(currentBet, msg, 10);
			alt_putstr("PLACED BET: ");
			alt_putstr(msg);
			alt_putstr("\n\n");
			return;
		}
	}
	return;
} 
void dealInitialCards(void) {
	int tempCard;
	int cardValue;  
	// Player First Two Cards
	for (int i = 0; i < 2; i++) {
		tempCard = generateRandomCard(); 
		while(cardDeck[tempCard] == 1) {
			tempCard = generateRandomCard(); 
		}
		updateDeck(tempCard);
		cardValue = translateCardValue(tempCard);
		// Ace Check
		if (cardValue == 11) {
			ace_flag = 1;
		}

		// DISPLAY TO LCD
		char msg[10]; 
		// itoa(cardValues[tempCard], msg, 10);
		alt_putstr("[PLAYER] - ");
		alt_putchar(cardValues[tempCard]);
		alt_putstr("\n");

		// Ace Low
		playerSum = playerSum + cardValue;
		if (ace_flag && (playerSum > 21)) {
			playerSum -= 10;
			ace_flag = 0;
		}
		displayPlayerSum();
		delay(1200000);
	}
	// Check for Player blackjack
	if (playerSum == 21) {
		blackjack = 1;
		alt_putstr("\n!!! BLACKJACK !!!\n\n");
	}

	// Dealer First Card Shown
	tempCard = generateRandomCard(); 
	while(cardDeck[tempCard] == 1) {
		tempCard = generateRandomCard(); 
	}
	updateDeck(tempCard);
	cardValue = translateCardValue(tempCard);

	// DISPLAY TO LCD
	char msg[10];
	// itoa(cardValues[tempCard], msg, 10);
	alt_putstr("[DEALER] - ");
	alt_putchar(cardValues[tempCard]);
	alt_putstr("\n");

	dealerSum = dealerSum + cardValue; 
	displayDealerSum();
	return;
} 
void playerTurn(void) {
	int KEY_PRESS;
	while(1) {
		KEY_PRESS = IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
		// HIT
		if (KEY_PRESS == 3) {
			while(KEY_PRESS == 3){
				update_GLED(KEY_PRESS);
				KEY_PRESS = IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
			}
			update_GLED(KEY_PRESS);

			hit();
			if (playerSum >= 21) {
				return;
			}
		}
		// STAY
		if (KEY_PRESS == 5) {
			while(KEY_PRESS == 5){
				update_GLED(KEY_PRESS);
				KEY_PRESS = IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
			}
			update_GLED(KEY_PRESS);
			stay();
			return;
		}
	}
	return;
} 
int playerBust(void) {
	int busted = 0;
	if (playerSum > 21) {
		busted = 1; 
	}
	return busted;
} 
void dealerTurn(void) {
	int card;
	int cardValue;
	while(1) {
		card = generateRandomCard();
		while(cardDeck[card] == 1) {
			card = generateRandomCard();
		}
		updateDeck(card);
		cardValue = translateCardValue(card);

		// DISPLAY TO LCD
		char msg[10];
		// itoa(cardValue, msg, 10);
		alt_putstr("[DEALER] - ");
		alt_putchar(cardValues[card]);
		alt_putstr("\n");

		// Update Dealer Sum
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
		bankRoll = bankRoll - currentBet;
		alt_putstr("\nRESULT: LOSS\n");
		return 0; 
	}
	else if (dealerBust() == 1 || (playerSum > dealerSum)) {
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 0xFF);
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0x80); // B
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0xC1); // U
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0xA1); // d
		// Blackjack pays 3 to 2
		if (blackjack == 1) {
			bankRoll = bankRoll + currentBet + (currentBet / 2);
		}
		else {
			bankRoll = bankRoll + currentBet;
		}
		alt_putstr("\nRESULT: WIN\n");
		return 1;
	}
	else if (playerSum == dealerSum) {
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 0x89); // H
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0x92); // S
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0xC1); // U
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0x8C); // P
		alt_putstr("\nRESULT: PUSH\n");
		return 2; 
	}
	else {
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 0x92); // S
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0x92); // S
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0xC0); // O
		IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0xC7); // L
		bankRoll = bankRoll - currentBet;
		alt_putstr("\nRESULT: LOSS\n");
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
	cardsDealt++;
	int random_num = IORD_ALTERA_AVALON_PIO_DATA(RANDOMS_BASE);
	return abs(random_num %52);
} 
void updateDeck(int cardIdx) {
	cardDeck[cardIdx] = 1; 
	if (cardsDealt == 47) {
		resetDeck();
	}
	return;
} 
void resetDeck(void) {
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
	// Display to HEX7 and HEX6
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
	// Display to HEX5 and HEX4
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
		case 9:
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

/************************************************************
 Player Actions
*************************************************************/ 
void hit(void) {
	int card;
	int cardValue;

	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 0xFF);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0x87);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0xCF);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0x89);

	card = generateRandomCard();
	while(cardDeck[card] == 1) {
		card = generateRandomCard(); 
	}
	updateDeck(card);
	cardValue = translateCardValue(card);

	// DISPLAY TO LCD
	char msg[10];
	// itoa(cardValue, msg, 10);
	alt_putstr("[PLAYER] - ");
	alt_putchar(cardValues[card]);
	alt_putstr("\n");

	// Ace Check
	if (cardValue == 11) {
		ace_flag = 1;
	}
	playerSum = playerSum + cardValue;
	if (playerSum > 21 && ace_flag) {
		playerSum = playerSum - 10;
		ace_flag = 0;
	}
	displayPlayerSum();
	return;
} 
void stay(void) {
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, 0x91);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_1_BASE, 0x88);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_2_BASE, 0x87);
	IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_3_BASE, 0x92);
	return;
}
