#include <globaldefs.h>
struct Node { unsigned char pad[0x20]; Node* next; };
struct Lists { Node* heads[6]; unsigned char counts[6]; };
#pragma force_active on
// Original: arm9/ov000 @ 0x0215FFC4; symbol: func_ov000_0215ffc4; size: 0x30.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" void Combat_AppendTargetResultToCategoryList(Lists* lists, Node* node, int index)
{
    Node** link=&lists->heads[index]; while (*link) link=&(*link)->next; *link=node; ++lists->counts[index];
}
