// Reviewed original ARM field widths and branch behavior. Hardware addresses are original MMIO literals.
extern "C" void func_02047230(void*);struct HalfCounter{unsigned low:16;unsigned high:16;};struct LowCounter{unsigned low:24;unsigned high:8;};
// Original: arm9/main @ 0x020A02D0; symbol: func_020a02d0; size: 0x30.
extern "C" void Object_AddSaturatedLowTwentyFourBitsAtOffset20(char* p,unsigned add){LowCounter* q=(LowCounter*)(p+32);unsigned v=q->low+add;if(v>0xffffff)v=0xffffff;q->low=v;}
