#include "globaldefs.h"
#include "std_library_functions.h"

// Original: arm9/ov031 @ 0x022411e4; symbol: ReadNamedSegmentedValueOrThreeByteFallback.
// Original data: arm9/ov031 @ 0x2290fc4; symbol: data_ov031_02290fc4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290fc8; symbol: data_ov031_02290fc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int Http_FindResponseHeaderValueSpan(unsigned char*,char*,int*),Util_CompareStringsViaSignedCharacterRoutine(char*,char*),Http_CopyHeaderBufferRange(unsigned char*,unsigned char*,int,int);extern void(*HttpDestroyRequest_UnknownRoleZeroInitializedStorage)(void*);extern void*(*HttpCreateRequestFromUrl_UnknownRoleZeroInitializedStorage_Variant2)(unsigned,int);extern char Http_GetResponseHeaderOrStatusCode_TextHTTPSTATUSCODE[];
extern "C" ARM int Http_GetResponseHeaderOrStatusCode(unsigned char*self,char*key,unsigned char**out){if(!*(unsigned*)(self+8))return -1;if(*(void**)(self+20)){HttpDestroyRequest_UnknownRoleZeroInitializedStorage(*(void**)(self+20));*(void**)(self+20)=0;}int offset;int length=Http_FindResponseHeaderValueSpan(self,key,&offset);if(length>=0){unsigned char*value=(unsigned char*)HttpCreateRequestFromUrl_UnknownRoleZeroInitializedStorage_Variant2(length+1,4);*(unsigned char**)(self+20)=value;value[length]=0;Http_CopyHeaderBufferRange(self,*(unsigned char**)(self+20),offset,length);*out=*(unsigned char**)(self+20);return length;}if(Util_CompareStringsViaSignedCharacterRoutine(Http_GetResponseHeaderOrStatusCode_TextHTTPSTATUSCODE,key))return -1;unsigned char*value=(unsigned char*)HttpCreateRequestFromUrl_UnknownRoleZeroInitializedStorage_Variant2(4,4);*(unsigned char**)(self+20)=value;value[3]=0;Http_CopyHeaderBufferRange(self,*(unsigned char**)(self+20),9,3);*out=*(unsigned char**)(self+20);return 3;}