#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionManager();
extern "C" void Network_ClearMemberDisconnectFlag(unsigned char*, int);
extern "C" void Field_CopyPartyJoinRecord(void*, const char*);
extern "C" char* strcpy(char*, const char*);
// Original: arm9/ov017 @ 0x0219541C; symbol: GameState_SetOwnerTextSlotAndActiveRecordText; size: 0x78.
// For indices 1–3, writes text to the 15-byte owner slot, clears the connection bit, and copies trailing text into the active record when its tag and index match.
extern "C" void Field_UpdateMemberJoinNameAndCache(unsigned char* owner, int index, const char* text) {
    void* connection = Network_GetConnectionManager();
    int slotIndex = index - 1;
    if (slotIndex < 0 || slotIndex > 2) return;
    Field_CopyPartyJoinRecord(owner + 0x42f1 + slotIndex * 15, text);
    Network_ClearMemberDisconnectFlag((unsigned char*)connection, index);
    unsigned char* record = *(unsigned char**)(owner + 0x441c);
    if (record[0] != 1 || record[2] != index) return;
    strcpy((char*)record + 4, text + 2);
}
