#include <globaldefs.h>
ARM
extern "C" unsigned ReadWordFieldAtOffset1C(void);
extern "C" void* memset(void*, int, unsigned);
extern "C" void Graphics_AppendGroupedMemberNameText(void*, unsigned, unsigned, void*);
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x021788D8; symbol: func_ov000_021788d8; size: 0x60.
extern "C" void Object_RebuildReadyRecordBufferAndLoad(void* self, unsigned id, unsigned argument) {
    if (id == 0) return;
    unsigned char* data = *(unsigned char**)((char*)ReadWordFieldAtOffset1C() + 0x5c);
    memset(data, 0, 0x960);
    Graphics_AppendGroupedMemberNameText(self, id, argument, data);
    LoadMatchingReadyRecordAndRefreshOwner((char*)self + 0x188, 0xe, data, 1, 0);
}
