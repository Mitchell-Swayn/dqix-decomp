#include <globaldefs.h>
struct Entry{unsigned ptr,unused;unsigned a:12;unsigned kind:6;unsigned rest:14;};extern "C" unsigned Text_LookupArticleString(unsigned);extern "C" unsigned Text_AppendPrefixAndNameWithSpacing(unsigned,unsigned,unsigned,int);
// Original: arm9/main @ 0x020E4750; symbol: func_020e4750; size: 0x48.
extern "C" ARM unsigned Text_AppendPrimaryNameWithArticle(unsigned a,Entry* e){if(e->ptr){unsigned kind=Text_LookupArticleString(e->kind);a=Text_AppendPrefixAndNameWithSpacing(a,kind,e->ptr,0);}return a;}
