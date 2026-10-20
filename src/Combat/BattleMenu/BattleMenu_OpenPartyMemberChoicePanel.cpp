#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void BattleMenu_ConfigureGlobalCommandSelection(void*,int,int);extern "C" unsigned TextContext_GetSharedInstance();extern "C" void* memset(void*,int,unsigned);extern "C" void Graphics_FormatAvailablePartyMemberChoices(char*,char*);extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
// Original: arm9/ov000 @ 0x0217768C; symbol: Graphics_PositionAndRenderPartyMemberChoicePanel; size: 0x10C.
extern "C" void BattleMenu_OpenPartyMemberChoicePanel(char* self,char* anchor,int mode,int value){if(!anchor)return;int x=W(anchor,68),y=W(anchor,72);BattleMenu_ConfigureGlobalCommandSelection(self,mode,value);char* panel=self+0x188;H(panel,160)=21;H(panel,162)=1;H(panel,164)=(x>>3)+9;H(panel,166)=(y>>3)+1;H(panel,172)=10;H(panel,174)=13;if(mode==2){H(panel,168)=12;H(panel,170)=10;}if(mode==3){H(panel,168)=12;H(panel,170)=8;}if(mode==4){H(panel,172)=10;H(panel,174)=11;H(panel,168)=12;H(panel,170)=4;}B(panel,177)=3;char* buffer=P((void*)TextContext_GetSharedInstance(),92);memset(buffer,0,2400);Graphics_FormatAvailablePartyMemberChoices(self,buffer);Window_PushTextCanvas(panel,buffer,0,1,0,1,0,0);}
