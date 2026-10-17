#include <globaldefs.h>
ARM
extern "C" { unsigned OV017_ReadWordField04(void*); void* _ZN9GameState11GetInstanceEv(); void* _ZN9GameState20GetGameObjectByIndexEi(void*,int); int sprintf(char*,const char*,...); int ReadScriptParameterAsInteger(void*); int ConvertNegativeIndexToBiasedMagnitude(int); void* _ZN16BackgroundLoader11GetInstanceEv(); void _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(void*,const char*,void**,unsigned*); void _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEP13SafeAllocatorPKvj(void*,void*,const void*,unsigned); void _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEPKcP13SafeAllocator(void*,const char*,void*); extern char data_ov001_02165745[]; extern void* data_ov001_021658b8; }
// Original: arm9/ov001 @ 0x0215F344; symbol: func_ov001_0215f344; size: 0xB8.
extern "C" int Graphics_LoadScriptSelectedTypeZeroAnimationPackage(unsigned char* parameters) {
 unsigned name=OV017_ReadWordField04(parameters);
 void* state=_ZN9GameState11GetInstanceEv();
 if(!state) return 0;
 char path[32];
 sprintf(path,data_ov001_02165745,name);
 int index=ConvertNegativeIndexToBiasedMagnitude(ReadScriptParameterAsInteger(parameters+8));
 void* object=_ZN9GameState20GetGameObjectByIndexEi(state,index);
 if(!object) return 0;
 void* allocator=data_ov001_021658b8;
 void* code;
 unsigned size;
 _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(_ZN16BackgroundLoader11GetInstanceEv(),path,&code,&size);
 if(code) _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEP13SafeAllocatorPKvj(object,allocator,code,size);
 else _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEPKcP13SafeAllocator(object,path,allocator);
 return 1;
}
