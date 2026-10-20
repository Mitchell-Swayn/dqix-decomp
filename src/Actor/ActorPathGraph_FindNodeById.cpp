// Reviewed ARM control flow and widths; surrounding object names remain unresolved.
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x020283C0; symbol: func_020283c0; size: 0x3C.
extern "C" char* ActorPathGraph_FindNodeById(char* p,int key){for(int i=0;i<(unsigned char)p[2];++i){char* entries=*(char**)(p+4);int off=i*16;if((unsigned char)entries[off]==key)return entries+off;}return 0;}
