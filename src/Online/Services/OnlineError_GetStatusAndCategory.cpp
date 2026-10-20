#include "globaldefs.h"
#include "std_library_functions.h"
// Original: arm9/ov031 @ 0x022119d0; symbol: ReadSharedStatusAndWriteMappedClass.
// Original data: arm9/ov031 @ 0x224e5a4; symbol: data_ov031_0224e5a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned OnlineErrorIsSet_UnknownRoleZeroInitializedStorage[];
extern "C" ARM unsigned OnlineError_GetStatusAndCategory(unsigned*result,unsigned*category){if(result)*result=OnlineErrorIsSet_UnknownRoleZeroInitializedStorage[1];if(category){switch(OnlineErrorIsSet_UnknownRoleZeroInitializedStorage[0]){case 2:case 3:case 4:case 5:case 8:*category=6;break;case 6:*category=3;break;case 7:*category=4;break;case 10:case 11:case 12:case 13:*category=1;break;case 1:case 9:*category=7;break;case 14:*category=5;break;case 15:case 17:case 19:*category=6;break;case 16:case 18:case 20:case 21:*category=2;break;default:*category=0;break;}}return OnlineErrorIsSet_UnknownRoleZeroInitializedStorage[0];}