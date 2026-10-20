#pragma thumb off
#pragma optimization_level 2
struct TokenFlags{signed char length:6;unsigned char other:2;};
extern "C" {int TextStream_IsControlToken(void*,const void*);int TextStream_TestFFPrefixMarker(void*,const void*);int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);int Text_ClassifyControlCodesFF20ThroughFF25(void*,const void*);char* TextLookup_FindMatchingByteKeyEntry(const void*,int);}
// Original: arm9/main @ 0x0206AC94; symbol: func_0206ac94; size: 0xE0.
extern "C" unsigned char* TextStream_FindEncodedControlToken(char* owner,unsigned value,unsigned char* text,unsigned extra){if(!text)return 0;if(!TextStream_IsControlToken(owner,&value))return 0;unsigned consumed=0;for(;;){if(!*text)break;if(TextStream_TestFFPrefixMarker(owner,text)){if(!RuntimeMemory_CompareByteRanges(&value,text,2))return text;int count=Text_ClassifyControlCodesFF20ThroughFF25(owner,text)*2+2;text+=count;consumed+=count;continue;}int step=1;char* token=TextLookup_FindMatchingByteKeyEntry(text,*(unsigned char*)(owner+0x19dc));if(token)step=((TokenFlags*)(token+5))->length;consumed+=step;text+=step;if(*(unsigned*)(owner+0x68)<consumed)break;}return 0;}
