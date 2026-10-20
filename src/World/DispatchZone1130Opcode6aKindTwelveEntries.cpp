#include <globaldefs.h>
#include <World/ZoneFeatures.h>
struct Owner {char pad[4];unsigned short id;char pad2[0x66];ZoneFeatures features;};extern "C" Owner* Zone3D_GetMainInstance();extern "C" void ZoneFeatures_QueueTriggerSynchronization(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020A8740; symbol: func_020a8740; size: 0x8C.
extern "C" void DispatchZone1130Opcode6aKindTwelveEntries() {Owner* owner=Zone3D_GetMainInstance();int i=0;while(true){ZoneFeatures::Opcode6aEntry* entry=owner->features.GetOpcode6aEntry(i++);if(!entry)return;if(*(int*)((char*)entry+4)!=12)continue;unsigned char* data=(unsigned char*)entry+0x2c;unsigned id=owner->id;if(!data)return;if(id==0x1130 && data[0]==1)ZoneFeatures_QueueTriggerSynchronization(data[0],data[1],data[2],2,0,0,0);}}
