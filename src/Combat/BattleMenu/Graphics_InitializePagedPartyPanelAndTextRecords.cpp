struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" void* BattleMenu_UpdateVocationActionDescriptionWindow(void*,int);
extern "C" void BattleMenu_ConfigureActorCommandSelection(void*,int,int);
extern "C" void Graphics_AppendPagedPartyStateText(void*,void*,char*);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void* memset(void*,int,unsigned);
extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
struct Record;struct Owner;
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" void BattleMenu_PositionStackedWindowsWithinScreen(void*,int,int);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov000 @ 0x02179B70; symbol: Graphics_InitializePagedPartyPanelAndTextRecords; size: 0xFC.
extern "C" void Graphics_InitializePagedPartyPanelAndTextRecords(char* self,char* entry,int a,int b){BattleMenu_UpdateVocationActionDescriptionWindow(self,(int)entry);int x=W(entry,68),y=W(entry,72);BattleMenu_ConfigureActorCommandSelection(entry,a,b);char* panel=self+0x188;H(panel,0xa0)=16;H(panel,0xa2)=1;H(panel,0xa4)=(x>>3)+16;H(panel,0xa6)=y>>3;H(panel,0xa8)=12;H(panel,0xaa)=10;H(panel,0xac)=10;H(panel,0xae)=14;B(panel,0xb1)=21;char* text=P(TextContext_GetSharedInstance(),92);memset(text,0,0x960);Graphics_AppendPagedPartyStateText(self,entry,text);Window_PushTextCanvas(panel,text,0,1,0,1,0,0);char* record=(char*)(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)panel),22);if(record)H(record,0xc2)=0;BattleMenu_PositionStackedWindowsWithinScreen(self+0x188,21,22);}