#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int sprintf(char*,const char*,...);
extern "C" char* strstr(const char*,const char*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(void*,const char*,void**,unsigned*);
extern "C" void _ZN8Object3D26LoadType0AnimationFromFileEiPKcP13SafeAllocator(void*,int,const char*,void*);
extern "C" void _ZN8Object3D34LoadType0AnimationFromFileInMemoryEiP13SafeAllocatorPKvj(void*,int,void*,const void*,unsigned);
extern "C" int ConvertNegativeIndexToBiasedMagnitude(int);
extern "C" int ReadScriptParameterAsInteger(void*);
extern "C" int OV017_ReadWordField04(void*);
extern "C" void* data_ov001_021658b8;
extern "C" char data_ov001_02165745[],data_ov001_02165791[],data_ov001_02165798[],data_ov001_0216579f[],data_ov001_021657a6[];
struct Param { char bytes[8]; };
// Original: arm9/ov001 @ 0x0215F060; symbol: func_ov001_0215f060; size: 0x150.
extern "C" int Script_LoadType0AnimationsForObjects(Param* params,int count) {
 int name=OV017_ReadWordField04(params++);
 void* state=_ZN9GameState11GetInstanceEv();
 void* allocator=data_ov001_021658b8;
 char path[32];
 sprintf(path,data_ov001_02165745,name);
 int type=-1;
 if(strstr(path,data_ov001_02165791)) type=0;
 else if(strstr(path,data_ov001_02165798)) type=1;
 else if(strstr(path,data_ov001_0216579f)) type=2;
 else if(strstr(path,data_ov001_021657a6)) type=3;
 if(type<0) return 0;
 void* file; unsigned size;
 _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(_ZN16BackgroundLoader11GetInstanceEv(),path,&file,&size);
 for(int i=1;i<count;i++) {
 int index=ReadScriptParameterAsInteger(params++);
 void* obj=_ZN9GameState20GetGameObjectByIndexEi(state,ConvertNegativeIndexToBiasedMagnitude(index));
 if(obj) {
 if(file) _ZN8Object3D34LoadType0AnimationFromFileInMemoryEiP13SafeAllocatorPKvj(obj,type,allocator,file,size);
 else _ZN8Object3D26LoadType0AnimationFromFileEiPKcP13SafeAllocator(obj,type,path,allocator);
 }
 }
 return 1;
}
