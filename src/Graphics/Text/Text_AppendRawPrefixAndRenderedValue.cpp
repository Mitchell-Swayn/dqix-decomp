#include <globaldefs.h>
ARM
extern "C" void *ReadWordFieldAtOffset1C();
extern "C" void *memcpy(void *,const void *,unsigned);
extern "C" unsigned strlen(const char *);
extern "C" void ProcessSixStagesUsingSharedWordScratchBuffer(void *,int,unsigned,char *,int,int,int);
// Original: arm9/main @ 0x02098F70; symbol: func_02098f70; size: 0x84.
extern "C" void Text_AppendRawPrefixAndRenderedValue(char **cursor,unsigned value,void *data,unsigned length) { void *context=ReadWordFieldAtOffset1C(); memcpy(*cursor,data,length); *cursor+=length; ProcessSixStagesUsingSharedWordScratchBuffer(context,12,value,*cursor,227,0,1); *cursor+=strlen(*cursor); }
