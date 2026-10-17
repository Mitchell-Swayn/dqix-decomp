#include <globaldefs.h>
ARM
extern "C" char* data_ov031_02290cf8;
extern "C" char data_ov031_022491fc[],data_ov031_022491f8[];
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" void DecodeBoundedPacketItemsIntoSixteenEntryList(void*,const unsigned short*);
struct Item { unsigned char type,length,pad[2];void* data; };
struct ItemList { unsigned char count,pad[3];Item items[16]; };
// Original: arm9/ov031 @ 0x02235A44; symbol: func_ov031_02235a44; size: 0x1D4.
extern "C" void Network_UpdateWirelessScanEntryCache(char* input) {
 char* entry; int slot; unsigned compareLength; int j,n; char* p; char* q; char* dest; int i;
 char* table=data_ov031_02290cf8+0x1300;
 _Z24InvalidateDataCacheRangePKvj(data_ov031_02290cf8+0xf00,0x400);
 int count=*(unsigned short*)(input+0xe);
 i=0;
 if(count<=0)return;
 do {
  entry=*(char**)(input+0x10+i*4);
  if(!*(unsigned char*)(entry+0xc)||*(unsigned short*)(entry+0x3c))goto nextEntry;
  p=table;slot=0;compareLength=6;
  do {
   if(!RuntimeMemory_CompareByteRanges(entry+4,p+0x20,compareLength))break;
   slot++;p+=0x2a;
  } while(slot<20);
  if(slot==20) {
   q=table;slot=0;compareLength=6;
   do {
    if(!RuntimeMemory_CompareByteRanges(q+0x20,data_ov031_022491fc,compareLength))break;
    slot++;q+=0x2a;
   } while(slot<20);
   if(slot==20)return;
  }
  dest=table+slot*0x2a;
  MI_CpuCopy8(entry+4,dest+0x20,6);
  MI_CpuCopy8(entry+0xc,dest,0x20);
  *(unsigned short*)(dest+0x26)=*(unsigned short*)(input+0x50+i*2);
  if(!(*(unsigned short*)(entry+0x2c)&0x10))*(unsigned char*)(dest+0x28)=0;
  else {
   *(unsigned char*)(dest+0x28)=1;
   ItemList list;
   DecodeBoundedPacketItemsIntoSixteenEntryList(&list,(unsigned short*)entry);
   n=list.count;
   j=0;
   if(n>0) {
   compareLength=4;
   do {
    Item* item=(Item*)((char*)&list+j*8+4);
    if(item->type==0x30) {*(unsigned char*)(dest+0x28)=2;break;}
    if(item->type==0xdd && item->length>=4 && !RuntimeMemory_CompareByteRanges(item->data,data_ov031_022491f8,compareLength)) {*(unsigned char*)(dest+0x28)=2;break;}
    j++;
   } while(j<n);
   }
  }
 nextEntry:
  i++;
 } while(i<*(unsigned short*)(input+0xe));
}
