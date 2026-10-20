#include <globaldefs.h>
ARM
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void* ResourceStringTable_GetTextByKey(void*, void*);
extern "C" void TextWindow_StartFormattedMessage(int, int, int, int);
// Original: arm9/ov003 @ 0x0217DD10; symbol: func_ov003_0217dd10; size: 0x50.
extern "C" void Resource_InitializeOwnerRecordState(void* object, int selector) {
    unsigned global = TextContext_GetSharedInstance();
    void* record = ResourceStringTable_GetTextByKey((char*)object + 0xcc, (void*)(short)selector);
    TextWindow_StartFormattedMessage(global, (int)record, 0, 0xe3);
    *(unsigned char*)(global + 0x19b2) = 1;
    *(unsigned*)(global + 0x99c) = 2;
}
