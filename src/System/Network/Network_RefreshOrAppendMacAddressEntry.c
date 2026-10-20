#pragma opt_propagation off
#pragma optimize_for_size off
typedef struct Entry {unsigned tag;unsigned char mac[6],pad[64];unsigned char enabled,pad2[5];signed char active;unsigned char tail[111];} Entry;
typedef struct Object {unsigned pad[3];int count;Entry entries[10];int timers[10];} Object;
// Original data: arm9/main @ 0x20feffc; symbol: data_020feffc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4168 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Entry NetworkConnectToDiscoveredPeerByIndex_UnknownRoleZeroInitializedStorage[];extern void Network_CopyDiscoveredPeerDescriptor(Entry *,const Entry *);
// Original: arm9/main @ 0x0202BAF4; symbol: func_0202baf4; size: 0x10C.
void Network_RefreshOrAppendMacAddressEntry(Object *p,const Entry *input){int n,i;if(!input->active||!input->enabled)return;n=p->count;if(n>0){for(i=0;i<n;++i){Entry *e=NetworkConnectToDiscoveredPeerByIndex_UnknownRoleZeroInitializedStorage+i;int same=e->mac[0]==input->mac[0]&&e->mac[1]==input->mac[1]&&e->mac[2]==input->mac[2]&&e->mac[3]==input->mac[3]&&e->mac[4]==input->mac[4]&&e->mac[5]==input->mac[5];if(same)break;}if(i!=n){Network_CopyDiscoveredPeerDescriptor(p->entries+i,input);p->timers[i]=4000;return;}}if(n<10){Network_CopyDiscoveredPeerDescriptor(p->entries+n,input);p->timers[p->count]=4000;++p->count;}}
