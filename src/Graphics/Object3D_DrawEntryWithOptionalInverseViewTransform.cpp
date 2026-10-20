#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include "Graphics/NSBXX/RenderConfig.h"
struct Bits { unsigned char low:2; bool sub:1; unsigned char transform:1, high:4; };extern "C" void Object3D_CopyPosition(Object3D *,const Vector3fix *);extern "C" void Object3D_DrawEffectHandle(Object3D *);
// Original: arm9/main @ 0x02059F54; symbol: func_02059f54; size: 0xCC.
extern "C" void Object3D_DrawEntryWithOptionalInverseViewTransform(Object3D *p,int index) {unsigned char *raw=(unsigned char *)p;if(*(short *)(raw+0xb0)<=0 && GameState::GetInstance()->GetGameObjectByIndex(index)) {Vector3fix original=*(Vector3fix *)(raw+0x44);Bits *bits=(Bits *)(raw+0xcc);if(bits->transform){Vector3fix temporary=*(Vector3fix *)(raw+0x44);Mat4x3_ApplyToVector(&temporary,RenderConfig::GetInverseViewMatrix(),&temporary);Object3D_CopyPosition(p,&temporary);}if(!*(unsigned *)(raw+0xac))p->Draw(bits->sub);else Object3D_DrawEffectHandle(p);if(bits->transform)Object3D_CopyPosition(p,&original);}}
