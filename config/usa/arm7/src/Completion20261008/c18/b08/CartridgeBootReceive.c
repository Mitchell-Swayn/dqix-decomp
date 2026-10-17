#pragma dont_inline on
#include "CartridgeService.h"
extern const char ARM7_CartridgeSourceFile[],ARM7_CartridgeInvalidCommand[];
extern void ARM7_Panic(const char*,int,const char*,...);
/* IPC callbacks take channel in r0, message in r1 and transport error in r2. */
// Original: arm7/wram @ 0x0380784C; symbol: ARM7_CartridgeBootReceive.
void ARM7_CartridgeBootReceive(int channel,unsigned int message,int error)
{
 if((message&63)==1) {
  ARM7_CartridgeServiceState.bootWord=message;
  ARM7_CartridgeServiceState.bootAcknowledged=1;
 } else ARM7_Panic(ARM7_CartridgeSourceFile,0x10c,ARM7_CartridgeInvalidCommand);
}
