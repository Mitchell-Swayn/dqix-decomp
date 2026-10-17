struct Flags19 { unsigned char b0:1,pad:1,b2:1,rest:5; };
extern "C" char* Object_GetBoundedTwentyFourByteEntry(void*,int);
extern "C" int AreByteFields5DSetAnd5EClear(void*);
extern "C" void SetTwoHalfwordsThroughOptionalPointer(void*,short,short);
extern "C" void Object_WriteHalfwordPairInOptionalOffset440Record(void*,short,short);
extern "C" void WriteFourOutputValues(void*,int,int,int,int);
#pragma force_active on
// Original: arm9/main @ 0x02042B98; symbol: func_02042b98; size: 0x8C.
extern "C" void SetRectangleCoordinatesAndDerivedCenter(char* p,int x,int y,int w,int h){*(int*)(p+2448)=x+(w>>1);SetTwoHalfwordsThroughOptionalPointer(p+6624,(short)x,(short)y);Object_WriteHalfwordPairInOptionalOffset440Record(p+6624,(short)w,(short)h);*(int*)(p+6232)=x;*(int*)(p+6236)=y+8;WriteFourOutputValues(p+6216,x,y+8,x+w,y+h);}
