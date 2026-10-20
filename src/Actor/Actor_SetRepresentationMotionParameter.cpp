#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02040BFC; symbol: func_02040bfc; size: 0x30.
void Actor_SetRepresentationMotionParameter(char **p,int v){if(p[5]){*(int *)(p[5]+0x8c)=v;return;}if(p[6]){*(int *)(p[6]+0xc8)=v;return;}if(p[7])*(int *)(p[7]+0x2ec)=v;}
}
