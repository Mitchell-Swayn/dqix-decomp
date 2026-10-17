#include <globaldefs.h>
#pragma optimize_for_size off

struct Record {unsigned* data;unsigned pad;unsigned kind:4;unsigned rest:28;};struct Packed{unsigned pad:11;unsigned a:4;unsigned b:4;unsigned c:4;unsigned d:4;unsigned tail:5;};
// Original: arm9/main @ 0x020DE2A4; symbol: func_020de2a4; size: 0x78.
extern "C" ARM unsigned PackedRecord_ReadSelectedQuadrantWordForSupportedKind(Record* p,int second,int high){int valid=p->kind<=7;if(!valid && p->kind!=11)return 0;Packed* v=(Packed*)p->data;if(!v)return 0;if(high){if(second)return v->d;return v->c;}if(second)return v->b;return v->a;}
