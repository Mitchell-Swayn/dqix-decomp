#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02064AF8; symbol: func_02064af8; size: 0x2C.
extern "C" void Script_AppendTriggerSpatialRegion(unsigned char* p,unsigned char* node) { unsigned char* tail=*(unsigned char**)(p+0x494);if (!tail) { *(unsigned char**)(p+0x494)=node; return; } unsigned char* next; while ((next=*(unsigned char**)(tail+0x2c))!=0)tail=next;*(unsigned char**)(tail+0x2c)=node; }
