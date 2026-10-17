#include <globaldefs.h>
extern "C" {
void *ReadGlobalAt02105AB4();void ReadGlobalValueAt021056B4(void *);void ReadGlobalAt021052B4(void *);
// Original: arm9/main @ 0x02093704; symbol: func_02093704; size: 0x28.
void UpdateGlobalContextAndOptionalReset(int v){void *p=ReadGlobalAt02105AB4();ReadGlobalValueAt021056B4(p);if(!v)ReadGlobalAt021052B4(p);}
}
