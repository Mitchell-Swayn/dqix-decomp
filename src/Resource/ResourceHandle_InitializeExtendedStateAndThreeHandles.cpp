#include <globaldefs.h>

ARM
extern "C" {
void InitializeHandleAndSignedIndexDefaults(void *);void Initialize1RecordFields_Main020BC078(void *);void UpdateByteLevelTransitionAndThreeChannels(void *,unsigned,int);void SetModeOneThroughFiveAndRefreshValue(void *,int);
struct State { unsigned char pad[0xb0]; unsigned a,b; short c,d; unsigned e,f,g; unsigned char flag0:1;unsigned char flag1:1;unsigned char flag2:1;unsigned char flag3:1;unsigned char rest:4; unsigned char count;short value,padcc,end; };
// Original: arm9/main @ 0x0209C174; symbol: func_0209c174; size: 0x98.
void ResourceHandle_InitializeExtendedStateAndThreeHandles(State *p) {
    InitializeHandleAndSignedIndexDefaults(p);p->a=0;p->b=0;p->c=-1;Initialize1RecordFields_Main020BC078(&p->e);p->d=-1;Initialize1RecordFields_Main020BC078(&p->f);Initialize1RecordFields_Main020BC078(&p->g);
    p->flag0=0;UpdateByteLevelTransitionAndThreeChannels(p,127,0);SetModeOneThroughFiveAndRefreshValue(p,3);p->end=-1;p->count=0;p->value=0;p->flag2=0;p->flag3=0;
}
}
