#include <globaldefs.h>

ARM
extern "C" {
void ResourceHandle_InitializeArchiveAndPlaybackState(void *);void ResourceHandle_InitializeSequenceHandle(void *);void Bgm_SetPlaybackVolumeAndFade(void *,unsigned,int);void Bgm_SetVolumeSetting(void *,int);
struct State { unsigned char pad[0xb0]; unsigned a,b; short c,d; unsigned e,f,g; unsigned char flag0:1;unsigned char flag1:1;unsigned char flag2:1;unsigned char flag3:1;unsigned char rest:4; unsigned char count;short value,padcc,end; };
// Original: arm9/main @ 0x0209C174; symbol: func_0209c174; size: 0x98.
void ResourceHandle_InitializeExtendedStateAndThreeHandles(State *p) {
    ResourceHandle_InitializeArchiveAndPlaybackState(p);p->a=0;p->b=0;p->c=-1;ResourceHandle_InitializeSequenceHandle(&p->e);p->d=-1;ResourceHandle_InitializeSequenceHandle(&p->f);ResourceHandle_InitializeSequenceHandle(&p->g);
    p->flag0=0;Bgm_SetPlaybackVolumeAndFade(p,127,0);Bgm_SetVolumeSetting(p,3);p->end=-1;p->count=0;p->value=0;p->flag2=0;p->flag3=0;
}
}
