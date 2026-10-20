struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" WindowCanvasRecord* Window_GetTopTextCanvas(WindowCanvasOwner*);
extern "C" unsigned Window_PopCanvasesAndResetSelection(...);
// Original data: arm9/ov000 @ 0x021834cc; symbol: data_ov000_021834cc.
// BattleMenu_PopSelectionPanels walks four pairs with stride two. The first column identifies canvas IDs requiring paired-panel handling; the second identifies the partner canvas to reset.
// Values (uint8_t[4][2]): {{15, 34}, {17, 36}, {16, 35}, {21, 22}}.
extern "C" unsigned char BattleMenu_SelectionCanvasPairs[];
// Original data: arm9/ov000 @ 0x021834cd; symbol: data_ov000_021834cd.
// Aliases SelectionCanvasPairs + 1. The consumer indexes with stride two to read the four partner IDs; this is not a separate allocation.
// Values (strided uint8_t view): {34, 36, 35, 22}, stride 2; aliases BattleMenu_SelectionCanvasPairs + 1.
extern "C" unsigned char BattleMenu_SelectionCanvasPartnerColumn[];
// Original: arm9/ov000 @ 0x0217629c; symbol: ResetModeRecordsAndClearPairedCounter.
extern "C" void BattleMenu_PopSelectionPanels(char* p){if(!U(p,0x38))return;int count=1;char* record=(char*)(unsigned)Window_GetTopTextCanvas((WindowCanvasOwner*)(U(p,0x38)));for(int i=0;i<4;i++){unsigned key=B(BattleMenu_SelectionCanvasPairs,i*2);unsigned value=B(record,0xc4);if(key==value){count=2;break;}}for(int i=0;i<count;i++)Window_PopCanvasesAndResetSelection(U(p,0x38),0);record=(char*)(unsigned)Window_GetTopTextCanvas((WindowCanvasOwner*)(U(p,0x38)));if(!record)return;for(int i=0;i<4;i++){unsigned key=B(BattleMenu_SelectionCanvasPairs,i*2);unsigned value=B(record,0xc4);if(key==value){char* pair=(char*)(unsigned)Window_FindActiveCanvasById((WindowCanvasOwner*)(U(p,0x38)),B(BattleMenu_SelectionCanvasPartnerColumn,i*2));if(pair)H(pair,0xc2)=0;return;}}}
