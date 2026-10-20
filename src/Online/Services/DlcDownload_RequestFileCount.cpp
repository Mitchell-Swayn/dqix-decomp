#include <globaldefs.h>
ARM
extern "C" int DlcDownload_CreateAuthenticatedRequest(int**,unsigned*,void*,void*,int,int);
extern "C" int System_StoreAsyncResultAndHandleNegativeStatus(int*,unsigned);
// Original data: arm9/ov031 @ 0x2290f08; symbol: data_ov031_02290f08.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char DlcDownload_RequestFileCount_TextY291BnQ[],DlcDownloadRequestFileCount_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0223F1E8; symbol: InitializeAsyncOperationWithArgument; size: 0x7c.
extern "C" int DlcDownload_RequestFileCount(int value){
int* object;unsigned argument;if(!DlcDownload_CreateAuthenticatedRequest(&object,&argument,DlcDownload_RequestFileCount_TextY291BnQ,DlcDownloadRequestFileCount_UnknownRoleZeroInitializedStorage,128,0))return 0;object[1]=1;object[4]=value;return System_StoreAsyncResultAndHandleNegativeStatus(object,argument)!=0;
}
