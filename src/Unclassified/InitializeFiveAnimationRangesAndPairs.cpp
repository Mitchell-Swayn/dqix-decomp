#include <globaldefs.h>

ARM
static inline void SetPair(unsigned char *p,unsigned char value){p[0x94]=value;p[0x98]=value;}
extern "C" {
void InitializeEntryAndFourFlagSlots(void *,int,int,int);void Object_SetUnsignedIntAtOffsetCAndSetUnsignedIntAtOffset10AndSetUnsignedIntAtOffset14(void *,int,int,int);
// Original: arm9/main @ 0x0208AF78; symbol: func_0208af78; size: 0x110.
void InitializeFiveAnimationRangesAndPairs(unsigned char *p) {
    InitializeEntryAndFourFlagSlots(p+4,0,1,80);InitializeEntryAndFourFlagSlots(p+0x24,0,1,20);InitializeEntryAndFourFlagSlots(p+0x40,1,5,20);InitializeEntryAndFourFlagSlots(p+0x5c,2,5,20);InitializeEntryAndFourFlagSlots(p+0x78,3,3,20);
    Object_SetUnsignedIntAtOffsetCAndSetUnsignedIntAtOffset10AndSetUnsignedIntAtOffset14(p+4,31,0,20);Object_SetUnsignedIntAtOffsetCAndSetUnsignedIntAtOffset10AndSetUnsignedIntAtOffset14(p+0x24,31,0,20);Object_SetUnsignedIntAtOffsetCAndSetUnsignedIntAtOffset10AndSetUnsignedIntAtOffset14(p+0x40,28,28,0);Object_SetUnsignedIntAtOffsetCAndSetUnsignedIntAtOffset10AndSetUnsignedIntAtOffset14(p+0x5c,28,28,0);Object_SetUnsignedIntAtOffsetCAndSetUnsignedIntAtOffset10AndSetUnsignedIntAtOffset14(p+0x78,25,0,0);
    for(int i=0;i<4;i++)SetPair(p+i,40);
    p[0x9c]=0;p[0xa8]=0;*(unsigned *)(p+0xb0)=0;*(unsigned *)(p+0xac)=-1;
}
}
