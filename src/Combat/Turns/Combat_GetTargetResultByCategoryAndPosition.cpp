#include <globaldefs.h>
struct Node { unsigned char pad[0x20]; Node* next; };
struct Lists { Node* heads[6]; unsigned char counts[6]; };
#pragma force_active on
// Original: arm9/ov000 @ 0x0215FFF4; symbol: func_ov000_0215fff4; size: 0x3C.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" Node* Combat_GetTargetResultByCategoryAndPosition(Lists* lists, int position, int index)
{
    if (lists->counts[index] <= position) return 0; Node* node=lists->heads[index]; int n=0; while (n < position && node) { node=node->next; ++n; } return node;
}
