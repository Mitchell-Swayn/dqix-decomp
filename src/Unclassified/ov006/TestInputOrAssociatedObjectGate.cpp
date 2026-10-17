#include <globaldefs.h>
extern "C" {
extern unsigned char data_02114e30[],data_02114e54[],data_02108760[];
int Object_TestNewlySetHalfwordMask(void*,int);
int ReadBit(void*);
int Input_TestPressedKeyBitOne(void*);
void ReadSelectedCoordinatePair(void*,int*,int*);
int Geometry_TestPointWithinScaledTextureRectangle(void*,short,short,short);
}

// Original: arm9/ov006 @ 0x02158B78; symbol: func_ov006_02158b78; size: 0xB0.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM int TestInputOrAssociatedObjectGate(char* p)
{
    int result=0;
    if(Object_TestNewlySetHalfwordMask(data_02114e30,2)) result=1;
    void* object=*(void**)(p+0x18);
    if(object && ReadBit(object))
    {
        if(Input_TestPressedKeyBitOne(*(void**)(p+0x18))) result=1;
    }
    else if(data_02114e54[0x55])
    {
        int x,y;
        ReadSelectedCoordinatePair(data_02114e54,&x,&y);
        if(!Geometry_TestPointWithinScaledTextureRectangle(*(void**)(p+0x14),*(short*)(p+0x36e),(short)x,(short)y)) result=1;
    }
    return result;
}
