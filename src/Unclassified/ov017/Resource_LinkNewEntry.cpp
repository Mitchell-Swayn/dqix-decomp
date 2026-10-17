#include <globaldefs.h>
#include <Resource/GameResources.h>
ARM
extern "C" int ReadIndirectByteOrMinusOne(char **);
extern "C" void InitializeType40RecordWithDefaults(void *);
extern "C" void func_ov017_021a7c28(void *, unsigned int);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned int *, unsigned int);
// Original: arm9/ov017 @ 0x021A7A74; symbol: func_ov017_021a7a74; size: 0x68.
extern "C" void Resource_LinkNewEntry(void *unused, unsigned int value) {
    GameResources *resources = GameResources_GetInstance();
    char **link = *(char *** )((char *)resources + 0x3000 + 0x6fc);
    if (ReadIndirectByteOrMinusOne(link) == 0x1a && *(int *)(*(char **)((char *)resources + 0x3000 + 0xb0c) + 0x64) != 0) return;
    void *node = *(void **)((char *)resources + 0x3000 + 0xb98);
    InitializeType40RecordWithDefaults(node);
    func_ov017_021a7c28(node, value);
    AppendLinkedNodeAndMarkActive((unsigned int *)link, (unsigned int)node);
}
