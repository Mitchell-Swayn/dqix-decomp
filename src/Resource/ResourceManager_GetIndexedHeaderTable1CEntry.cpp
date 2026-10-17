struct Header { unsigned char unknown[0x1c]; int tableOffset; };
struct Owner { unsigned char unknown[0x8c]; Header *header; };
struct Table { unsigned int count; int offsets[1]; };
extern "C" Owner *data_02110370;
// Original: arm9/main @ 0x020BD710; symbol: func_020bd710; size: 0x64.
extern "C" void *ResourceManager_GetIndexedHeaderTable1CEntry(int index) {
    Owner *owner = data_02110370;
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
