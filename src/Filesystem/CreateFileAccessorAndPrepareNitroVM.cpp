#include <globaldefs.h>
#include <Filesystem/FileAccessor.h>
void NitroVM_Initialize(NitroVM*);
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int Filesystem_ReadHeaderAndOptionalAllocatedPayload(void*,unsigned,unsigned); extern void* NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
struct FileState { unsigned pad[12]; unsigned state; NitroVM vm; NitroFileAccessor file; unsigned a,b,data,c; };
// Original: arm9/main @ 0x020BD110; symbol: func_020bd110; size: 0x80.
extern "C" void CreateFileAccessorAndPrepareNitroVM(FileState* obj,const char* path,unsigned flags,unsigned mode) { unsigned char* p=(unsigned char*)obj; *(unsigned*)(p+140)=0; *(unsigned*)(p+132)=0; *(unsigned*)(p+136)=0; *(unsigned*)(p+144)=0; if(!CreateFileAccessor(&obj->file,path))return; NitroVM_Initialize(&obj->vm); if(!NitroVM_PrepareReadFileByID(&obj->vm,obj->file))return; *(unsigned*)(p+48)=1; if(Filesystem_ReadHeaderAndOptionalAllocatedPayload(p,flags,mode))NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage=p; }
