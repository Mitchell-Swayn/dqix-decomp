#include <globaldefs.h>
ARM
extern "C" char* ReadWordFieldAtOffset1C();extern "C" void Object_InitializeFixedPointRangeAndByteDefaults(void*);extern "C" void InitializeEmbeddedDisplayRecords(void*);extern "C" void ClearFourHalfwordsAndFourWordsWithTrailing7FFF(void*);extern "C" void func_020462d0(void*,void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x0205C840; symbol: func_0205c840; size: 0xC4.
extern "C" void TextLayout_ResetBuffersAndLoadedLineEntries(unsigned char* p){char* state=ReadWordFieldAtOffset1C();state[0x19b0]=0;Object_InitializeFixedPointRangeAndByteDefaults(p+4);InitializeEmbeddedDisplayRecords(p+28);ClearFourHalfwordsAndFourWordsWithTrailing7FFF(p+180);*(unsigned*)(p+208)=0;if(p[562]){state=ReadWordFieldAtOffset1C();for(int i=0;i<p[562];++i)func_020462d0(state,p+288+*(unsigned short*)(p+544+i*2)*2,256);}memset(p+288,0,256);memset(p+544,0,16);*(unsigned short*)(p+560)=0;p[562]=0;p[563]=0;p[564]=0;}
