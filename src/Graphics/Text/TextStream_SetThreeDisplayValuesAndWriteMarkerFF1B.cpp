#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" void Text_ParseDelimitedSignedIntegerSequence(unsigned,unsigned*,int);extern "C" unsigned char* ReadWordFieldAtOffset1C();
// Original: arm9/main @ 0x020699C4; symbol: func_020699c4; size: 0x88.
extern "C" ARM int TextStream_SetThreeDisplayValuesAndWriteMarkerFF1B(void** out,unsigned arg){unsigned local[3];unsigned short code;Text_ParseDelimitedSignedIntegerSequence(arg,local,3);unsigned char* p=ReadWordFieldAtOffset1C();unsigned short value=local[2];bool second=local[1]!=0;bool first=local[0]!=0;p[0x19c6]=first;p[0x19c7]=second;*(unsigned short*)(p+0x187e)=value;void* destination=*out;code=0xff1b;memcpy(destination,&code,2);return 2;}
