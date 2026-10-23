#include <globaldefs.h>
ARM
class SafeAllocator;
extern "C" char* Menu_FindSessionArenaById(void*,unsigned);
extern "C" void Resource_InitializeSharedRecordState(char*,int,int);
extern "C" void ItemDetail_AllocateDisplayResources(char*,SafeAllocator*);
// Original: arm9/ov023 @ 0x021FBD00; symbol: Resource_InitializeRecordFromTreeNodeAndFlags; size: 0x90.
extern "C" void MenuRecord_ResetHeader(void*);
extern "C" int MenuBackground_InitializeWithAllocatorAndFlags(char *self,void* tree,int a,int b,unsigned flags,int value,unsigned char mode) {
 MenuRecord_ResetHeader(self);*(short*)(self+4)=16;*(short*)(self+6)=a;*(short*)(self+8)=b;
 char *node=Menu_FindSessionArenaById(tree,*(unsigned short*)(self+8));if(!node)return 0;
 Resource_InitializeSharedRecordState(self+32,-1,0);
 *(unsigned short*)(self+0x794)|=(unsigned short)(flags|0x4000);
 ItemDetail_AllocateDisplayResources(self+32,(SafeAllocator*)(node+4));*(int*)(self+0x68)=value;*(unsigned char*)(self+0x798)=mode;return 1;
}
