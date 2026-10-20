// Reconstructed from original ARM instructions; field names remain unresolved.
// Original: arm9/main @ 0x020467F0; symbol: func_020467f0; size: 0x5C.
extern "C" char* ResourceFile_GetPayloadByIndex(char* p,int index,char** out,unsigned int* size) { if(!p) return 0; int i=0; while(*p) { if(index==i) { int off=*(int*)(p+0x40); if(size) *size=*(unsigned int*)(p+0x44); *out=p; return p+off; } p+=*(int*)(p+0x48); ++i; } return 0; }
