#pragma thumb off
#pragma optimization_level 2
extern "C" {int TextStream_TestControlMarkerRange(void*,const unsigned short*);int IsCopiedHalfwordHighByteFF(void*,const unsigned short*);int ClassifyValidatedFF20ThroughFF25Code(void*,const unsigned short*);void TextEntry_DecrementReferenceAndResetUnusedEntry(void*,unsigned short);}
// Original: arm9/main @ 0x0206B61C; symbol: func_0206b61c; size: 0x9C.
extern "C" void TextStream_ConsumeTokensUntilStopCondition(char* owner){bool active=true;int consumed=0;unsigned short* cursor=*(unsigned short**)(owner+0x4c)+*(int*)(owner+0x74);while(active){if(TextStream_TestControlMarkerRange(owner,cursor))active=false;if(IsCopiedHalfwordHighByteFF(owner,cursor)){int count=ClassifyValidatedFF20ThroughFF25Code(owner,cursor);cursor+=count;consumed+=count;}else TextEntry_DecrementReferenceAndResetUnusedEntry(owner,*cursor);++cursor;++consumed;}*(int*)(owner+0x74)+=consumed;++*(int*)(owner+0x78);}
