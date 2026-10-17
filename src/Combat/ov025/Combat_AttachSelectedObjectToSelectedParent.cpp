#include <globaldefs.h>
ARM
extern "C" int DispatchCombatSelectionProcedure(void*,void*,unsigned,int*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void _ZN8Object3D6DetachEv(void*);
extern "C" void _ZN8Object3D6AttachEPS_PKc(void*,void*,const char*);
// Original: arm9/ov025 @ 0x021E7324; symbol: func_ov025_021e7324; size: 0xA4.
extern "C" int Combat_AttachSelectedObjectToSelectedParent(unsigned char* command,void* context,void* unused,void* selection) {
 int first[12],second[12];
 int a=DispatchCombatSelectionProcedure(selection,context,command[8],first);
 int b=DispatchCombatSelectionProcedure(selection,context,command[9],second);
 if(!a || !b) return 1;
 void* state=_ZN9GameState11GetInstanceEv();
 void* child=_ZN9GameState20GetGameObjectByIndexEi(state,first[0]);
 void* parent=_ZN9GameState20GetGameObjectByIndexEi(state,second[0]);
 if(!child || !parent) return 1;
 _ZN8Object3D6DetachEv(child);
 _ZN8Object3D6AttachEPS_PKc(child,parent,*(const char**)(command+12));
 return 1;
}
