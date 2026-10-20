#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))
#define V(p,o) (*(char**)((p)+(o)))
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];extern "C" int Script_ReadParameterAsInteger(void*);extern "C" void _ZN8Object3D11DisableFlagEi(void*,int);extern "C" void _ZN8Object3D10EnableFlagEi(void*,int);extern "C" void Object3D_MakeFirstAvailableRepresentationVisible(char*);extern "C" void Object_HideFirstAvailableRenderTarget(unsigned char*);
struct Ref{int type,a,b;char* object;};
// Original: arm9/ov001 @ 0x02161408; symbol: Script_SetReferencedObjectVisibilityByRecordKind; size: 0x11C.
extern "C" int Event_ScriptSetReferencedObjectVisibility(char* params){
int index=Script_ReadParameterAsInteger(params);int enabled=Script_ReadParameterAsInteger(params+8);Ref* base=(Ref*)V(EventGetObjectSession_UnknownRoleZeroInitializedStorage,4);switch(base[index].type){case 0:case 1:case 4:case 5:{char* object=base[index].object;if(!object)return 0;if(enabled)_ZN8Object3D11DisableFlagEi(object,1);else _ZN8Object3D10EnableFlagEi(object,1);break;}case 6:{char* object=base[index].object;if(!object||!V(object,24))return 0;if(enabled){_ZN8Object3D11DisableFlagEi(V(object,24),1);Object3D_MakeFirstAvailableRepresentationVisible(V(V(EventGetObjectSession_UnknownRoleZeroInitializedStorage,4)+index*16,12));}else{_ZN8Object3D10EnableFlagEi(V(object,24),1);Object_HideFirstAvailableRenderTarget((unsigned char*)V(V(EventGetObjectSession_UnknownRoleZeroInitializedStorage,4)+index*16,12));}break;}case 2:{char* object=base[index].object;if(!object)return 0;if(enabled)Object3D_MakeFirstAvailableRepresentationVisible(object);else Object_HideFirstAvailableRenderTarget((unsigned char*)object);break;}default:break;}return 1;
}
