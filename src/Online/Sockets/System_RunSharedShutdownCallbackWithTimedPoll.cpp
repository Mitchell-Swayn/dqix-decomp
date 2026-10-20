#include <globaldefs.h>
ARM
struct Shutdown {unsigned char a[0x18];void(*start)();char b[0x2c];int(*poll)();char c[4];void* object;};
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Shutdown NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage;
extern "C" void Network_BroadcastArpRequest(void*);
extern "C" void _Z19SleepCurrentContextj(unsigned);
extern "C" unsigned long long _Z19GetCurrentTimestampv();
extern "C" void Network_ResetAddressStateAndWakeSocketWaiters(int);
// Original: arm9/ov031 @ 0x02203BCC; symbol: System_RunSharedShutdownCallbackWithTimedPoll; size: 0xa0.
// Invokes shared shutdown callback, waits up to23 timestamp units while polling and dispatches state4 on abort byte.
extern "C" void System_RunSharedShutdownCallbackWithTimedPoll() {
 NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.start();if(!NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.object)return;
 Network_BroadcastArpRequest(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.object);_Z19SleepCurrentContextj(100);Network_BroadcastArpRequest(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.object);
 int start=(unsigned)(_Z19GetCurrentTimestampv()>>16);
 while(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.poll() && (int)((unsigned)(_Z19GetCurrentTimestampv()>>16)-start)<23) {
 if(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.a[1]){Network_ResetAddressStateAndWakeSocketWaiters(4);return;}_Z19SleepCurrentContextj(100);
 }
}
