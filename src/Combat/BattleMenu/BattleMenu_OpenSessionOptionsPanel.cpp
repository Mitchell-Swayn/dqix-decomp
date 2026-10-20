#include <globaldefs.h>
ARM
extern "C" int GameState_ReadProtagonistObjectIndex(...);
extern "C" int Network_IsSessionActive(...);
extern "C" int Network_GetConnectionManager(...);
extern "C" int TextContext_GetSharedInstance(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int Window_PushTextCanvas(...);
extern "C" int BattleMenu_AppendSessionOptions(...);
extern "C" int BattleMenu_ConfigureGlobalCommandSelection(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov000 @ 0x02177454; symbol: BuildPositionedSelectionPanelAndSubmitText.
extern "C" void BattleMenu_OpenSessionOptionsPanel(char*self,char*object,int key,int value){
if(!object)return;int x=W(object,68),y=W(object,72);BattleMenu_ConfigureGlobalCommandSelection(self,key,value);char*panel=self+392;H(panel,160)=10;H(panel,162)=7;H(panel,164)=(x>>3)+9;H(panel,166)=(y>>3)+1;H(panel,168)=12;H(panel,170)=7;H(panel,172)=10;H(panel,174)=13;if(Network_IsSessionActive(Network_GetConnectionManager())&&GameState_ReadProtagonistObjectIndex(_ZN9GameState11GetInstanceEv())==0){H(panel,168)=12;H(panel,170)=4;H(panel,172)=10;H(panel,174)=11;}B(panel,177)=2;char*buffer=P(C(TextContext_GetSharedInstance()),92);memset(buffer,0,2400);BattleMenu_AppendSessionOptions(self,buffer);Window_PushTextCanvas(panel,buffer,0,1,0,1,0,0);
}
