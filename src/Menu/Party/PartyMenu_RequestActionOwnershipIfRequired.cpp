#include <globaldefs.h>
ARM
extern "C" void* ActionData_GetGlobalTables();
struct Record { char pad[0x18]; unsigned type : 5; unsigned category : 7; unsigned rest : 20; };
extern "C" Record* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char* p,void* a);
extern "C" void *NetworkOwnership_GetRegistry();
extern "C" void NetworkOwnership_QueueRequest(unsigned char *p,unsigned char v);
// Original: arm9/ov002 @ 0x0215B720; symbol: func_ov002_0215b720; size: 0xB0.
extern "C" int PartyMenu_RequestActionOwnershipIfRequired(char *self, unsigned id) {
    int mode = *(int*)(self + 0x1bb8);
    int match = 0;
    if (mode == 6 || mode == 17) {
        if (id == 0x198 || id == 0x22 || id == 0x310) match = 1;
    } else {
        volatile Record *record = ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)ActionData_GetGlobalTables(), (void*)id);
        if (record) {
            unsigned category = record->category;
            unsigned type = record->type;
            if (category == 2 || category == 7 || category == 79 || category == 80 || category == 18 || category == 26) match = 1;
            if (type == 5 && *(int*)(self + 0x1bb8) == 7) match = 1;
        }
    }
    if (match) NetworkOwnership_QueueRequest((unsigned char*)NetworkOwnership_GetRegistry(), 1);
    return match;
}
