/*                                           ### description ###                       

*/

//---------------------------------------------- headers -------------------------------------------------
#pragma  once
#include "gamepieces.h"
#include <ncurses.h>
#include <stdlib.h>
//---------------------------------------------- define --------------------------------------------------

//---------------------------------------------- enums ---------------------------------------------------


//---------------------------------------------- typedefs ------------------------------------------------


//---------------------------------------------- structs -------------------------------------------------


//---------------------------------------------- global vars ---------------------------------------------
extern int         PLAY;
extern CHARACTER  *PLAYER;
extern CHARACTER  *COMPANION;
extern ITEMONMAP  *LOOSEITEMS;
//extern WINDOW      *MAIN_WIN;

//---------------------------------------------- prototypes ----------------------------------------------
void  selectClass           (void);
int   playerTurn            (void);
int   accessPlayerInventory (void);

//---------------------------------------------- prototypes in other files -------------------------------
extern void         printToPrompt               (const int x, const int y, const char *const str);
extern void         clearPromptWin              (void);
extern int          moveCharacter               (const MOVEMENT next_move,CHARACTER *const character);
extern int          playerDisplayInventory      (void);
extern void         initalizeWorld		        (void);
extern void         printAllEnemies             (void);
extern void         printWorldMap               (void);
extern void         restoreMainWin	            (void);
extern int          useItem                     (const ITEMTYPE item, CHARACTER *const attacker,CHARACTER *const defender);
extern CHARACTER    *itemUseOn                  (void);
extern void         printAreYouSure             (void);
extern void         printCharacter              (const CHARACTER *const character);
extern void         printWorldMap               (void);
extern void         printTilePiece              (const int x, const int y);
extern int          checkIfEnemy                (void); 
extern void         engageCombat                (CHARACTER *const character);
extern void         removeItemOffMap            (const ITEM *const item);
extern void         restoreMainWinFromCombat    (void);
extern void         restoreMainWinFromInventory (void);
extern void         restoreMainWinFromCombat    (void);
extern void         copyMainWinToCombat         (void);
extern void         updateStatsWin              (void);
extern void  checkEffects                (CHARACTER *const character);