// Reviewed ARM control flow and widths; surrounding object names remain unresolved.
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x0203B634; symbol: func_0203b634; size: 0x38.
extern "C" void Graphics_ClearBackgroundStateBlocks(char* p){memset(p,0,32);memset(p+32,0,32);memset(p+64,0,32);}
