// Original: arm9/ov004 @ 0x0216A464; symbol: func_ov004_0216a464; size: 0x184.
#include <globaldefs.h>
struct State;
struct GameResources;
struct E {short key;short pad;unsigned int value;};struct T {E *data;short count;};
struct Buffer { char pad[0x4ac]; char names[16][64]; };
struct RecordFlags { unsigned short low:14; unsigned short occupied:1; unsigned short high:1; };
struct SavedProfileListHeader { unsigned char count; unsigned char unknown[3]; };
struct ProfileManagerView { unsigned char unknown[0x190]; SavedProfileListHeader *list; };
extern "C" ProfileManagerView *MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage;
extern "C" void* TileGrid_ResolveByKey(void*,unsigned);
extern "C" void* ProfileMenu_GetMessageTableById(void*,unsigned);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" unsigned Menu_GetSelectedGridIndex(unsigned short*);
extern "C" int ProfileMenu_RemoveSelectedSavedProfile(void*);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void ProfileMenu_PopulateSavedProfilePage(void*);
extern "C" void* __clear(void*,unsigned);
extern "C" unsigned MessageTextTable_FindTextById(T*,int);
extern "C" void TextLayout_ResetFormattingWorkspace(signed char*);
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
extern "C" void TextContext_SetStringArgument(Buffer*,int,const char*);
extern "C" void TextWindow_StartFormattedMessage(void*,unsigned,unsigned,unsigned);
extern "C" void* GameState_AppendValueAndSetNodeFlags(void*,unsigned short,unsigned);
extern "C" void Menu_SetActiveSelectionGrid(State*,unsigned);
extern "C" void Menu_QueueScriptEntry(State*,unsigned);
extern "C" int ProfileMenu_ReplaceSelectedProfileFromPendingRecord(void* self){
 if(!MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->list)return 0;
 unsigned char* pending; T* table; unsigned char* context;
 void* grid=TileGrid_ResolveByKey(self,100);
 table=(T*)ProfileMenu_GetMessageTableById(self,3);
 context=(unsigned char*)TextContext_GetSharedInstance();
 Menu_GetSelectedGridIndex((unsigned short*)grid);
 ProfileMenu_RemoveSelectedSavedProfile(self);
 pending=*(unsigned char**)((unsigned char*)GameResources_GetInstance()+0x3b84);
 unsigned char* record=(unsigned char*)(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->list+1);
 for(int i=0;i<16;record+=0x2c,++i){
  if(!((RecordFlags*)(record+0x12))->occupied){
   memcpy(record,pending+0x28,0x2c);
   ++MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->list->count;
   break;
  }
 }
 ProfileMenu_PopulateSavedProfilePage(self);
 unsigned char name[48];__clear(name,48);
 unsigned text=MessageTextTable_FindTextById(table,13);
 TextLayout_ResetFormattingWorkspace((signed char*)context);
 Text_MapInputBytesToVariableLengthOutputSequences(pending+0x2e,name,1);
 TextContext_SetStringArgument((Buffer*)context,0,(char*)name);
 TextWindow_StartFormattedMessage(context,text,0,0xe3);
 *(unsigned*)(context+0x998)=1;
 GameState_AppendValueAndSetNodeFlags(self,30,8);
 GameState_AppendValueAndSetNodeFlags(self,31,8);
 GameState_AppendValueAndSetNodeFlags(self,2,8);
 Menu_SetActiveSelectionGrid((State*)self,102);
 Menu_QueueScriptEntry((State*)self,104);
 return 0;
}
