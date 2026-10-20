#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" void *Queue_AppendNode(void *queue);
extern "C" void *memcpy(void *destination, const void *source, unsigned length);
// Original: arm9/ov001 @ 0x02158F30; symbol: func_ov001_02158f30; size: 0x34.
extern "C" void CutsceneCamera_QueueTargetPosition(void *queue, Vector3fix position) {
    unsigned char *node = (unsigned char *)Queue_AppendNode(queue);
    if (!node) return;
    *(unsigned *)node = 2;
    memcpy(node + 0x10, &position, 12);
}
