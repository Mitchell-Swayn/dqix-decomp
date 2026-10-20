#pragma thumb off
#pragma optimization_level 4

extern "C" void CombatStatus_ClearDefenseStage(void*);
// Original: arm9/main @ 0x020878B4; symbol: func_020878b4; size: 0x78.
extern "C" int CombatStatus_AdjustDefenseStageAndRefreshTimer(char* object,int delta){int value=delta+(*(int*)(object+0x58)<<26>>29);if(value>2)value=2;if(value < -2)value=-2;if(!value){CombatStatus_ClearDefenseStage(object);return 0;}*(unsigned*)(object+0x58)=(*(unsigned*)(object+0x58)&~0x38)|((unsigned)(value<<29)>>26);object[0x6f]=6;object[0x92]=0;*(unsigned*)(object+0x14)|=0x800;return *(int*)(object+0x58)<<26>>29;}
