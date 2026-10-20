#include <globaldefs.h>
extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" int RuntimeMemory_CompareByteRanges(const char*,const char*,unsigned);extern "C" int Runtime_ParseStringAsBaseTenInteger(const char*);
// Original: arm9/main @ 0x0204FC40; symbol: func_0204fc40; size: 0xC0.
extern "C" ARM int TextMarkup_ParseIntegerCommand(void* unused,char** cursor,const char* token,unsigned short* output,int count){unsigned length=String_CountBytesUntilTerminator(token);char*p=*cursor;if(!RuntimeMemory_CompareByteRanges(p,token,length)){p+=length;for(short i=0;i<count;i++){output[i]=Runtime_ParseStringAsBaseTenInteger(p);if(i==count-1)break;while(*p!=',')p++;p++;}while(*p!='>'&&*p)p++;*cursor=p+1;return 1;}return 0;}
