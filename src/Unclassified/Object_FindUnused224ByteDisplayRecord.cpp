#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02081DE0; symbol: func_02081de0; size: 0x38.
extern "C" void* Object_FindUnused224ByteDisplayRecord(unsigned char* p){unsigned count=p[57];unsigned char* entry=*(unsigned char**)(p+48);unsigned char i=0;while(i<count){if(entry[196]==255)return entry;unsigned next=i+1;entry+=224;i=next;}return 0;}
