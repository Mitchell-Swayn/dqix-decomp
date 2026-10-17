#include <globaldefs.h>
ARM
extern "C" void ReadSelectedCoordinatePair(void*,int*,int*);
// Original: arm9/main @ 0x02012B54; symbol: func_02012b54; size: 0x54.
extern "C" bool TestCoordinatePairOutsideDisplayBounds(void* p){int x,y;ReadSelectedCoordinatePair(p,&x,&y);if(x<2)return true;if(x>253)return true;if(y<2)return true;return y>189;}
