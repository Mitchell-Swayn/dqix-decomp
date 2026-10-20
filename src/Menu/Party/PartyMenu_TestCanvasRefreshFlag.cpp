struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
// Original: arm9/ov002 @ 0x0216197C; symbol: Record_HasBit40AfterStopIndexLookup; size: 0x38.
extern "C" int PartyMenu_TestCanvasRefreshFlag(unsigned id, void* owner) { void* r=(void*)Window_FindActiveCanvasById((WindowCanvasOwner*)(owner),id); if(!r)return 0; return (*(unsigned char*)((char*)r+0xc5)&0x40)!=0; }
