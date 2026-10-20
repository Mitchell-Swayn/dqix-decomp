#include <globaldefs.h>
extern "C" {
struct A{unsigned int rest:24;unsigned int value:2;};
// Original: arm9/main @ 0x0206885C; symbol: func_0206885c; size: 0x1C.
unsigned int TextCondition_ReadActionGrammaticalGender(int unused,A **p){A *q=p[2];if(q)return q[2].value;return 0;}
}
