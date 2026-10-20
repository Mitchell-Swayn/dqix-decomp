#include <globaldefs.h>
ARM
struct DrawRequest { int x,y; unsigned int palette; int alignment; int a; short index; };
// Original data: arm9/main @ 0x2105244; symbol: data_02105244.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char* TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage;
extern "C" int Graphics_ReadIndexedRecordHorizontalExtent(const DrawRequest*);
extern "C" void TextCache_AppendEntryOamSprites(unsigned char* self,int index,int a,int b,int c,unsigned int palette);
// Original: arm9/main @ 0x0203C1C8; symbol: func_0203c1c8; size: 0x80.
extern "C" void Graphics_PopulateAlignedIndexedRecord(const DrawRequest* request) {
 if (TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage) {
 int extent=Graphics_ReadIndexedRecordHorizontalExtent(request);
 int half=extent>>1;
 int x=request->x;
 int y=request->y;
 switch(request->alignment) {
 case 1: x-=extent; break;
 case 2: x-=half; break;
 case 3: x=128-half; break;
 }
 TextCache_AppendEntryOamSprites(TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage,request->index,request->a,x,y,request->palette);
 }
}
