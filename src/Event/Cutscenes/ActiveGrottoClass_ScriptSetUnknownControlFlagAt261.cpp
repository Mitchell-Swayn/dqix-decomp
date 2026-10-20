#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance();
// Original: arm9/ov001 @ 0x02161F64; symbol: SetGlobalControlByte264D; size: 0x1C.
// Sets byte offset 0x264D in the returned global control block and returns one.
extern "C" int ActiveGrottoClass_ScriptSetUnknownControlFlagAt261(void) {
    char *base=(char *)Zone3D_GetMainInstance()+0x3ec; char *sub=base+0x2000; *(unsigned char *)(sub+0x261)=1; return 1;
}
