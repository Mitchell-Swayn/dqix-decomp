struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x02070FE4; symbol: func_02070fe4; size: 0x10.
extern "C" unsigned int MonsterBattleData_GetEntryCount(Flags* p){return p->value;}
