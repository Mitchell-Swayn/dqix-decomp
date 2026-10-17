#include <globaldefs.h>
ARM
struct Connection { unsigned active; unsigned char pad[6]; unsigned short port; };
struct Node { unsigned char pad[0x68]; Node* next; unsigned char pad2[0x38]; Connection* connection; };
extern "C" { extern Node* data_02111304[]; extern unsigned short data_ov031_0224c980[]; }
// Original: arm9/ov031 @ 0x02203078; symbol: func_ov031_02203078; size: 0xA8.
extern "C" unsigned Network_SelectUnusedEphemeralPort(Node* head) {
 head=data_02111304[2];
 int used;
 do {
  used=0;
  ++data_ov031_0224c980[4];
  unsigned port=data_ov031_0224c980[4];
  if(port<1024 || port>=5000) data_ov031_0224c980[4]=1024;
  Node* node=head;
  if(node) {
   unsigned current=data_ov031_0224c980[4];
   do {
   Connection* connection=node->connection;
   if(connection && connection->active && connection->port==current) { used=1; break; }
   node=node->next;
   } while(node);
  }
 } while(used);
 return data_ov031_0224c980[4];
}
