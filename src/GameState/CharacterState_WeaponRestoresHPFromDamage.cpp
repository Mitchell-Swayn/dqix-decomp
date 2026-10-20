// Reviewed original ARM field widths and branch behavior. Hardware addresses are original MMIO literals.
extern "C" void func_02047230(void*);struct HalfCounter{unsigned low:16;unsigned high:16;};struct LowCounter{unsigned low:24;unsigned high:8;};
// Original: arm9/main @ 0x020850FC; symbol: func_020850fc; size: 0x2C.
extern "C" int CharacterState_WeaponRestoresHPFromDamage(char* p){if(*(short*)(p+0x2ac)<=0)return 0;return ((*(unsigned*)(p+756)<<28)>>31)!=0;}
