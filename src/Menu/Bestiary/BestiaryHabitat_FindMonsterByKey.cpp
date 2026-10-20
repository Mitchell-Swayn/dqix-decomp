extern "C" {
struct Table { unsigned short first, count, n, m; unsigned pad; unsigned* base; unsigned char* relocBase; };
struct Node { Node* next; };
struct Owner { unsigned char pad[0xb8]; Node* head; Node* selected; void* service; unsigned char gap[0xc]; short* linked; unsigned char gap2[0xa6]; unsigned char state, phase, other[3], closed; };
struct Stream { unsigned char data[0x14]; short index; unsigned short active; int handle; void* source; };
// Original: arm9/ov014 @ 0x021892D4; symbol: func_ov014_021892d4; size: 0x78.
unsigned* BestiaryHabitat_FindMonsterByKey(Table* p,int key,int (*readKey)(unsigned*)) { unsigned* base=p->base; if(!base || !readKey)return 0;int count=p->first;if(!count)return 0;int lo=0;int hi=count-1;while(lo<=hi) { int mid=lo+((hi-lo+1)>>1);unsigned* entry=base+mid;int value=readKey(entry);if(value==key)return entry;if(value>key)hi=mid-1;else lo=mid+1;}return 0; }
}
