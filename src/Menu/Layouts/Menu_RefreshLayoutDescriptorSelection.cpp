#include <globaldefs.h>
extern "C" int Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*,unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void* GameResources_GetInstance();
extern "C" void Menu_SetActiveSelectionGrid(void*,unsigned);
extern "C" void Menu_SetGridCancelState(void*,unsigned);
extern "C" void Menu_SetGridCancelCallback(void*,unsigned);
extern "C" void Menu_SetSpriteCellPaletteOverride(void*,int);
extern "C" void Menu_SetSpriteCellPriorityOverride(void*,int);
extern "C" void Menu_SetGridNavigationWrapEnabled(void*,unsigned);
extern "C" void Graphics_SetDescriptorNibbleAndOptionallyRefresh(void*,void*,unsigned,unsigned);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);
extern "C" void* Menu_FindSessionArenaById(void*,unsigned);
extern "C" unsigned Menu_AllocateTemporaryBufferFromArena(void*,unsigned,unsigned);
extern "C" unsigned Menu_AllocateCanvasPixelBufferFromArena(void*,unsigned,unsigned);
extern "C" void RemoveDescriptorsMatchingHalfwordKey(void*,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
extern "C" void Object_InvokeSaveTextureImageVRAMState(void*);
// Original: arm9/ov011 @ 0x0218735C; symbol: func_ov011_0218735c; size: 0x68.
extern "C" unsigned Menu_RefreshLayoutDescriptorSelection(void* self) { unsigned id=Menu_ReadScriptArgumentAsInteger(self); unsigned char value=Menu_ReadScriptArgumentAsInteger((char*)self+8); void* state=Resource_GetSharedLoadState(); void* item=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(state),id); if(!item) return 0; if(MenuRecord_GetType(item)!=6) return 0; Graphics_SetDescriptorNibbleAndOptionallyRefresh(item,state,value,1); return 1; }
