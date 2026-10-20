#include <globaldefs.h>
ARM
extern "C" char* Network_GetWirelessWorkspace();
extern "C" char* Network_FindAccessPointByBssid(void*);
extern "C" char* Network_AllocateAccessPointListEntry();
extern "C" char* Ov031_ReadSharedEntryValue();
extern "C" void MIi_CpuCopyFast(const void*,void*,unsigned);
extern "C" void MoveNodeToSharedListTail(void*);
// Original: arm9/ov031 @ 0x0220EC5C; symbol: Resource_CopyUnblockedRecordIntoSharedList; size: 0x8c.
// Obtains an available shared entry, tags it and copies C0-byte unblocked record before appending to shared list.
extern "C" void Resource_CopyUnblockedRecordIntoSharedList(char* self,unsigned short tag) {
 char* shared=Network_GetWirelessWorkspace();if(!shared)return;
 if(*(unsigned char*)(shared+0x226a)||*(unsigned short*)(self+0x3c))return;
 char* entry=Network_FindAccessPointByBssid(self+4);if(!entry)entry=Network_AllocateAccessPointListEntry();
 if(!entry && *(int*)(shared+0x2278)==1)entry=Ov031_ReadSharedEntryValue();
 if(!entry)return;
 *(unsigned short*)(entry+2)=tag;MIi_CpuCopyFast(self,entry+0x10,0xc0);MoveNodeToSharedListTail(entry);
}
