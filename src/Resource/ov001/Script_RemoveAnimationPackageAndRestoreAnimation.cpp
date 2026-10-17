#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" int _ZN8Object3D24MaybeSetRegularAnimationEPKci(void*,const char*,int);
extern "C" void _ZN8Object3D26RemoveAnimationPackageByIDEi(void*,int);
extern "C" int ConvertNegativeIndexToBiasedMagnitude(int);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" char data_ov001_02165769[];
// Original: arm9/ov001 @ 0x0215BCC0; symbol: func_ov001_0215bcc0; size: 0x9C.
extern "C" int Script_RemoveAnimationPackageAndRestoreAnimation(char* params,int count) {
 int package;
 void* state=_ZN9GameState11GetInstanceEv();
 _ZN16BackgroundLoader11GetInstanceEv();
 int index=ConvertNegativeIndexToBiasedMagnitude(ReadScriptParameterAsInteger((IntegerParameterView*)params));
 package=3;
 if(count>=2) package=ReadScriptParameterAsInteger((IntegerParameterView*)(params+8));
 char* object=_ZN9GameState20GetGameObjectByIndexEi(state,index);
 if(!object) return 0;
 unsigned char mode=*(unsigned char*)(object+0x19);
 const char* animation=*(const char**)(object+0x14);
 _ZN8Object3D26RemoveAnimationPackageByIDEi(object,package);
 if(!_ZN8Object3D24MaybeSetRegularAnimationEPKci(object,animation,mode))
  _ZN8Object3D24MaybeSetRegularAnimationEPKci(object,data_ov001_02165769,0);
 return 1;
}
