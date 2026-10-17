#include <globaldefs.h>
ARM
extern "C" {
extern unsigned char data_ov025_021ef988[];
void* Object_GetGlobalSixteenEntryDisplayState();
unsigned char* GetRecordForObjectIndex208Through223(unsigned char*,int);
int DispatchCombatSelectionProcedure(void*,void*,int,int*);
void* GetIndexedEntryPointerOrNull(void*,int);
}
// Original: arm9/ov025 @ 0x021E5014; symbol: func_ov025_021e5014; size: 0x88.
extern "C" int Combat_SetDisplayRecordSelectedTarget(unsigned char* action,void* selection,int unused,void* context) {
 int* entry=(int*)GetIndexedEntryPointerOrNull(*(void**)(data_ov025_021ef988+12),action[9]);
 if(!entry) return 1;
 int index=*entry;
 unsigned char* display=(unsigned char*)Object_GetGlobalSixteenEntryDisplayState();
 unsigned char* record=GetRecordForObjectIndex208Through223(display,index);
 if(!record) return 1;
 int ids[8];
 int count=DispatchCombatSelectionProcedure(context,selection,action[8],ids);
 if(count!=1) { *(short*)(record+0xb2)=-1; return 1; }
 else { *(short*)(record+0xb2)=ids[0]; return 1; }
 return 1;
}
