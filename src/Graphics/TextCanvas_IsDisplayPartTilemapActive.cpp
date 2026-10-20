#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void *TextCanvas_FindDisplayPartByKey(void *,int);int TextCanvas_HasActiveTilemap(void *);
// Original: arm9/main @ 0x020811E8; symbol: func_020811e8; size: 0x2C.
bool TextCanvas_IsDisplayPartTilemapActive(void *p,int i){void *q=TextCanvas_FindDisplayPartByKey(p,i);if(q)return TextCanvas_HasActiveTilemap(q)!=0;return false;}
}
