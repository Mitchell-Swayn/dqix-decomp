#include <globaldefs.h>
ARM
struct PacketRing { unsigned char pad[0x28]; volatile unsigned write; unsigned pad2; volatile unsigned read; unsigned char pad3[0x24]; unsigned char* buffer; volatile unsigned capacity; };
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" PacketRing NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x224968c; symbol: data_ov031_0224968c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex aaaa03000000080000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ProcessBufferAfterSixByteHeader_UnknownRoleInitializedBytes[];
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
// Original: arm9/ov031 @ 0x022008AC; symbol: func_ov031_022008ac; size: 0x1F4.
extern "C" void Network_AppendValidatedFrameToRing(const void* source,const void* destination,const unsigned char* packet,unsigned length,const void* extra,unsigned extraLength) {
 unsigned total; unsigned short size; unsigned next;
 unsigned char* buffer=NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.buffer;
 if(!buffer || !NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.capacity) return;
 total=length+extraLength;
 if(total<8 || total>0x5e4) return;
 if(packet[0]!=ProcessBufferAfterSixByteHeader_UnknownRoleInitializedBytes[0] || packet[1]!=ProcessBufferAfterSixByteHeader_UnknownRoleInitializedBytes[1] || packet[2]!=ProcessBufferAfterSixByteHeader_UnknownRoleInitializedBytes[2] || packet[6]!=8) return;
 if(packet[7]!=0 && packet[7]!=6) return;
 size=(total+9)&~1;
 next=NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.write+size;
 if(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.write<NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.read && NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.read<=next) return;
 if(next==NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.capacity) { next=0; if(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.read==0) return; }
 else if(next>NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.capacity) { next=size; if(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.read<=size) return; }
 if(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.write+size>NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.capacity) {
  if(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.capacity-NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.write>=2) *(unsigned short*)(buffer+NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.write)=0;
  NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.write=0;
 }
 *(unsigned short*)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.buffer+NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.write)=size;
 MI_CpuCopy8(destination,NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.buffer+NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.write+2,6);
 MI_CpuCopy8(source,NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.buffer+NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.write+8,6);
 MI_CpuCopy8(packet+6,NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.buffer+NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.write+14,length-6);
 if(extra && extraLength) MI_CpuCopy8(extra,NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.buffer+NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.write+8+length,extraLength);
 NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.write=next;
}
