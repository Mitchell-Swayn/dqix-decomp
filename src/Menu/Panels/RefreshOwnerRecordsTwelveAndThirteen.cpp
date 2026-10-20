#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Owner;
extern "C" {int Window_ReplaceCanvasTextById(Owner*,unsigned,void*,unsigned,unsigned char);void Menu_AppendOptionalPanelText(void*);void Text_AppendGlyphGrid(void*);}
// Original: arm9/ov023 @ 0x021E81F4; symbol: func_ov023_021e81f4; size: 0x7C.
extern "C" void RefreshOwnerRecordsTwelveAndThirteen(unsigned char* p){
memset(*(void**)(p+0x5d8),0,0x960);
Menu_AppendOptionalPanelText(p);
Window_ReplaceCanvasTextById((Owner*)(p+0x78),12,*(void**)(p+0x5d8),0,1);
memset(*(void**)(p+0x5d8),0,0x960);
Text_AppendGlyphGrid(p);
Window_ReplaceCanvasTextById((Owner*)(p+0x78),13,*(void**)(p+0x5d8),0,1);
}
