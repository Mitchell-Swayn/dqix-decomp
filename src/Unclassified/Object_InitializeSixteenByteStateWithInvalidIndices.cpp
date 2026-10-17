// Reviewed original ARM field widths and branch behavior. Hardware addresses are original MMIO literals.
extern "C" void func_02047230(void*);struct HalfCounter{unsigned low:16;unsigned high:16;};struct LowCounter{unsigned low:24;unsigned high:8;};
// Original: arm9/main @ 0x020A64BC; symbol: func_020a64bc; size: 0x2C.
extern "C" void Object_InitializeSixteenByteStateWithInvalidIndices(char* p){*(int*)p=0;*(int*)(p+4)=0;p[8]=-1;p[9]=1;p[10]=0;p[11]=0;*(int*)(p+12)=-1;}
