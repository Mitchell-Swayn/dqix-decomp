typedef signed int s32;
typedef unsigned char u8;

struct RecordList
{
    u8 reserved[0x20];
    u8* records;
    s32 count;
};

extern "C" void* func_02027878(RecordList* list, s32 index)
{
    if (index < 0)
        goto invalid;
    if (list->count > index)
        goto valid;
invalid:
    return 0;
valid:
    return list->records + index * 0x24;
}
