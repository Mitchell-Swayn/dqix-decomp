#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance(void);
extern "C" unsigned int ActorPool_GetGlobalInstance(void);
extern "C" void* ActorPool_GetDefinitionList(unsigned);
extern "C" void InitializeType5GraphicsRecord(void*);
extern "C" void* ActorPool_FindDefinitionById(void*, unsigned);
extern "C" void LinkedQueue_AppendAndMarkActive(void*, void*);
extern "C" void Graphics_ReleaseOptionalBackgroundStateAndMark(void*);
// Original: arm9/ov017 @ 0x0219593C; symbol: Resource_InitializeAndLinkModeD7Node; size: 0x78.
// Initializes a resource node, searches its embedded list for key 99, sets mode 0xd7, appends it when found, and conditionally invokes a follow-up handler.
extern "C" void Resource_InitializeAndLinkModeD7Node(void) {
    unsigned char* resources=(unsigned char*)GameResources_GetInstance();
    void* node=*(void**)(resources+0x3710);
    void* container=ActorPool_GetDefinitionList(ActorPool_GetGlobalInstance());
    InitializeType5GraphicsRecord(node);
    *(void**)((char*)node+0x114)=ActorPool_FindDefinitionById(container,99);
    *(unsigned*)((char*)node+0x124)=0xd7;
    if (*(void**)((char*)node+0x114)) LinkedQueue_AppendAndMarkActive(*(void**)(resources+0x36fc),node);
    unsigned char* finalRecord=*(unsigned char**)(resources+0x3b00);
    unsigned char active = finalRecord[2];
    if (active != 0) Graphics_ReleaseOptionalBackgroundStateAndMark(finalRecord);
}
