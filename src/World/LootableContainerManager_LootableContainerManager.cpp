#include <globaldefs.h>
#include <World/LootableContainer.h>
// Explicit ABI entry for the constructor; the header defines an inline constructor.
// Original: arm9/main @ 0x0207C244; symbol: _ZN24LootableContainerManagerC1Ev; size: 0x14.
extern "C" LootableContainerManager *_ZN24LootableContainerManagerC1Ev(LootableContainerManager *p){p->Reset();return p;}
