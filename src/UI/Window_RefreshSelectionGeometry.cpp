struct WindowCanvasOwner;
struct WindowCanvasRecord;
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned); extern "C" void TextCanvas_GetMarkedRectangleArrays(void*,int*,int*,int*,int*); extern "C" void Grid_SetTouchCellBounds(void*,int,int,int,int,int);
// Original: arm9/main @ 0x0205D904; symbol: func_0205d904; size: 0x78.
 extern "C" void Window_RefreshSelectionGeometry(unsigned char *self) { int a,b,c,d; unsigned char *target=(unsigned char *)Window_FindActiveCanvasById((WindowCanvasOwner*)(self),self[0xb0]); if(target) { TextCanvas_GetMarkedRectangleArrays(target,&a,&b,&c,&d); Grid_SetTouchCellBounds(self+4,18,a,b,c,d); short x=*(short*)(target+0xac),y=*(short*)(target+0xae); *(short*)(self+0x3c)=x*8; *(short*)(self+0x3e)=y*8; } }
