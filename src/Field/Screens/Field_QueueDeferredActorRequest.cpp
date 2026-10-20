#include <globaldefs.h>
#include <Resource/GameResources.h>
ARM
extern "C" int LinkedQueue_GetFrontKindOrInvalid(char **);
extern "C" void Field_InitializeDeferredActorRequest(void *);
extern "C" void Field_CopyDeferredActorRequestDescriptor(void *, unsigned int);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int *, unsigned int);
// Original: arm9/ov017 @ 0x021A7A74; symbol: func_ov017_021a7a74; size: 0x68.
extern "C" void Field_QueueDeferredActorRequest(void *unused, unsigned int value) {
    GameResources *resources = GameResources_GetInstance();
    char **link = *(char *** )((char *)resources + 0x3000 + 0x6fc);
    if (LinkedQueue_GetFrontKindOrInvalid(link) == 0x1a && *(int *)(*(char **)((char *)resources + 0x3000 + 0xb0c) + 0x64) != 0) return;
    void *node = *(void **)((char *)resources + 0x3000 + 0xb98);
    Field_InitializeDeferredActorRequest(node);
    Field_CopyDeferredActorRequestDescriptor(node, value);
    LinkedQueue_AppendAndMarkActive((unsigned int *)link, (unsigned int)node);
}
