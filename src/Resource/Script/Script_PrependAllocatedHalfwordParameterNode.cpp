#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Node{unsigned char flag,id,count,pad;unsigned short*values;unsigned unused[2];Node*next;};struct Owner{char pad[0x754];Node*head;};struct Global{unsigned reserved[2];SafeAllocator*allocator;unsigned padc;Owner*owner;};extern "C" Global PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x0201F660; symbol: func_0201f660; size: 0xC8.
extern "C" ARM int Script_PrependAllocatedHalfwordParameterNode(const Script::Parameter*params,int count){Node*node=(Node*)PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage.allocator->Allocate(20);if(!node)return 0;node->flag=0;*(char*)&node->count=count;node->values=(unsigned short*)PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage.allocator->Allocate((unsigned char)count*2);if(!node->values)return 0;for(int i=0;i<node->count;i++){node->values[i]=params->ToInt();++params;}Node*head=PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage.owner->head;node->id=head?head->id+1:1;node->next=PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage.owner->head;PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage.owner->head=node;return 1;}
