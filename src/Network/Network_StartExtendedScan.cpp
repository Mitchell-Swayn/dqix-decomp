#include <globaldefs.h>
ARM
struct ScanParam { void* buffer; unsigned short size,channel,time; unsigned char bssid[6]; unsigned short type,length; unsigned char ssid[32]; unsigned short match; };
struct Request { unsigned short command,channel;void* buffer;unsigned short size,time; unsigned char bssid[6];unsigned short type,length;unsigned char ssid[32];unsigned short match; unsigned reserved; };
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" void WMi_SetCallbackTable(int,unsigned);
extern "C" int WMi_SendCommandDirect(const void*,unsigned);
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(unsigned,...);
// Original: arm9/main @ 0x020D5340; symbol: func_020d5340; size: 0x150.
extern "C" int Network_StartExtendedScan(unsigned callback,ScanParam* param) {
 Request request;
 int result=TestCurrentStatusAgainstVariadicAllowedValues(3,2,3,5);
 if(result)return result;
 if(!param)return 6;
 if(!param->buffer)return 6;
 if(param->size>1024)return 6;
 if(param->length>32)return 6;
 unsigned short type=param->type;
 if(type!=0 && type!=1 && type!=2 && type!=3)return 6;
 if((unsigned short)(type+65534)<=1 && param->match>32)return 6;
 WMi_SetCallbackTable(38,callback);
 request.command=38;
 request.channel=param->channel;
 request.buffer=param->buffer;
 request.size=param->size;
 request.time=param->time;
 MI_CpuCopy8(param->bssid,request.bssid,6);
 request.type=param->type;
 request.match=param->match;
 request.length=param->length;
 MI_CpuCopy8(param->ssid,request.ssid,32);
 result=WMi_SendCommandDirect(&request,60);
 if(result==0)return 2;
 return result;
}
