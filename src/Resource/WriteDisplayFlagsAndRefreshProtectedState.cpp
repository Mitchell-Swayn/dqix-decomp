#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void System_PushInterruptFourEnabledStateAndDisable();extern "C" void Interrupts_UpdateTimerOneFromShiftingGlobalMask();extern "C" void SetSelectedBackgroundRecordAndEnablePairedRecord(void*,int);extern "C" int Graphics_ReadSelectedScreenPowerState(void*);
// Original: arm9/main @ 0x020DB264; symbol: func_020db264; size: 0x70.
extern "C" void WriteDisplayFlagsAndRefreshProtectedState(unsigned char* p,int a,int b,int c,int d){if(p[80]&&a)return;System_PushInterruptFourEnabledStateAndDisable();if(!c)*(unsigned short*)(p+102)=0;p[80]=a;p[82]=b;p[83]=c;p[84]=d;SetSelectedBackgroundRecordAndEnablePairedRecord(p,a==0);p[60]=Graphics_ReadSelectedScreenPowerState(p);Interrupts_UpdateTimerOneFromShiftingGlobalMask();}
