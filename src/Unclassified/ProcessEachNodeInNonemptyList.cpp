#include <globaldefs.h>
struct Node{char pad[0x1ec];Node* next;};struct List{Node* head;int count;};extern "C" void Model3D_RestagePresentTexturePalette(Node*),Object_RestageOptionalModelTextureImage(Node*);
// Original: arm9/main @ 0x02058564; symbol: func_02058564; size: 0x38.
extern "C" ARM void ProcessEachNodeInNonemptyList(List* p){if(p->count<=0)return;for(Node* node=p->head;node;node=node->next){Model3D_RestagePresentTexturePalette(node);Object_RestageOptionalModelTextureImage(node);}}
