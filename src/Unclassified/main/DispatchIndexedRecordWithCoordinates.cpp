#include <globaldefs.h>
#pragma optimization_level 4
struct IndexedRecordView { unsigned char pad[0x10]; unsigned char* records; void* resource; unsigned char pad2[5]; unsigned char count; };
extern "C" void Graphics_CopyClippedTilemapRectangle(IndexedRecordView*,void*,void*,unsigned,unsigned,short,short,short,short,unsigned short);
// Original: arm9/main @ 0x0204B8D0; symbol: func_0204b8d0; size: 0x68.
extern "C" ARM void DispatchIndexedRecordWithCoordinates(IndexedRecordView* self,unsigned index,unsigned flags,unsigned argument,short x,short y,short width,short height,unsigned short color) { if(self->count>index) { unsigned char* record=self->records; if(record) { record+=index*16; if(self->resource) Graphics_CopyClippedTilemapRectangle(self,self->resource,record,flags,argument,x,y,width,height,color); } } }
