#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2105244; symbol: data_02105244.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char* TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage;extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(void*,unsigned,int);
// Original: arm9/main @ 0x0203C248; symbol: func_0203c248; size: 0x3C.
extern "C" void TextSprite_DecodeCachedText(unsigned char* object,unsigned value){if(!TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage)return;unsigned char* base=TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage+4;short index=*(short*)(object+20);if(index<0)return;Text_MapInputBytesToVariableLengthOutputSequences(base+index*0x28,value,0);}
