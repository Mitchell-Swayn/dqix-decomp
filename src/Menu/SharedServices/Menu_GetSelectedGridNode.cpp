// Original: arm9/ov004 @ 0x02156E68; symbol: Menu_GetSelectedGridNode; size: 0x68.
#include <globaldefs.h>
ARM
struct State;struct Grid;
extern "C" {
void* Menu_GetDisplayRecordRegistry(State*);
void* MenuRecordList_LocateByKey(void**,unsigned short);
unsigned MenuRecord_GetType(void*);
unsigned short Menu_GetSelectedGridColumn(const void*);
unsigned Menu_GetSelectedGridRow(void*);
unsigned short Menu_ReadGridEntryOrZero(Grid*,unsigned,unsigned);
}
extern "C" void* Menu_GetSelectedGridNode(void* self,unsigned short key){
void** registry=(void**)Menu_GetDisplayRecordRegistry((State*)self);void* node=MenuRecordList_LocateByKey(registry,key);if(!node)return 0;if(MenuRecord_GetType(node)!=7)return 0;unsigned column=Menu_GetSelectedGridColumn(node);unsigned row=Menu_GetSelectedGridRow(node);unsigned short selected=Menu_ReadGridEntryOrZero((Grid*)node,row,column);return MenuRecordList_LocateByKey(registry,selected);
}
