// Original assembly and callee argument/return behavior reviewed.
extern "C" {int Network_GetAssociationId();int Network_FindWirelessSlotByMemberId(void*,int);char* DisplayLayout_FindPartById(void*,int);void* SystemState_GetGlobalFlags();void SystemState_SetFlags(void*,unsigned);char* LinkedList_FindNodeByUnsignedKey(void*,int);void* Network_GetConnectionManager();int Network_IsSessionActive(void*);char* PartySync_FindEntryByKey(void*,int);void* MessageTextTable_FindTextById(void*,int);}struct Nibbles{unsigned char low:4;unsigned char high:4;};
// Original: arm9/main @ 0x02080828; symbol: func_02080828; size: 0x2C.
extern "C" void TextCanvas_GetEntryLocalPosition(char* p,int i,short* a,short* b){char* q=DisplayLayout_FindPartById(p+4,i);if(q){*a=*(short*)(q+6);*b=*(short*)(q+8);}}
