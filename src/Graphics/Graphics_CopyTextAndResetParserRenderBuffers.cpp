#include <globaldefs.h>
ARM
extern "C" unsigned String_CountBytesUntilTerminator(const char*);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void* memset(void*,int,unsigned);
extern "C" void ResetTextParserCountersAndProcessSource(void*);
extern "C" void TextLayout_WrapEncodedTextToPixelWidth(void*,unsigned,void*,void*,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x0206A974; symbol: Graphics_CopyTextAndResetParserRenderBuffers; size: 0xb4.
// Copies source text, resets two640-byte rendering buffers, parses and copies rendered text.
extern "C" void Graphics_CopyTextAndResetParserRenderBuffers(char* self,const char* text,unsigned option) {
 if(!text)return;void* destination=*(void**)(self+0x48);*(unsigned*)(self+0x68)=String_CountBytesUntilTerminator(text);memcpy(destination,text,*(unsigned*)(self+0x68));
 *(void**)(self+0x54)=*(void**)(self+0x58)=*(void**)(self+0x48);memset(*(void**)(self+0x4c),0,640);memset(*(void**)(self+0x50),0,640);
 ResetTextParserCountersAndProcessSource(self);TextLayout_WrapEncodedTextToPixelWidth(self,1,*(void**)(self+0x50),*(void**)(self+0x60),option,0,1,1);
 unsigned length=String_CountBytesUntilTerminator(*(char**)(self+0x60));memcpy(*(void**)(self+0x50),*(void**)(self+0x60),length);
}
