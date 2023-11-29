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
void dispBankroll(void); //SW2


// Game Flow
void gameInitialization(void); // set deck and 
void playerBet(void); // Read Value from Switches, Wait for KEY0 to be pressed
void dealInitialCards(void); 
void playerTurn(void); 
int playerBust(int);
void dealerTurn(void); 
int dealerBust(int);
void updateBankroll(int, int);


// Game Functionality
int generateRandomCard(void); // Hardware Random Number Generator
void updateDeck(int); // Array of Flags - Set Flag when card is selected
void resetDeck(void); 
int translateCardValue(int); 
void displayPlayerSum(int); // seven segment HEX7 and HEX6
void displayDealerSum(int); // seven segment HEX5 and HEX4
void displayResult(int);


// Player Actions
void hit(void); // KEY3
void stay(void); // KEY2


int main()
{
	int switch_data;
	int key_data;
	int delay;
	int led_pattern=0x0;
	alt_putstr("Ciao from Nios II!\n");
	int card_val;
	printf("start program\n");
	while(1) {
//			switch_data = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
//
//			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, switch_data & led_pattern);
//			delay = 0;
//			while(delay < 200000) {
//				delay++;
//			}
//			led_pattern ^= switch_data; // toggle LEDs on selected switches
//
//			IOWR_ALTERA_AVALON_PIO_DATA(SEV_SEG_0_BASE, random_num);


//			char msg[10];
//			card_val = generateRandomCard();
//			itoa(card_val, msg, 10);
//			alt_putstr(msg);
//			alt_putstr("\n");



		update_GLED(IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE));
		update_RLED(IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE));

		//key_data = IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);





	}
	return 0;
}

/************************************************************
 Hardware Initialization and Updating
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
	return;
} 
void init_Switches(void) {
	return;
}
void init_Keys(void) {
	return;
}
void init_LCD(void) {
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
	return;
} 
void dispBankroll(void) {
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
void updateBankroll(int busted, int playerBet) {
	if (busted == 1) {
		if (playerBet >= bankRoll) {
			// TODO: GAME OVERRRRRRRRRRRRR
		}
		bankRoll = bankRoll - playerBet; 
	}
	else {
		bankRoll = bankRoll + playerBet; 
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
	// display sum to HEX7 and HEX6 on seven seg display
	return;
} 
void displayDealerSum(int dealerSum) {
	// display sum to HEX5 and HEX4 on seven seg display
	return;
} 
void displayResult(int result) {
	// display message on LCD
	if (result == 1) { // WIN
		return; 
	}
	else { // LOSE
		return; 
	}
	return;
}


/************************************************************
 Player Actions
*************************************************************/ 
void hit(void) {
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
	return;
} 
void stay(void) { // Nothing Happens
	return;
}
