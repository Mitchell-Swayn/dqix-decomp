#include <globaldefs.h>
ARM
struct GameResources;
extern "C" GameResources* GameResources_GetInstance();
extern "C" int ReadMaskedWord(GameResources*,unsigned);
extern "C" int ReadIndirectByteOrMinusOne(char**);
extern "C" void SetNestedSecondWordForTypeThree(void*,int);
extern "C" void SetWordMaskBits_Main0203B4A0(unsigned*,unsigned);
// Original: arm9/ov001 @ 0x02162F8C; symbol: func_ov001_02162f8c; size: 0x7C.
extern "C" int SetTypeThreeOutputFromResourceFlag(void* p) {
 GameResources* res=GameResources_GetInstance();
 if(ReadMaskedWord(res,16)) { SetNestedSecondWordForTypeThree(p,0); return 1; }
 int flag=ReadIndirectByteOrMinusOne(*(char***)((char*)res+0x3700))!=19;
 SetNestedSecondWordForTypeThree(p,!flag);
 if(flag) SetWordMaskBits_Main0203B4A0((unsigned*)res,16);
 return 1;
}
