struct F{unsigned int low:10;unsigned int flag:1;unsigned int high:21;};
// Original: arm9/main @ 0x020851D8; symbol: func_020851d8; size: 0x2C.
extern "C" int CharacterState_WeaponGuaranteesQualifyingActionSuccess(char* p){if(*(short*)(p+0x2ac)<=0)return 0;return ((F*)(p+0x2f4))->flag!=0;}
