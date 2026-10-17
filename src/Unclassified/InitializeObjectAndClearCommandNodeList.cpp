#include <globaldefs.h>
ARM
extern "C" void ClearMatchingAssociationUnderIRQProtection(void*,void*,void*);
extern "C" void ClearLinkedCommandNodesAndFlushEachHeader(void*);
// Original: arm9/main @ 0x020BE4D4; symbol: func_020be4d4; size: 0x20.
extern "C" void InitializeObjectAndClearCommandNodeList(void* object,int unused,void* a,void* b) {
    ClearMatchingAssociationUnderIRQProtection(object,a,b);
    ClearLinkedCommandNodesAndFlushEachHeader(object);
}
