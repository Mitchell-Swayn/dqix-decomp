#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" int Network_FindTaggedAcknowledgement(void);
extern "C" void Network_ResetTaggedAcknowledgementEntry(void);
extern "C" void Network_GetConnectionManager(void);
extern "C" int Network_IsParentOrOffline(void);
extern "C" void QueueTaggedRecordOperationMessage34(unsigned int, unsigned int, unsigned int);
// Original: arm9/main @ 0x020E3994; symbol: func_020e3994; size: 0x40.
extern "C" void Network_RemoveTaggedAcknowledgement(unsigned int unused, unsigned int param_2, unsigned int param_3) {
    if (Network_FindTaggedAcknowledgement() == 0) return;
    Network_ResetTaggedAcknowledgementEntry();
    Network_GetConnectionManager();
    if (Network_IsParentOrOffline() == 0) return;
    QueueTaggedRecordOperationMessage34(3, param_2 & 0xff, param_3);
}
