#include <globaldefs.h>
ARM
extern "C" int Object_FindSignedByteKeyInSixteenEntries();extern "C" void UpdateEnabledMemberCountAndTimestampOnTransition(void*);
// Original: arm9/main @ 0x0202C1E8; symbol: func_0202c1e8; size: 0x34.
extern "C" void Object_SetSelectedBitAndRefreshState(unsigned char* object){int bit=Object_FindSignedByteKeyInSixteenEntries();if(bit<0)return;object[0x100c]|=1<<bit;UpdateEnabledMemberCountAndTimestampOnTransition(object);}
