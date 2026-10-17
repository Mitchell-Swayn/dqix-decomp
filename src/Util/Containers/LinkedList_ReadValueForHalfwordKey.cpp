// Reviewed original ARM field widths and branch behavior. Hardware addresses are original MMIO literals.
extern "C" void func_02047230(void*);struct HalfCounter{unsigned low:16;unsigned high:16;};struct LowCounter{unsigned low:24;unsigned high:8;};
// Original: arm9/main @ 0x020D794C; symbol: func_020d794c; size: 0x2C.
extern "C" void* LinkedList_ReadValueForHalfwordKey(char** p,int key){char* q=*p;while(q){if(*(short*)(q+2)==key)return *(void**)(q+4);q=*(char**)(q+8);}return 0;}
