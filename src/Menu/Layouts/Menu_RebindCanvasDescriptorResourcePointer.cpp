#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*, unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
struct Argument { unsigned kind; void* pointer; };
struct Arguments { Argument entries[2]; };
extern "C" void MenuLayerRecord_BeginTaggedResourceReload(void*, void*);
// Original: arm9/ov011 @ 0x02186F08; symbol: func_ov011_02186f08; size: 0x6C.
extern "C" unsigned Menu_RebindCanvasDescriptorResourcePointer(Arguments* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 void* value=self->entries[1].kind==2 ? self->entries[1].pointer : 0;
 if(!value) return 0;
 void* item=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(Resource_GetSharedLoadState()),id);
 if(!item) return 0;
 if(MenuRecord_GetType(item)!=2) return 0;
 MenuLayerRecord_BeginTaggedResourceReload(item,value);
 return 1;
}
