#include <globaldefs.h>
static inline bool IsInactiveState(char* state) { return *(int*)(state+0x998)==0; }
extern "C" {
extern unsigned char data_02114e30[],data_02114e54[],data_02108760[];
int Object_TestNewlySetHalfwordMask(void*,int);
char* ReadWordFieldAtOffset1C();
void DispatchStoredHalfwordIndexWithTwoArguments(void*,int,int);
}

// Original: arm9/ov023 @ 0x021F4FC8; symbol: func_ov023_021f4fc8; size: 0x134.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM bool TestGlobalInputOrInactiveState(void)
{
    char* state=ReadWordFieldAtOffset1C();
    int result=0;
    int mode=*(int*)(state+0x9a0);
    if(mode==3 || mode==0)
    {
        if(Object_TestNewlySetHalfwordMask(data_02114e30,1)||Object_TestNewlySetHalfwordMask(data_02114e30,2)||Object_TestNewlySetHalfwordMask(data_02114e30,0x200)||Object_TestNewlySetHalfwordMask(data_02114e30,0x100)||Object_TestNewlySetHalfwordMask(data_02114e30,0x400)||Object_TestNewlySetHalfwordMask(data_02114e30,0x40)||Object_TestNewlySetHalfwordMask(data_02114e30,0x80)||Object_TestNewlySetHalfwordMask(data_02114e30,0x20)||Object_TestNewlySetHalfwordMask(data_02114e30,0x10)) result=1;
        if(data_02114e54[0x54]) result=1;
    }
    if(result)
    {
        DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,1,0);
        return true;
    }
    return (int)IsInactiveState(state) != 0;
}
