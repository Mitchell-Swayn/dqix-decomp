#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" void SetGlobalValueExceptModesNineAndTen(void);
extern "C" void Network_RestartCallbackForCurrentOperation(void);
extern "C" int ValidateSlotAgainstSharedMaskAndSubmit(const void *, unsigned int, void *, unsigned int);
extern "C" void Network_RestartOperationAndTrackFailure(void);
extern "C" unsigned int data_021015a0;
extern "C" void SetInitialStateOrReportMessageError(void);
// Original: arm9/main @ 0x0202D584; symbol: func_0202d584; size: 0x68.
extern "C" void Network_BeginDisconnectOperationAndHandleFailure(void *self, unsigned int unused1, unsigned int unused2, unsigned int unused3) {
 if (*(unsigned short *)((char *)self + 2) != 0) {
  SetGlobalValueExceptModesNineAndTen();
  Network_RestartCallbackForCurrentOperation();
  return;
 }
 *(unsigned int *)((char *)&data_021015a0 + 0x10) = 3;
 int result = ValidateSlotAgainstSharedMaskAndSubmit((const void *)&SetInitialStateOrReportMessageError, 0, &data_021015a0, 3);
 int success = 0;
 if (result == 2) success = 1;
 else {
  SetGlobalValueExceptModesNineAndTen();
  Network_RestartOperationAndTrackFailure();
  success = 0;
 }
 if (success == 0) *(unsigned int *)((char *)&data_021015a0 + 0x10) = 9;
}
