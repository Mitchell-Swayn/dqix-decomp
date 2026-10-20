#include <globaldefs.h>
ARM
extern "C" void *TextContext_GetSharedInstance();
extern "C" void *memcpy(void *,const void *,unsigned);
extern "C" unsigned strlen(const char *);
extern "C" void TextMarkup_ExpandAndWrapText(void *,int,unsigned,char *,int,int,int);
// Original: arm9/main @ 0x02098F70; symbol: func_02098f70; size: 0x84.
extern "C" void Text_AppendRawPrefixAndRenderedValue(char **cursor,unsigned value,void *data,unsigned length) { void *context=TextContext_GetSharedInstance(); memcpy(*cursor,data,length); *cursor+=length; TextMarkup_ExpandAndWrapText(context,12,value,*cursor,227,0,1); *cursor+=strlen(*cursor); }
