#include <globaldefs.h>
struct RangeState { char opaque[0x5c]; short origin, unused, endpoint; };
// Original: arm9/ov015 @ 0x02193150; symbol: func_ov015_02193150; size: 0x10.
extern "C" ARM void CharacterViewer_SetMenuSelectionIndex(RangeState* p,int delta){p->endpoint=delta+p->origin;}
