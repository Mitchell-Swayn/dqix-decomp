#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
// Original: arm9/ov017 @ 0x021B4760; symbol: func_ov017_021b4760; size: 0x2C.
extern "C" void Filesystem_RemoveBackgroundTaskAndClearId(int* p) { void* loader = _ZN16BackgroundLoader11GetInstanceEv(); int id = p[3]; if (id > -1) { _ZN16BackgroundLoader10RemoveTaskEi(loader, id); p[3] = -1; } }
