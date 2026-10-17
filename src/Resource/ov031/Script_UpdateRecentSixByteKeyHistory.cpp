#include <globaldefs.h>
ARM
struct RecentRecord { unsigned char key[6]; unsigned char age; unsigned char pad; };
extern "C" {
extern unsigned char data_ov031_02291e04[];
void* _ZN9GameState11GetInstanceEv();
int _ZNK6Script9Parameter5ToIntEv(const void*);
int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
void* memcpy(void*,const void*,unsigned);
void* memset(void*,int,unsigned);
}
// Original: arm9/ov031 @ 0x02243144; symbol: func_ov031_02243144; size: 0x1BC.
extern "C" int Script_UpdateRecentSixByteKeyHistory(unsigned char* args) {
 if(!*(void**)(data_ov031_02291e04+0x34)) return 1;
 if(data_ov031_02291e04[3]) return 1;
 unsigned char* first=args;
 args+=8;
 _ZNK6Script9Parameter5ToIntEv(first);
 unsigned char key[6];
 for(int i=0;i<6;i++) { key[i]=_ZNK6Script9Parameter5ToIntEv(args); args+=8; }
 if(RuntimeMemory_CompareByteRanges(key,*(unsigned char**)(data_ov031_02291e04+0x18)+4,6)==0) {
  data_ov031_02291e04[6]=1;
  int best=-1;
  int age=best;
  RecentRecord* records=(RecentRecord*)((unsigned char*)_ZN9GameState11GetInstanceEv()+0x7fb0);
  RecentRecord* node=records;
  for(int i=0;i<8;i++,node++) {
   if(RuntimeMemory_CompareByteRanges(node,key,6)==0) {
    best=i;
    if(node->age!=255 && data_ov031_02291e04[7]==0) { data_ov031_02291e04[4]=node->age; return 1; }
    break;
   }
   if(age>node->age || age<0) { best=i; age=node->age; }
  }
  data_ov031_02291e04[3]=1;
  node=records;
  for(int i=0;i<8;i++,node++) {
   if(node->age) {
    if(node->age==255) node->age=0;
    else node->age--;
    if(!node->age) memset(node,0,8);
   }
  }
  node=records+best;
  memcpy(node,key,6);
  node->age=7;
 }
 return 1;
}
