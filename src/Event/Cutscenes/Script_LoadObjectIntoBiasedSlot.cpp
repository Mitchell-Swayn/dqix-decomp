#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <World/Object3D.h>
ARM
struct IntegerParameterView;
extern "C" unsigned Script_ReadParameterString(void*);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" int Script_ResolveEventObjectIndex(int);
extern "C" int Event_ResolveCharacterArchiveMember(const char*,char*,char*);
extern "C" unsigned Event_LoadFileIntoSharedScratch(const char*,void**);
extern "C" void GameState_SetIndexedObjectAndSlot(GameState*,int,GameObject*);
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" SafeAllocator* EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
extern "C" char Script_LoadEventTextTable_PathDataS[],Script_LoadObjectIntoBiasedSlot_TextChr[],Script_LoadObjectIntoBiasedSlot_TextEnemy[],Script_LoadObjectIntoBiasedSlot_TextCharaSub[],Script_LoadObjectIntoBiasedSlot_TextNsbmd[];
// Original: arm9/ov001 @ 0x0215B72C; symbol: func_ov001_0215b72c; size: 0x298.
// Loads an archive or model resource into an object slot in the biased range 160..191.
extern "C" int Script_LoadObjectIntoBiasedSlot(char *parameters,int count) {
 GameState *game;SafeAllocator *allocator;unsigned sourceState;BackgroundLoader *loader;GameObject *object;int compressed;void *copy;int index;
 game=GameState::GetInstance();
 loader=BackgroundLoader::GetInstance();
 sourceState=Script_ReadParameterString(parameters);
 index=Script_ResolveEventObjectIndex(Script_ReadParameterAsInteger((IntegerParameterView*)(parameters+8)));
 int pool=0;
 if(count>=3)pool=Script_ReadParameterAsInteger((IntegerParameterView*)(parameters+16));
 allocator=EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[pool];
 if(index<160 || index>191)return 0;
 char path[80],archive[80];
 ObjectArchiveLoadInfo info;
 void *file=0;unsigned size=0;
 if(Event_ResolveCharacterArchiveMember((const char*)sourceState,path,archive))loader->GetLoadedFileInArchive(archive,path,&file,&size);
 else {sprintf(path,Script_LoadEventTextTable_PathDataS,(const char*)sourceState);loader->GetLoadedFileByName(path,&file,&size);}
 // The source name is no longer needed; reuse its word for scratch-lock ownership.
 sourceState=0;
 if(!file) {
  BackgroundLoader::AddLockGlobal();sourceState=1;
  if(!Event_LoadFileIntoSharedScratch(path,&file)) {BackgroundLoader::RemoveLockGlobal();return 0;}
 }
 object=(GameObject*)allocator->Allocate(0xac);
 if(!object) {if(sourceState)BackgroundLoader::RemoveLockGlobal();return 0;}
 object->obj3D_.Initialize();
 if(strstr(path,Script_LoadObjectIntoBiasedSlot_TextChr)) {
  compressed=0;
  if(strstr(path,Script_LoadObjectIntoBiasedSlot_TextEnemy)||strstr(path,Script_LoadObjectIntoBiasedSlot_TextCharaSub))compressed=1;
  info.allocator=allocator;info.fileData=file;info.unk_8=size;info.unk_10=1;
  if(compressed==0)object->obj3D_.LoadFromCHRArchive(&info);
  else if(compressed==1)object->obj3D_.LoadFromCCHROrCMOTArchive(&info,0);
  object->obj3D_.SetBCFGAnimationByIndex(0,0);
 } else if(strstr(path,Script_LoadObjectIntoBiasedSlot_TextNsbmd)) {
  copy=allocator->Allocate(size);
  memcpy(copy,file,size);
  object->obj3D_.SetModelFromFile(allocator,copy,size,(Model3D::TextureStagingMode)0);
 } else {if(sourceState)BackgroundLoader::RemoveLockGlobal();return 0;}
 if(sourceState)BackgroundLoader::RemoveLockGlobal();
 GameState_SetIndexedObjectAndSlot(game,index,object);
 object->obj3D_.SetScale(0x10a,0x10a,0x10a);
 return 1;
}
