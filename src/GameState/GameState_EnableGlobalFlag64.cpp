// Original assembly and callee argument/return behavior reviewed.
extern "C" {int Network_GetAssociationId();int Network_FindWirelessSlotByMemberId(void*,int);char* DisplayLayout_FindPartById(void*,int);void* SystemState_GetGlobalFlags();void SystemState_SetFlags(void*,unsigned);char* LinkedList_FindNodeByUnsignedKey(void*,int);void* Network_GetConnectionManager();int Network_IsSessionActive(void*);char* PartySync_FindEntryByKey(void*,int);void* MessageTextTable_FindTextById(void*,int);}struct Nibbles{unsigned char low:4;unsigned char high:4;};
// Original: arm9/main @ 0x020DC2BC; symbol: func_020dc2bc; size: 0x14.
extern "C" void GameState_EnableGlobalFlag64(){SystemState_SetFlags(SystemState_GetGlobalFlags(),64);}
