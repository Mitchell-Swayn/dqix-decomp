#include <globaldefs.h>
ARM
extern "C" void __clear(void*,unsigned);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" int FindIndexedBinaryKeyByLengthComparison(const void*,int);
extern "C" char* TextLookup_FindMatchingByteKeyEntry(const void*,int);
extern "C" int EncodeTextAsGlyphIds(const char*,unsigned char*,unsigned);
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
extern "C" unsigned char data_ov003_0217f3b0[];
// Original: arm9/ov003 @ 0x0215EC90; symbol: func_ov003_0215ec90; size: 0x1B4.
extern "C" int Text_InsertSelectedGlyphWithinLengthAndWidthLimits(unsigned char* self) {
 unsigned char* p;
 int saved;
 unsigned char* text;
 int width;
 unsigned mode;
 int limit;
 unsigned char* rec=*(unsigned char**)self;
 if(!rec) goto fail;
 {
 if(rec[15]) return 13;
 unsigned selected=data_ov003_0217f3b0[self[0x20]];
 unsigned other=self[0x1e];
 mode=self[0x1f];
 text=*(unsigned char**)(self+8);
 width=*(int*)(self+0xc);
 limit=*(int*)(self+0x14);
 void* key=*(void**)(rec+4);
 if(selected==other) key=*(void**)(rec+8);
 unsigned char encoded[256];
 __clear(encoded,256);
 int glyph=FindIndexedBinaryKeyByLengthComparison(key,mode);
 int length=EncodeTextAsGlyphIds((char*)text,encoded,mode);
 p=encoded;
 for(int i=0;i<limit;i++,p++) {
 if(i==limit-1) {
 saved=*p;
 *p=glyph;
 if(width) {
 unsigned char temp[256];__clear(temp,256);
 Text_MapInputBytesToVariableLengthOutputSequences(encoded,temp,mode);
 if(width<TextLayout_ComputeWidthWithGlyphSpacing((char*)temp,0)) {*p=saved;goto fail;}
 }
 Text_MapInputBytesToVariableLengthOutputSequences(encoded,text,mode);
 self[0x20]=0;
 return limit<=length+1?3:2;
 } else if(*p==0) {
 if(width) {
 saved=TextLayout_ComputeWidthWithGlyphSpacing((char*)text,0);
 char* match=TextLookup_FindMatchingByteKeyEntry(key,0);
 if(match) saved+=*(signed char*)(match+4)+1;
 if(width<saved) goto fail;
 }
 *p=glyph;
 Text_MapInputBytesToVariableLengthOutputSequences(encoded,text,mode);
 self[0x20]=0;
 return limit<=length+1?3:2;
 }
 }
 }
 fail:
 return 0;
}
