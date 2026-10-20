#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" void Text_ParseDelimitedSignedIntegerSequence(void*,unsigned*,int); extern "C" void* TextContext_GetSharedInstance(); extern "C" void TextWindow_EnqueueControlDelay(void*,unsigned);
// Original: arm9/main @ 0x02069834; symbol: func_02069834; size: 0x50.
extern "C" int TextStream_QueueValueAndWriteMarkerFF1A(void** output,void* input) { unsigned value; Text_ParseDelimitedSignedIntegerSequence(input,&value,1); TextWindow_EnqueueControlDelay(TextContext_GetSharedInstance(),value); void* destination=*output; unsigned short marker=0xff1a; memcpy(destination,&marker,2); return 2; }
