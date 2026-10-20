#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov031 @ 0x224e5c0; symbol: data_ov031_0224e5c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
typedef void(*Callback)(unsigned,unsigned,unsigned);extern "C" {extern Callback* DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage;void OnlineError_SetStatusAndDetail(unsigned,unsigned);void DisableInterruptsAndHaltForever();}
// Original: arm9/ov031 @ 0x022127C0; symbol: System_RecordErrorAndDispatchStatus; size: 0xf8.
// Records error-pair values for status codes then dispatches the shared callback.
extern "C" void DownloadService_ReportStatus(unsigned context,unsigned status,unsigned detail){if(!status){(*DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage)(context,status,detail);return;}switch(status){case 1:OnlineError_SetStatusAndDetail(9,-31001);break;case 2:DisableInterruptsAndHaltForever();break;case 3:OnlineError_SetStatusAndDetail(15,-31020);break;case 4:OnlineError_SetStatusAndDetail(14,-31030);break;case 5:OnlineError_SetStatusAndDetail(14,-31000-detail);break;case 6:break;case 7:DisableInterruptsAndHaltForever();break;case 8:OnlineError_SetStatusAndDetail(9,-31009);break;default:DisableInterruptsAndHaltForever();break;}(*DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage)(context,status,detail);}
