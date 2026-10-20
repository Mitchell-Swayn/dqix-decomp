#include <globaldefs.h>
ARM
struct State; struct Tree; struct Owner;
extern "C" {
void _ZN13SafeAllocator5ResetEv(void*);
int TextCanvas_HasActiveTilemap(char*);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
void* ProfileMenu_FindControlById(void*,unsigned);
void ProfileMenu_ShowCurrentPlayerSummary(void*);
Tree* Menu_FindSessionArenaById(Tree*,unsigned);
void Menu_QueueScriptEntry(State*,unsigned);
void* Menu_GetDisplayRecordRegistry(State*);
void Menu_SetActiveSelectionGrid(State*,unsigned);
void* TileGrid_ResolveByKey(void*,unsigned);
void RemoveDescriptorsMatchingHalfwordKey(Owner*,int);
void* MenuRecordList_LocateByKey(void**,unsigned short);
unsigned MenuRecord_GetType(void*);
void MenuTextCanvas_ResetLayoutAndDisplayFlags(char*);
void Memory_ZeroBufferUsingElementCountAndStride(unsigned char*);
void Menu_SetSpriteCellPaletteOverride(void*,unsigned char);
// Original data: arm9/ov004 @ 0x2171030; symbol: data_ov004_02171030.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern unsigned char* MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov004 @ 0x021698F4; symbol: func_ov004_021698f4; size: 0x134.
// Resets an active canvas and allocator subtree, refreshes state, and dispatches a pending shared notification.
extern "C" int ResetActiveCanvasAndDispatchPendingNotification(State* self){
 bool reset=false;
 void* control=ProfileMenu_FindControlById(self,31);
 if(!control)return 0;
 char* canvas=(char*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self),21);
 if(!canvas || MenuRecord_GetType(canvas)!=6)canvas=0;
 if(canvas){
  char* display=canvas+32;
  if(display && TextCanvas_HasActiveTilemap(display)){
   MenuTextCanvas_ResetLayoutAndDisplayFlags(canvas);
   Tree* node=Menu_FindSessionArenaById((Tree*)self,2);
   if(node){
    RemoveDescriptorsMatchingHalfwordKey((Owner*)Menu_GetDisplayRecordRegistry(self),2);
    _ZN13SafeAllocator5ResetEv((char*)node+4);
   }
   Menu_SetActiveSelectionGrid(self,0);
   unsigned char* descriptor=(unsigned char*)TileGrid_ResolveByKey(self,100);
   if(descriptor){Memory_ZeroBufferUsingElementCountAndStride(descriptor);reset=true;}
  }
 }
 Menu_SetSpriteCellPaletteOverride(control,2);
 ProfileMenu_ShowCurrentPlayerSummary(self);
 Menu_QueueScriptEntry(self,83);
 if(reset)Menu_SetActiveSelectionGrid(self,100);
 if(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage[0x1a0])SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage[0x1a0]=0;
 return 0;
}
