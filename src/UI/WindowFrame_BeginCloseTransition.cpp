// Reviewed original ARM field widths and branch behavior. Hardware addresses are original MMIO literals.
extern "C" void func_02047230(void*);struct HalfCounter{unsigned low:16;unsigned high:16;};struct LowCounter{unsigned low:24;unsigned high:8;};
// Original: arm9/main @ 0x0202F6D4; symbol: func_0202f6d4; size: 0x2C.
extern "C" void WindowFrame_BeginCloseTransition(char* p){if(!*(char**)(p+0x440))return;*(int*)(*(char**)(p+0x440)+16)=0x1000;*(int*)(*(char**)(p+0x440)+20)=0x1000;*(int*)(*(char**)(p+0x440)+8)=3;}
