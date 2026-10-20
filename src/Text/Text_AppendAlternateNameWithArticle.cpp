#include <globaldefs.h>
struct Record {unsigned unused; const char* file; unsigned flags;}; extern "C" const char* Text_LookupArticleString(int); extern "C" char* Text_AppendPrefixAndNameWithSpacing(char*,const char*,const char*,...);
// The fourth argument is passed in r3 for the formatting call's record context.
// Original: arm9/main @ 0x020E4810; symbol: func_020e4810; size: 0x54.
extern "C" ARM char* Text_AppendAlternateNameWithArticle(char* out,Record* record){if(record->file){const char* directory=Text_LookupArticleString((short)(((record->flags<<8)>>26)+200)); out=Text_AppendPrefixAndNameWithSpacing(out,directory,record->file,record);} return out;}
