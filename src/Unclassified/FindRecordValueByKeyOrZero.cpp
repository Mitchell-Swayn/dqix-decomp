#include <globaldefs.h>
extern "C" {
struct E {short key;short pad;unsigned int value;};struct T {E *data;short count;};
// Original: arm9/main @ 0x02072A68; symbol: func_02072a68; size: 0x40.
unsigned int FindRecordValueByKeyOrZero(T *p,int key){for(int i=0;i<p->count;i++)if(p->data[i].key==key)return p->data[i].value;return 0;}
}
