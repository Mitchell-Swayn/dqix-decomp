#include <globaldefs.h>
ARM
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" char* strcpy(char*, const char*);
extern "C" void Field_QueueOrReplacePartyJoinRequest(void*, const char*);
// Original: arm9/ov017 @ 0x021CC148; symbol: func_ov017_021cc148; size: 0x50.
extern "C" void Field_UpsertHostMemberNameRecord(unsigned char value, unsigned char* source, int unused, void* output, unsigned* state) {
    char record[0x10];
    if (Network_IsParentOrOffline(state)) {
        record[0] = value;
        record[1] = source[5];
        strcpy(record + 2, (char*)source + 6);
        Field_QueueOrReplacePartyJoinRequest(output, record);
    }
}
