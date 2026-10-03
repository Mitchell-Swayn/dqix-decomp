// Only the fields accessed by these routines have established meanings.
struct DispatchRecord { unsigned char reserved[8]; unsigned char counts[2]; };
struct DispatchRequest { void* record; int mode; int kind; int index; int ordinal; unsigned char flags; };
extern "C" {
void __clear(void*, unsigned int);
unsigned char* func_ov000_02160094(void*, int);
unsigned char* func_ov000_021600f8(void*, int);
void func_ov025_021d8c30(void*, void*, int, int, int, int, int);
void func_ov025_021d8ab8(void*, DispatchRecord*, int, int, int);
void func_ov025_021d8a40(void* context, DispatchRecord* record)
{
    int counts[2] = { record->counts[1], record->counts[0] };
    for (int group = 0; group < 2; ++group) {
        for (int i = 0; i < counts[group]; ++i)
            func_ov025_021d8ab8(context, record, 1, 6, group);
    }
}
void func_ov025_021d8ab8(void* context, DispatchRecord* record, int mode, int kind, int index)
{
    int counts[6];
    __clear(counts, sizeof(counts));
    int* values = counts;
    if (mode == 0) {
        unsigned char* entry = func_ov000_02160094(record, index);
        if (entry) {
            values[0] = entry[0x26]; values[1] = entry[0x28];
            values[2] = entry[0x29]; values[3] = entry[0x2b];
            values[4] = entry[0x2a]; values[5] = entry[0x27];
        }
    } else if ((unsigned int)(mode - 1) <= 2) {
        unsigned char* entry = func_ov000_021600f8(record, index);
        if (entry) {
            values[0] = entry[0x18]; values[1] = entry[0x19]; values[2] = entry[0x1a];
        }
    }
    if (kind == 6) {
        for (int group = 0; group < 6; ++group)
            for (int i = 0; i < values[group]; ++i)
                func_ov025_021d8c30(context, record, mode, group, index, i, 0);
    } else {
        for (int i = 0; i < values[kind]; ++i)
            func_ov025_021d8c30(context, record, mode, kind, index, i, 0);
    }
}
void func_ov025_021d8bfc(void* context, const DispatchRequest* request)
{
    func_ov025_021d8c30(context, request->record, request->mode, request->kind,
                      request->index, request->ordinal, request->flags);
}
}
