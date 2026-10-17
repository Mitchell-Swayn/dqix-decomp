#include <globaldefs.h>
ARM
extern "C" unsigned char* FindTwoHundredTwentyFourByteRecordByByteKey(void*,int);extern "C" int Object_CreateAndConfigureSelectedDisplayPart(void*,int);
// Original: arm9/main @ 0x02081EA4; symbol: func_02081ea4; size: 0x40.
extern "C" void SetKeyedRecordByteFlagBitSixAndRefresh(void* p,int key,int enabled){unsigned char* entry=FindTwoHundredTwentyFourByteRecordByByteKey(p,key);if(!entry)return;if(enabled)entry[197]|=64;else entry[197]&=~64;Object_CreateAndConfigureSelectedDisplayPart(p,key);}
