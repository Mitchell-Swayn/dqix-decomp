#include <globaldefs.h>
ARM
extern "C" void *_ZN8Object3D24GetLoadedAnimationRecordEPKc(void *, const char *);
// Original: arm9/ov015 @ 0x0218F39C; symbol: ResolveLoadedAnimationRecord; delegates animation lookup.
extern "C" void *CharacterViewer_FindLoadedAnimation(void *object, const char *name) { unsigned char state=*(unsigned char *)((char *)object+0x1c); void *target=*(void **)((char *)object+0x24); switch(state){case 0: case 1: return _ZN8Object3D24GetLoadedAnimationRecordEPKc(target,name); default: return _ZN8Object3D24GetLoadedAnimationRecordEPKc(target,name);}}
