#include <globaldefs.h>
ARM
class GameState; struct AllocatorUnion;
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(GameState*);
extern "C" void* memset(void*,int,unsigned);
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void Graphics_InitializeBackgroundCanvasAndDayState(unsigned char*);
extern "C" void Memory_InitializeFiveAllocatorRegions(void*,unsigned);
extern "C" int Inn_UpdateStayDialog(char*,int);
extern "C" void Inn_ReleaseStayDialogResources(char*);
extern "C" void Inn_ShowServiceMessage(char*,int,int,int,int);
// Original: arm9/ov003 @ 0x0216BB70; symbol: func_ov003_0216bb70; size: 0x18C.
// Creates the panel allocation, waits for its transition, then releases it and selects the next display state.
extern "C" void Inn_AdvanceNestedGuestPanel(char* p) {
 GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();
 if(*(short*)(p+6)==0) {
 memset(*(void**)(TextContext_GetSharedInstance()+0x5c),0,0x960);
 void* allocation=AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,0x10000);
 VectorizedMemset(allocation,0,0x10000);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x12d4,allocation,0x10000);
 _ZN13SafeAllocator5ResetEv(p+0x12d4);
 Graphics_InitializeBackgroundCanvasAndDayState((unsigned char*)p+0x14);
 Memory_InitializeFiveAllocatorRegions(p+0x14,(unsigned)(p+0x12d4));
 p[0x404]=1;*(short*)(p+6)=1;
 }
 if(*(short*)(p+6)==1) {
 if(Inn_UpdateStayDialog(p+0x14,_ZNK9GameState12GetTickCountEv(game))) *(short*)(p+6)=2;
 }
 if(*(short*)(p+6)==2) {
 unsigned char selection=p[0x405];
 Inn_ReleaseStayDialogResources(p+0x14);
 void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0x12d4);
 if(allocation) {_ZN13SafeAllocator7DestroyEv(p+0x12d4); Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);}
 if(selection==0) {*(short*)(p+4)=7;*(short*)(p+6)=0;}
 else {
 *(volatile unsigned*)0x4000000=(*(volatile unsigned*)0x4000000&~0x1f00)|0x1700;
 *(short*)(p+10)=3;
 *(unsigned*)(TextContext_GetSharedInstance()+0x998)=1;
 Inn_ShowServiceMessage(p,0x29,-1,-1,-1);
 *(short*)(p+4)=1;*(short*)(p+6)=0;*(short*)(p+8)=0;
 ((unsigned char*)p)[0x13ec]|=1;
 }
 }
}
