struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void BattleMenu_UpdateSkillDescriptionWindow(void*);void BattleMenu_ConfigureActorCommandSelection(void*,int,int);unsigned Grid_GetEntryCount(unsigned*);unsigned TextContext_GetSharedInstance();void* memset(void*,int,unsigned);void Text_AppendSelectionPageEntries(char*,char*,char*);void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);void BattleMenu_PositionStackedWindowsWithinScreen(void*,int,int);}
// Original: arm9/ov000 @0x02179018; symbol:Graphics_BuildSelectionPageAtSavedCoordinates; size:0x110.
// Builds selection-page text using saved record coordinates and initializes selected ready record.
extern "C" void BattleMenu_BuildSkillListWindow(unsigned char* self,unsigned char* records,int value,int option){BattleMenu_UpdateSkillDescriptionWindow(self);int x=W(records,0x44),y=W(records,0x48);BattleMenu_ConfigureActorCommandSelection(records,value,option);unsigned char* owner=self+0x188;H(owner,0xa0)=16;H(owner,0xa2)=9;H(owner,0xa4)=(x>>3)+16;H(owner,0xa6)=y>>3;H(owner,0xa8)=12;H(owner,0xaa)=8;H(owner,0xac)=10;H(owner,0xae)=12;owner[0xb1]=16;int styled=0;if((int)Grid_GetEntryCount((unsigned*)(owner+0x54))>4)styled=1;unsigned char* text=P((unsigned char*)TextContext_GetSharedInstance(),0x5c);memset(text,0,2400);Text_AppendSelectionPageEntries((char*)self,(char*)records,(char*)text);Window_PushTextCanvas(owner,text,0,0,styled,1,0,0);unsigned char* record=(unsigned char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(owner),35);if(record)H(record,0xc2)=0;BattleMenu_PositionStackedWindowsWithinScreen(self+0x188,16,35);}
