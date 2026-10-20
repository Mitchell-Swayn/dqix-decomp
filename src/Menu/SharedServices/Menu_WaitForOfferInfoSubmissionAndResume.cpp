#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" {extern char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];unsigned DisplayContext_GetGlobalInstance();void DisplayContext_IgnoreCommand(unsigned,int,int,int,int);int DisplayContext_ReportRequestComplete(unsigned);void Menu_CheckOfferTimestampAndResumeMenu(void*);}
// Original: arm9/ov004 @ 0x0215C268; symbol: AdvanceSharedDisplayCommandOrFinish; size: 0xa4.
// Starts shared display command72/202 or clears command state on completion.
extern "C" int Menu_WaitForOfferInfoSubmissionAndResume(void* self){if((*(unsigned char**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage+8))[0x30]){unsigned context=DisplayContext_GetGlobalInstance();if(!(*(unsigned char**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage+8))[0x2c]){DisplayContext_IgnoreCommand(context,0x72,0x202,0,0);++(*(unsigned char**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage+8))[0x2c];return 1;}if(DisplayContext_ReportRequestComplete(context))(*(unsigned char**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage+8))[0x2c]=0;else return 1;}Menu_CheckOfferTimestampAndResumeMenu(self);return 0;}
