#include <globaldefs.h>
extern "C" void func_ov028_021d9188(void *);
extern "C" void Object_NoOpCleanup(void *);
extern "C" int _Z13IsSceneLoadedj(unsigned);
extern "C" void func_ov001_0215686c();
// Original: arm9/ov017 @ 0x021BB8F0; symbol: func_ov017_021bb8f0; size: 0x40.
extern "C" void OV017_CleanupStateAndResumeScene(void *state) {
    if (*(void **)((char *)state + 0x160)) func_ov028_021d9188(*(void **)((char *)state + 0x160));
    if (*(void **)((char *)state + 0x120)) Object_NoOpCleanup(*(void **)((char *)state + 0x120));
    if (_Z13IsSceneLoadedj(1)) func_ov001_0215686c();
}
