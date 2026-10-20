#include <globaldefs.h>
#include "Resource/Script.h"
// Four zero-terminated map-list opcode groups in their original order.
// The first group is used by LoadZoneInfoFromMapListScript; the later
// groups retain the original unused variants from MapListLoader.cpp.
int MapList_Opcode_64_Unused(Script::Parameter*, int);
int MapList_Opcode_65_Unused(Script::Parameter*, int);
int MapList_Opcode_66(Script::Parameter*, int);
int MapList_Opcode_66_AllocateGroupingEntriesB(Script::Parameter*, int);
int MapList_Opcode_67(Script::Parameter*, int);
int MapList_Opcode_67_InsertGroupingEntryB(Script::Parameter*, int);
int MapList_Opcode_68(Script::Parameter*, int);
int MapList_Opcode_68_InsertGroupingEntryA(Script::Parameter*, int);
int MapList_Opcode_69(Script::Parameter*, int);
int MapList_Opcode_69_AllocateGroupingEntriesA(Script::Parameter*, int);
// Original data: arm9/main @ 0x20ef2c0; symbol: data_020ef2c0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 66000000f4c5010267000000fcc50102690000001cc701026800000014c70102000000000000000065000000c0c1010264000000b8c1010267000000f8c10102 ...; full span in module reference.
// Observed span: 184 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Script::OpcodeLookupEntry LoadZoneInfoFromMapListScript_UnknownRoleProcedureReferenceRecords[23] = {
    {102, MapList_Opcode_66},
    {103, MapList_Opcode_67},
    {105, MapList_Opcode_69},
    {104, MapList_Opcode_68},
    {0, 0},
    {101, MapList_Opcode_65_Unused},
    {100, MapList_Opcode_64_Unused},
    {103, MapList_Opcode_67_InsertGroupingEntryB},
    {104, MapList_Opcode_68_InsertGroupingEntryA},
    {0, 0},
    {101, MapList_Opcode_65_Unused},
    {100, MapList_Opcode_64_Unused},
    {103, MapList_Opcode_67_InsertGroupingEntryB},
    {105, MapList_Opcode_69_AllocateGroupingEntriesA},
    {104, MapList_Opcode_68_InsertGroupingEntryA},
    {0, 0},
    {101, MapList_Opcode_65_Unused},
    {100, MapList_Opcode_64_Unused},
    {102, MapList_Opcode_66_AllocateGroupingEntriesB},
    {103, MapList_Opcode_67_InsertGroupingEntryB},
    {105, MapList_Opcode_69_AllocateGroupingEntriesA},
    {104, MapList_Opcode_68_InsertGroupingEntryA},
    {0, 0},
};
