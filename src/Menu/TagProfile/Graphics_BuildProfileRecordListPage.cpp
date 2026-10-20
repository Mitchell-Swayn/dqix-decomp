#include <globaldefs.h>
extern "C" void TextMarkup_AppendFrameTag(void*, int, int, int, int, int),TextMarkup_AppendCursorTag(void*, int),Text_AppendFormattedIntegerAndStringFragment(void*, int, const void*),Text_AppendFormatString(void*, const void*),TextMarkup_AppendPaletteTag(void*,int);
extern "C" const void* MessageTextTable_FindTextById(void*, short);
struct ProfilePageBits { unsigned short index : 5; unsigned short value : 11; };
extern "C" void Graphics_ConfigureProfilePageLayout(void*,unsigned,int,int),ProfileEditor_AppendUnlockedTitleChoices(void*,void*,int),Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
extern "C" void* memset(void*,int,unsigned);
// Attach the profile list, enabling paging when more than sixteen values exist.
// Original: arm9/ov012 @ 0x0218A7A0; symbol: func_ov012_0218a7a0; size: 0xA4.
extern "C" void Graphics_BuildProfileRecordListPage(unsigned char* screen) {
    Graphics_ConfigureProfilePageLayout(screen,screen[0x1371],0,1);
    memset(*(void**)(screen+0x1374),0,0x960);
    ProfileEditor_AppendUnlockedTitleChoices(screen,*(void**)(screen+0x1374),0);
    int count = ((ProfilePageBits*)(screen+0x13c4))->value;
    int paged = (count - 1) / 16 > 0;
    Window_PushTextCanvas(screen+0xac,*(void**)(screen+0x1374),0,0,paged,1,0,0);
}
