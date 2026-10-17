#include <globaldefs.h>
ARM
extern "C" void ClearMatchingAssociationUnderIRQProtection(void*,unsigned,unsigned);extern "C" void DispatchCommandThirtyTwoWithTwoValues(void*,void*);extern "C" void ClearLinkedCommandNodesAndFlushEachHeader(void*);
// Original: arm9/main @ 0x020BE4A4; symbol: func_020be4a4; size: 0x30.
extern "C" void PrepareRangeAndFinalizeOperation(char* p,int size,unsigned a,unsigned b){ClearMatchingAssociationUnderIRQProtection(p,a,b);DispatchCommandThirtyTwoWithTwoValues(p,p+size);ClearLinkedCommandNodesAndFlushEachHeader(p);}
