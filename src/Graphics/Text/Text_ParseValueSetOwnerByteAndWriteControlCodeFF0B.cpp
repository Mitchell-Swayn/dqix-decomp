#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" void Text_ParseDelimitedSignedIntegerSequence(unsigned,unsigned*,unsigned);
extern "C" char* TextContext_GetSharedInstance();
// Original: arm9/main @ 0x020697B8; symbol: func_020697b8; size: 0x54.
extern "C" unsigned Text_ParseValueSetOwnerByteAndWriteControlCodeFF0B(void** output,unsigned index) {unsigned value;unsigned short code;Text_ParseDelimitedSignedIntegerSequence(index,&value,1);TextContext_GetSharedInstance()[0x195e]=value;void* dest=*output;code=0xff0b;memcpy(dest,&code,2);return 2;}
