#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void _ZN8Object3D11MakeVisibleEv(void*);
extern "C" void _ZN8Object3D10MakeHiddenEv(void*);
// Original: arm9/ov001 @ 0x021605D4; symbol: func_ov001_021605d4; size: 0x98.
extern "C" int Graphics_SetScriptObjectPairVisibility(char* args) {
int index=Script_ReadParameterAsInteger((IntegerParameterView*)args);
int visible=Script_ReadParameterAsInteger((IntegerParameterView*)(args+8));
void* state=_ZN9GameState11GetInstanceEv();
int base=index*12;
char* object=_ZN9GameState20GetGameObjectByIndexEi(state,base+28);
if(object && *(short*)(object+2)>=0) {
if(visible) _ZN8Object3D11MakeVisibleEv(object);
else _ZN8Object3D10MakeHiddenEv(object);
}
object=_ZN9GameState20GetGameObjectByIndexEi(state,base+29);
if(object && *(short*)(object+2)>=0) {
if(visible) _ZN8Object3D11MakeVisibleEv(object);
else _ZN8Object3D10MakeHiddenEv(object);
}
return 1;
}
