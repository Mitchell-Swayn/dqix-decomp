#pragma thumb off

extern "C" char* data_02110370;
// Original: arm9/main @ 0x020BD648; symbol: func_020bd648; size: 0x64.
extern "C" void* ReadBoundedGlobalTableEntryAtHeader18(int index) {
    char* owner = data_02110370;
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
