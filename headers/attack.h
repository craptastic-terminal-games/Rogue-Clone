/*                                           ### description ###                       

*/

//---------------------------------------------- headers -------------------------------------------------
#include "characters.h"
#include <stdlib.h> 
#include <ncurses.h>

//---------------------------------------------- enums ---------------------------------------------------

//---------------------------------------------- define --------------------------------------------------

//---------------------------------------------- typedefs ------------------------------------------------

//---------------------------------------------- structs -------------------------------------------------


//---------------------------------------------- global vars ---------------------------------------------
extern CHARACTER  *PLAYER;
extern CHARACTER  *COMPANION;
//---------------------------------------------- prototypes ----------------------------------------------
int  playerAttack              (CHARACTER *const attacker,CHARACTER *const defender);
int  swordsmanAttack           (CHARACTER *const attacker,CHARACTER *const defender);
int  mageAttack                (CHARACTER *const attacker,CHARACTER *const defender);
int  spearmanAttack            (CHARACTER *const attacker,CHARACTER *const defender);
int  wolfAttack                (CHARACTER *const attacker,CHARACTER *const defender);
int  archerAttack              (CHARACTER *const attacker,CHARACTER *const defender);
int  bearAttack                (CHARACTER *const attacker,CHARACTER *const defender);
int  skeletonAttack            (CHARACTER *const attacker,CHARACTER *const defender);
int  monsterAttack             (CHARACTER *const attacker,CHARACTER *const defender);
void combatLoop            	   (CHARACTER *const character1,CHARACTER *const character2);
void resetAttributes           (CHARACTER *const character);
attack_fpointer   makeCharAtack(CHARTYPE type);

//---------------------------------------------- prototypes in other files -------------------------------
extern void  printToPrompt          (const int x, const int y, const char *const str);
extern void  restoreMainWin         (void); 
extern void  clearMainWin           (void);
extern void  copyMainWin            (void);
extern void  clearPromptWin         (void);
extern int   checkIfHealthPotion    (CHARACTER *const attacker);
extern int   playerUseItem          (void);
extern int   checkIfValidItem       (const unsigned int item);
extern int   charUseItem            (CHARACTER *const attacker,CHARACTER *const defender,ITEMTYPE item);
extern int   computerCheckItem      (CHARACTER *const attacker,CHARACTER *const defender);
extern int   playerDisplayInventory (void);
extern int   accessPlayerInventory  (void);