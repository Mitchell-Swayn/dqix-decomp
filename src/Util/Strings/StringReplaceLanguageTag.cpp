#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#include <Filesystem/FileIOConfiguration.h>
extern "C" {char* String_FindFirstSubstring(char*,const char*);int String_CountBytesUntilTerminator(const char*);}
// Original: arm9/main @ 0x020757B4; symbol: _Z24StringReplaceLanguageTagPKcPci; size: 0xEC.
char* StringReplaceLanguageTag(const char* src,char* out,int language){if(!src||!out)return out;{const char* tag=gFileIOConfiguration.languageTag;strcpy(out,src);char* found=String_FindFirstSubstring(out,tag);const char* replace=gFileIOConfiguration.languages[language];unsigned int size=String_CountBytesUntilTerminator(replace);int delta=String_CountBytesUntilTerminator(replace)-String_CountBytesUntilTerminator(tag);while(found){if(delta>0){int length=String_CountBytesUntilTerminator(found);memmove(found+delta,found,length+1);}else if(delta<0){int length=String_CountBytesUntilTerminator(found);memmove(found,found-delta,delta+length+1);}memmove(found,replace,size);found=String_FindFirstSubstring(out,tag);}}return out;}
