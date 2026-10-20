#include <globaldefs.h>
ARM
extern "C" char* Combat_FindIndexedMonsterObject(int,int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(int);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(int,void*,void*,int,int,int,bool);
// Original: arm9/ov024 @ 0x021DFE9C; symbol: Combat_ReserveIndexedObjectAndCreateCurrentRecord; size: 0xa0.
// Reserves indexed object with descriptor and creates current record using owner flag80.
extern "C" void* Combat_ReserveIndexedObjectAndCreateCurrentRecord(char* self,int unused,int index) {
 char* object=Combat_FindIndexedMonsterObject(*(int*)(self+16),index);if(!object)return 0;if(!*(void**)(object+0x148))return 0;
 object[0x17e]=1;++*(int*)(self+20);void* record=Combat_ClearCurrentResultNodeSlot(*(int*)(self+16));if(!record)return 0;
 bool flag=(((unsigned)*(unsigned char*)(*(char**)(self+12)+28)<<24)>>31)!=0;
 Combat_PopulateResultWithCurrentHealthAndMagic(*(int*)(self+16),record,object,0,0,0,flag);return record;
}
