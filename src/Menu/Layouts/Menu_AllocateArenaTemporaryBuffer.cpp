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
// Original: arm9/ov011 @ 0x021878DC; symbol: func_ov011_021878dc; size: 0x50.
extern "C" unsigned Menu_AllocateArenaTemporaryBuffer(void* self) { unsigned id=Menu_ReadScriptArgumentAsInteger(self); unsigned size=Menu_ReadScriptArgumentAsInteger((char*)self+8); void* state=Resource_GetSharedLoadState(); if(!Menu_FindSessionArenaById(state,id)) return 0; Menu_AllocateTemporaryBufferFromArena(state,id,size); return 1; }
