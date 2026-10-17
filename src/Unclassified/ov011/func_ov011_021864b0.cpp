#include <globaldefs.h>
extern "C" int func_ov011_02184c30(void*);
extern "C" float func_ov011_02184c4c(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*,unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" void func_ov023_021fb25c(void*,unsigned,unsigned,unsigned,unsigned);
extern "C" unsigned WriteBoundedHalfwordGridCell(void*,unsigned,unsigned,unsigned);
extern "C" void func_ov011_02184c00(void*);
extern "C" void func_ov011_02184c14(void*);
extern "C" void MapVRAMBanksToMainBG(unsigned);
extern "C" void MapVRAMBanksToSubBG(unsigned);
extern "C" void ColorEffect_ConfigureAlphaBlend(void*,unsigned,unsigned,unsigned,unsigned);
typedef void (*Setup)(unsigned,unsigned,unsigned,unsigned,unsigned);
typedef void (*Priority)(unsigned);
struct SetupTable { Setup entries[2][4]; };
struct PriorityTable { Priority entries[2][4]; };
struct MainBankTable { unsigned values[17]; };
struct SubBankTable { unsigned values[4]; };
extern "C" const SetupTable data_ov011_02188914;
extern "C" const PriorityTable data_ov011_02188934;
extern "C" const MainBankTable data_ov011_02188954;
extern "C" const SubBankTable data_ov011_02188904;
struct Vector { int x,y,z; };
struct Object { void (**methods)(); };
// Original: arm9/ov011 @ 0x021864B0; symbol: func_ov011_021864b0; size: 0x98.
extern "C" unsigned func_ov011_021864b0(void* self) { unsigned screen=func_ov011_02184c30(self); unsigned a=func_ov011_02184c30((char*)self+8); unsigned b=func_ov011_02184c30((char*)self+16); unsigned c=func_ov011_02184c30((char*)self+24); unsigned d=func_ov011_02184c30((char*)self+32); if(screen==0) ColorEffect_ConfigureAlphaBlend((void*)0x04000050,a,b,c,d); else if(screen==1) ColorEffect_ConfigureAlphaBlend((void*)0x04001050,a,b,c,d); return 1; }
