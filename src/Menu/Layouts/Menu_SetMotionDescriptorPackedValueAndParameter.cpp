#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*, unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
struct Item { char header[0x42]; unsigned short field42; unsigned char field44; unsigned char reserved:1; unsigned char value:6; unsigned char enabled:1; };
// Original: arm9/ov011 @ 0x0218702C; symbol: func_ov011_0218702c; size: 0x78.
extern "C" unsigned Menu_SetMotionDescriptorPackedValueAndParameter(void* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 unsigned value=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 unsigned last=Menu_ReadScriptArgumentAsInteger((char*)self+16);
 Item* item=(Item*)MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(Resource_GetSharedLoadState()),id);
 if(!item) return 0;
 if(MenuRecord_GetType(item)!=8) return 0;
 item->value=(unsigned char)value;
 item->field42=last;
 return 1;
}
