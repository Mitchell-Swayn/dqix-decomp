// Reviewed original ARM field widths and branch behavior. Hardware addresses are original MMIO literals.
extern "C" void func_02047230(void*);struct HalfCounter{unsigned low:16;unsigned high:16;};struct LowCounter{unsigned low:24;unsigned high:8;};
// Original: arm9/main @ 0x020A00A4; symbol: func_020a00a4; size: 0x30.
extern "C" void AddToHighHalfwordCounterAtOffsetCSaturatingAt65535(char* p,unsigned add){HalfCounter* q=(HalfCounter*)(p+12);unsigned v=q->high+add;if(v>65535)v=65535;q->high=v;}
