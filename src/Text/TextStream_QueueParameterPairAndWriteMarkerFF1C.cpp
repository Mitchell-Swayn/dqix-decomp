#include <globaldefs.h>
ARM
#include "std_library_functions.h"
extern "C" int Text_ParseDelimitedSignedIntegerSequence(const char*,int*,int);extern "C" signed char* TextContext_GetSharedInstance();
// Original: arm9/main @ 0x02069A4C; symbol: func_02069a4c; size: 0x98.
extern "C" int TextStream_QueueParameterPairAndWriteMarkerFF1C(void** output,const char* source) {unsigned short command;int values[2];Text_ParseDelimitedSignedIntegerSequence(source,values,2);signed char* context=TextContext_GetSharedInstance(); int second=values[1];context[0x1956]%=4;(context+context[0x1956])[0x194e]=values[0];(context+context[0x1956])[0x1952]=second;++context[0x1956];void* destination=*output;command=(unsigned short)0xff1c;memcpy(destination,&command,2);return 2;}
