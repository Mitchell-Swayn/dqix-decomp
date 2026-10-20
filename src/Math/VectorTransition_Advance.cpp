#include <globaldefs.h>
// Original data: arm9/main @ 0x20e8f08; symbol: data_020e8f08.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 480e0a02000000004c0e0a020000000034100a0200000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Object { int index; }; typedef void (Object::*Method)(); struct Methods { Method entries[3]; }; extern "C" Methods VectorTransitionAdvance_UnknownRoleProcedureReferenceRecords;
// Original: arm9/main @ 0x020A0DEC; symbol: func_020a0dec; size: 0x5C.
 extern "C" void VectorTransition_Advance(Object* p) { Methods methods=VectorTransitionAdvance_UnknownRoleProcedureReferenceRecords; (p->*methods.entries[p->index])(); }
