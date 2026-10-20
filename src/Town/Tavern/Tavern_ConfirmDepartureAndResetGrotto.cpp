#include <globaldefs.h>
ARM
extern "C" void* NavigationMessage_GetGlobalInstance();
extern "C" void Tavern_OpenConfirmationOptions(char*);
extern "C" int Tavern_PollConfirmationOptions(unsigned char*);
extern "C" void Graphics_UpdateCounted224ByteDisplayRecords(char*);
extern "C" void Network_QueueLocalMemberInteractionExclusion(void);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState15GetGrottoStructEv(void*);
extern "C" void VectorizedMemset(void*,int,unsigned int);
extern "C" void NavigationMessage_DisableAndCancelLoading(unsigned char*);
extern "C" int GameState_SetDisplayPartEnabledBitAndConfigure(char*,unsigned int,int);
// Original: arm9/ov003 @ 0x0216512C; symbol: func_ov003_0216512c; size: 0x14C.
// Advances display selection exit, clears grotto state on acceptance, or queues rejection text.
extern "C" void Tavern_ConfirmDepartureAndResetGrotto(char* p) {
 void* manager=NavigationMessage_GetGlobalInstance();
 unsigned int phase=(unsigned char)p[0x4a4];
 if(phase==0) { Tavern_OpenConfirmationOptions(p); ++((unsigned char*)p)[0x4a4]; }
 else if(phase==1) {
 int result=Tavern_PollConfirmationOptions((unsigned char*)p);
 if(result != -1) { if(result==1) {
 Graphics_UpdateCounted224ByteDisplayRecords(*(char**)(p+0x324));
 *(short*)(p+0x484)=0x13; ++((unsigned char*)p)[0x4a4]; *(unsigned int*)(p+0x464)|=0xc000000;
 Network_QueueLocalMemberInteractionExclusion();
 } } else {
 *(short*)(p+0x488)=0x1b; *(short*)(p+0x474)=*(short*)(p+0x48a)=0xaa;
 *(short*)(*(char**)(p+0x324)+0x36)=*(short*)(p+0x48a);
 *(short*)(p+0x484)=0x12; *(short*)(p+0x486)=1; p[0x4a4]=3;
 }
 }
 else if(phase==2) {
 char* state=_ZN9GameState15GetGrottoStructEv(_ZN9GameState11GetInstanceEv());
 VectorizedMemset(state,0,0x88); state[0]=0;state[1]=0;
 *(unsigned int*)(p+0x464)|=0x82; p[0x4a3]=6;p[0x4a4]=0;
 NavigationMessage_DisableAndCancelLoading((unsigned char*)manager);
 }
 else if(phase==3) { GameState_SetDisplayPartEnabledBitAndConfigure(p,*(short*)(p+0x488),0);p[0x4a3]=10;p[0x4a4]=1;
 }
}
