#pragma thumb off
#pragma optimization_level 4

extern "C" void ClearField14Flag800AndField58Flag38AndBytes6FAnd92(void*);
// Original: arm9/main @ 0x020878B4; symbol: func_020878b4; size: 0x78.
extern "C" int Object_AdjustSignedThreeBit58Field3AndSetTimer(char* object,int delta){int value=delta+(*(int*)(object+0x58)<<26>>29);if(value>2)value=2;if(value < -2)value=-2;if(!value){ClearField14Flag800AndField58Flag38AndBytes6FAnd92(object);return 0;}*(unsigned*)(object+0x58)=(*(unsigned*)(object+0x58)&~0x38)|((unsigned)(value<<29)>>26);object[0x6f]=6;object[0x92]=0;*(unsigned*)(object+0x14)|=0x800;return *(int*)(object+0x58)<<26>>29;}
