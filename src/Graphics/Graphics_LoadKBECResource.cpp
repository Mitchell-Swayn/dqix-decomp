#include <globaldefs.h>
ARM
#pragma optimization_level 2
#include <std_library_functions.h>
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
struct State;
extern "C" void Graphics_InitializeSpriteTransformDefaults(State*);
extern "C" int NNS_G2dGetUnpackedCellBank(unsigned,char**);
extern "C" unsigned char* NNS_G2dGetCellDataByIdx(unsigned char*,unsigned);
struct Triple { unsigned short a,b,c; };
struct Record {unsigned short count,flags; Triple* src; Triple* copy; char pad[18]; unsigned short index; char p2[2]; unsigned char start; char p3[5];};
#define U16(p,o) (*(unsigned short*)((p)+(o)))
#define U32(p,o) (*(unsigned*)((p)+(o)))
// Original: arm9/main @ 0x0205A658; symbol: func_0205a658; size: 0x32C.
extern "C" int Graphics_LoadKBECResource(char* self,char* data,unsigned size,unsigned allocator) {
 char* block;
 if(!data) data=0;
 else if(!size) data=0;
 else {memcpy(data,data,size);if(!NNS_G2dGetUnpackedCellBank((unsigned)data,&block))data=0;}
 if(!data)return 1;
 if(allocator&&!U32(self,0x40)) {
 unsigned short allocatedCount=U16(block,0); U16(self,0x4c)=allocatedCount;
 U32(self,0x40)=(unsigned)_ZN13SafeAllocator8AllocateEj(allocator,allocatedCount*40);
 for(unsigned short i=0;i<U16(self,0x4c);i++)Graphics_InitializeSpriteTransformDefaults((State*)(U32(self,0x40)+i*40));
 }
 Record* records;unsigned short cap;cap=U16(self,0x4c);records=(Record*)U32(self,0x40);
 if(records&&cap&&allocator){unsigned count=U16(block,0);Record *dst,*src;unsigned short i,total;total=0;for(i=0;i<count;i++) {
 if(cap<=i)break;
 src=(Record*)NNS_G2dGetCellDataByIdx((unsigned char*)block,i);if(!src)break;
 unsigned n=src->count;dst=records+i;dst->index=i;dst->start=total;dst->count=src->count;dst->flags=src->flags;dst->src=src->src;
 dst->copy=(Triple*)_ZN13SafeAllocator8AllocateEj(allocator,n*6);dst->src=dst->copy;
 for(unsigned short j=0;j<src->count;j++){Triple* from=src->src+j;Triple* to=dst->copy+j;to->a=from->a;to->b=from->b;to->c=from->c;}
 total+=src->count;
 }}
 U16(self,0x4e)=U16(block,0);U32(self,0x38)=U32(block,8);
 Record* last=(Record*)NNS_G2dGetCellDataByIdx((unsigned char*)block,(unsigned short)(U16(block,0)-1));if(!last)return 1;
 unsigned shift=U32(self,0x38);Triple* t=&last->src[last->count-1];shift+=5;unsigned value=(t->c&1023)<<shift;int b=(t->b&0xc000)>>14;int a=(t->a&0xc000)>>14;unsigned bits=5;
 switch(a){case 0:switch(b){case 0:bits=5;break;case 1:bits=7;break;case 2:bits=9;break;case 3:bits=11;break;}break;
 case 1:switch(b){case 0:bits=6;break;case 1:bits=7;break;case 2:bits=8;break;case 3:bits=10;break;}break;
 case 2:switch(b){case 0:bits=6;break;case 1:bits=7;break;case 2:bits=8;break;case 3:bits=10;break;}break;}
 if(shift<bits)shift=bits;U32(self,0x48)=value+(1<<shift);return 0;
}
