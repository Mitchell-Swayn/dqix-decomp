#include <globaldefs.h>
extern "C" void InvokeStoredChildWithRenderArguments(int,char*,int,int,int,int,int,int,unsigned short);
// Original: arm9/main @ 0x0204C8F0; symbol: func_0204c8f0; size: 0x74.
extern "C" void DrawEnabledPresentRecordGeometry(void* object, int value) {
    char* p=(char*)object;
    if (*(int*)(p+4)==0) return;
    if ((*(unsigned char*)(p+0xC5)&1)!=0) {
        value=*(int*)(p+0x9C);
        if (value!=0 && (*(unsigned char*)(p+0xC5)&0x20)==0)
            InvokeStoredChildWithRenderArguments(*(int*)(p+4),p+0xC8,0,0,(int)*(short*)(p+0xAC),(int)*(short*)(p+0xAE),(int)*(short*)(p+0xC8),(int)*(short*)(p+0xC0),*(unsigned short*)(p+0xC2));
    }
}
