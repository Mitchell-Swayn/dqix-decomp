#include <globaldefs.h>
#pragma optimize_for_size off
struct CartridgeInfo {unsigned short id;unsigned char unknown[3];unsigned char checked:1,changed:1,rest:6;unsigned short pad;unsigned code;};
extern "C" unsigned char data_02112148[];
extern "C" void AcquireGBABusOrDetectOtherOwner(unsigned short,unsigned*);
extern "C" void System_SaveBusControlBitsAndSetDefaultBusMode(unsigned*);
extern "C" void GamecardBus_SetTimingFields(const unsigned*);
extern "C" void System_ReleaseGBABusAndRestoreIRQState(unsigned short,unsigned*);
// Original: arm9/main @ 0x020D135C; symbol: func_020d135c; size: 0x10C.
extern "C" ARM int ValidateCartridgeIdentityUnderBusLock() {
 unsigned interruptState[2];
 unsigned busTiming[2];
 int result=1;
 CartridgeInfo* info=(CartridgeInfo*)0x027ffc30;
 if(info->id==0xffff)return 0;
 if(info->changed==1)return 0;
 AcquireGBABusOrDetectOtherOwner(*(unsigned short*)(data_02112148+6),interruptState);
 System_SaveBusControlBitsAndSetDefaultBusMode(busTiming);
 unsigned char* rom=(unsigned char*)0x08000000;
 unsigned marker=rom[0xb2];
 if((marker==0x96 && info->id!=*(volatile unsigned short*)(rom+0xbe)) || (marker!=0x96 && info->id!=*(volatile unsigned short*)0x0801fffe) || (info->code!=*(volatile unsigned*)(rom+0xac) && info->checked)){
  result=0;info->changed=1;
 }
 GamecardBus_SetTimingFields(busTiming);
 System_ReleaseGBABusAndRestoreIRQState(*(unsigned short*)(data_02112148+6),interruptState);
 return result;
}
