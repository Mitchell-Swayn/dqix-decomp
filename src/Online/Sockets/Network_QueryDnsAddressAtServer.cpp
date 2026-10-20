#include <globaldefs.h>
ARM
#pragma force_active on
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void Network_InitializeCurrentThreadSocket();
extern "C" void Network_EnableUdpSocketMode();
extern "C" void Resource_UpdateSelectedRecordModesFromEnableState(int,unsigned short,unsigned);
extern "C" unsigned Network_QueryDnsRecord(const char*,unsigned,int,void*,unsigned);
extern "C" void Network_DeactivateCurrentThreadSocket();
// Original: arm9/ov031 @ 0x02204C20; symbol: func_ov031_02204c20; size: 0x64.
// Opens a temporary UDP socket at the supplied DNS server and queries an A record.
extern "C" unsigned Network_QueryDnsAddressAtServer(const char* hostname,unsigned server,int transactionId)
{
 if(!server)return -1;
 Network_InitializeCurrentThreadSocket();
 Network_EnableUdpSocketMode();
 Resource_UpdateSelectedRecordModesFromEnableState(0,53,server);
 unsigned result=Network_QueryDnsRecord(hostname,1,transactionId,0,0);
 Network_DeactivateCurrentThreadSocket();
 return result;
}
