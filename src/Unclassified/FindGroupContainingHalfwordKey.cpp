struct Flags19 { unsigned char b0:1,pad:1,b2:1,rest:5; };
extern "C" char* Object_GetBoundedTwentyFourByteEntry(void*,int);
extern "C" int AreByteFields5DSetAnd5EClear(void*);
extern "C" void SetTwoHalfwordsThroughOptionalPointer(void*,short,short);
extern "C" void Object_WriteHalfwordPairInOptionalOffset440Record(void*,short,short);
extern "C" void WriteFourOutputValues(void*,int,int,int,int);
#pragma force_active on
// Original: arm9/main @ 0x020810B4; symbol: func_020810b4; size: 0x7C.
extern "C" char* FindGroupContainingHalfwordKey(char* p,int key){short count=*(short*)(p+16);for(short i=0;i<count;++i){char* r=Object_GetBoundedTwentyFourByteEntry(p+12,i);if(r)for(unsigned char j=0;j<(unsigned char)r[19];++j)if((*(short**)r)[j]==key)return r;}return 0;}
