#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma always_inline on
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
// Original data: arm9/main @ 0x20ef74c; symbol: data_020ef74c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 407d00000800000008000000ffffffff.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int DebugMenuInitialize_UnknownRoleInitializedBytes[];
// Original data: arm9/main @ 0x20ef772; symbol: data_020ef772.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 256300.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ef775; symbol: data_020ef775.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 256400.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char DebugMenuUpdateAndRender_UnknownRoleInitializedBytes_Variant3[],DebugMenuUpdateAndRender_UnknownRoleInitializedBytes_Variant4[];
inline int MeasureText(const char* text) { int width; if(text) width=TextLayout_ComputeWidthWithGlyphSpacing(text,1); return width; }
// Original: arm9/main @ 0x0202A6C4; symbol: func_0202a6c4; size: 0x208.
extern "C" void TextLayout_ComputeLinkedMenuDimensions(char* self) {
 int maxWidth=strlen(self+4);
 if(DebugMenuInitialize_UnknownRoleInitializedBytes[3]>=3 && DebugMenuInitialize_UnknownRoleInitializedBytes[3]<=6) maxWidth=MeasureText(self+4)/DebugMenuInitialize_UnknownRoleInitializedBytes[2];
 char* entry=*(char**)(self+0x44);
 int index=0;
 int width;
 int measured;
 while(entry) {
 if(DebugMenuInitialize_UnknownRoleInitializedBytes[3]>=3 && DebugMenuInitialize_UnknownRoleInitializedBytes[3]<=6) {
 if(entry+4) measured=TextLayout_ComputeWidthWithGlyphSpacing(entry+4,1);
 measured/=DebugMenuInitialize_UnknownRoleInitializedBytes[2];
 width=measured;
 if(*(short*)(self+0x5c)>=0 && *(short*)(self+0x5c)<=*(short*)(self+0x5e) && *(short*)(self+0x5c)<=index && index<=*(short*)(self+0x5e)) width=measured+2;
 if(*(int*)entry==2) width+=6;
 if(*(int*)entry==3) {
 width+=4;
 char number[16];
 if(*(unsigned short*)(entry+0x4c)&0x80) sprintf(number,DebugMenuUpdateAndRender_UnknownRoleInitializedBytes_Variant3,*(int*)(entry+0x40)+64);
 else sprintf(number,DebugMenuUpdateAndRender_UnknownRoleInitializedBytes_Variant4,*(int*)(entry+0x40));
 width+=strlen(number)*2;
 }
 } else {
 width=strlen(entry+4);
 if(*(short*)(self+0x5c)>=0 && *(short*)(self+0x5c)<=*(short*)(self+0x5e) && *(short*)(self+0x5c)<=index && index<=*(short*)(self+0x5e)) width++;
 if(*(int*)entry==2) width+=3;
 }
 entry=*(char**)(entry+0x34);
 if(maxWidth<width) maxWidth=width;
 index++;
 }
 *(short*)(self+0x54)=(maxWidth+3)*DebugMenuInitialize_UnknownRoleInitializedBytes[2];
 *(short*)(self+0x56)=(*(unsigned short*)(self+0x5a)+3)*(*(volatile int*)&DebugMenuInitialize_UnknownRoleInitializedBytes[1]);
 if(*(short*)(self+0x50)+*(short*)(self+0x56)>192) *(short*)(self+0x56)=192-*(short*)(self+0x50)-(*(volatile int*)&DebugMenuInitialize_UnknownRoleInitializedBytes[1]);
 *(short*)(self+0x62)=*(short*)(self+0x56)/(*(volatile int*)&DebugMenuInitialize_UnknownRoleInitializedBytes[1])-2;
 int start=*(short*)(self+0x5c);
 int end=*(short*)(self+0x5e);
 int total=*(unsigned short*)(self+0x5a);
 int rows=*(unsigned short*)(self+0x62);
 int remaining=rows-(total-(end-start));
 *(short*)(self+0x64)=start;
 *(short*)(self+0x66)=start+remaining;
}
