#include <globaldefs.h>
#include <System/Matrix.h>
ARM
struct Owner;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void GameObject_ChangeMotionStateAndRefreshAnimation(Owner*,unsigned int);
extern "C" bool _ZNK8Object3D25IsTransitioningAnimationsEv(void*);
// Original: arm9/ov017 @ 0x021BF6FC; symbol: func_ov017_021bf6fc; size: 0xB0.
extern "C" int World_PollDistanceAndAnimationCountdown(unsigned char* p) {
unsigned char* object=_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
unsigned char* target=*(unsigned char**)(p+12);
Vector3fix current=*(Vector3fix*)(object+0x44);
Vector3fix destination;
*(int*)((unsigned char*)&destination+0)=*(int*)(target+8);
*(int*)((unsigned char*)&destination+4)=*(int*)((unsigned char*)&current+4);
*(int*)((unsigned char*)&destination+8)=*(int*)(target+16);
int distance=Vector3fix_Distance(&current,&destination);
--*(short*)(p+0x14);
if(distance<0x199 || (*(short*)(p+0x14)<0 && !_ZNK8Object3D25IsTransitioningAnimationsEv(object))){
GameObject_ChangeMotionStateAndRefreshAnimation((Owner*)object,0);*(short*)(p+0x14)=-1;return 2;
}
return 1;
}
