#include <globaldefs.h>
ARM
struct Flags {unsigned char active:1,quality:6,seen:1;};
struct Record {Flags flags;char name[48];unsigned char mac[6];};
struct PeerFlags {unsigned char pad:3,blocked:1,ready:1,eligible:1,rest:2;};
struct Peer {char pad[4];unsigned char mac[6];char gap[0x39];unsigned char invalid;char tail[12];unsigned char name[16];char pad60[3];signed char quality;char pad64;PeerFlags flags;};
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_GetDiscoveredPeerCount(void*);
extern "C" Peer* Network_GetDiscoveredPeerDescriptor(void*,int);
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
extern "C" void __clear(void*,unsigned);
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
extern "C" int sprintf(char*,const char*,...);
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/ov003 @ 0x0215F698; symbol: func_ov003_0215f698; size: 0x234.
extern "C" void Network_SynchronizeDiscoveredPeerNames(Record* records,short* count) {
 void* connection=Network_GetConnectionManager();
 int total=Network_GetDiscoveredPeerCount(connection);
 Record* record=records;
 for(short i=0;i<10;i++,record++)record->flags.active=0;
 for(int i=0;i<total;i++) {
 Peer* peer=Network_GetDiscoveredPeerDescriptor(connection,i);
 int found=0;
 for(short j=0;j<*count;j++) {
 record=&records[j];
 if(peer->invalid==0&&RuntimeMemory_CompareByteRanges(record->mac,peer->mac,6)==0&&!peer->flags.blocked&&peer->flags.ready&&peer->flags.eligible) {
 record->flags.seen=1;record->flags.active=1;
 unsigned char text[48];__clear(text,48);
 Text_MapInputBytesToVariableLengthOutputSequences(peer->name,text,1);
 sprintf(record->name,(char*)text);
 memcpy(record->mac,peer->mac,6);
 record->flags.quality=(unsigned char)peer->quality;
 found=1;break;
 }
 }
 if(!found&&*count<10&&peer->invalid==0&&!peer->flags.blocked&&peer->flags.ready&&peer->flags.eligible&&peer->quality>0) {
 Record* record=&records[*count];
 record->flags.seen=1;record->flags.active=1;
 unsigned char text[48];__clear(text,48);
 Text_MapInputBytesToVariableLengthOutputSequences(peer->name,text,1);
 sprintf(record->name,(char*)text);
 memcpy(record->mac,peer->mac,6);
 record->flags.quality=(unsigned char)peer->quality;
 ++*count;
 }
 }
}
