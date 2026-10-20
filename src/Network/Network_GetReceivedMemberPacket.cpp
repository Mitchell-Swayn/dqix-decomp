// Original assembly and callee argument/return behavior reviewed.
extern "C" {int Network_GetAssociationId();int Network_FindWirelessSlotByMemberId(void*,int);char* DisplayLayout_FindPartById(void*,int);void* SystemState_GetGlobalFlags();void SystemState_SetFlags(void*,unsigned);char* LinkedList_FindNodeByUnsignedKey(void*,int);void* Network_GetConnectionManager();int Network_IsSessionActive(void*);char* PartySync_FindEntryByKey(void*,int);void* MessageTextTable_FindTextById(void*,int);}struct Nibbles{unsigned char low:4;unsigned char high:4;};
// Original: arm9/main @ 0x0202C178; symbol: func_0202c178; size: 0x24.
extern "C" char* Network_GetReceivedMemberPacket(char* p,int key){int i=Network_FindWirelessSlotByMemberId(p,key);if(i<0)return 0;return p+0xbc0+i*0x74;}
