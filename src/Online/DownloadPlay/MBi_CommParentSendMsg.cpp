#include <globaldefs.h>
ARM
struct Record { unsigned char kind,pad; unsigned short a,b; };
extern "C" unsigned char *SerializeTaggedHalfwordPair(Record*,unsigned char*);
extern "C" int MBi_BlockHeaderEnd(unsigned,unsigned,void*);
// Original data: arm9/ov027 @ 0x21e33ec; symbol: data_ov027_021e33ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char *MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
// Original: arm9/ov027 @ 0x021D96C4; symbol: func_ov027_021d96c4; size: 0x40.
// Serializes a parent control-message tag into the shared packet and sends its six-byte header.
extern "C" int MBi_CommParentSendMsg(unsigned kind,unsigned destinations)
{
    Record record;
    record.kind=kind;
    SerializeTaggedHalfwordPair(&record,MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2);
    return MBi_BlockHeaderEnd(6,destinations,MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2);
}
