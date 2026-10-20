#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2105244; symbol: data_02105244.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern void* TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage;extern "C" void __clear(void*,unsigned);extern "C" int sprintf(char*,const char*,...);extern "C" void TextCache_RetainEntry(void*,int);extern "C" void TextSprite_ReleaseCachedText(void*);extern "C" void TextCache_FindOrAllocateConvertedTextEntry(void*,char*,void*);extern "C" void TextCache_DropTemporaryEntryReference(void*,int);
// Original: arm9/main @ 0x0203C108; symbol: func_0203c108; size: 0x90.
extern "C" void TextSprite_FormatAndUpdateTextReference(unsigned char* object,const char* format){char buffer[256];if(TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage && format && *format){__clear(buffer,256);sprintf(buffer,format);short value=*(short*)(object+20);TextCache_RetainEntry(TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage,value);TextSprite_ReleaseCachedText(object);TextCache_FindOrAllocateConvertedTextEntry(TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage,buffer,object+20);TextCache_DropTemporaryEntryReference(TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage,value);}}
