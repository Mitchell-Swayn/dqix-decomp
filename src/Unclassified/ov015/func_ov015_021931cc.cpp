#include <globaldefs.h>
struct History { char opaque[0x1a8];int values[32];int count; };
// Original: arm9/ov015 @ 0x021931CC; symbol: func_ov015_021931cc; size: 0x2C.
extern "C" ARM int func_ov015_021931cc(History* p){if(p->count<=0)return -1;int index=p->count-1;p->count=index;int result=p->values[index];p->values[index]=-1;return result;}
