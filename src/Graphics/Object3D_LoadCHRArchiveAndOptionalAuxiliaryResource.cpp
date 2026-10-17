#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <World/Object3D.h>
#include <Resource/ResourceMutex.h>
#include <Filesystem/NarcHandle.h>
#include <Filesystem/LowNitroHandle.h>
#include <Filesystem/FileAccessor.h>
extern "C" const char data_020f04b4[],data_020f04b8[];extern "C" void InitializeSignedAllocatorLists(void*);extern "C" void RelocateSerializedPointerTables(void*,SafeAllocator*,const void*,int);
// Original: arm9/main @ 0x020553EC; symbol: func_020553ec; size: 0x16C.
extern "C" int Object3D_LoadCHRArchiveAndOptionalAuxiliaryResource(unsigned* p,unsigned value,SafeAllocator* allocator,const unsigned char* file,int arg) {p[0]=value;p[0x7a]=0;Object3D* object=(Object3D*)(p+5);object->Initialize();InitializeSignedAllocatorLists(p+0x30);if(allocator)p[1]=(unsigned)allocator;ObjectArchiveLoadInfo info;info.unk_0=0;info.unk_10=0;info.unk_14=0;info.unk_18=0;info.packageID=0;info.fileData=file;info.unk_8=arg;info.allocator=allocator;object->LoadFromCHRArchive(&info);LockResourceMutex();NarcHandle archive;if(archive.Initialize(data_020f04b4,file)) {NitroVM vm;NitroVM_Initialize(&vm);char path[80];unsigned index=0;while(PrepareReadFileInNARCByID(&vm,&archive,index)) {NitroVM_WriteOutFilePath(&vm,path,80);if(strstr(path,data_020f04b8)) {const void* data=archive.GetFileByIndex(index);int length=vm.fileInfo.endOffset;length-=vm.fileInfo.startOffset;RelocateSerializedPointerTables(p+0x30,allocator,data,length);p[0x7a]=1;NitroVM_FinishRead(&vm);break;}NitroVM_FinishRead(&vm);++index;}archive.Destroy();}UnlockResourceMutex();if(!p[0x7a])object->MaybeSetBCFGAnimation(0,0);return 1; }
