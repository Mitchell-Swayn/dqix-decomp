#include <globaldefs.h>
ARM
extern unsigned char data_02114e54[];extern "C" void ReadSelectedCoordinatePair(void*,int*,int*);extern "C" int Input_FindContainingOriginRelativeRectangle(unsigned,int,int);
// Original: arm9/main @ 0x020E1E4C; symbol: func_020e1e4c; size: 0x64.
extern "C" int Input_ResolveCoordinateHitIndexOrNegativeStatus(unsigned key){int x,y;if(data_02114e54[0x55]){ReadSelectedCoordinatePair(data_02114e54,&x,&y);int result=Input_FindContainingOriginRelativeRectangle(key,(short)x,(short)y);if(result<0)result=-2;return result;}return -1;}
