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
// Original: arm9/ov011 @ 0x02186650; symbol: func_ov011_02186650; size: 0x90.
extern "C" unsigned func_ov011_02186650(void* self) { unsigned id=func_ov011_02184c30(self); Vector position; position.x=(int)(4096.0f*func_ov011_02184c4c((char*)self+8)); position.y=(int)(4096.0f*func_ov011_02184c4c((char*)self+16)); position.z=0; Object* item=(Object*)func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()),id); if(!item) return 0; ((void(*)(Object*,Vector*))item->methods[50])(item,&position); return 1; }
