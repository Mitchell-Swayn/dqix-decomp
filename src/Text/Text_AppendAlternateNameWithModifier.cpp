#include <globaldefs.h>
ARM
struct Record{int a;void* data;unsigned int flags;};extern "C" {int Text_LookupArticleString(short);int Text_AppendPrefixAndNameWithSpacing(int,int,void*,Record*);
// Original: arm9/main @ 0x020E47BC; symbol: func_020e47bc; size: 0x54.
int Text_AppendAlternateNameWithModifier(int value,Record* p){if(p->data){int key=Text_LookupArticleString((short)(((p->flags<<20)>>26)+300));value=Text_AppendPrefixAndNameWithSpacing(value,key,p->data,p);}return value;}}
