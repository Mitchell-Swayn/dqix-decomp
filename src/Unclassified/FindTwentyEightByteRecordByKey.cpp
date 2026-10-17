#include <globaldefs.h>
ARM
#pragma optimization_level 4
typedef int (*KeyGetter)(void*);extern "C" int Object_ReadShortAtOffset8(void*);extern "C" void* Object_BinarySearchTwentyEightByteEntriesByCallback(void*,int,KeyGetter);
// Original: arm9/main @ 0x0206F4F0; symbol: func_0206f4f0; size: 0x14.
extern "C" void* FindTwentyEightByteRecordByKey(void* p,int key){return Object_BinarySearchTwentyEightByteEntriesByCallback(p,key,Object_ReadShortAtOffset8);}
