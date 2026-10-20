#include <globaldefs.h>
ARM

extern "C" void *GameResources_GetInstance(void);
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *);
extern "C" void ModelObject_InitializeWithOptionalExternalStorage(unsigned *, void *, char *);
extern "C" void BackgroundLoader_QueueFileWhenExternalObjectAbsent(unsigned int *);

// Original: arm9/ov017 @ 0x021B621C; symbol: func_ov017_021b621c; size: 0x74.
extern "C" void Resource_InitializeExternalModelObject(void *object, void *external, char *resourceName) {
    unsigned char *entry = (unsigned char *)object;
    GameResources_GetInstance();
    LinkedQueue_InitializeNodeStatus((signed char *)object);
    entry[0] = 0x16;
    ModelObject_InitializeWithOptionalExternalStorage((unsigned int *)(entry + 0xC), external, (char *)resourceName);
    BackgroundLoader_QueueFileWhenExternalObjectAbsent((unsigned int *)(entry + 0xC));
    entry[0xFC] = 0;
    *(short *)(entry + 0xFE) = -1;
    if (external == 0) {
        entry[0xFD] = 0xF;
    } else {
        entry[0xFD] = 0;
    }
    entry[8] = 1;
    *(short *)(entry + 0x100) = -1;
}
