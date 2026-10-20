#include <globaldefs.h>
ARM
extern "C" void MIi_CpuCopy32(const void*,void*,unsigned);
extern "C" void MIi_CpuClear32(int,void*,unsigned);
struct Entry{unsigned char bytes[4];};
struct Payload{char bytes[192];};
// Original: arm9/ov031 @ 0x02213B20; symbol: InsertPriorityEntryAndClearSpare; size: 0xf0.
// Moves an entry backward by byte priority while swapping its 192-byte payload.
extern "C" void WirelessScan_RankAccessPoint(int index,char *object){
 int previous;unsigned temp; char payload[192]; Entry *entries=(Entry*)(object+0x444);Payload *values=(Payload*)(object+0x470);
 previous=index-1; if(previous>=0)do{
 if(entries[index].bytes[2]<entries[previous].bytes[2])break;
 MIi_CpuCopy32(entries+previous,&temp,4);
 MIi_CpuCopy32(entries+index,entries+previous,4);
 MIi_CpuCopy32(&temp,entries+index,4);
 MIi_CpuCopy32(values+previous,payload,192);
 MIi_CpuCopy32(values+index,values+previous,192);
 MIi_CpuCopy32(payload,values+index,192);
 index=previous;
 }while(--previous>=0);
 MIi_CpuClear32(0,entries+10,4);MIi_CpuClear32(0,values+10,192);
}
