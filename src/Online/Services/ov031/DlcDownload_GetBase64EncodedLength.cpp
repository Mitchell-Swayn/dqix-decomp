#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0223E438; symbol: DlcDownload_GetBase64EncodedLength; size: 0x1C.
// Rounds the signed input upward by two, divides by three with truncation, and scales by four.
extern "C" int DlcDownload_GetBase64EncodedLength(int value) { return ((value+2)/3)*4; }
