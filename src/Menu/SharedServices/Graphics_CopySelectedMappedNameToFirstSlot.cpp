#include <globaldefs.h>
ARM
#pragma opt_propagation off
struct State; struct Buffer;
// Original data: arm9/ov004 @ 0x2171030; symbol: data_ov004_02171030.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char* MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage;
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void* TileGrid_ResolveByKey(void*,unsigned);
extern "C" void* ProfileMenu_GetMessageTableById(void*,unsigned);
extern "C" unsigned Menu_GetSelectedGridIndex(unsigned short*);
extern "C" void TextLayout_ResetFormattingWorkspace(signed char*);
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
extern "C" void TextContext_SetStringArgument(Buffer*,int,const char*);
extern "C" void Menu_QueueScriptEntry(State*,unsigned);
struct Entry { unsigned char pad[6],text[38]; };
struct Table { unsigned header; Entry entries[1]; };
// Original: arm9/ov004 @ 0x02169A28; symbol: func_ov004_02169a28; size: 0xB4.
extern "C" int Graphics_CopySelectedMappedNameToFirstSlot(State* self) {
 Table* table=*(Table**)(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage+0x190);
 if(table) {
  Buffer* names=(Buffer*)TextContext_GetSharedInstance();
  unsigned char* selection=(unsigned char*)TileGrid_ResolveByKey(self,100);
  ProfileMenu_GetMessageTableById(self,3);
  short row=*(short*)(selection+0x5c);
  unsigned index=Menu_GetSelectedGridIndex((unsigned short*)selection);
  unsigned char text[48]={};
  TextLayout_ResetFormattingWorkspace((signed char*)names);
  Entry* entry=&table->entries[index+row*8];
  Text_MapInputBytesToVariableLengthOutputSequences(entry->text,text,1);
  TextContext_SetStringArgument(names,0,(char*)text);
  Menu_QueueScriptEntry(self,0x51);
 }
 return 0;
}
