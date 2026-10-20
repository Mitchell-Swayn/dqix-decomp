#include <globaldefs.h>
ARM
#pragma scheduling off
#pragma optimize_for_size on
#pragma optimization_level 2
#pragma opt_common_subs off
struct Color { unsigned char r,g,b; }; struct Entry { unsigned word; Color color; unsigned char padding; };
// Original: arm9/main @ 0x020E3B44; symbol: func_020e3b44; size: 0x48.
 extern "C" void Network_ApplyTaggedAcknowledgementSnapshot(Entry* p,int index,Entry value){if(index>=0 && index<4){p[index].word=value.word;p[index].color.r=value.color.r;p[index].color.g=value.color.g;p[index].color.b=value.color.b;}}
