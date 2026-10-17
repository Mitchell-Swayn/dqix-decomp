#include <globaldefs.h>
ARM
struct A;
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short* p,unsigned int mask);
extern "C" int ReadSelectedCoordinatePair(void *, int *, int *);
extern "C" int Geometry_TestPointWithinScaledTextureRectangle(void* owner,int index,int x,int y);
extern "C" unsigned int ReadBit(A **p);
extern "C" bool Input_TestPressedKeyBitOne(void*);
extern "C" unsigned short data_02114e30[];
extern "C" unsigned char data_02114e54[];
// Original: arm9/ov003 @ 0x02155208; symbol: func_ov003_02155208; size: 0xB0.
extern "C" int Input_TestNewKeyOrOutsideTextureRectangle(char *self) {
    int result = 0;
    if (Object_TestNewlySetHalfwordMask(data_02114e30,2)) result = 1;
    void *input = *(void **)(self + 0x1c);
    if (input && ReadBit((A **)input)) {
        if (Input_TestPressedKeyBitOne(*(void **)(self + 0x1c))) result = 1;
    } else {
        if (data_02114e54[0x55]) {
            int x,y;
            ReadSelectedCoordinatePair(data_02114e54,&x,&y);
            if (!Geometry_TestPointWithinScaledTextureRectangle(*(void **)(self + 0x18),*(short *)(self + 0x1e6),(short)x,(short)y)) result = 1;
        }
    }
    return result;
}
