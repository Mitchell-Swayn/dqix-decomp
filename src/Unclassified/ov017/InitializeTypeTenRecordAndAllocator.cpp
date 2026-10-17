#include <globaldefs.h>
#pragma optimize_for_size off
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
extern "C" void InitializeFourWordsWithInvalidIndex(signed char*);
extern "C" void Object_Initialize54ByteTypedRecordDefaults(char*);
// Original: arm9/ov017 @ 0x021B6F18; symbol: func_ov017_021b6f18; size: 0x84.
// Field roles are unresolved; observed offsets are retained.
extern "C" ARM void InitializeTypeTenRecordAndAllocator(unsigned char* p)
{
    InitializeFourWordsWithInvalidIndex((signed char*)p);
    p[0]=10;
    ((SafeAllocator*)(p+8))->ResetAllocatorPointer();
    Object_Initialize54ByteTypedRecordDefaults((char*)p+28);
    *(unsigned int*)(p+0x6ac)=0;
    *(unsigned int*)(p+0x6b0)=0;
    *(unsigned short*)(p+0x6b4)=1;
    *(unsigned short*)(p+0x6b6)=0;
    *(unsigned int*)(p+0x6b8)=0;
    p[0x6bd]=255;
    p[0x6bc]=255;
    *(signed char*)(p+0x6be)=-1;
    memset(p+0x6c0,0,3);
    p[0x6c3]=0;
    *(unsigned short*)(p+0x6c4)=0;
    p[0x6c7]=0;
    *(unsigned short*)(p+0x6c8)=0;
    p[0x6c6]=0;
}
