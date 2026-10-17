#include <globaldefs.h>
ARM
extern "C" void ClearMaskedFlagsAtOffset5C(void*);extern "C" void Object3D_ApplyPendingNamedOrIndexedAnimation();
struct Object{char pad[20];void* first;void* second;};
// Original: arm9/main @ 0x02040BCC; symbol: func_02040bcc; size: 0x30.
extern "C" void Object_UpdatePrimaryRenderTargetOrSecondaryGlobalState(Object* p){if(p->first){ClearMaskedFlagsAtOffset5C(p->first);return;}if(!p->second)return;Object3D_ApplyPendingNamedOrIndexedAnimation();}
