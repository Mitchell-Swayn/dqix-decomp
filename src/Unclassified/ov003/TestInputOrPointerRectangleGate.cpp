#include <globaldefs.h>
extern "C" unsigned char data_02114e30[];
extern "C" unsigned char data_02114e54[];
extern "C" int Object_TestNewlySetHalfwordMask(void*,int);
extern "C" int ReadBit(void*);
extern "C" int Input_TestPressedKeyBitOne(void*);
extern "C" void ReadSelectedCoordinatePair(void*,int*,int*);
extern "C" int Geometry_TestPointWithinScaledTextureRectangle(void*,short,short,short);
// Original: arm9/ov003 @ 0x021766E8; symbol: func_ov003_021766e8; size: 0xB0.
extern "C" ARM int TestInputOrPointerRectangleGate(unsigned char* self) { int result=0; if(Object_TestNewlySetHalfwordMask(data_02114e30,2)) result=1; void* input=*(void**)self; if(input && ReadBit(input)) { if(Input_TestPressedKeyBitOne(*(void**)self)) result=1; } else if(data_02114e54[0x55]) { int x,y; ReadSelectedCoordinatePair(data_02114e54,&x,&y); if(!Geometry_TestPointWithinScaledTextureRectangle(*(void**)(self+0x89c),*(short*)(self+0xffe),(short)x,(short)y)) result=1; } return result; }
