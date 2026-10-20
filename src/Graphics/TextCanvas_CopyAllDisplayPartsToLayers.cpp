#include <globaldefs.h>
ARM
struct State{unsigned char pad[0x2c];unsigned char* a;unsigned char* b;unsigned char pad34[5];unsigned char count;};extern "C" {void TextCanvas_CopyVisibleTilemapToLayer(void*);
// Original: arm9/main @ 0x0207FD00; symbol: func_0207fd00; size: 0x44.
void TextCanvas_CopyAllDisplayPartsToLayers(State* p){unsigned char count;unsigned char* cur;if(!p->a||!(cur=p->b))return;count=p->count;for(unsigned char i=0;i<count;i++){TextCanvas_CopyVisibleTilemapToLayer(cur);cur+=0xe0;}}}
