#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f2bf4; symbol: data_020f2bf4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 542a0e02202a0e02ec290e02b8290e02.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
typedef void (*Callback)(unsigned,unsigned,unsigned,unsigned); extern "C" Callback WindowControlApplyEnabledBoundsAndMasks_UnknownRoleProcedureReferenceRecords[][2];extern "C" void WindowControl_ApplyInsideAndOutsideMasks(void*);struct Request { unsigned char enabled,kind,index;char pad[17];unsigned a,b,c,d; };
// Original: arm9/main @ 0x020E2C34; symbol: func_020e2c34; size: 0x48.
extern "C" void WindowControl_ApplyEnabledBoundsAndMasks(Request* p) { if(!p->enabled)return;WindowControl_ApplyInsideAndOutsideMasks(p);WindowControlApplyEnabledBoundsAndMasks_UnknownRoleProcedureReferenceRecords[p->kind][p->index](p->a,p->b,p->c,p->d); }
