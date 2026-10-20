#include <globaldefs.h>
extern "C" void* ScriptQueryContext_GetActiveInstance();
extern "C" unsigned ScriptQueryContext_GetLinkedZoneFloor(void*);
extern "C" void Script_WriteIntegerReferenceOutput(unsigned,unsigned);
// Original: arm9/main @ 0x0209D658; symbol: func_0209d658; size: 0x30.
extern "C" int Script_WriteZoneOrGrottoBossFloor(unsigned value) { void* p=ScriptQueryContext_GetActiveInstance(); if (!p) return 0; Script_WriteIntegerReferenceOutput(value,ScriptQueryContext_GetLinkedZoneFloor(p));return 1; }
