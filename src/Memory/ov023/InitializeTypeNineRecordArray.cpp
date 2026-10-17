#include <globaldefs.h>
ARM
struct Tree;
struct Entry {char bytes[0x28];};
struct Record {int pad;unsigned short type,a,b,c;int pad2,value;char pad3[8];int state;unsigned short count;unsigned short pad4;Entry* entries;};
extern "C" {void ResetRecordWithInvalidIndex(void*);Tree* FindTreeNodeForwarder(Tree*,unsigned);char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);void Ov023_ClearFourByteRecord(void*);}
// Original: arm9/ov023 @ 0x021F9EC8; symbol: func_ov023_021f9ec8; size: 0xB0.
extern "C" int InitializeTypeNineRecordArray(Record* p,Tree* tree,unsigned a,unsigned b,unsigned count){
ResetRecordWithInvalidIndex(p);p->type=9;p->a=a;p->b=b;p->c=0;p->value=0;p->state=2;p->count=count;
Tree* node=FindTreeNodeForwarder(tree,p->b);if(!node)return 0;
p->entries=(Entry*)_ZN13SafeAllocator8AllocateEj((unsigned)((char*)node+4),p->count*0x28);
if(!p->entries)return 0;
for(int i=0;i<p->count;i++)Ov023_ClearFourByteRecord(&p->entries[i]);
return 1;
}
