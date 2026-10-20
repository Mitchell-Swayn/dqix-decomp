struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Owner; struct Record;
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" void* Graphics_GetConfiguredBackgroundCharacterBase(Owner*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* __clear(void*,unsigned);
extern "C" int Text_EncodeGlyphIndices(const char*,unsigned char*,unsigned);
extern "C" unsigned String_CountBytesUntilTerminator(const signed char*);
extern "C" void DrawIndexedGridCellAndLabel(void*,const unsigned char*,int,unsigned char*);
extern "C" unsigned Graphics_GetCharacterTransferCallback(unsigned,unsigned);
// Original data: arm9/ov023 @ 0x21ffa44; symbol: data_ov023_021ffa44.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned RefreshGridLabelBackground_UnknownRoleZeroInitializedStorage[];
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void _Z15CleanCacheRangePKvj(const void*,unsigned);
// Original: arm9/ov023 @ 0x021E8270; symbol: func_ov023_021e8270; size: 0x158.
// Restores a background, draws three adjacent grid labels, and uploads the character data.
extern "C" void RefreshGridLabelBackground(char* self){
 unsigned char cells[0x3a]; unsigned char scratch[0x400];
 char* text=*(char**)(self+0x600);
 char* record=(char*)(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)(self+0x78)),13);
 if(record){
 void* data=*(void**)(record+8); unsigned offset=*(unsigned*)(record+0xa0); unsigned length=*(unsigned*)(record+0xa4);
 void* base=Graphics_GetConfiguredBackgroundCharacterBase((Owner*)record);
 char* layer=*(char**)(record+4);
 memcpy(data,(char*)base+offset,length);
 char* state=(char*)_ZN9GameState11GetInstanceEv()+0x569c;
 __clear(cells,0x3a);__clear(scratch,0x400);
 int count;
 if(text)count=Text_EncodeGlyphIndices(text,cells,1);
 else {count=String_CountBytesUntilTerminator((signed char*)state+8);memcpy(cells,state+8,count);}
 // The retained callee body never uses its fourth formal; this caller supplies three ABI arguments.
 typedef void (*DrawThree)(void*,const unsigned char*,int);
 ((DrawThree)DrawIndexedGridCellAndLabel)(record,cells,count-1);
 ((DrawThree)DrawIndexedGridCellAndLabel)(record,cells,count);
 ((DrawThree)DrawIndexedGridCellAndLabel)(record,cells,count+1);
 if(!(RefreshGridLabelBackground_UnknownRoleZeroInitializedStorage[0]&1)){
 struct Nibbles { unsigned char first:4,second:4; };
 Nibbles* value=(Nibbles*)(layer+0x1c);
 RefreshGridLabelBackground_UnknownRoleZeroInitializedStorage[1]=Graphics_GetCharacterTransferCallback(value->first,value->second);
 RefreshGridLabelBackground_UnknownRoleZeroInitializedStorage[0]|=1;
 }
 _Z25CleanInvalidateCacheRangePKvj(data,length);
 ((void(*)(const void*,unsigned,unsigned))RefreshGridLabelBackground_UnknownRoleZeroInitializedStorage[1])(data,offset,length);
 _Z15CleanCacheRangePKvj(data,length);
 }
}
