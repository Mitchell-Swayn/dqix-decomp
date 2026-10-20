#include <globaldefs.h>
ARM
struct RecentRecord { unsigned char key[6]; unsigned char age; unsigned char pad; };
extern "C" {
// Original data: arm9/ov031 @ 0x2291e04; symbol: data_ov031_02291e04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[];
void* _ZN9GameState11GetInstanceEv();
int _ZNK6Script9Parameter5ToIntEv(const void*);
int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
void* memcpy(void*,const void*,unsigned);
void* memset(void*,int,unsigned);
}
// Original: arm9/ov031 @ 0x02243144; symbol: func_ov031_02243144; size: 0x1BC.
extern "C" int Script_UpdateRecentSixByteKeyHistory(unsigned char* args) {
 if(!*(void**)(ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage+0x34)) return 1;
 if(ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[3]) return 1;
 unsigned char* first=args;
 args+=8;
 _ZNK6Script9Parameter5ToIntEv(first);
 unsigned char key[6];
 for(int i=0;i<6;i++) { key[i]=_ZNK6Script9Parameter5ToIntEv(args); args+=8; }
 if(RuntimeMemory_CompareByteRanges(key,*(unsigned char**)(ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage+0x18)+4,6)==0) {
  ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[6]=1;
  int best=-1;
  int age=best;
  RecentRecord* records=(RecentRecord*)((unsigned char*)_ZN9GameState11GetInstanceEv()+0x7fb0);
  RecentRecord* node=records;
  for(int i=0;i<8;i++,node++) {
   if(RuntimeMemory_CompareByteRanges(node,key,6)==0) {
    best=i;
    if(node->age!=255 && ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[7]==0) { ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[4]=node->age; return 1; }
    break;
   }
   if(age>node->age || age<0) { best=i; age=node->age; }
  }
  ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[3]=1;
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
