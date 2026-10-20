#include <globaldefs.h>
// Preserves the original early-return epilogue and branch-oriented child filtering.
#pragma optimize_for_size off
#include <System/Memory.h>

struct Record { unsigned char kind, pad; unsigned short a, b; };
extern "C" unsigned char* SerializeTaggedHalfwordPair(Record*, unsigned char*);
extern "C" int MBi_BlockHeaderEnd(unsigned, unsigned, void*);
extern "C" unsigned char* MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
// Original data: arm9/ov027 @ 0x021DD8E0; symbol: data_ov027_021dd8e0; initialized selection cursor.
extern "C" unsigned char MBiCommParentSendDLFileInfo_UnknownRoleInitializedBytes[];
#pragma force_active on
// Original: arm9/ov027 @ 0x021D9704; symbol: func_ov027_021d9704; size: 0x198.
// Selects a requested download file in round-robin order and sends its file-information record to waiting children.
extern "C" int MBi_CommParentSendDLFileInfo()
{
    int selected = -1;
    unsigned short destinations = 0;
    unsigned char counts[16];
    Record record;
    VectorizedMemset(counts, 0, sizeof(counts));
    unsigned char* parent = MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
    unsigned short child = 1;
    do
    {
        if (*(int*)(parent + 0x14e4 + child * 4) == 5)
            ++counts[*(signed char*)(parent + 0x1525 + child)];
    } while (++child <= 15);
    unsigned char candidate = MBiCommParentSendDLFileInfo_UnknownRoleInitializedBytes[0];
    unsigned char i = 0;
    do
    {
        candidate = (candidate + 1) % 16;
        if (*(parent + candidate * 0x5d4 + 0x1d52) && counts[candidate])
        {
            selected = (signed char)candidate;
            break;
        }
    } while (++i < 16);
    if (selected == -1)
        return 21;
    MBiCommParentSendDLFileInfo_UnknownRoleInitializedBytes[0] = selected;
    child = 1;
    do
    {
        if (*(int*)(parent + 0x14e4 + child * 4) == 5)
        {
            if (selected == *(signed char*)(parent + 0x1525 + child))
                destinations |= 1 << child;
        }
    } while (++child <= 15);
    record.kind = 3;
    record.a = selected;
    unsigned char* payload = SerializeTaggedHalfwordPair(&record, parent);
    if (payload)
        MI_CpuCopy8(MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2 + 0x1788 + selected * 0x5d4, payload, 0xe4);
    return MBi_BlockHeaderEnd(0xea, destinations, MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2);
}
