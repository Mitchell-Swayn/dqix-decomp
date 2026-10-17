#include <globaldefs.h>
ARM
struct GameResources; struct Node;
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned int*,unsigned int);
extern "C" int LinkedList_ContainsTag(Node**,int);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void InitializeKind70ObjectWithTwoBytes(unsigned char*,unsigned char,unsigned char);
// Original: arm9/ov017 @ 0x021D24F0; symbol: func_ov017_021d24f0; size: 0x8C.
extern "C" void Resource_QueueKind70NodeForMatchingObject(void* unused,unsigned char* request,void* state) {
unsigned char* resources=(unsigned char*)GameResources_GetInstance();
Node** list=*(Node***)(resources+0x36fc);
if(LinkedList_ContainsTag(list,10))return;
if(*(unsigned int*)(request+8)!=_ZNK8Object3D10GetField06Ev(_ZN9GameState20GetUnknownGameObjectEv(state)))return;
if(LinkedList_ContainsTag(list,26))return;
unsigned char* node=*(unsigned char**)(resources+0x3bb0);
if(node[2])return;
InitializeKind70ObjectWithTwoBytes(node,1,request[4]);
AppendLinkedNodeAndMarkActive((unsigned int*)list,(unsigned int)node);
}
