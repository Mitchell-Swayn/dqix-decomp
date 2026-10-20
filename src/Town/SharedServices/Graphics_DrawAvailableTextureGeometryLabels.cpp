#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void*);
extern "C" void TextCanvas_GetGroupEntryPixelRectangle(char*,int,int,short*,short*,short*,short*);
extern "C" bool TextCanvas_HasDisplayPart(void*,int);
extern "C" void Tavern_SubmitMenuSpriteAtPosition(void*,short,short,int,int);
struct Keys { short value[3]; };
struct Source { char padding[0x28]; Keys keys; };
// Original data: arm9/ov003 @ 0x217f3ec; symbol: data_ov003_0217f3ec.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 780051003c000000030000000400000006000700.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" Source GraphicsDrawAvailableTextureGeometryLabels_UnknownRoleInitializedBytes;
// Original data: arm9/ov003 @ 0x217f448; symbol: data_ov003_0217f448.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex a600a700a800ffffab00ffff.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" short GraphicsDrawAvailableTextureGeometryLabels_UnknownRoleInitializedBytes_Variant2[][2];
// Original: arm9/ov003 @ 0x0216052C; symbol: func_ov003_0216052c; size: 0x14C.
extern "C" void Graphics_DrawAvailableTextureGeometryLabels(char* self) {
 if(!*(void**)(self+0x324)) return;
 if(Network_IsSessionActive(Network_GetConnectionManager())) return;
 char* object=*(char**)(self+0x324);
 if(!(*(unsigned*)(self+0x464)&0x10000)) return;
 Keys keys=GraphicsDrawAvailableTextureGeometryLabels_UnknownRoleInitializedBytes.keys;
 for(int i=0;i<3;i++) {
 unsigned char j,label;
 short key=keys.value[i];
 if(TextCanvas_HasDisplayPart(object,key)) {
 label=1;
 short x,y,a,b;
 for(j=0;j<2;j++) {
 int id=GraphicsDrawAvailableTextureGeometryLabels_UnknownRoleInitializedBytes_Variant2[i][j];
 if(id<0) continue;
 TextCanvas_GetGroupEntryPixelRectangle(object,key,id,&x,&y,&a,&b);
 b=(16-b)>>1;
 unsigned current=label++;
 Tavern_SubmitMenuSpriteAtPosition(self,(short)(x+a+6),(short)(y-b+1),0,current);
 }
 break;
 }
 }
}
