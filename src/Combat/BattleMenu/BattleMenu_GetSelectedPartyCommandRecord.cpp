#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
struct Entry {
    char pad[0x4c];
    unsigned key;
    char tail[0x3f8];
};
// Original: arm9/ov000 @ 0x0217F8C0; symbol: func_ov000_0217f8c0; size: 0x50.
extern "C" Entry* BattleMenu_GetSelectedPartyCommandRecord(char* obj) {
    for(int i=0; i<4; i++) {
        Entry* p=(Entry*)(obj+0x958+((signed char*)(obj+i))[0x6c]*0x448);
        if(*(unsigned*)(obj+0x17c)==p->key)return p;
    }
    return 0;
}
