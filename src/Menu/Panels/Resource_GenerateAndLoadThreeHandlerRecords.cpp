#include <globaldefs.h>
ARM
struct State { unsigned char pad[0x5d8]; void* buffer; };
typedef void (State::*Handler)();
struct Table { Handler handlers[3]; };
// Original data: arm9/ov023 @ 0x21fd7e4; symbol: data_ov023_021fd7e4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex c8831e02000000003c851e020000000004861e0200000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" { extern Table ResourceGenerateAndLoadThreeHandlerRecords_UnknownRoleProcedureReferenceRecords; unsigned TextContext_GetSharedInstance(); void TextLayout_ResetFormattingWorkspace(signed char*); void* memset(void*,int,unsigned); int Window_ReplaceCanvasTextById(void*,unsigned,void*,unsigned,unsigned char); }
// Original: arm9/ov023 @ 0x021E7EB0; symbol: func_ov023_021e7eb0; size: 0xB8.
extern "C" void Resource_GenerateAndLoadThreeHandlerRecords(State* state) {
 Table table=ResourceGenerateAndLoadThreeHandlerRecords_UnknownRoleProcedureReferenceRecords;
 signed char* global=(signed char*)TextContext_GetSharedInstance();
 for(unsigned char i=0;i<3;++i) {
  TextLayout_ResetFormattingWorkspace(global);
  memset(state->buffer,0,2400);
  (state->*table.handlers[i])();
  Window_ReplaceCanvasTextById((unsigned char*)state+0x78,i,state->buffer,1,0);
 }
}
