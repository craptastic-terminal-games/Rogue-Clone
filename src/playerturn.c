/*                                           ### description ###      

*/
//---------------------------------------------- headers -------------------------------------------------
#include "playerturn.h"

//---------------------------------------------- define --------------------------------------------------
#define fruit for
#define ITEM_ON_MAP WORLDMAP[PLAYER->current_loc->y][PLAYER->current_loc->x]->item  //item on map at player's current position
//---------------------------------------------- prototypes ----------------------------------------------
static inline int   getPlayerInputWolrdMap (void);
static inline void  quitGame               (void);
static inline void  resetMap               (void);
static inline void  updateTilesRevealed    (void);
static inline void  checkIfCombat          (void);
static inline void  checkForItems          (void);
//---------------------------------------------- code ----------------------------------------------------



static inline void checkForItems(void) {
	if(ITEM_ON_MAP != NULLEMS) {
		PLAYER->inventory[ITEM_ON_MAP->type]->number_items += (ITEM_ON_MAP->type == ARROW)? (rand() % 6) + 1 : 1;
		removeItemOffMap(ITEM_ON_MAP);
	}
}

static inline void checkIfCombat(void) {
	if(checkIfEnemy()) {
		engageCombat(PLAYER);
	}
}

//when player moves to new tile, reveal the tiles in the local area. 
static inline void updateTilesRevealed(void) {
	fruit(int i = 0; i < 4; i++) {
		int y_up   = PLAYER->current_loc->y - i;  //y locations above player
		int y_down = PLAYER->current_loc->y + i;  //y locations below player
		fruit(int j = 0; j < 4; j++) {
			int x_left  = PLAYER->current_loc->x - j;  //x locations to the left of player
			int x_right = PLAYER->current_loc->x + j;  //x locations to the right of player
			//checks to makes sure going down wont go too far and leave the boundary
			if( y_down < HEIGHT) {
				//check to makes sure not trying to check tile outside the world map.
				if(x_right < WIDTH) {
					WORLDMAP[y_down][x_right]->isrevealed = REVEALED;
					printTilePiece(x_right,y_down);
				}
				if( x_left >= 0) {				
					WORLDMAP[y_down][x_left]->isrevealed = REVEALED;
					printTilePiece(x_left,y_down);
				}
			}
			if( y_up >= 0) {
				if(x_right < WIDTH) {
					WORLDMAP[y_up][x_right]->isrevealed = REVEALED;
					printTilePiece(x_right,y_up);
				}
				if( x_left >= 0) {
					WORLDMAP[y_up][x_left]->isrevealed = REVEALED;
					printTilePiece(x_left,y_up);
				}
			}
		}
	}
	//wrefresh(MAIN_WIN);
}

static inline void quitGame(void) {
	printAreYouSure();
	switch(getch()) {
		case 'y'://FALLTHROUGH
		case 'Y':
			PLAY = 0;
			break;
		default:
			restoreMainWinFromCombat();
			break;
	}
}

static inline void resetMap(void) {	
	printAreYouSure();
	switch(getch()) {
		case 'y'://FALLTHROUGH
		case 'Y':
			initalizeWorld();
			printWorldMap();
			printAllEnemies();
			break;
		default:// do nothing
			break;
	}
}

int accessPlayerInventory(void) {
	playerDisplayInventory();
	int status = 0;
	unsigned int choice = getch() - '0';
	copyMainWinToCombat();
	if(PLAYER->has_comp == 1) {
		status = useItem(choice,itemUseOn(),PLAYER);
	}
	else {
		status = useItem(choice,PLAYER,PLAYER);
	}
	getch();
	restoreMainWinFromCombat();
	restoreMainWinFromInventory();
	return status;
}

void selectClass(void) {
	switch(getch()) {
		case '1':
			clearPromptWin();
			printToPrompt(0,0,"you selected Warrior");
			PLAYER_CLASS = WARRIOR;
			break;
		case '2':
			clearPromptWin();
			printToPrompt(0,0,"you selected Archer");
			PLAYER_CLASS = PLAYER_ARCHER;
			break;
		case '3':
			clearPromptWin();
			printToPrompt(0,0,"you selected Animal Whisperer");
			PLAYER_CLASS = ANIMAL_WHISPER;
			break;
		default: 
			clearPromptWin();
			printToPrompt(0,0,"sorry,wrong choice");
			selectClass();
	}
}
//when player is on world map, get the input
static inline int getPlayerInputWolrdMap(void) {
	switch(getch()) {
		case 'w':
			return moveCharacter(UP,PLAYER);
		case 'a':
			return moveCharacter(LEFT,PLAYER);
		case 's':
			return moveCharacter(DOWN,PLAYER);
		case 'd':
			return moveCharacter(RIGHT,PLAYER);	
		case 'q':
			quitGame();
			return 1;
		case 't':
			resetMap();
			return 1;
		case 'i':
			accessPlayerInventory();
			return 0;
		default: 
			return 0;	
	}
	return 1;
}

int playerTurn(void) {
	checkIfCombat();
	clearPromptWin();
	printToPrompt(0,0,"'w','a','s','d' to move around.");
	printToPrompt(0,1,"'i' to open inventory");
	printToPrompt(0,2,"'q' to quit game");
	if (getPlayerInputWolrdMap()) {
		updateTilesRevealed();
		checkIfCombat();
		checkForItems();
		printCharacter(PLAYER);
		checkEffects(PLAYER);
		updateStatsWin();
		return 1;
	}
	else {
		return playerTurn();
	}
	return 0;
}
