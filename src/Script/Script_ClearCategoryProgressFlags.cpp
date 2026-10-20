// Reviewed ARM control flow and widths; surrounding object names remain unresolved.
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x0206E080; symbol: func_0206e080; size: 0x50.
extern "C" void Script_ClearCategoryProgressFlags(char* p,int i){char* q=p+i*28;memset(q+3,0,4);memset(q+8,0,8);memset(q+16,0,4);memset(q+20,0,8);}
