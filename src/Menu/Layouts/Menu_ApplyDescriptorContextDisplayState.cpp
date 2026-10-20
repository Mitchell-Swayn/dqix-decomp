#include <globaldefs.h>
struct Object;
typedef void (*Method)(Object*,unsigned);
typedef void (*Method0)(Object*);
typedef void (*Method3)(Object*,unsigned,unsigned,unsigned);
struct VTable { Method slots[54]; };
struct Object { VTable* methods; unsigned short kind; char pad[6]; unsigned char flags; };
struct GlobalState { char pad[0x998]; unsigned field998,field99c,field9a0; char pad9a4[0x1026]; unsigned char enabled; };
extern "C" GlobalState* TextContext_GetSharedInstance();
extern "C" int Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" Object* MenuRecordList_LocateByKey(void*,unsigned);
extern "C" unsigned MenuRecord_GetType(Object*);
extern "C" void Menu_WriteScriptIntegerReference(void*,unsigned);
extern "C" void Menu_StartIndexedCallback(void*,unsigned);
// Original: arm9/ov011 @ 0x02186790; symbol: func_ov011_02186790; size: 0x3C.
extern "C" unsigned Menu_ApplyDescriptorContextDisplayState(void* self) { unsigned id=Menu_ReadScriptArgumentAsInteger(self); Object* item=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(Resource_GetSharedLoadState()),id); if(!item) return 0; ((Method0)item->methods->slots[52])(item); return 1; }
