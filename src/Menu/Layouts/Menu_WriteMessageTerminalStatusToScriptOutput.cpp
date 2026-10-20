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
// Original: arm9/ov011 @ 0x02188534; symbol: func_ov011_02188534; size: 0x2C.
extern "C" unsigned Menu_WriteMessageTerminalStatusToScriptOutput(void* self) { unsigned state=TextContext_GetSharedInstance()->field9a0; unsigned result=0; if(state==3) result=1; Menu_WriteScriptIntegerReference(self,result); return 1; }
