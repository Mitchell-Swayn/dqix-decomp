#include <globaldefs.h>
struct State {unsigned char active,pad;unsigned short id;};
extern "C" State data_02108dfc;
extern "C" void Card_WaitForIdleAndUnlockReadManager(unsigned short);
// Original: arm9/main @ 0x02075CB8; symbol: func_02075cb8; size: 0x24.
extern "C" void ActivateGlobalOperationByStoredId() {Card_WaitForIdleAndUnlockReadManager(data_02108dfc.id);data_02108dfc.active=1;}
