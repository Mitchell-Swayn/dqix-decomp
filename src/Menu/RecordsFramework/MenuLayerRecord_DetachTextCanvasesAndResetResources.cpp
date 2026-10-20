#include <globaldefs.h>
ARM

extern "C" unsigned int MenuRecord_GetNext(const void *p);
extern "C" unsigned int MenuRecord_GetType(void *);
extern "C" void Graphics_ResetLoadedLayerResources(unsigned char *p);

// Original: arm9/ov023 @ 0x021F7984; symbol: func_ov023_021f7984; size: 0x60.
extern "C" void MenuLayerRecord_DetachTextCanvasesAndResetResources(void *self, void **headRef) {
    char *node = *(char **)headRef;
    while (node != 0) {
        char *next = (char *)MenuRecord_GetNext(node);
        if (MenuRecord_GetType(node) == 6) {
            char *fields = node + 0x20;
            if (fields != 0 && (char *)self + 0x28 == *(char **)(fields + 4)) {
                *(char **)(fields + 4) = 0;
            }
        }
        node = next;
    }
    Graphics_ResetLoadedLayerResources((unsigned char *)self + 0x28);
}
