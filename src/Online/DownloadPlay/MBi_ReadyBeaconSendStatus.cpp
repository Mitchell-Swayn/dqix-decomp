#include <globaldefs.h>
ARM
extern "C" int ValidateAndSubmitBounded112BytePayload(unsigned,void*,unsigned,unsigned,unsigned short,unsigned char);
extern "C" unsigned MBi_GetGgid();
extern "C" unsigned MBi_GetTgid();
extern "C" void MBi_ClearSendStatus(void);
// Original data: arm9/ov027 @ 0x21dd940; symbol: data_ov027_021dd940.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern unsigned char MBAddGameInfo_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov027 @ 0x21dd980; symbol: data_ov027_021dd980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern unsigned char MBiSendVolatBeacon_UnknownRoleZeroInitializedStorage[];
struct BeaconEntry { unsigned char pad[0x4b4]; unsigned char sequence; unsigned char pad1[7]; BeaconEntry *next; };
struct BeaconSend { unsigned char pad[24]; BeaconEntry * volatile head; BeaconEntry *current; unsigned char pad1[4]; unsigned char state,pad2,sequence; };
// Original: arm9/ov027 @ 0x021DAECC; symbol: func_ov027_021daecc; size: 0xA0.
// Selects the next queued beacon entry, or submits the empty beacon when no entry is queued.
extern "C" int MBi_ReadyBeaconSendStatus(void)
{
    #define send ((BeaconSend*)MBAddGameInfo_UnknownRoleZeroInitializedStorage)
    if(!send->head) {
        unsigned callback=MBi_GetGgid();
        unsigned a=MBi_GetTgid();
        // The reader returns a zero-extended halfword; preserve its full register
        // value in the stack argument while retaining the canonical declaration.
        ((int(*)(unsigned,void*,unsigned,unsigned,unsigned,unsigned))ValidateAndSubmitBounded112BytePayload)(0,MBiSendVolatBeacon_UnknownRoleZeroInitializedStorage,112,callback,a,8);
        return 0;
    }
    BeaconEntry *entry=send->current;
    if(entry && entry->next) entry=entry->next;
    else entry=send->head;
    send->current=entry;
    MBi_ClearSendStatus();
    send->sequence=send->current->sequence;
    send->state=2;
    return 1;
}
