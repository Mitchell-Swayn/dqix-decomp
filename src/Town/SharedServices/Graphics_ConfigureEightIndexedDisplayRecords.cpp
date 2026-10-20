#include <globaldefs.h>
ARM
struct EightBytes { unsigned char item[8]; };
struct RecordBits { unsigned type:4; unsigned rest:28; };
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_GetObjectWithFlag100(void*,int);
void TextCanvas_ShowDisplayPart(unsigned char*,int);
void TextCanvas_SetGroupPalette(char*,int,unsigned char);
void* TextCanvas_GetResourceTextByKey(void**,int);
void TextCanvas_SetEntryHorizontalOffset(unsigned char*,int,int);
void TextCanvas_SetEntryTextColor(char*,int,unsigned);
void TextCanvas_SetEntryTextPointer(char*,int,int);
void TextCanvas_EnableEntryUppercaseFormatting(unsigned char*,int);
int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
// Original data: arm9/ov003 @ 0x217faa4; symbol: data_ov003_0217faa4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 080907000501060a.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern EightBytes GraphicsConfigureEightIndexedDisplayRecords_UnknownRoleInitializedBytes;
}
// Original: arm9/ov003 @ 0x02177410; symbol: func_ov003_02177410; size: 0x140.
extern "C" void Graphics_ConfigureEightIndexedDisplayRecords(unsigned char* p) {
void* state=_ZN9GameState11GetInstanceEv();
unsigned char* owner=*(unsigned char**)(p+0x89c);
TextCanvas_ShowDisplayPart(owner,14);
TextCanvas_SetGroupPalette((char*)owner,14,0);
unsigned char* object=(unsigned char*)GameState_GetObjectWithFlag100(state,*(signed char*)(p+0x1043));
if(!object)return;
EightBytes indices=GraphicsConfigureEightIndexedDisplayRecords_UnknownRoleInitializedBytes;
int fallback=(int)TextCanvas_GetResourceTextByKey((void**)owner,20);
for(short i=0;i<8;i++) {
unsigned index=indices.item[i];
short key=i+0x68;
int value=fallback; unsigned nibble=3;
if(index!=255) {
unsigned char* record=*(unsigned char**)(object+0x150)+0x194+index*32;
if(!record)continue;
if(*(short*)(record+0x18)>0 && ((RecordBits*)(record+8))->type!=11){value=*(int*)(record+4);nibble=15;}
}
TextCanvas_SetEntryHorizontalOffset(owner,key,13);
TextCanvas_SetEntryTextColor((char*)owner,key,nibble);
TextCanvas_SetEntryTextPointer((char*)owner,key,value);
TextCanvas_EnableEntryUppercaseFormatting(owner,key);
}
TextCanvas_CreateAndConfigureDisplayPart((char*)owner,14);
}
