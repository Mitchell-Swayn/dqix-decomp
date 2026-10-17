// Reviewed original ARM field widths and branch behavior. Hardware addresses are original MMIO literals.
extern "C" void func_02047230(void*);struct HalfCounter{unsigned low:16;unsigned high:16;};struct LowCounter{unsigned low:24;unsigned high:8;};
// Original: arm9/main @ 0x020857EC; symbol: func_020857ec; size: 0x2C.
extern "C" int Object_TestPositiveCountAndOffset2F8Bit3(char* p){if(*(short*)(p+0x2ac)<=0)return 0;return ((*(unsigned*)(p+760)<<28)>>31)!=0;}
