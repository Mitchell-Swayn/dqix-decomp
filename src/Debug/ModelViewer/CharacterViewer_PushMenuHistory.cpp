#include <globaldefs.h>
struct History { char opaque[0x1a8];int values[32];int count; };
// Original: arm9/ov015 @ 0x021931B4; symbol: func_ov015_021931b4; size: 0x18.
extern "C" ARM void CharacterViewer_PushMenuHistory(History* p,int value){p->values[p->count++]=value;}
