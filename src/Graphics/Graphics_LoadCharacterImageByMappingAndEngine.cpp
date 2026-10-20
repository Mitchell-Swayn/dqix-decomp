#include <globaldefs.h>
ARM
extern "C" void NNS_G2dInitImageProxy(void*);
extern "C" int Graphics_TestOptionalCharacterBlockUnavailable(void**,void*,void*);
extern "C" void Graphics_ApplyPackedDisplayConfigurationByMode(void*,int,int,void*);
extern "C" void Graphics_ApplyDisplayRegisterFlagsByMode(void*,void*,int,void*);
struct State {char pad[56];int kind;char pad3c[8];void* resource;char pad48[8];unsigned char mode;};
// Original: arm9/main @ 0x0205AAF8; symbol: func_0205aaf8; size: 0x80.
extern "C" int Graphics_LoadCharacterImageByMappingAndEngine(State* p,void* a,void* b) {
    void* output;
    NNS_G2dInitImageProxy(p);
    if(Graphics_TestOptionalCharacterBlockUnavailable(&output,a,b))return 1;
    int mode=p->mode==0?1:2;
    if(p->kind==4)Graphics_ApplyPackedDisplayConfigurationByMode(output,0,mode,p);
    else Graphics_ApplyDisplayRegisterFlagsByMode(output,p->resource,mode,p);
    return 0;
}
