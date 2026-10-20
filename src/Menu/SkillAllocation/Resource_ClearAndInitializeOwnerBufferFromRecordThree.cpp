#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned int);
extern "C" void AppendTwoChoiceLabels(void*, void*);
extern "C" int Window_ReplaceCanvasTextById(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov013 @ 0x02186C1C; symbol: Resource_ClearAndInitializeOwnerBufferFromRecordThree; size: 0x48.
// Clears 0x960 bytes at owner+0x658, initializes that buffer, and loads ready record 3 into owner+0x38.
extern "C" void Resource_ClearAndInitializeOwnerBufferFromRecordThree(void* self) {
    memset(*(void**)((char*)self + 0x658), 0, 0x960);
    AppendTwoChoiceLabels(self, *(void**)((char*)self + 0x658));
    Window_ReplaceCanvasTextById((char*)self + 0x38, 3, *(void**)((char*)self + 0x658), 1, 1);
}
