#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" void Network_RecordWirelessErrorUnlessTerminal(void);
extern "C" void Network_RestartCallbackForCurrentOperation(void);
extern "C" int ValidateSlotAgainstSharedMaskAndSubmit(const void *, unsigned int, void *, unsigned int);
extern "C" void Network_RestartOperationAndTrackFailure(void);
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int NetworkGetAssociationId_UnknownRoleZeroInitializedStorage;
extern "C" void Network_HandleDisconnectCompletion(void);
// Original: arm9/main @ 0x0202D584; symbol: func_0202d584; size: 0x68.
extern "C" void Network_BeginDisconnectOperationAndHandleFailure(void *self, unsigned int unused1, unsigned int unused2, unsigned int unused3) {
 if (*(unsigned short *)((char *)self + 2) != 0) {
  Network_RecordWirelessErrorUnlessTerminal();
  Network_RestartCallbackForCurrentOperation();
  return;
 }
 *(unsigned int *)((char *)&NetworkGetAssociationId_UnknownRoleZeroInitializedStorage + 0x10) = 3;
 int result = ValidateSlotAgainstSharedMaskAndSubmit((const void *)&Network_HandleDisconnectCompletion, 0, &NetworkGetAssociationId_UnknownRoleZeroInitializedStorage, 3);
 int success = 0;
 if (result == 2) success = 1;
 else {
  Network_RecordWirelessErrorUnlessTerminal();
  Network_RestartOperationAndTrackFailure();
  success = 0;
 }
 if (success == 0) *(unsigned int *)((char *)&NetworkGetAssociationId_UnknownRoleZeroInitializedStorage + 0x10) = 9;
}
