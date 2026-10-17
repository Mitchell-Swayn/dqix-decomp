#include <globaldefs.h>
ARM
extern "C" char* data_ov031_02250bf8;
extern "C" const unsigned char data_ov031_022489a4[];
extern "C" void* Memory_AllocateZeroedBlock(unsigned,unsigned);
extern "C" void* Resource_ExpandPackedTableToAllocatedBuffer(unsigned,unsigned);
extern "C" void* Unclassified_InvokeHelperWithZeroFifthArgument(unsigned,void(*)(),unsigned,unsigned);
extern "C" void System_ExpandSharedEntriesAndSetHeaderFlags();
// Original: arm9/ov031 @ 0x02223A64; symbol: func_ov031_02223a64; size: 0xB8.
extern "C" void CreateIndexedRecordAndCallbackState(int index) {
if(data_ov031_02250bf8) return;
char* node=(char*)Memory_AllocateZeroedBlock(12,4);
unsigned code=data_ov031_022489a4[index*4];
data_ov031_02250bf8=node;
node[8]=index;
*(void**)data_ov031_02250bf8=Resource_ExpandPackedTableToAllocatedBuffer(0,code);
**(unsigned**)data_ov031_02250bf8=(**(unsigned**)data_ov031_02250bf8&0xfe00ff00)|0xe50026;
*(unsigned short*)(*(char**)data_ov031_02250bf8+4)=(*(unsigned short*)(*(char**)data_ov031_02250bf8+4)&~0xc00)|0x800;
*(void**)(data_ov031_02250bf8+4)=Unclassified_InvokeHelperWithZeroFifthArgument(0,System_ExpandSharedEntriesAndSetHeaderFlags,0,120);
}
