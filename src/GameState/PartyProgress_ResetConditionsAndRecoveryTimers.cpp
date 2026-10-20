#include <globaldefs.h>

ARM
static inline void SetPair(unsigned char *p,unsigned char value){p[0x94]=value;p[0x98]=value;}
extern "C" {
void PartyProgress_InitializeConditionContext(void *,int,int,int);void PartyProgress_SetCompletionEffectColor(void *,int,int,int);
// Original: arm9/main @ 0x0208AF78; symbol: func_0208af78; size: 0x110.
void PartyProgress_ResetConditionsAndRecoveryTimers(unsigned char *p) {
    PartyProgress_InitializeConditionContext(p+4,0,1,80);PartyProgress_InitializeConditionContext(p+0x24,0,1,20);PartyProgress_InitializeConditionContext(p+0x40,1,5,20);PartyProgress_InitializeConditionContext(p+0x5c,2,5,20);PartyProgress_InitializeConditionContext(p+0x78,3,3,20);
    PartyProgress_SetCompletionEffectColor(p+4,31,0,20);PartyProgress_SetCompletionEffectColor(p+0x24,31,0,20);PartyProgress_SetCompletionEffectColor(p+0x40,28,28,0);PartyProgress_SetCompletionEffectColor(p+0x5c,28,28,0);PartyProgress_SetCompletionEffectColor(p+0x78,25,0,0);
    for(int i=0;i<4;i++)SetPair(p+i,40);
    p[0x9c]=0;p[0xa8]=0;*(unsigned *)(p+0xb0)=0;*(unsigned *)(p+0xac)=-1;
}
}
