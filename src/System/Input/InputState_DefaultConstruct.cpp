#include <globaldefs.h>

// Original: arm9/main @ 0x02012298; symbol: func_02012298; size: 0x4.
// Static initialization calls this empty constructor on input state at 0x02114e30.
struct InputState;
extern "C" InputState* InputState_DefaultConstruct(InputState* self) { return self; }
