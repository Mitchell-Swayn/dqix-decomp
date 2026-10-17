#include <globaldefs.h>
ARM
struct State { unsigned char pad[0x5d8]; void* buffer; };
typedef void (State::*Handler)();
struct Table { Handler handlers[3]; };
extern "C" { extern Table data_ov023_021fd7e4; unsigned ReadWordFieldAtOffset1C(); void ClearOwnerBuffersAndResetSignedByteSentinels(signed char*); void* memset(void*,int,unsigned); int LoadMatchingReadyRecordAndRefreshOwner(void*,unsigned,void*,unsigned,unsigned char); }
// Original: arm9/ov023 @ 0x021E7EB0; symbol: func_ov023_021e7eb0; size: 0xB8.
extern "C" void Resource_GenerateAndLoadThreeHandlerRecords(State* state) {
 Table table=data_ov023_021fd7e4;
 signed char* global=(signed char*)ReadWordFieldAtOffset1C();
 for(unsigned char i=0;i<3;++i) {
  ClearOwnerBuffersAndResetSignedByteSentinels(global);
  memset(state->buffer,0,2400);
  (state->*table.handlers[i])();
  LoadMatchingReadyRecordAndRefreshOwner((unsigned char*)state+0x78,i,state->buffer,1,0);
 }
}
