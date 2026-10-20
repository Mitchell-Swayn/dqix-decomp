#include <globaldefs.h>
ARM
extern "C" {
char* TextCanvas_FindDisplayPartByKey(char*,unsigned);
bool TextCanvas_IsReady(void*);
void* ZoneState2754_FindPrimaryRecordByKey(void*,int);
void TextCanvas_GetGroupEntryPixelPosition(char*,unsigned,int,short*,short*);
int ZoneSerializedRecord_GetKindIconIndex(void*);
void Shop_SubmitInterfaceSpriteAtPosition(char*,int,int,unsigned char,unsigned char);
int TextCanvas_HasActiveTilemap(char*);
// Original data: arm9/ov003 @ 0x217fa9c; symbol: data_ov003_0217fa9c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1c12151316141718.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
// Original data: arm9/ov003 @ 0x217fabd; symbol: data_ov003_0217fabd.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1c12151316141718191919.
// Observed span: 11 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern unsigned char GraphicsDrawPageRecordKindIcons_UnknownRoleInitializedBytes_Variant2[],GraphicsDrawPageRecordKindIcons_UnknownRoleInitializedBytes[];
}
// Original: arm9/ov003 @ 0x02175504; symbol: func_ov003_02175504; size: 0x278.
extern "C" void Graphics_DrawPageRecordKindIcons(char* self) {
 char* display=*(char**)(self+0x89c);
 unsigned char slot=6;
 char* group=TextCanvas_FindDisplayPartByKey(display,3);
 if(group) {
  if(TextCanvas_IsReady(group)) {
   short part=7;
   short index=*(short*)(self+0x1014)*6;
   for(unsigned char i=0;i<6;part++,index++,i++) {
    void* entry=ZoneState2754_FindPrimaryRecordByKey(self+0x874,*(short*)(self+0x848+index*2));
    if(entry) {
     short x,y;
     TextCanvas_GetGroupEntryPixelPosition(display,3,part,&x,&y);
     int kind=ZoneSerializedRecord_GetKindIconIndex(entry);
     Shop_SubmitInterfaceSpriteAtPosition(self,x,y-1,kind+6,slot);
    }
    slot++;
   }
  }
 } else {
  if(*(short*)(self+0x100c)==119) {
   char* selected=0;
   char* node=TextCanvas_FindDisplayPartByKey(display,21);
   if(node && TextCanvas_IsReady(node))selected=node;
   node=TextCanvas_FindDisplayPartByKey(display,22);
   if(node && TextCanvas_IsReady(node))selected=node;
   node=TextCanvas_FindDisplayPartByKey(display,30);
   if(node && TextCanvas_IsReady(node))selected=node;
   if(selected) {
    short x=*(short*)(selected+0xac),y=*(short*)(selected+0xae);
    unsigned char key=*(short*)(self+0x1012)-286;
    x*=8;y*=8;
    Shop_SubmitInterfaceSpriteAtPosition(self,x+3,y+3,GraphicsDrawPageRecordKindIcons_UnknownRoleInitializedBytes_Variant2[key],6);
    return;
   }
  }
  if(*(void**)(self+0xff8) && *(short*)(self+0xffe)>=0) {
   char* selected=TextCanvas_FindDisplayPartByKey(display,14);
   if(selected && TextCanvas_HasActiveTilemap(selected)) {
    short part=104;
    for(unsigned char i=0;i<8;part++,slot++,i++) {
     short x,y;
     TextCanvas_GetGroupEntryPixelPosition(display,14,part,&x,&y);
     Shop_SubmitInterfaceSpriteAtPosition(self,x,y-1,GraphicsDrawPageRecordKindIcons_UnknownRoleInitializedBytes[i],slot);
    }
   }
  }
 }
}
