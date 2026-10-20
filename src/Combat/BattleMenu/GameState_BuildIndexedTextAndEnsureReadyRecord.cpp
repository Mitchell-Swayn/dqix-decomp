struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" unsigned TextContext_GetSharedInstance(void);
extern "C" void* memset(void*, int, unsigned);
extern "C" int Text_InitializeAndPopulateBoundedOutputBuffer(int, char*);
extern "C" void TextMarkup_ExpandAndWrapText(void*, int, void*, void*, int, int, unsigned);
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" int Window_ReplaceCanvasTextById(void*, unsigned, void*, unsigned, unsigned char);
extern "C" void Window_PushTextCanvas(void*, void*, int, int, int, int, int, int);
// Original: arm9/ov000 @ 0x021781F8; symbol: GameState_BuildIndexedTextAndEnsureReadyRecord; size: 0x124.
// Retains a named stage pointer and reads both source coordinates before fallback initialization.
extern "C" void GameState_BuildIndexedTextAndEnsureReadyRecord(void* owner, void* currentRecord) {
    unsigned char scratch[0x800];
    void* buffer = *(void**)(TextContext_GetSharedInstance() + 0x5C);
    memset(buffer, 0, 0x960);
    int index = *(signed char*)((char*)owner + 0x1D6F);
    int textSize = *(short*)((char*)owner + index * 2 + 0x26);
    Text_InitializeAndPopulateBoundedOutputBuffer(textSize, (char*)buffer);
    TextMarkup_ExpandAndWrapText((void*)TextContext_GetSharedInstance(), 10, buffer, scratch, 0x72, 0, 0);
    void* stage = &scratch[0];
    void* recordOwner = (char*)owner + 0x188;
    if ((void*)Window_FindActiveCanvasById((WindowCanvasOwner*)(recordOwner), 0x21) != 0) {
        Window_ReplaceCanvasTextById(recordOwner, 0x21, stage, 1, 0);
    } else {
        int firstCoordinate = *(int*)((char*)currentRecord + 0x44);
        int secondCoordinate = *(int*)((char*)currentRecord + 0x48);
        *(unsigned short*)((char*)recordOwner + 0xA0) = 0x10;
        *(unsigned short*)((char*)recordOwner + 0xA2) = 8;
        *(unsigned short*)((char*)recordOwner + 0xA4) = (firstCoordinate >> 3) + 0x10;
        *(unsigned short*)((char*)recordOwner + 0xA6) = secondCoordinate >> 3;
        *(unsigned short*)((char*)recordOwner + 0xA8) = 7;
        *(unsigned short*)((char*)recordOwner + 0xAA) = 5;
        *(unsigned short*)((char*)recordOwner + 0xAC) = 10;
        *(unsigned short*)((char*)recordOwner + 0xAE) = 14;
        *((unsigned char*)recordOwner + 0xB1) = 0x21;
        Window_PushTextCanvas(recordOwner, stage, 0, 0, 0, 1, 0, 0);
    }
}
