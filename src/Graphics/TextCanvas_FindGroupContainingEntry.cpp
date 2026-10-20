struct Flags19 { unsigned char b0:1,pad:1,b2:1,rest:5; };
extern "C" char* DisplayLayout_GetGroupByIndex(void*,int);
extern "C" int TouchInput_IsNewPress(void*);
extern "C" void WindowFrame_SetLinkedPosition(void*,short,short);
extern "C" void WindowFrame_SetLinkedDimensions(void*,short,short);
extern "C" void TextWindow_SetClippingEdges(void*,int,int,int,int);
#pragma force_active on
// Original: arm9/main @ 0x020810B4; symbol: func_020810b4; size: 0x7C.
extern "C" char* TextCanvas_FindGroupContainingEntry(char* p,int key){short count=*(short*)(p+16);for(short i=0;i<count;++i){char* r=DisplayLayout_GetGroupByIndex(p+12,i);if(r)for(unsigned char j=0;j<(unsigned char)r[19];++j)if((*(short**)r)[j]==key)return r;}return 0;}
