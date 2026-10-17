#include <globaldefs.h>
ARM
struct Flags{unsigned mode:3;unsigned low:10;unsigned bits:8;unsigned high:11;};
// Original: arm9/main @ 0x0209BDC8; symbol: func_0209bdc8; size: 0x60.
extern "C" void* FindRecordMatchingModeAndBitMask(unsigned char* p,int mode,unsigned mask){unsigned required=mode==0;for(int i=0;i<*(int*)(p+192);++i){unsigned char* q=p+i*32;Flags* f=(Flags*)(q+4);if(required==f->mode||f->mode==2){if(mask&f->bits)return q;}}return 0;}
