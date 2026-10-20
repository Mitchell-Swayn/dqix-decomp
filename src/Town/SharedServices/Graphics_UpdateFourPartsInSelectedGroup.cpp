#include <globaldefs.h>
ARM
extern "C" void TextCanvas_GetEntryLocalPosition(char*,int,short*,short*);
extern "C" void TextCanvas_SetEntryLocalPosition(char*,int,int,int);
extern "C" void TextCanvas_SetEntryDimensions(unsigned char*,int,int,int);
// Original data: arm9/ov003 @ 0x217f420; symbol: data_ov003_0217f420.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 450015005500.
// Observed span: 6 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" short GraphicsUpdateFourPartsInSelectedGroup_UnknownRoleInitializedBytes[];
// Original: arm9/ov003 @ 0x02160794; symbol: func_ov003_02160794; size: 0xC0.
extern "C" void Graphics_UpdateFourPartsInSelectedGroup(unsigned char* p){
 short x,y;
 if(!*(void**)(p+0x470))return;
 char* object=*(char**)(p+0x324);
 for(int i=0;i<3;i++){
 short index=GraphicsUpdateFourPartsInSelectedGroup_UnknownRoleInitializedBytes[i];
 int selected=**(short**)(p+0x470);
 if(index>selected || selected>=index+4)continue;
 for(int j=0;j<4;j++){
 TextCanvas_GetEntryLocalPosition(object,index,&x,&y);
 TextCanvas_SetEntryLocalPosition(object,index,x,y);
 TextCanvas_SetEntryDimensions((unsigned char*)object,index,208,10);
 index++;
 }
 }
}
