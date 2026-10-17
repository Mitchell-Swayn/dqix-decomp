#include <globaldefs.h>
ARM
extern "C" void ClearMatchingAssociationUnderIRQProtection(void*,unsigned,unsigned);extern "C" void SubmitOperationCodeThirtyOne(void*,void*);extern "C" void UnlinkNodeFromOwnersAndCleanCaches(void*);
// Original: arm9/main @ 0x020BE474; symbol: func_020be474; size: 0x30.
extern "C" void ResourceManager_ConfigureAndSubmitMemoryRange(char* p,int size,unsigned a,unsigned b){ClearMatchingAssociationUnderIRQProtection(p,a,b);SubmitOperationCodeThirtyOne(p,p+size);UnlinkNodeFromOwnersAndCleanCaches(p);}
