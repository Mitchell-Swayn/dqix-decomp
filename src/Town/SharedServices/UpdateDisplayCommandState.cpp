#include <globaldefs.h>
ARM
extern "C" unsigned int DisplayContext_GetGlobalInstance();
extern "C" void DisplayContext_IgnoreCommand(unsigned,int,int,int,int);
extern "C" int DisplayContext_ReportRequestComplete(unsigned);
struct CommandState { char pad[6]; signed char state; char pad2; unsigned short flags; };
// Original: arm9/ov003 @ 0x0217DC94; symbol: func_ov003_0217dc94; size: 0x7C.
extern "C" void UpdateDisplayCommandState(CommandState* p) {
 if(p->flags&1) {
 if(p->state==0) { DisplayContext_IgnoreCommand(DisplayContext_GetGlobalInstance(),501,102,0,0); p->state=1; }
 else if(p->state==1) { if(DisplayContext_ReportRequestComplete(DisplayContext_GetGlobalInstance())) { p->flags &= ~1; p->state=-1; } }
 }
}
