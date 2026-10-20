#include <globaldefs.h>
ARM
#pragma optimization_level 4
class GameState;class SafeAllocator;struct List;
extern "C" {
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
struct OverlayGlobals {int a,b,counter;char* state;};extern OverlayGlobals CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
void* _ZN16BackgroundLoader11GetInstanceEv();void* Combat_GetCurrentPresentationAllocator(char*);unsigned Combat_GetCurrentPresentationTextureState(void*);void* Object_GetGlobalSixteenEntryDisplayState();void* _ZN9GameState11GetInstanceEv();int GameState_ReadSupportedFirmwareLanguage(GameState*);
void* __clear(void*,unsigned);void _Z24StringReplaceLanguageTagPKcPci(const char*,char*,int);bool Filesystem_SplitMatchedPathPrefixAndSuffix(char*,char*,char*);
int _ZN16BackgroundLoader22GetLoadedFileInArchiveEPKcS1_PPvPj(void*,const char*,const char*,void**,unsigned*);int _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(void*,const char*,void**,unsigned*);
char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);void* memcpy(void*,const void*,unsigned);
void Combat_RegisterDeferredPresentationCleanup(unsigned char*,unsigned char*);void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
int Object_AllocateAndAppendInitializedLinkedNode(List*,int,SafeAllocator*,void*,void*);
void Object_InvokeSaveTextureImageVRAMState(char*);void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);void Resource_RemoveIndexedHalfword(void*,int);
}
#define STATE (CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.state)
// Original: arm9/ov025 @ 0x021E27C8; symbol: func_ov025_021e27c8; size: 0x1B8.
// Copies a loaded language-tagged resource into an allocator and registers display state with deferred cleanup.
extern "C" void LoadAndRegisterLocalizedDisplayResource(char* path,int id) {
 char archive[80],inner[80],localized[80];void* file;unsigned size;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 Combat_GetCurrentPresentationAllocator(STATE);Combat_GetCurrentPresentationTextureState(STATE);Object_GetGlobalSixteenEntryDisplayState();
 int language=GameState_ReadSupportedFirmwareLanguage((GameState*)_ZN9GameState11GetInstanceEv());
 file=0;__clear(localized,80);_Z24StringReplaceLanguageTagPKcPci(path,localized,language);
 int task;
 if(Filesystem_SplitMatchedPathPrefixAndSuffix(path,archive,inner))task=_ZN16BackgroundLoader22GetLoadedFileInArchiveEPKcS1_PPvPj(loader,archive,inner,&file,&size);
 else task=_ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(loader,localized,&file,&size);
 void* original=file;
 if(original){
 unsigned length=size;void* allocator;void* copy;
 _ZN16BackgroundLoader11GetInstanceEv();
 allocator=Combat_GetCurrentPresentationAllocator(STATE);void* vram=(void*)Combat_GetCurrentPresentationTextureState(STATE);void* display=Object_GetGlobalSixteenEntryDisplayState();
 copy=_ZN13SafeAllocator8AllocateEj((unsigned)allocator,length);
 if(copy){memcpy(copy,original,length);
 if(id<0)id=CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.counter+100;
 unsigned char* node=(unsigned char*)_ZN13SafeAllocator8AllocateEj((unsigned)allocator,12);
 if(node){node[0]=1;*(unsigned short*)(node+4)=id;Combat_RegisterDeferredPresentationCleanup((unsigned char*)STATE,node);
 Graphics_RestoreTextureImageAndPaletteVRAMState(vram);
 Object_AllocateAndAppendInitializedLinkedNode((List*)display,id,(SafeAllocator*)allocator,copy,(void*)length);
 Object_InvokeSaveTextureImageVRAMState((char*)vram);
 ++CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.counter;
 }}
 }
 if(task>=0){_ZN16BackgroundLoader10RemoveTaskEi(loader,task);Resource_RemoveIndexedHalfword(STATE,task);}
}
