#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void _Z19BlockCurrentContextP18BlockedContextList(void*);
struct Ring {unsigned char pad[0x28];unsigned write;int pad2;unsigned read;unsigned char pad3[0x20];void* blocked;unsigned char* buffer;unsigned capacity;};
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Ring NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov031 @ 0x02200AF8; symbol: func_ov031_02200af8; size: 0xC0.
extern "C" unsigned char* Network_WaitForReceivedEthernetFrame(unsigned* size){
 int irq=_Z20DisableIRQInterruptsv();
 while(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.read==NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.write){
 NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.blocked=OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[1];
 _Z19BlockCurrentContextP18BlockedContextList(0);
 NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.blocked=0;
 }
 _Z20SetIRQInterruptStatei(irq);
 unsigned char* buffer=NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.buffer;
 unsigned length;
 do{
 if(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.capacity-NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.read<2)NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.read=0;
 length=*(unsigned short*)(buffer+NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.read);
 if(!length)NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.read=0;
 }while(!length);
 *size=length-2;
 return NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.buffer+NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.read+2;
}
