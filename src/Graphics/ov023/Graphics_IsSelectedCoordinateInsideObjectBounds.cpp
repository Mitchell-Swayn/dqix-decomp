#include <globaldefs.h>
ARM
extern "C" void func_ov023_021fd420(unsigned char*,unsigned short*,unsigned short*,unsigned short*,unsigned short*);
extern "C" int ReadSelectedCoordinatePair(void*,int*,int*);
extern "C" char data_02114e54[];
// Original: arm9/ov023 @ 0x021FD46C; symbol: func_ov023_021fd46c; size: 0x8C.
extern "C" int Graphics_IsSelectedCoordinateInsideObjectBounds(unsigned char* object) {
if(object[12]&16)return 0;
int x,y;
unsigned short left,top,right,bottom;
func_ov023_021fd420(object,&left,&top,&right,&bottom);
ReadSelectedCoordinatePair(data_02114e54,&x,&y);
if(left<=x && x<right && top<=y && y<bottom)return 1;
return 0;
}
