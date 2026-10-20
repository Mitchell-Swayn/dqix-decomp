#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned OnlineError_GetStatusAndCategory(...);
// Original data: arm9/ov031 @ 0x224e598; symbol: data_ov031_0224e598.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char YssdClientSetError_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02211764; symbol: ReadSharedResultAndClassifyStatus; size: 0xbc.
// Reads shared result, maps statuses2..6/16/17 into6, zero into0 and other statuses into7.
extern "C" unsigned OnlineError_GetEffectiveStatus(unsigned* value,unsigned* classification){
 unsigned result=OnlineError_GetStatusAndCategory();if(result)return result;if(value)*value=U(YssdClientSetError_UnknownRoleZeroInitializedStorage,4);
 if(classification)switch(U(YssdClientSetError_UnknownRoleZeroInitializedStorage,0)){case 0:*classification=0;break;case 2:case 3:case 4:case 5:case 6:case 16:case 17:*classification=6;break;default:*classification=7;break;}
 return U(YssdClientSetError_UnknownRoleZeroInitializedStorage,0);
}
