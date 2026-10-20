#include <globaldefs.h>
ARM
struct Connection { unsigned active; unsigned char pad[6]; unsigned short port; };
struct Node { unsigned char pad[0x68]; Node* next; unsigned char pad2[0x38]; Connection* connection; };
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern Node* OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[]; extern unsigned short NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[]; }
// Original: arm9/ov031 @ 0x02203078; symbol: func_ov031_02203078; size: 0xA8.
extern "C" unsigned Network_SelectUnusedEphemeralPort(Node* head) {
 head=OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[2];
 int used;
 do {
  used=0;
  ++NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[4];
  unsigned port=NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[4];
  if(port<1024 || port>=5000) NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[4]=1024;
  Node* node=head;
  if(node) {
   unsigned current=NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[4];
   do {
   Connection* connection=node->connection;
   if(connection && connection->active && connection->port==current) { used=1; break; }
   node=node->next;
   } while(node);
  }
 } while(used);
 return NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[4];
}
