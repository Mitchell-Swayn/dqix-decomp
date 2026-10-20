#include <globaldefs.h>
ARM
extern "C" char* strstr(const char*,const char*);extern "C" unsigned String_CountBytesUntilTerminator(const char*);
// Original: arm9/main @ 0x02068E1C; symbol: func_02068e1c; size: 0x84.
extern "C" char* TextMarkup_RemoveUnselectedBranchThroughClosingMarker(char* text,char* first,char* middle,char* last) { char* a=strstr(text,first);if(a) { char* b=strstr(a,middle);if(b) { char* c=strstr(b,last);if(c) { text=a+String_CountBytesUntilTerminator(first);unsigned length=String_CountBytesUntilTerminator(last);char* dst=text;char* src=text;for(;;) {if(src==b)src=c+length;char ch=*src;*dst=ch;if(!ch)break;++dst;++src;} } } }return text; }
