#include <globaldefs.h>
ARM
extern "C" {void* DisplayContext_GetGlobalInstance();void DisplayContext_IgnoreTransitionParameter(void*,int);void DisplayContext_IgnoreRequest(void*,int,int);int DisplayContext_ReportRequestComplete(void*);
// Original: arm9/main @ 0x02092F00; symbol: func_02092f00; size: 0x80.
void GameState_AdvancePartyTransitionDisplayRequest(unsigned char* p){if(p[0x37]&8)return;if(!(p[0x37]&4))return;void* q=DisplayContext_GetGlobalInstance();if(p[0x36]==0){DisplayContext_IgnoreTransitionParameter(q,10);DisplayContext_IgnoreRequest(q,0x1f8,0);p[0x36]++;return;}if(p[0x36]==1){if(DisplayContext_ReportRequestComplete(q)){p[0x37]&=~4;p[0x36]=0;}return;}}}
