#include <globaldefs.h>
ARM
#include <System/Cache.h>
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,int,int,int); extern "C" void WirelessCommand_ValidateThreeConfigurationBounds(void*),WMi_SetCallbackTable(int,int);extern "C" int WMi_SendCommand(int,int,void*);
// Original: arm9/main @ 0x020D507C; symbol: func_020d507c; size: 0xDC.
extern "C" int ValidateTwoLengthFieldsAndDispatchCommandSeven(int id,char* p,int a,int b){
 int result=TestCurrentStatusAgainstVariadicAllowedValues(1,2,a,b);if(result)return result;if(!p)return 6;
 if(*(unsigned short*)(p+4)&&!*(void**)p)return 6;
 unsigned short enabled=*(unsigned short*)(p+20);
 if((int)*(unsigned short*)(p+52)+(enabled?42:0)>512||(int)*(unsigned short*)(p+54)+(enabled?6:0)>512)return 6;
 WirelessCommand_ValidateThreeConfigurationBounds(p);WMi_SetCallbackTable(7,id);CleanCacheRange(p,64);
 if(*(unsigned short*)(p+4))CleanCacheRange(*(void**)p,*(unsigned short*)(p+4));
 result=WMi_SendCommand(7,1,p);if(!result)result=2;return result;
}
