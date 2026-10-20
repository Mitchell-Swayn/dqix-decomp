// Reviewed ARM control flow and widths; surrounding object names remain unresolved.
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x0202A9AC; symbol: func_0202a9ac; size: 0x48.
extern "C" char* DebugMenu_GetEntryByIndex(char* p,int i){if(i<0 || *(unsigned short*)(p+0x5a)<=i)return 0;char* node=*(char**)(p+0x44);for(int n=0;n<i;++n){if(!node)return 0;node=*(char**)(node+0x34);}return node;}
