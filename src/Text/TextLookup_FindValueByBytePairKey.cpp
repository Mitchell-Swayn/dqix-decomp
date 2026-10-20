#include <globaldefs.h>
struct Table{unsigned short stride,unused[2];short count;unsigned char* keys;char* values;};
// Original: arm9/main @ 0x020429E4; symbol: func_020429e4; size: 0x6C.
extern "C" ARM char* TextLookup_FindValueByBytePairKey(Table* p,const unsigned char* key){int count;unsigned char* k;int i;unsigned char a,b;if(!p)return 0;if(!key){a=0;b=a;}else{a=key[0];b=key[1];}count=p->count;k=p->keys;for(i=0;i<count;++i){if(a==k[0]&&b==k[1])return p->values+i*p->stride;k+=2;}return 0;}
