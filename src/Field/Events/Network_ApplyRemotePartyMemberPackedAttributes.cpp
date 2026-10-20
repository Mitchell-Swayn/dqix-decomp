#include <globaldefs.h>
ARM
extern "C" int Network_GetLocalMemberId(char*);
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" char* GameObject_ResolveLinkedStatsOrNull(char**);
// Original: arm9/ov017 @ 0x021C44D8; symbol: GameState_ApplyIndexedRecordFields; size: 0xDC.
// Checks the record's index and item against a supplied indexed record, then writes packed flags and three signed fields.
extern "C" void Network_ApplyRemotePartyMemberPackedAttributes(void* unused, unsigned char* record, void* state, void* owner, char* indexed) {
    int index = ((signed char*)record)[0x10];
    if (((signed char*)record)[0x10] >= 0 && ((signed char*)record)[0x10] != Network_GetLocalMemberId(indexed)) return;
    unsigned char item = (unsigned char)record[4];
    if (item == Network_GetLocalMemberId(indexed)) return;
    void* object = GameState_GetObjectWithFlag100(state, item);
    if (!object) return;
    unsigned char* fields = (unsigned char*)GameObject_ResolveLinkedStatsOrNull((char**)object);
    if (!fields) return;
    fields[0x15] = (fields[0x15] & ~0x0f) | (record[5] & 0x0f);
    fields[0x14] = (fields[0x14] & ~0xf0) | ((record[6] & 0x0f) << 4);
    fields[0x14] = (fields[0x14] & ~0x0e) | ((record[7] & 0x07) << 1);
    fields[0x14] = (fields[0x14] & ~0x01) | (record[8] & 1);
    *(short*)(fields+0x16) = *(short*)(record+0xa);
    *(short*)(fields+0x18) = *(short*)(record+0xc);
    *(short*)(fields+0x1a) = *(short*)(record+0xe);
}
