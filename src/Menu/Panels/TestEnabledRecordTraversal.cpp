#include <globaldefs.h>
ARM
extern "C" char* MenuLayout_FindGroupByKey(char*,int);
// Original: arm9/ov023 @ 0x021E2C38; symbol: func_ov023_021e2c38; size: 0x70.
// Tests the enabled flag while traversing positive forward keys and nonnegative link keys in 24-byte records.
extern "C" int TestEnabledRecordTraversal(char* self,int key){
 int enabled=1;char* node=MenuLayout_FindGroupByKey(self,key);
 while(node){
 enabled=(*(unsigned char*)(node+22)&1)?1:0;
 if(!enabled)break;
 while(*(short*)(node+16)>0)node=MenuLayout_FindGroupByKey(self,*(short*)(node+16));
 if(*(short*)(node+12)>=0)node=MenuLayout_FindGroupByKey(self,*(short*)(node+12));
 }
 return enabled;
}
