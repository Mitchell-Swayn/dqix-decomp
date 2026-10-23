#include <globaldefs.h>
extern "C" unsigned char* PartySync_FindSelectedEntryForMember(unsigned char*, int);
// Original: arm9/main @ 0x0207DA30; symbol: func_0207da30; size: 0x4C.
extern "C" bool PartySync_IsSelectedRecordKeyForMember(int object, unsigned int key, int index) {
    unsigned short* entry=(unsigned short*)PartySync_FindSelectedEntryForMember((unsigned char*)object,index);
    if (entry==0) return false;
    if (*entry!=key) return false;
    return *((signed char*)entry+index+8)!=-1;
}
