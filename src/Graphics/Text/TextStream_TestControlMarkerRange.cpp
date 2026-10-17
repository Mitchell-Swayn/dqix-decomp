#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x02067AD8; symbol: func_02067ad8; size: 0x50.
extern "C" bool TextStream_TestControlMarkerRange(void*,const void* text) { unsigned short value;memcpy(&value,text,2);if(value>=0xff01 && value<=0xff18)return true;return (value&0xffe0)==0xffe0; }
