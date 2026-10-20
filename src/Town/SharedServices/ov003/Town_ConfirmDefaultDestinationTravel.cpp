#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma opt_propagation off
#pragma always_inline on
class GameResources;struct Global;
typedef unsigned int undefined4;
struct GlobalSelection {char pad[0xb3c];unsigned mode;};
inline unsigned ReadSelectionMode(GlobalSelection* p){return p->mode;}
inline GlobalSelection* GetSelectionRegion(char* p){return (GlobalSelection*)(p+0x1840);}
extern "C" {
void* GameState_ReadUnkF8(GameState*);
void* Zone3D_GetMainInstance();unsigned TextContext_GetSharedInstance();
ARM undefined4 TextWindow_GetChoiceResult(int);
void LinkedQueue_AppendAndMarkActive(unsigned*,unsigned);
void FieldTransition_InitializeRequestDefaults(char*);
GameResources* GameResources_GetInstance();
void Field_InitializeZoneTransitionCommand(unsigned char*,int);
void InitializeTypeFourStateAndBuffers(unsigned char*,int);
}
inline void ConfigureTint(char* tint) { *(unsigned short*)tint=0xc3bc;tint[7]=1;*(unsigned*)(tint+0x14)=0x266;*(unsigned*)(tint+0x18)=0xffff84cd;tint[0xc]=1;}
// Original: arm9/ov003 @ 0x0217D53C; symbol: Town_ConfirmDefaultDestinationTravel; size: 0x170.
// Appends type-four and type-three records, choosing the first record ID from the global selection mode.
extern "C" void Town_ConfirmDefaultDestinationTravel(char* p) {
 GameState* game=(GameState*)((void*)GameState::GetInstance());
 unsigned int ownerAddress=TextContext_GetSharedInstance(); char* owner=(char*)ownerAddress;
 char* resources=(char*)GameResources_GetInstance();
 unsigned* list=*(unsigned**)(resources+0x36fc);
 char* global=(char*)Zone3D_GetMainInstance();
 if(p[5]!=0||*(int*)(owner+0x9a0))return;
 if(TextWindow_GetChoiceResult(ownerAddress)==0) {
 unsigned char* node=*(unsigned char**)(resources+0x3734);
 InitializeTypeFourStateAndBuffers(node,1);node[0x10b]=1;
 switch(ReadSelectionMode(GetSelectionRegion(global))) {
 case 0:case 1:case 2:*(unsigned short*)(node+8)=0xd067;break;
 case 3:case 4:*(unsigned short*)(node+8)=0xd068;break;
 case 5:*(unsigned short*)(node+8)=0xd069;break;
 case 6:*(unsigned short*)(node+8)=0xd06a;break;
 }
 LinkedQueue_AppendAndMarkActive(list,(unsigned)node);
 node=*(unsigned char**)(resources+0x370c);Field_InitializeZoneTransitionCommand(node,0);
 char* tint=(char*)GameState_ReadUnkF8(game);FieldTransition_InitializeRequestDefaults(tint);
 ConfigureTint(tint);
 LinkedQueue_AppendAndMarkActive(list,(unsigned)node);
 p[4]=4;p[5]=0;return;
 }
 p[4]=4;p[5]=0;
}
