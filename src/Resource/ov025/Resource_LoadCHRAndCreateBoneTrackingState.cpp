#include <globaldefs.h>
ARM
struct Path { char text[40]; };
struct LoadInfo { unsigned unknown;void*file;unsigned length,allocator,flag,a,b,c; };
struct Object3D;
extern "C" char data_ov025_021ef988[];
extern "C" Path data_ov025_021eef78;
extern "C" char data_ov025_021ef7f7[],data_ov025_021ef7fb[];
extern "C" char* strcat(char*,const char*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_SetUnknown3b0(void*,void*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" int _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(void*,const char*,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN8Object3D10InitializeEv(void*);
extern "C" bool _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(void*,LoadInfo*);
extern "C" void ClearEightBytes(unsigned*);
extern "C" void InitializeObjectFlag10AndResourceIndices(void*);
extern "C" void Object3D_EnableBoneTrackingAndLinkedFlagBitTwo(char*,Object3D*);
extern "C" void CopyResourceNameAndInvalidateIndex(void*,const char*);
extern "C" void CopyNameAndInvalidateCachedIndex(int,char*);
extern "C" void* GetPointerSelectedByByteIndex(char*);
extern "C" void Util_PrependNodeToListAtOffset1D8(unsigned char*,unsigned char*);
extern "C" void Resource_RemoveIndexedHalfword(void*,int);
// Original: arm9/ov025 @ 0x021E4BE4; symbol: func_ov025_021e4be4; size: 0x22C.
extern "C" int Resource_LoadCHRAndCreateBoneTrackingState(char* self) {
 Path path; LoadInfo info; void* file; unsigned length;
 void* game=_ZN9GameState11GetInstanceEv();
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 unsigned allocator=(unsigned)GetPointerSelectedByByteIndex(*(char**)(data_ov025_021ef988+12));
 path=data_ov025_021eef78;
 strcat(path.text,*(char**)(self+8));
 int task=_ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(loader,path.text,&file,&length);
 if(!file) {
  if(task>=0) { _ZN16BackgroundLoader10RemoveTaskEi(loader,task); Resource_RemoveIndexedHalfword(*(void**)(data_ov025_021ef988+12),task); }
  return 1;
 }
 char* object=_ZN13SafeAllocator8AllocateEj(allocator,0xac);
 if(!object) { _ZN16BackgroundLoader10RemoveTaskEi(loader,task); Resource_RemoveIndexedHalfword(*(void**)(data_ov025_021ef988+12),task); return 1; }
 char* node=_ZN13SafeAllocator8AllocateEj(allocator,12);
 if(!node) { _ZN16BackgroundLoader10RemoveTaskEi(loader,task); Resource_RemoveIndexedHalfword(*(void**)(data_ov025_021ef988+12),task); return 1; }
 _ZN8Object3D10InitializeEv(object);
 ClearEightBytes((unsigned*)&info);
 info.file=file; info.length=length; info.allocator=allocator; info.flag=1;
 if(!_ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(object,&info)) { _ZN16BackgroundLoader10RemoveTaskEi(loader,task); Resource_RemoveIndexedHalfword(*(void**)(data_ov025_021ef988+12),task); return 1; }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,task); Resource_RemoveIndexedHalfword(*(void**)(data_ov025_021ef988+12),task);
 char* tracking=_ZN13SafeAllocator8AllocateEj(allocator,0x268);
 if(!tracking) { _ZN16BackgroundLoader10RemoveTaskEi(loader,task); Resource_RemoveIndexedHalfword(*(void**)(data_ov025_021ef988+12),task); return 1; }
 InitializeObjectFlag10AndResourceIndices(tracking);
 Object3D_EnableBoneTrackingAndLinkedFlagBitTwo(tracking,(Object3D*)object);
 CopyResourceNameAndInvalidateIndex(tracking,data_ov025_021ef7f7);
 CopyNameAndInvalidateCachedIndex((int)tracking,data_ov025_021ef7fb);
 GameState_SetUnknown3b0(game,tracking);
 node[0]=3;
 Util_PrependNodeToListAtOffset1D8(*(unsigned char**)(data_ov025_021ef988+12),(unsigned char*)node);
 return 1;
}
