#include <globaldefs.h>
ARM
extern "C" void __clear(void*,unsigned);
struct Record{unsigned word;short a,b,c;unsigned short da:4;unsigned short db:4;unsigned short dc:4;unsigned short rest:4;char pad[20];};
struct Table{unsigned head;Record* records;unsigned short unused,count;};
// Original: arm9/main @ 0x02071DA4; symbol: func_02071da4; size: 0x258.
extern "C" Record* Util_FindRecordWithProportionalTriple(Table* self,short* keys,unsigned char* values,unsigned char* out){
 if(!keys || !values)return 0;
 unsigned char count=0;
 for(unsigned char i=0;i<3;i++)if(keys[i]>0)count++;
 Record* records=self->records;unsigned short total=self->count;
 Record* record;
 for(unsigned short index=0;index<total;index++){
  record=&records[index];
  unsigned char n=0;
  n+=record->a>0?1:0;n+=record->b>0?1:0;n+=record->c>0?1:0;
  if(n!=count)continue;
  unsigned char ratios[3];__clear(ratios,3);
  unsigned char i;
  for(i=0;i<n;i++){
   int key=keys[i];int value=values[i];
   if(key==record->a){int divisor=record->da;if(value%divisor)break;ratios[0]=value/divisor;}
   else if(key==record->b){int divisor=record->db;if(value%divisor)break;ratios[1]=value/divisor;}
   else if(key==record->c){int divisor=record->dc;if(value%divisor)break;ratios[2]=value/divisor;}
   else break;
  }
  unsigned char nonzero=0;
  for(unsigned char j=0;j<3;j++)if(ratios[j])nonzero++;
  if(n!=nonzero)continue;
  int different=0;
  for(i=1;i<n;i++)if(ratios[0]!=ratios[i]){different=1;break;}
  if(!different){*out=ratios[0];return record;}
 }
 return 0;
}
