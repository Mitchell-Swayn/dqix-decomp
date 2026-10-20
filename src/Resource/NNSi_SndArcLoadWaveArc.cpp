#include <globaldefs.h>
ARM
struct Code {unsigned id:24;unsigned flags:8;};
extern "C" Code* NNS_SndArcGetWaveArcInfo(void*);
extern "C" int NNS_SndArcGetFileAddress(unsigned);
extern "C" int ResourceManager_GetOrCreateSecondaryCachedValue(unsigned,int,int);
extern "C" int SoundArchive_LoadWaveArchiveIndex(unsigned,int,int);
// Original: arm9/main @ 0x020BE010; symbol: func_020be010; size: 0x8C.
extern "C" int NNSi_SndArcLoadWaveArc(void* resource,unsigned flags,int a,int b,int* out) {
    Code* p=NNS_SndArcGetWaveArcInfo(resource);if(!p)return 5;
    int result;
    if(flags&4){if(p->flags&1)result=SoundArchive_LoadWaveArchiveIndex(p->id,a,b);else result=ResourceManager_GetOrCreateSecondaryCachedValue(p->id,a,b);if(!result)return 9;}
    else result=NNS_SndArcGetFileAddress(p->id);
    if(out)*out=result;return 0;
}
