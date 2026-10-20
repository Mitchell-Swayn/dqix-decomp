#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02071D60; symbol: func_02071d60; size: 0x44.
extern "C" unsigned char* ScriptRecordTable_FindById(unsigned char* p,int key) { for(unsigned short i=0;i<*(unsigned short*)(p+10);i++) { unsigned char* base=*(unsigned char**)(p+4);unsigned int off=i*32;if(key==*(short*)(base+off))return base+off; }return 0; }
