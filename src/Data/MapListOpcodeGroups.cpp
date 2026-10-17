#include <globaldefs.h>
#include "Resource/Script.h"
// Four zero-terminated map-list opcode groups in their original order.
// The first group is used by LoadZoneInfoFromMapListScript; the later
// groups retain the original unused variants from MapListLoader.cpp.
int MapList_Opcode_64_Unused(Script::Parameter*, int);
int MapList_Opcode_65_Unused(Script::Parameter*, int);
int MapList_Opcode_66(Script::Parameter*, int);
int MapList_Opcode_66_Unused(Script::Parameter*, int);
int MapList_Opcode_67(Script::Parameter*, int);
int MapList_Opcode_67_Unused(Script::Parameter*, int);
int MapList_Opcode_68(Script::Parameter*, int);
int MapList_Opcode_68_Unused(Script::Parameter*, int);
int MapList_Opcode_69(Script::Parameter*, int);
int MapList_Opcode_69_Unused(Script::Parameter*, int);
extern "C" Script::OpcodeLookupEntry data_020ef2c0[23] = {
    {102, MapList_Opcode_66},
    {103, MapList_Opcode_67},
    {105, MapList_Opcode_69},
    {104, MapList_Opcode_68},
    {0, 0},
    {101, MapList_Opcode_65_Unused},
    {100, MapList_Opcode_64_Unused},
    {103, MapList_Opcode_67_Unused},
    {104, MapList_Opcode_68_Unused},
    {0, 0},
    {101, MapList_Opcode_65_Unused},
    {100, MapList_Opcode_64_Unused},
    {103, MapList_Opcode_67_Unused},
    {105, MapList_Opcode_69_Unused},
    {104, MapList_Opcode_68_Unused},
    {0, 0},
    {101, MapList_Opcode_65_Unused},
    {100, MapList_Opcode_64_Unused},
    {102, MapList_Opcode_66_Unused},
    {103, MapList_Opcode_67_Unused},
    {105, MapList_Opcode_69_Unused},
    {104, MapList_Opcode_68_Unused},
    {0, 0},
};
