#include <globaldefs.h>
ARM
extern "C" int strcmp(const char*,const char*);
// Original: arm9/main @ 0x020480B8; symbol: func_020480b8; size: 0x4C.
extern "C" int Resource_FindAnimationNameIndex(unsigned char* p,const char* text){for(int i=0;i<*(int*)p;++i){if(strcmp(text,*(char**)(p+4)+i*30)==0)return i;}return 0;}
