#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" unsigned short TestIndexedHalfwordFlag(const unsigned char*,unsigned);
extern "C" unsigned data_ov004_02170854[];
extern "C" unsigned char data_ov004_02170838[];
extern "C" unsigned char data_ov004_021707e8[];
// Original: arm9/ov004 @ 0x0215E9DC; symbol: func_ov004_0215e9dc; size: 0x144.
extern "C" unsigned char Object_CycleEnabledIndexedFlag(void*,int objectIndex,unsigned char index,int forward) {
 unsigned char* obj=(unsigned char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),objectIndex);
 if(data_ov004_02170854[index]) {
  if(forward) {
   index=(unsigned char)(index+1)%13;
   if(!index) index=1;
  } else {
   index--;
   if(index<1) index=12;
  }
  while(!TestIndexedHalfwordFlag(obj,data_ov004_02170854[index]) || !data_ov004_02170838[index]) {
   if(forward) {
    index=(unsigned char)(index+1)%13;
    if(data_ov004_021707e8[2] && !index) ++index;
    if(TestIndexedHalfwordFlag(obj,data_ov004_02170854[index]) && data_ov004_02170838[index]) break;
   } else {
    --index;
    if(index<1) index=12;
    if(data_ov004_021707e8[2] && !index) index=12;
    if(TestIndexedHalfwordFlag(obj,data_ov004_02170854[index]) && data_ov004_02170838[index]) break;
   }
  }
 }
 return index;
}
