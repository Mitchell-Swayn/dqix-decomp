struct LowTwelve{unsigned value:12;unsigned rest:20;};
// Reviewed original ARM field widths and source behavior; float initialization is a real 1.0 constant.
extern "C" {int strcmp(const char*,const char*);void* memset(void*,int,unsigned);void func_02030b0c(void*);}
// Original: arm9/main @ 0x020797E8; symbol: func_020797e8; size: 0x10.
extern "C" unsigned ActionData_GetDefinitionIdentifier(char* p){return ((LowTwelve*)(p+4))->value;}
