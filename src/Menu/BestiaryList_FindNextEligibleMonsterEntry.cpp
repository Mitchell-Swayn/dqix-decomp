#include <globaldefs.h>
struct Entry{char pad[0xe];short key;char gap[3];unsigned char enabled:1;unsigned char bit1:1;unsigned char excluded:1;unsigned char rest:5;char tail[12];};struct List{int unknown;unsigned count:12;unsigned other:20;Entry* entries;};
// Original: arm9/main @ 0x02097720; symbol: func_02097720; size: 0x78.
extern "C" ARM Entry* BestiaryList_FindNextEligibleMonsterEntry(List* p,int key){unsigned short count=p->count;Entry* entries=p->entries;Entry* best=0;int bestKey=0x7fff;for(unsigned short i=0;i<count;++i){Entry* e=entries+i;if(!e->excluded&&e->enabled){int k=e->key;if(k>key&&bestKey>k){bestKey=k;best=e;}}}return best;}
