#include <globaldefs.h>
ARM
// Original: arm9/ov002 @ 0x02155024; symbol: OV002_InitializeIfInactive; size: 0x38.
extern "C" void PartyMenu_RequestCloseIfIdle(void* base) { unsigned char* b=(unsigned char*)base; if(b[0x248f])return; if(b[0x248e])return; b[0x248e]=1; *(unsigned*)(b+0x1bb8)=42; *(unsigned*)(b+0x1bc0)=0; }
