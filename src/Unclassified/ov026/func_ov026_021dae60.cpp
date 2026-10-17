struct Entry { char reserved[0x4c]; int index; char rest[0x3f8]; };
struct State { char reserved[0x958]; Entry entries[4]; };
// Original: arm9/ov026 @ 0x021DAE60; symbol: func_ov026_021dae60; size: 0x68.
extern "C" Entry *func_ov026_021dae60(State *state,int index) { int valid=(index>=0 && index<=3); if(valid) { for(int i=0;i<4;i++) if(state->entries[i].index==index) return &state->entries[i]; } return 0; }
