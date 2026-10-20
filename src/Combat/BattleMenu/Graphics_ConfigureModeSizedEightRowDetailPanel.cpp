#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv(),*GameState_GetIndexList(void*);extern "C" void BattleMenu_ConfigureGlobalCommandSelection(void*,int,int),BattleMenu_AppendPartyBattleOptionLabels(void*,void*),Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);extern "C" unsigned TextContext_GetSharedInstance();extern "C" void* memset(void*,int,unsigned);
// Original: arm9/ov000 @ 0x021784d4; symbol: Graphics_ConfigureModeSizedEightRowDetailPanel; size 0x128.
extern "C" void Graphics_ConfigureModeSizedEightRowDetailPanel(char* self,void* source,int a,int b){if(!source)return;int x=W(source,0x44),y=W(source,0x48);GameState_GetIndexList(_ZN9GameState11GetInstanceEv());int mode=B(self,0x79);BattleMenu_ConfigureGlobalCommandSelection(self,a,b);char* panel=self+0x188;H(panel,0xa0)=16;H(panel,0xa2)=1;H(panel,0xa4)=(x>>3)+9;H(panel,0xa6)=(y>>3)+1;H(panel,0xa8)=12;H(panel,0xaa)=10;H(panel,0xac)=10;H(panel,0xae)=13;if(mode==2){H(panel,0xa8)=12;H(panel,0xaa)=10;}if(mode==3){H(panel,0xa8)=12;H(panel,0xaa)=8;}if(mode==4){H(panel,0xa8)=12;H(panel,0xaa)=4;H(panel,0xac)=10;H(panel,0xae)=11;}B(panel,0xb1)=8;void* scratch=P((void*)TextContext_GetSharedInstance(),0x5c);memset(scratch,0,0x960);BattleMenu_AppendPartyBattleOptionLabels(self,scratch);Window_PushTextCanvas(panel,scratch,0,1,0,1,0,0);}
