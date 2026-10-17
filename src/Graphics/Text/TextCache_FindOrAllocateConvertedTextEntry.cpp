#include <globaldefs.h>
ARM
extern "C" void __clear(void*,unsigned);extern "C" unsigned EncodeTextAsGlyphIds(void*,void*,int);extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);extern "C" void func_0203bebc(void*,const void*,void*);
// Original: arm9/main @ 0x0203C5A8; symbol: func_0203c5a8; size: 0x110.
extern "C" void TextCache_FindOrAllocateConvertedTextEntry(unsigned char* p,void* text,short* result,unsigned unused){unsigned char buffer[256];if(!text)return;__clear(buffer,256);unsigned size=EncodeTextAsGlyphIds(text,buffer,0);unsigned char* entry=p+4;for(int i=0;i<32;entry+=40,i=(short)(i+1)){if(entry[36]&&entry[32]==size&&!RuntimeMemory_CompareByteRanges(entry,buffer,size)){entry[36]++;*result=i;return;}}entry=p+4;for(int i=0;i<32;entry+=40,i=(short)(i+1)){if(!entry[36]){char* pool=*(char**)(p+1288);(*(unsigned short*)(p+1298))++;entry[36]=1;entry[32]=size;func_0203bebc(entry,buffer,pool+i*1024);*result=i;return;}}}
