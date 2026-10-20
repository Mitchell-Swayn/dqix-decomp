#include <globaldefs.h>
ARM
struct Node{virtual void Pass0(int);virtual void Pass1(int);virtual void Pass2(int);virtual void Pass3(int);virtual void Pass4(int);char padding[20];Node* next;};
extern "C" int System_DispatchFirstInactiveRecordGroup(void*,int);
extern "C" void Util_SelectFirstEligibleLinkedNode(void*,int);
// Original: arm9/ov023 @ 0x021F68DC; symbol: DispatchThreeVirtualPassesAndFallbackListUpdate; size: 0xa8.
extern "C" void MenuRecordList_RunUpdatePassesAndDispatchSelection(Node** self,int value) {
 Node* node=*self;for(;node;node=node->next)node->Pass3(value);
 node=*self;for(;node;node=node->next)node->Pass0(value);
 node=*self;for(;node;node=node->next)node->Pass4(value);
 if(!System_DispatchFirstInactiveRecordGroup(self,value))Util_SelectFirstEligibleLinkedNode(self,value);
}
