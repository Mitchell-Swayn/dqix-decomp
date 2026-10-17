#include <globaldefs.h>
extern "C" char* data_02110370;
// Original: arm9/main @ 0x020BD5E4; symbol: func_020bd5e4; size: 0x64.
extern "C" ARM char* ResourceManager_GetIndexedHeaderTable24Entry(int index) {
 char* state=data_02110370; char* base=*(char**)(state+0x8c);
 int offset=*(int*)(base+0x24);
 unsigned int* table; if(offset==0)table=0;else table=(unsigned int*)(base+offset);
 if (!table) return 0;
 if (index<0) return 0;
 if ((unsigned int)index>=*table) return 0;
 offset=*(unsigned int*)((char*)table+index*4+4); base=*(char**)(state+0x8c);
 if(offset==0) return 0; return base+offset;
}
