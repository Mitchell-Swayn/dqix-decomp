#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*, unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
struct Item { char prefix[0x45]; unsigned char reserved:7; unsigned char enabled:1; };
// Original: arm9/ov011 @ 0x02188884; symbol: func_ov011_02188884; size: 0x68.
extern "C" unsigned Menu_SetMotionDescriptorPackedEnableBit(void* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 unsigned value=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 Item* item=(Item*)MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(Resource_GetSharedLoadState()),id);
 if(!item) return 0;
 if(MenuRecord_GetType(item)!=8) return 0;
 item->enabled=(unsigned char)value;
 return 1;
}
