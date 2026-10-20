#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" void* GameState_GetIndexList(void*);
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*, unsigned, unsigned);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void* Text_LookupStandardString(unsigned int);
extern "C" int Text_AppendFormatString(char*, const char*);
extern "C" void TextLayout_ResetFormattingWorkspace(signed char*);
extern "C" void TextContext_SetNumericArgument(unsigned int*, int, unsigned int);
extern "C" void TextContext_SetNumericArgumentWidth(char*, int, int);
extern "C" void TextContext_SetNumericArgumentAlignment(char*, int, int);
extern "C" void Window_PushTextCanvas(void*, void*, int, int, int, int, int, int);
// Original: arm9/ov003 @ 0x0216982C; symbol: GameState_InitializeSelectedPairRecordAndFormatBuffer; size: 0x10c.
extern "C" void Bank_OpenHeldGoldWindow(char* self) {
    void* gameState = _ZN9GameState11GetInstanceEv();
    unsigned int owner = TextContext_GetSharedInstance();
    void* indexList = GameState_GetIndexList(gameState);
    Window_BindNextCanvasResourceByFormatAndLayer(self + 0xe4, 0, 2);
    *(unsigned short*)(self + 0x184) = 0xb;
    *(unsigned short*)(self + 0x186) = 2;
    *(unsigned short*)(self + 0x188) = 0x14;
    *(unsigned short*)(self + 0x18a) = 0;
    *(unsigned short*)(self + 0x18c) = 0x10;
    *(unsigned short*)(self + 0x18e) = 2;
    *(unsigned short*)(self + 0x190) = 0xa;
    *(unsigned short*)(self + 0x192) = 0xe;
    self[0x195] = 0;
    self[0x199] = 1;
    memset(*(char**)(self + 0x7c), 0, 0x960);
    Text_AppendFormatString(*(char**)(self + 0x7c), (const char*)Text_LookupStandardString(0x3f1));
    TextLayout_ResetFormattingWorkspace((signed char*)owner);
    TextContext_SetNumericArgument((unsigned*)owner, 0, *(unsigned int*)((char*)indexList + 0xf6c));
    TextContext_SetNumericArgumentWidth((char*)owner, 0, 7);
    TextContext_SetNumericArgumentAlignment((char*)owner, 0, 1);
    Window_PushTextCanvas(self + 0xe4, *(char**)(self + 0x7c), 0, 0, 0, 1, 0, 0);
}
