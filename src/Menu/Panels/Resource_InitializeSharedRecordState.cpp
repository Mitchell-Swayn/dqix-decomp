#include <globaldefs.h>
ARM
struct State;
extern "C" void* memset(void*,int,unsigned);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void Graphics_InitializeSpriteTransformDefaults(State*);
extern "C" void Graphics_InitializeSpriteResourceBuffers(unsigned char*);
extern "C" void* ResourceGroupTable_InitializeView(void*);
extern "C" void ResourceStringLoader_Reset(char*);
extern "C" void Menu_ResetLayout(char*);
extern "C" void Menu_ResetTimedPointEffects(unsigned char*,unsigned char);
extern "C" void ItemDetail_ClearQuantityRows(void*,int);
// Original data: arm9/ov023 @ 0x21ff9e0; symbol: data_ov023_021ff9e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov023 @ 0x21ffa0c; symbol: data_ov023_021ffa0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned char ItemDetailDispatchDisplayState_UnknownRoleZeroInitializedStorage[];
struct Bits {unsigned char a:1,b:1,rest:6;};
// Original: arm9/ov023 @ 0x021DC134; symbol: func_ov023_021dc134; size: 0x220.
extern "C" void Resource_InitializeSharedRecordState(char* self,unsigned short id,int mode) {
 int zero=0;
 MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[1]=zero;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x14);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x28);
 *(int*)(self+0x3c)=zero;
 *(int*)(self+0x40)=zero;
 *(int*)(self+0x44)=zero;
 *(int*)(self+0x48)=zero;
 *(int*)(self+0x4c)=zero;
 *(int*)(self+0x50)=zero;
 ResourceStringLoader_Reset(self+0x54);
 ResourceGroupTable_InitializeView(self+0x6c);
 ResourceGroupTable_InitializeView(self+0x7c);
 ResourceStringLoader_Reset(self+0x8c);
 ResourceStringLoader_Reset(self+0xa4);
 *(int*)(self+0xc4)=zero;
 *(int*)(self+0xc8)=zero;
 Menu_ResetLayout(self+0xcc);
 self[0x128]=zero;
 self[0x129]=zero;
 Graphics_InitializeSpriteResourceBuffers((unsigned char*)self+0x12c);
 for(unsigned char i=0;i<30;++i) Graphics_InitializeSpriteTransformDefaults((State*)(self+0x180+i*40));
 memset(self+0x630,0,0x100);
 *(int*)(self+0x730)=0;
 *(int*)(self+0x734)=-1;
 for(int i=0;i<7;++i) *(int*)((self+i*4)+0x738)=-1;
 *(int*)(self+0x758)=0;
 *(int*)(self+0x75c)=0;
 *(unsigned short*)(self+0x770)=id;
 *(unsigned short*)(self+0x772)=id;
 *(unsigned short*)(self+0x774)=0;
 self[0x776]=0;
 self[0x777]=0;
 self[0x778]=0;
 self[0x779]=-1;
 self[0x77a]=-1;
 self[0x79a]=-1;
 ((Bits*)(self+0x79b))->a=0;
 ((Bits*)(self+0x79b))->b=0;
 self[0x77d]=-1;
 self[0x77e]=1;
 *(int*)(self+0x780)=-1;
 ItemDetail_ClearQuantityRows(self,1);
 *(int*)(self+0x760)=0;
 *(int*)(self+0x764)=0;
 self[0x799]=1;
 *(int*)(self+0x768)=0;
 *(int*)(self+0x76c)=0;
 MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[6]=5;
 MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[3]=9;
 MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[4]=0;
 self[0x77b]=mode;
 self[0x77c]=1;
 if(mode==1) {self[0x77c]=0;*(unsigned short*)(self+0x774)|=0x800;}
 *(short*)(self+0xc2)=0;
 memset(self+0xbc,0,6);
 MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[5]=(unsigned)(self+0x54);
 MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[9]=(unsigned)(self+0x6c);
 MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[0]=(unsigned)(self+0x7c);
 MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[2]=(unsigned)(self+0x8c);
 MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[10]=(unsigned)(self+0xa4);
 MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[8]=(unsigned)(self+0x0);
 *(unsigned short*)(self+0x774)|=8;
 Menu_ResetTimedPointEffects(ItemDetailDispatchDisplayState_UnknownRoleZeroInitializedStorage,0);
}
