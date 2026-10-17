#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Entry { int value; char* string; };
struct Store { int count; unsigned int allocator; Entry** entries; };
extern "C" Store data_ov001_02165800;
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned int,unsigned int);
// Original: arm9/ov001 @ 0x021536FC; symbol: func_ov001_021536fc; size: 0xA4.
extern "C" int Script_AppendIntegerAndOwnedString(unsigned char* parameters) {
(*data_ov001_02165800.entries)[data_ov001_02165800.count].value=_ZNK6Script9Parameter5ToIntEv(parameters);
const char* string=_ZNK6Script9Parameter8ToStringEv(parameters+8);
if(!string)return 0;
(*data_ov001_02165800.entries)[data_ov001_02165800.count].string=_ZN13SafeAllocator8AllocateEj(data_ov001_02165800.allocator,strlen(string)+1);
if(!(*data_ov001_02165800.entries)[data_ov001_02165800.count].string)return 0;
strcpy((*data_ov001_02165800.entries)[data_ov001_02165800.count].string,string);
++data_ov001_02165800.count;
return 1;
}
