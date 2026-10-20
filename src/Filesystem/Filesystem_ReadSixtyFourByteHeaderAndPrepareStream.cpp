#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 4
#include <Filesystem/NitroVM.h>
extern "C" int Filesystem_ReadIndexedResourceRangeInChunks(void*,void*,unsigned,int);extern "C" void ResourceManager_ReadGlobalWordPair7C(NitroFileAccessor*);extern "C" bool _Z27NitroVM_PrepareReadFileByIDP7NitroVM17NitroFileAccessor(void*,NitroFileAccessor);extern "C" unsigned ReadIndexedSixteenByteTableWord0C(void*);
// Original: arm9/main @ 0x020C0044; symbol: func_020c0044; size: 0x74.
extern "C" int Filesystem_ReadSixtyFourByteHeaderAndPrepareStream(char* p,void* handle){if(Filesystem_ReadIndexedResourceRangeInChunks(handle,p+168,64,0)!=64)return 0;NitroFileAccessor access;ResourceManager_ReadGlobalWordPair7C(&access);if(!_Z27NitroVM_PrepareReadFileByIDP7NitroVM17NitroFileAccessor(p+92,access))return 0;*(unsigned*)(p+164)=ReadIndexedSixteenByteTableWord0C(handle);return 1;}
