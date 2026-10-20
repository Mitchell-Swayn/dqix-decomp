#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
#pragma force_active on
ARM
struct ZoneTransferPacket {
    unsigned char command;
    unsigned char reserved[3];
    unsigned char data[13];
    unsigned char length:4;
    unsigned char member:3;
    unsigned char last:1;
    unsigned short offset;
};
extern "C" int Network_GetLocalMemberId(char*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_DisableIncomingRecordType(unsigned char*,unsigned);
// Original: arm9/ov017 @ 0x021D3DCC; symbol: func_ov017_021d3dcc; size: 0x70.
// Copies a zone-state chunk addressed to this member and finishes its incoming transfer.
extern "C" void Network_ApplyZoneStateTransferChunk(int unused,unsigned char* record,void* game,void* resources,void* connection)
{
    const ZoneTransferPacket* packet=(const ZoneTransferPacket*)record;
    if(Network_GetLocalMemberId((char*)connection)!=packet->member) return;
    Zone3D* zone=(Zone3D*)Zone3D_GetMainInstance();
    zone->state_840_.CopyBytesAtOffset(packet->offset,(const unsigned char*)packet+4,packet->length);
    if(!packet->last) return;
    unsigned char* tail=(unsigned char*)&zone->state_840_;
    tail+=0x1000;
    tail[offsetof(ZoneState0840,unknown_1b62)-0x1000]=1;
    Network_DisableIncomingRecordType((unsigned char*)Network_GetCommandRecordPool(),0xb9);
}
