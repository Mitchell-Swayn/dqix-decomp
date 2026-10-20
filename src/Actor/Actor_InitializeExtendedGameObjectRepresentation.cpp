#include <globaldefs.h>
extern "C" void GameObject_InitializePartyFollowAndLadderState(void);
ARM
#pragma optimize_for_size off
// Original: arm9/main @ 0x020415D8; symbol: func_020415d8; size: 0x50.
extern "C" void Actor_InitializeExtendedGameObjectRepresentation(unsigned char *p) {
    GameObject_InitializePartyFollowAndLadderState(); *(unsigned short *)(p+0x2d0)=0; *(unsigned int *)(p+0x2d4)=0; *(unsigned int *)(p+0x2e4)=0; *(unsigned char *)(p+0x2e8)=0; *(unsigned int *)(p+0x2f4)=0; *(unsigned int *)(p+0x2ec)=0x7a; *(unsigned char *)(p+0x2f0)=0;
    *(unsigned short *)p |= 0x4000; *(unsigned short *)p &= ~0x80;
}
