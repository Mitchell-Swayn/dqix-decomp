#include <globaldefs.h>
ARM
#include <World/ZoneFeatures.h>
extern "C" char* ReadGlobalValueAt020FB3F0();extern "C" void UpdateIndexedByteFlagOrDispatchPackedRecord(unsigned char*,unsigned char,unsigned char,unsigned char);
// Original: arm9/main @ 0x020A86B8; symbol: func_020a86b8; size: 0x88.
extern "C" void UpdateMatchingZoneOpcode6AEntries(void* unused,int enabled,unsigned a,unsigned b,unsigned c,unsigned char x,unsigned char y,unsigned char z){ZoneFeatures* features=(ZoneFeatures*)(ReadGlobalValueAt020FB3F0()+0x6c);int i=0;for(;;){ZoneFeatures::Opcode6aEntry* q=features->GetOpcode6aEntry(i++);if(!q)return;char* raw=(char*)q;if(*(int*)(raw+4)!=12)continue;unsigned char* data=(unsigned char*)raw+44;if(!data)return;if(enabled&&data[0]==a&&data[1]==b&&data[2]==c&&a==1){UpdateIndexedByteFlagOrDispatchPackedRecord(data,x,y,z);return;}}}
