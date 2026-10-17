#include <globaldefs.h>
ARM
extern "C" { void* memcpy(void*,const void*,unsigned); unsigned char* _ZN9GameState11GetInstanceEv(); unsigned ReadWordFieldAtOffset1C(); void func_ov011_021848a0(void*,unsigned); extern unsigned char* data_ov004_02171048[]; }
struct Nested { unsigned unknown; char data[64]; };
// Original: arm9/ov004 @ 0x0216F788; symbol: func_ov004_0216f788; size: 0x9C.
extern "C" int System_SelectStateFromTwoStatusBytes(void* self) {
 unsigned char saved[64];
 unsigned char* state=_ZN9GameState11GetInstanceEv();
 Nested* nested=(Nested*)(state+0x6380);
 memcpy(saved,nested->data,64);
 if(!data_ov004_02171048[1][0x32]) {
  func_ov011_021848a0(self,101);
  data_ov004_02171048[1][0x31]=1;
 } else if(!data_ov004_02171048[1][0x33]) {
  func_ov011_021848a0(self,102);
  *(int*)(ReadWordFieldAtOffset1C()+0x2c8)=1;
 } else func_ov011_021848a0(self,200);
 return 0;
}
