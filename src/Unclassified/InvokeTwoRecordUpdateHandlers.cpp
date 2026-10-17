#include <globaldefs.h>
extern "C" void InitializePartyIndexedRecordAndCopyDerivedHalfwords(unsigned,unsigned,unsigned,int);extern "C" void Object_ReadSelectedPairOfTwelveMixedWidthFields(unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020DDAF4; symbol: func_020ddaf4; size: 0x2C.
extern "C" ARM void InvokeTwoRecordUpdateHandlers(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e,unsigned f){InitializePartyIndexedRecordAndCopyDerivedHalfwords(a,b,c,0);Object_ReadSelectedPairOfTwelveMixedWidthFields(a,d,e,f);}
