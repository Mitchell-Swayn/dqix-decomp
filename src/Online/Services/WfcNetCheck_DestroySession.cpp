#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov031 @ 0x224e60c; symbol: data_ov031_0224e60c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
typedef void(*Release)(const char*,void*,unsigned);extern "C" {extern unsigned char WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage[];extern char WfcNetCheck_DestroySession_TextFREEDWChttp[],WfcNetCheck_DestroySession_TextFREEDWCnetcheckBody302[],WfcNetCheck_DestroySession_TextFREEDWCnetcheckBodyWayport[],WfcNetCheck_DestroySession_TextFREEDWCnetcheck[];void Memory_ReleaseContextBuffersAndReset(unsigned char*);void NasAuth_DestroySession();}
// Original: arm9/ov031 @ 0x02219080; symbol: Memory_ReleaseSharedContextAndNamedBuffers; size: 0xf8.
// Releases pending context and named buffers through registered allocator callback.
extern "C" void WfcNetCheck_DestroySession(){Release release=*(Release*)(P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,0)+0x110c);if(P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,20)){Memory_ReleaseContextBuffersAndReset(P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,20));release(WfcNetCheck_DestroySession_TextFREEDWChttp,P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,20),0);P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,20)=0;}NasAuth_DestroySession();if(!P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,0))return;if(P(P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,0),0x1114)){release(WfcNetCheck_DestroySession_TextFREEDWCnetcheckBody302,P(P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,0),0x1114),0);P(P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,0),0x1114)=0;}if(P(P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,0),0x1118)){release(WfcNetCheck_DestroySession_TextFREEDWCnetcheckBodyWayport,P(P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,0),0x1118),0);P(P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,0),0x1118)=0;}release(WfcNetCheck_DestroySession_TextFREEDWCnetcheck,P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,0),0);P(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,0)=0;}
