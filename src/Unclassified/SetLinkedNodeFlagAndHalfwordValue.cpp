#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" {
ARM struct Node { char pad[52]; volatile unsigned short flag; unsigned short pad36; volatile unsigned short value; };
// Original: arm9/main @ 0x020BC1EC; symbol: func_020bc1ec; size: 0x24.
 void SetLinkedNodeFlagAndHalfwordValue(Node* volatile* node,unsigned short value) { if(!*node) return; (*node)->flag=1; (*node)->value=value; }
}
