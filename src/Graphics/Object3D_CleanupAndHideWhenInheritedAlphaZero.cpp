#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" int _ZNK8Object3D17GetInheritedAlphaEv(void*);extern "C" void Object3D_InitializeExtendedMovementStateDefaults(void*);extern "C" void _ZN8Object3D10MakeHiddenEv(void*);
// Original: arm9/main @ 0x02078660; symbol: func_02078660; size: 0x28.
extern "C" void Object3D_CleanupAndHideWhenInheritedAlphaZero(void* p){if(_ZNK8Object3D17GetInheritedAlphaEv(p))return;Object3D_InitializeExtendedMovementStateDefaults(p);_ZN8Object3D10MakeHiddenEv(p);}
