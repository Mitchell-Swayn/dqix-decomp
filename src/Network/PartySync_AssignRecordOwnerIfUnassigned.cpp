#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" int PartySync_FindEntryByKey(void);
extern "C" void Network_GetConnectionManager(void);
extern "C" int Network_IsParentOrOffline(void);
extern "C" void InitializeQueuedRecordOwner(unsigned int, int);
// Original: arm9/main @ 0x0207DB58; symbol: func_0207db58; size: 0x50.
extern "C" int PartySync_AssignRecordOwnerIfUnassigned(unsigned int unused, unsigned int param_2, unsigned int param_3) {
    int value = PartySync_FindEntryByKey();
    if (value == 0) return -1;
    if (*(signed char *)(value + 4) < 0) {
        *(unsigned char *)(value + 4) = (unsigned char)param_3;
        Network_GetConnectionManager();
        if (Network_IsParentOrOffline() != 0)
            InitializeQueuedRecordOwner(param_2, *(signed char *)(value + 4));
    }
    return *(signed char *)(value + 4);
}
