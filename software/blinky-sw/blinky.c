#include <sys/alt_stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include <stdio.h>


char cardValues[52] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K','A',
					  '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A', 
					  '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A', 
					  '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A'};
int cardDeck[52] = {0}
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
bool playerBust(int); 
void dealerTurn(void); 
bool dealerBust(int); 
void updateBankroll(bool, int); 


// Game Functionality
int GenerateRandomCard(void); // Hardware Random Number Generator
void updateDeck(void); // Array of Flags - Set Flag when card is selected
void resetDeck(void); 
void displayPlayerSum(int); // seven segment HEX7 and HEX6
void displayDealerSum(int); // seven segment HEX5 and HEX4
void displayResult(bool);


// Player Actions
void hit(void); // KEY3
void stay(void); // KEY2
void submitBet(void); // KEY0


int main()
{
	int switch_data;
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




			char msg[10];
			card_val = GenerateRandomCard();
			itoa(card_val, msg, 10);
			alt_putstr(msg);
			alt_putstr("\n");

	}
	return 0;
}

/************************************************************
 Hardware Initialization
*************************************************************/ 
void init_GLED(void) {

} 
void init_RLED(void) {
	
}
void init_SevenSeg(void) {
	
} 
void init_Switches(void) {
	
}
void init_Keys(void) {
	
}
void init_LCD(void)


/************************************************************
 Game State
*************************************************************/ 
void readSwitches(void) {
	// play if SW0 = 1
	// display instructions if SW1 = 1 
	// display bankroll if SW2 = 1
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
	
} 
void dispBankroll(void) {
	
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
	// Read Switches once KEY0 is pressed
} 
void dealInitialCards(void) {
	// Generate Dealer First Card and Player Cards
	// Update and Display Dealer Sum
	// Update and Display Player Sum
} 
void playerTurn(void) {
	// Wait for Key Press (hit or stay)
	// Calculate
	// Bust?
	// Wait for Key Press...
} 
bool playerBust(int) {
	// Check if Player sum <= 21
} 
void dealerTurn(void) {
	// Automatic cycle
	// Implement wait time for each card
} 
bool dealerBust(int) {
	// Check if Dealer sum <= 21
} 
void updateBankroll(bool, int) {
	
} 


/************************************************************
 Game Functionality
*************************************************************/ 
int GenerateRandomCard(void) {
	int random_num = IORD_ALTERA_AVALON_PIO_DATA(RANDOMS_BASE);
	return abs(random_num %52);
} 
void updateDeck(void) {
	// set 0 -> 1 in cardDeck array
} 
void resetDeck(void) {
	// set all indicies of cardDeck array back to 0
} 
void displayPlayerSum(int) {
	// display sum to HEX7 and HEX6 on seven seg display
} 
void displayDealerSum(int) {
	// display sum to HEX5 and HEX4 on seven seg display
} 
void displayResult(bool) {
	// display message on LCD
}


/************************************************************
 Player Actions
*************************************************************/ 
void hit(void) {
	// Generate Random Card
	// Update Deck
	// Update playerSum
} 
void stay(void) {
	// Dealer Turn
}
void submitBet(void) {
	// ReadSwitches
	// KEY0 Press for Enter
}


