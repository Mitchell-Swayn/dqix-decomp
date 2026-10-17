#include <globaldefs.h>
ARM
extern "C" {void* Object_ReadGlobalDisplayContextWord();void DisplayContext_IgnoreTransitionParameter(void*,int);void IgnoreDisplayContextRequest(void*,int,int);int ReturnOne_Main02094B4C(void*);
// Original: arm9/main @ 0x02092F00; symbol: func_02092f00; size: 0x80.
void AdvanceTwoPhasePendingTransitionUnlessBlocked(unsigned char* p){if(p[0x37]&8)return;if(!(p[0x37]&4))return;void* q=Object_ReadGlobalDisplayContextWord();if(p[0x36]==0){DisplayContext_IgnoreTransitionParameter(q,10);IgnoreDisplayContextRequest(q,0x1f8,0);p[0x36]++;return;}if(p[0x36]==1){if(ReturnOne_Main02094B4C(q)){p[0x37]&=~4;p[0x36]=0;}return;}}}
