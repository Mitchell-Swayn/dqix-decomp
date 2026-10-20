#include <globaldefs.h>
ARM
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Graphics_ResetOwnedTilePayload(void*);
extern "C" unsigned DisplayContext_GetGlobalInstance();
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(int);
extern "C" void Menu_RemoveStoredBackgroundTask(int*);
extern "C" void Resource_InitializeSharedRecordState(char*,int,int);
extern "C" void UpdateDisplayPlaneStateFromObjectMode(void*);
// Original data: arm9/ov023 @ 0x21ff9e0; symbol: data_ov023_021ff9e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" void* MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
struct Bits {unsigned char retain:1,rest:7;};
// Original: arm9/ov023 @ 0x021DC354; symbol: func_ov023_021dc354; size: 0x134.
extern "C" void Resource_DestroyAndResetSharedRecordState(char* self) {
 Menu_RemoveStoredBackgroundTask((int*)(self+0x780));
 self[0x77e]=-1;
 if(!(*(unsigned short*)(self+0x774)&16)) BackgroundLoader_CancelEightTasksAndResetState(DisplayContext_GetGlobalInstance());
 Menu_RemoveStoredBackgroundTask((int*)(self+0x734));
 int* tasks=(int*)(self+0x338);
 int i=0;
 tasks+=0x100;
 for(;i<7;++i) Menu_RemoveStoredBackgroundTask(tasks+i);
 if(*(void**)(self+0xc8)) Graphics_ResetOwnedTilePayload(*(void**)(self+0xc8));
 if(*(void**)(self+0xc4)) Graphics_ResetOwnedTilePayload(*(void**)(self+0xc4));
 if(self[0x77b]!=1) UpdateDisplayPlaneStateFromObjectMode(self);
 if(*(void**)(self+0x44)) _ZN13SafeAllocator7DestroyEv(*(void**)(self+0x44));
 if(*(void**)(self+0x40)) _ZN13SafeAllocator7DestroyEv(*(void**)(self+0x40));
 if(*(void**)(self+0x3c)) _ZN13SafeAllocator7DestroyEv(*(void**)(self+0x3c));
 _ZN13SafeAllocator7DestroyEv(self+0x28);
 _ZN13SafeAllocator7DestroyEv(self+0x14);
 _ZN13SafeAllocator7DestroyEv(self);
 if(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[1]) {
  if(!((Bits*)(self+0x79b))->retain) Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[1]);
  MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[1]=0;
 }
 Resource_InitializeSharedRecordState(self,-1,self[0x77b]);
}
