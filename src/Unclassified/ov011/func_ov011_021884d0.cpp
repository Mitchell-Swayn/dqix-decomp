#include <globaldefs.h>
struct Flags { char prefix[0x55]; unsigned char enabled; };
extern "C" unsigned data_02114e30[];
extern "C" Flags data_02114e54;
extern "C" unsigned data_02108760[];
extern "C" int Object_TestNewlySetHalfwordMask(void*, unsigned);
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(void*, unsigned, unsigned);
extern "C" void func_ov011_02184c68(void*, unsigned);
// Original: arm9/ov011 @ 0x021884D0; symbol: func_ov011_021884d0; size: 0x64.
extern "C" unsigned func_ov011_021884d0(void* self) {
 unsigned value=0;
 if(Object_TestNewlySetHalfwordMask(data_02114e30,0x7f3) || data_02114e54.enabled) {
  DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,1,0);
  value=1;
 }
 func_ov011_02184c68(self,value);
 return 1;
}
