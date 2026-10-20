// Reviewed ARM control flow and widths; surrounding object names remain unresolved.
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x020E385C; symbol: func_020e385c; size: 0x44.
extern "C" char* Network_FindTaggedAcknowledgement(char* p,int tag,int key){for(int i=0;i<4;++i,p+=8){if((unsigned char)p[4]==tag){if(*(int*)p==key || key==-1)return p;}}return 0;}
