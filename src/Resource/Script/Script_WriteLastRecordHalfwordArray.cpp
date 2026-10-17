#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" unsigned char* Object_GetBoundedTwentyFourByteEntry(void*,int);extern "C" void* data_02108ed8[2];
// Original: arm9/main @ 0x0207EEF8; symbol: func_0207eef8; size: 0x68.
extern "C" int Script_WriteLastRecordHalfwordArray(Script::Parameter* p){void* table=data_02108ed8[1];unsigned char* entry=Object_GetBoundedTwentyFourByteEntry(table,(short)(*(short*)((unsigned char*)table+4)-1));unsigned short* values=*(unsigned short**)(entry+4);for(unsigned char i=0;i<entry[20];i++)values[i]=(p++)->ToInt();return 1;}
