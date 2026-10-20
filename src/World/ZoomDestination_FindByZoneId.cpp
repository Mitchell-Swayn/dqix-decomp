#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020A83FC; symbol: func_020a83fc; size: 0x5C.
extern "C" void* ZoomDestination_FindByZoneId(unsigned char* p,unsigned key){unsigned char* q=*(unsigned char**)p;if(key==5801)key=1800;if(key==4506)key=1800;for(int i=0;i<*(unsigned short*)(p+6);++i,q+=44){if(*(unsigned short*)(q+24)==key)return q;}return 0;}
