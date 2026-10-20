#include <globaldefs.h>
ARM
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char *, unsigned, unsigned);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void Graphics_FormatFiveRowSelectionText(unsigned char *, char *);
extern "C" void Graphics_FormatFiveRowSelectionText(unsigned char *, char *);
extern "C" void Window_PushTextCanvas(void *, void *, int, int, int, int, int, int);
extern "C" void Grid_SetOrientationAndCoordinatePointers(unsigned char *, int, int, int);
extern "C" void Grid_SetEntryCountAndClampSelection(int *, int);
extern "C" void Grid_SelectIndexAndInvalidateTouchHistory(void *, int);
extern "C" void Grid_SelectIndexAndComputePageCoordinates(void *, int);
// Original: arm9/ov013 @ 0x02185310; symbol: InitializeMatchingSelectionOverlay; size: 0x114.
extern "C" void InitializeMatchingSelectionOverlay(unsigned char *p) {
    Window_BindNextCanvasResourceByFormatAndLayer((char *)p + 0x38, 0, 2);
    *(short *)(p + 0xd8) = 0x1e;
    *(short *)(p + 0xda) = 0xd;
    *(short *)(p + 0xdc) = 1;
    *(short *)(p + 0xde) = 0;
    *(short *)(p + 0xe0) = 0;
    *(short *)(p + 0xe2) = 5;
    *(short *)(p + 0xe4) = 10;
    *(short *)(p + 0xe6) = 0xd;
    p[0xe9] = 0;
    if (p[0x640] != 0) *(volatile unsigned char *)(p + 0xed) = 0;
    else *(volatile unsigned char *)(p + 0xed) = 1;
    memset(*(void **)(p + 0x658), 0, 0x960);
    Graphics_FormatFiveRowSelectionText(p, *(char **)(p + 0x658));
    Window_PushTextCanvas(p + 0x38, *(void **)(p + 0x658), 0, 0, 0, 1, 0, 0);
    p[0xe9] = 0;
    *(int *)(p + 0x40) = 1;
    *(int *)(p + 0x90) = 1;
    Grid_SetOrientationAndCoordinatePointers(p + 0x3c, 1, 6, 0);
    Grid_SetOrientationAndCoordinatePointers(p + 0x8c, 1, 6, 0);
    Grid_SetEntryCountAndClampSelection((int *)(p + 0x3c), 6);
    Grid_SetEntryCountAndClampSelection((int *)(p + 0x8c), 6);
    Grid_SelectIndexAndInvalidateTouchHistory(p + 0x3c, 1);
    Grid_SelectIndexAndComputePageCoordinates(p + 0x8c, 1);
}
