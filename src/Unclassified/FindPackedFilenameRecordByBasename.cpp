// Reviewed original ARM field widths and source behavior; float initialization is a real 1.0 constant.
extern "C" {int strcmp(const char*,const char*);void* memset(void*,int,unsigned);void func_02030b0c(void*);}
// Original: arm9/main @ 0x0204673C; symbol: func_0204673c; size: 0x84.
extern "C" char* FindPackedFilenameRecordByBasename(char* p,const signed char* path){if(!p)return 0;if(!path)return 0;if(!*path)return 0;const signed char* name=path;while(*path){if(*path==47)name=path+1;++path;}while(*p){if(!strcmp(p,(const char*)name))return p;p+=*(int*)(p+72);}return 0;}
