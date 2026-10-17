#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" int TestResolvedBitInByteField100C(void*,int);extern "C" unsigned ReadElement0At021015A0();extern "C" unsigned short* GetRecordAtResolvedIndexWithStride116(void*,int);
// Original: arm9/main @ 0x0202BED8; symbol: func_0202bed8; size: 0x68.
extern "C" int Object_TestMemberHalfwordBit14(unsigned char* p,int index){if(!TestResolvedBitInByteField100C(p,index))return 0;unsigned base=ReadElement0At021015A0();unsigned short* entry;if(index==(signed char)(p+base)[0x1038])entry=(unsigned short*)(p+0x7c0);else entry=GetRecordAtResolvedIndexWithStride116(p,index);if(!entry)return 0;return (((unsigned)entry[1]<<17)>>31)!=0;}
