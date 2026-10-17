#include <globaldefs.h>
ARM
struct State { unsigned char pad[0x11a]; unsigned char phase,selection; };
typedef void (State::*Handler)();
struct Table { Handler handlers[4]; };
extern "C" { void* _ZN9GameState11GetInstanceEv(); unsigned _ZNK9GameState12GetTickCountEv(void*); int Object_UpdateDisplayRecordsAndPendingSelection(unsigned char*,unsigned); extern Table data_ov023_021fd510; extern Handler data_020e6d5c; }
// Original: arm9/ov023 @ 0x021D8BB4; symbol: func_ov023_021d8bb4; size: 0xAC.
extern "C" int Graphics_UpdateSelectionAndDispatchPhase(State* state) {
 unsigned tick=_ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
 if(tick==0) tick=1;
 if(state->selection==255) Object_UpdateDisplayRecordsAndPendingSelection((unsigned char*)state+0x20,tick);
 Table table=data_ov023_021fd510;
 table.handlers[3]=data_020e6d5c;
 if(!table.handlers[state->phase]) return 0;
 (state->*table.handlers[state->phase])();
 return 0;
}
