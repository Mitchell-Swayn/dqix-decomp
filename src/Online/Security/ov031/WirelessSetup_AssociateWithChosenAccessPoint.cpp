#include <globaldefs.h>
ARM
#include <System/ProcessorContext.h>
extern "C" int Network_ConfigureSharedWorkWithSwappedWords(char*);
THUMB
#pragma optimize_for_size off
extern "C" int StageWirelessRequestWithNinetySixByteOptions(const void*,const void*,int);
extern "C" unsigned WirelessSetup_PopEvent();
extern "C" unsigned long long Time_GetScaledCurrentTimestamp();

extern "C" void WirelessSetup_EnqueueTimeoutEvent(void*);
extern "C" unsigned char WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[],Ov031UpdateModeFromStatus_UnknownRoleDataReferences[];
extern "C" char WirelessSetupAssociateWithChosenAccessPoint_UnknownRoleDataReferences[];
#define FIELD(T,o) (*(T*)(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage+(o)))
// Original: arm9/ov031 @ 0x0221FB90; symbol: WirelessSetup_AssociateWithChosenAccessPoint; size: 0x124.
// Stages the indexed wireless request, polls timed events, then configures shared work on success.
// Event meanings and alarm userdata0x12 remain unresolved; the alarm callback uses generic userdata ABI.
extern "C" int WirelessSetup_AssociateWithChosenAccessPoint() {
 int active=1,result=-2;
 char* config=FIELD(char*,0x5c)+FIELD(int,0x18)*0xc0;
 if(!config)return 0;
 if(!StageWirelessRequestWithNinetySixByteOptions(config,0,0x30000))return -2;
 Alarm alarm;
 ZeroInitializeAlarm(&alarm);
 SetTimeout(&alarm,0x3fec42,(Alarm::PFNCompletion)WirelessSetup_EnqueueTimeoutEvent,(ProcessorContext**)0x12);
 do {
  if((unsigned)Time_GetScaledCurrentTimestamp()>=*(unsigned*)(Ov031UpdateModeFromStatus_UnknownRoleDataReferences+12)){result=-3;break;}
  if(FIELD(int,0x10)){result=-8;break;}
  SleepCurrentContext(10);
  int event=(int)WirelessSetup_PopEvent();
  if(event!=0)do {
   switch(event) {
   case 12:active=0;result=1;break;
   case 13:
    if(FIELD(int,0x10)){active=0;result=-8;}
    else if(!StageWirelessRequestWithNinetySixByteOptions(config,0,0x30000))return result;
    break;
   case 4:case 5:case 18:case 19:break;
   default:active=0;break;
   }
   event=(int)WirelessSetup_PopEvent();
  }while(event!=0);
 }while(active);
 CancelAlarm(&alarm);
 while(WirelessSetup_PopEvent()!=0){}
 if(result>0) {
  FIELD(int,0x20)=1;
  if(Network_ConfigureSharedWorkWithSwappedWords(WirelessSetupAssociateWithChosenAccessPoint_UnknownRoleDataReferences)<0)result=-2;
  else FIELD(int,0x24)=1;
 }
 return result;
}
