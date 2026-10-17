#include <globaldefs.h>
struct Obj{char pad[0x474];short state;};struct Other{char pad[0x44];int value;};extern "C" void Graphics_SubmitGeometryCommand25(void*),Render_DrawNodeTreeWithLightingVisibility(Obj*,Other*,int,int);
// Original: arm9/main @ 0x02016DB4; symbol: func_02016db4; size: 0x60.
extern "C" ARM void SubmitGeometryStateWithRenderRegisters(Obj* p,Other* q){*(volatile unsigned*)0x04000444=0;if(p->state)Graphics_SubmitGeometryCommand25((char*)p+0x444);Render_DrawNodeTreeWithLightingVisibility(p,q,q->value,0);*(volatile unsigned*)0x04000448=1;}
