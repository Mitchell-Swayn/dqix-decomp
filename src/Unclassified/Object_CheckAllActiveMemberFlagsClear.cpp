#include <globaldefs.h>
struct Owner {char pad[0x1038];signed char ids[4];};struct Flags { short unused; unsigned short a:1,bits:4,rest:11; }; extern "C" { int TestResolvedBitInByteField100C(void*,int);int ReadElement0At021015A0();Flags* GetRecordAtResolvedIndexWithStride116(void*,int);
// Original: arm9/main @ 0x0202BD68; symbol: func_0202bd68; size: 0xA0.
int Object_CheckAllActiveMemberFlagsClear(Owner* p,unsigned bit) { int i=0; for(;i<4;++i) { if(i>0 && *((signed char*)p+0x1038+i)==0)continue; if(!TestResolvedBitInByteField100C(p,p->ids[i]))continue; Flags* f=i==ReadElement0At021015A0() ? (Flags*)((char*)p+0x7c0) : GetRecordAtResolvedIndexWithStride116(p,p->ids[i]);if(f && (f->bits&(1u<<bit)))return 0; } return 1; } }
