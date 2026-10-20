struct Flags19 { unsigned char b0:1,pad:1,b2:1,rest:5; };
extern "C" char* DisplayLayout_GetGroupByIndex(void*,int);
extern "C" int TouchInput_IsNewPress(void*);
extern "C" void WindowFrame_SetLinkedPosition(void*,short,short);
extern "C" void WindowFrame_SetLinkedDimensions(void*,short,short);
extern "C" void TextWindow_SetClippingEdges(void*,int,int,int,int);
#pragma force_active on
// Original: arm9/main @ 0x02012AD0; symbol: func_02012ad0; size: 0x84.
extern "C" int TouchInput_UpdateRepeatCountdown(unsigned char* p){bool active=p[95]&&*(unsigned short*)(p+36);if(active){int n=*(int*)(p+88);if(!n){if(TouchInput_IsNewPress(p)){*(int*)(p+88)=12;return 1;}else{*(int*)(p+88)=2;return 1;}}*(int*)(p+88)=n-1;}else if(!p[95]||!*(unsigned short*)(p+36))*(int*)(p+88)=0;return 0;}
