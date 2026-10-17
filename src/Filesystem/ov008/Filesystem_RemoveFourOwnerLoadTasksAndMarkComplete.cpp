#include <globaldefs.h>
ARM
struct GameResources; struct State;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void Object_ResetSelectionAndApplyConfiguredMode(State*,int);
extern "C" void* GetGlobalStatePointer();
extern "C" void RecordFlags_ClearWordMask(unsigned*,unsigned);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void Flags_ClearWordMask(unsigned*,unsigned);
struct Flags { unsigned char unused:3,done:1,rest:4; };
// Original: arm9/ov008 @ 0x0218B240; symbol: func_ov008_0218b240; size: 0xC0.
extern "C" void Filesystem_RemoveFourOwnerLoadTasksAndMarkComplete(unsigned char* self) {
 if(((Flags*)(self+0xec0))->done) return;
 _ZN9GameState11GetInstanceEv();
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 self[0xec0]&=~1;
 Object_ResetSelectionAndApplyConfiguredMode((State*)(self+0x18),1);
 self[0xe99]=2; self[0xe9a]=0; self[0xe9b]=2; self[0xe9c]=0;
 RecordFlags_ClearWordMask((unsigned*)GetGlobalStatePointer(),0x2f);
 Flags_ClearWordMask((unsigned*)GameResources_GetInstance(),0x10);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0xea0));
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0xeb4));
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0xea4));
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0xea8));
 *(int*)(self+0xea0)=-1;
 *(int*)(self+0xeb4)=-1;
 *(int*)(self+0xea4)=-1;
 *(int*)(self+0xea8)=-1;
 self[0xec0]|=8;
}
