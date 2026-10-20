#include <globaldefs.h>
struct RangeState { char opaque[0x5c]; short origin, unused, endpoint; };
// Original: arm9/ov015 @ 0x02191284; symbol: func_ov015_02191284; size: 0x10.
extern "C" ARM int CharacterViewer_GetMenuSelectionIndex(RangeState* p){return p->endpoint-p->origin;}
