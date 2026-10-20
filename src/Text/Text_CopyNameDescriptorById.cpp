#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void Text_RelocateNameTableEntryStrings();extern "C" void Text_InitializeSerializedNameTable(void*,void*,void*,void(*)());extern "C" void* Text_BinarySearchNameTableEntry(void*,int);
// Original: arm9/main @ 0x020E5334; symbol: func_020e5334; size: 0x88.
extern "C" void* Text_CopyNameDescriptorById(void* out,void* source,int enabled,int index){if(!out||!source||!enabled||index<0)return 0;unsigned local[3];unsigned state;memset(local,0,12);Text_InitializeSerializedNameTable(local,source,&state,Text_RelocateNameTableEntryStrings);void* data=Text_BinarySearchNameTableEntry(local,index);if(!data)return 0;memcpy(out,data,12);return out;}
