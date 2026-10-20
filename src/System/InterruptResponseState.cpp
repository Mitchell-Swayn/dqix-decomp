#include "System/InterruptResponse.h"

DMAOrTimerResponse GetInterruptHandler_UnknownRoleZeroInitializedStorage[8];
// Hardware IRQ bit numbers: DMA0..3, then timer0..3.
unsigned short OnDMAOrTimerCompletion_UnknownRoleInitializedBytes[8] = {8, 9, 10, 11, 3, 4, 5, 6};
