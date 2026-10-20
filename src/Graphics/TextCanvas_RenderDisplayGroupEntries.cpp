#include "globaldefs.h"
// Original: arm9/main @ 0x02081574; symbol: DispatchListedKeyEntriesAndAdjustSelectedCoordinates.
struct Entry{unsigned char pad[0x13];unsigned char kind:4;unsigned char rest:4;};
// Original data: arm9/main @ 0x20e8a54; symbol: data_020e8a54.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6c1608020000000018180802000000007018080200000000141a0802000000003c1b080200000000e81c080200000000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Owner;typedef void(Owner::*Method)(void*,unsigned char*);extern Method TextCanvasRenderDisplayGroupEntries_UnknownRoleProcedureReferenceRecords[];struct Owner{void Dispatch(void*,unsigned char*);};extern "C" unsigned char* DisplayLayout_FindPartById(void*,int);extern "C" void TextCanvas_DrawSelectionMarker(void*,int,int);
extern "C" ARM void TextCanvas_RenderDisplayGroupEntries(unsigned char*self,void* display,unsigned char*list){unsigned char *entry;int key;if(!list)return;for(unsigned char i=0;i<list[0x13];i++){key=(*(short**)list)[i];entry=DisplayLayout_FindPartById(self+4,key);if(entry){if(*(short*)(self+0x36)==key){int kind=((Entry*)entry)->kind;short x=*(short*)(entry+6)-*(short*)(self+0x34);short y=*(short*)(entry+8);switch(kind){case 8:y--;break;case 12:y++;break;}TextCanvas_DrawSelectionMarker(display,x,y);}if(!(entry[0x2a]&1))(((Owner*)self)->*TextCanvasRenderDisplayGroupEntries_UnknownRoleProcedureReferenceRecords[entry[0x12]])(display,entry);}}}
