#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*, unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
struct GlobalState { char header[0x998]; unsigned field998; char padding99c[0x1036]; unsigned char enabled; };
extern "C" void* Menu_GetRecordMessageTable(void*);
extern "C" GlobalState* TextContext_GetSharedInstance();
extern "C" unsigned MessageTextTable_FindTextById(void*,int);
extern "C" void TextWindow_StartFormattedMessage(GlobalState*,unsigned,unsigned,unsigned);
// Original: arm9/ov011 @ 0x021873C4; symbol: func_ov011_021873c4; size: 0x9C.
extern "C" unsigned Menu_StartMessageFromTextTableDescriptor(void* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 unsigned value=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 void* item=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(Resource_GetSharedLoadState()),id);
 if(!item) return 1;
 if(MenuRecord_GetType(item)!=4) return 1;
 void* contents=Menu_GetRecordMessageTable(item);
 if(!contents) return 1;
 GlobalState* state=TextContext_GetSharedInstance();
 unsigned result=MessageTextTable_FindTextById(contents,(short)value);
 TextWindow_StartFormattedMessage(state,result,0,0xe3);
 state->field998=1;
 state->enabled=1;
 return 1;
}
