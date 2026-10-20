struct Flags19 { unsigned char b0:1,pad:1,b2:1,rest:5; };
extern "C" char* DisplayLayout_GetGroupByIndex(void*,int);
extern "C" int TouchInput_IsNewPress(void*);
extern "C" void WindowFrame_SetLinkedPosition(void*,short,short);
extern "C" void WindowFrame_SetLinkedDimensions(void*,short,short);
extern "C" void TextWindow_SetClippingEdges(void*,int,int,int,int);
#pragma force_active on
// Original: arm9/main @ 0x02042B98; symbol: func_02042b98; size: 0x8C.
extern "C" void TextWindow_SetViewportRectangle(char* p,int x,int y,int w,int h){*(int*)(p+2448)=x+(w>>1);WindowFrame_SetLinkedPosition(p+6624,(short)x,(short)y);WindowFrame_SetLinkedDimensions(p+6624,(short)w,(short)h);*(int*)(p+6232)=x;*(int*)(p+6236)=y+8;TextWindow_SetClippingEdges(p+6216,x,y+8,x+w,y+h);}
