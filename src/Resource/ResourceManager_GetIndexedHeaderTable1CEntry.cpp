struct Header { unsigned char unknown[0x1c]; int tableOffset; };
struct Owner { unsigned char unknown[0x8c]; Header *header; };
struct Table { unsigned int count; int offsets[1]; };
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Owner *NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020BD710; symbol: func_020bd710; size: 0x64.
extern "C" void *ResourceManager_GetIndexedHeaderTable1CEntry(int index) {
    Owner *owner = NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
    Header *header = owner->header;
    int offset = header->tableOffset;
    Table *table;
    if (offset == 0) table = 0;
    else table = (Table *)((char *)header + offset);
    if (!table) return 0;
    if (index < 0) return 0;
    if ((unsigned int)index >= table->count) return 0;
    offset = table->offsets[index];
    header = owner->header;
    if (offset == 0) return 0;
    else return (char *)header + offset;
}
