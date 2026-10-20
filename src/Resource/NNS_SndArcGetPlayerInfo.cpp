#pragma thumb off

// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char* NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020BD648; symbol: func_020bd648; size: 0x64.
extern "C" void* NNS_SndArcGetPlayerInfo(int index) {
    char* owner = NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
    char* base = *(char**)(owner + 0x8c);
    int offset = *(int*)(base + 0x18);
    unsigned* table = !offset ? 0 : (unsigned*)(base + offset);
    if (!table) return 0;
    if (index < 0) return 0;
    if ((unsigned)index >= table[0]) return 0;
    unsigned entry = *(unsigned*)((char*)(table + 1) + index * 4);
    base = *(char**)(owner + 0x8c);
    return !entry ? 0 : base + entry;
}
