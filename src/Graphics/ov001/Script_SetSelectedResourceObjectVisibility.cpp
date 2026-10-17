#include <globaldefs.h>
ARM
struct IntegerParameterView;
struct GameResources;
extern "C" {void _ZN8Object3D11MakeVisibleEv(void*);void _ZN8Object3D10MakeHiddenEv(void*);GameResources* GameResources_GetInstance();void* ReadPointerAtOffset4334(GameResources*);void* OV017_ReadWordField4338(GameResources*);int ReadScriptParameterAsInteger(IntegerParameterView*);}
// Original: arm9/ov001 @ 0x02162174; symbol: func_ov001_02162174; size: 0x9C.
extern "C" int Script_SetSelectedResourceObjectVisibility(char* parameters,int count){
int mask;GameResources* resources;int visible=ReadScriptParameterAsInteger((IntegerParameterView*)parameters);mask=0;
if(count>=2)mask=ReadScriptParameterAsInteger((IntegerParameterView*)(parameters+8));
resources=GameResources_GetInstance();
if(mask==0||(mask&1)){void* object=ReadPointerAtOffset4334(resources);if(object){if(visible)_ZN8Object3D11MakeVisibleEv(object);else _ZN8Object3D10MakeHiddenEv(object);}}
if(mask&2){void* object=OV017_ReadWordField4338(resources);if(object){if(visible)_ZN8Object3D11MakeVisibleEv(object);else _ZN8Object3D10MakeHiddenEv(object);}}
return 1;
}
