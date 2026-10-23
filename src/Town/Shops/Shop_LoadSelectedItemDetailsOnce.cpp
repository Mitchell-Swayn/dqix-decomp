#include <globaldefs.h>
ARM
struct Page7{char pad[176];unsigned short flags;};
struct Page{char pad[70];unsigned short flags;};
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
class SafeAllocator;
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_SetFlags(void*,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void ItemDetail_ResetAndAllocateDisplay(char*,SafeAllocator*,int,char*,unsigned short);
extern "C" void Resource_InitializeSharedRecordState(char*,int,int);
extern "C" void ItemDetail_AllocateDisplayResources(char*,SafeAllocator*);
// Original: arm9/ov003 @ 0x021748C4; symbol: Resource_InitializeSelectedMemberOnceWithAllocator; size: 0xc4.
extern "C" void Shop_LoadSelectedItemDetailsOnce(char* self) {
 SystemState_SetFlags(SystemState_GetGlobalFlags(),1);char* owner=P(self,4);unsigned flags=((Page*)(self+0x1000))->flags;if(flags&2048)return;
 if(flags&128){_ZN13SafeAllocator5ResetEv(owner+40);ItemDetail_ResetAndAllocateDisplay(self+60,(SafeAllocator*)(owner+40),H(self,0x103a),self+0x874,0x450);((Page*)(self+0x1000))->flags=2048|((Page*)(self+0x1000))->flags;return;}
 _ZN13SafeAllocator5ResetEv(owner+40);Resource_InitializeSharedRecordState(self+60,H(self,0x103a),0);((Page7*)(self+0x700))->flags=0x450|((Page7*)(self+0x700))->flags;ItemDetail_AllocateDisplayResources(self+60,(SafeAllocator*)(owner+40));P(self,0x84)=self+0x874;((Page*)(self+0x1000))->flags=0x880|((Page*)(self+0x1000))->flags;
}
