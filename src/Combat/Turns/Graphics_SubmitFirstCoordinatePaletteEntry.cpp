#include <globaldefs.h>
ARM
// Exact layout from the owning Graphics_PopulateAlignedIndexedRecord definition.
struct DrawRequest { int x,y; unsigned int palette; int alignment; int a; short index; };
extern "C" void Graphics_PopulateAlignedIndexedRecord(const DrawRequest*);
// Original: arm9/ov000 @ 0x021704D8; symbol: func_ov000_021704d8; size: 0x60.
// Configures centered alignment and submits the first indexed coordinate/palette entry, then clears its palette.
extern "C" void Graphics_SubmitFirstCoordinatePaletteEntry(DrawRequest* request,const int* x,const int* y,const unsigned* palettes)
{
    request->alignment=2;
    request->a=1;
    for(int i=0;i<1;++i) {
        int nextY=y[i];
        int nextX=x[i];
        request->x=nextX;request->y=nextY;request->palette=palettes[i];
        Graphics_PopulateAlignedIndexedRecord(request);
    }
    request->palette=0;
}
