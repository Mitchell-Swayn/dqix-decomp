#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" char WorldMap_SetTitleAndMeasureWidth_Text[];extern "C" unsigned TextLayout_ComputeWidthWithGlyphSpacing(char*,int);
// Original: arm9/main @ 0x02026428; symbol: func_02026428; size: 0x48.
extern "C" ARM void WorldMap_SetTitleAndMeasureWidth(char* p,const char* name){if(!name)strcpy(p+0x5b4,WorldMap_SetTitleAndMeasureWidth_Text);else strcpy(p+0x5b4,name);*(unsigned*)(p+0xbe4)=TextLayout_ComputeWidthWithGlyphSpacing(p+0x5b4,0);}
