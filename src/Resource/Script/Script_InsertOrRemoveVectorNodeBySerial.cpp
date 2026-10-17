#include <globaldefs.h>
ARM
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
struct State{unsigned char pad[10];unsigned short serial,id;unsigned short padE;void* object;SafeAllocator* alloc;};extern "C" {extern State data_02108cec;void InitializeRecordAndInvalidHalfwordIndices(void*);void LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(void*,int);void SelectNodeRankFromEntryFlags(void*,void*);
// Original: arm9/main @ 0x0206C010; symbol: func_0206c010; size: 0xE8.
int Script_InsertOrRemoveVectorNodeBySerial(Script::Parameter* p,int count){data_02108cec.serial++;unsigned int id=p->ToInt();if(id!=data_02108cec.id)return 1;unsigned char* node=(unsigned char*)data_02108cec.alloc->Allocate(0x78);if(!node)return 0;InitializeRecordAndInvalidHalfwordIndices(node);*(short*)(node+2)=id;node[0]=(p+1)->ToInt();if(count<3){LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(data_02108cec.object,node[0]);return 1;}Script::Parameter* next=(p+2)->ToVec3fix((Vector3fix*)(node+16));*(short*)(node+0x1c)=(int)(4096.0f*next->ToFloat());if(count>6)node[0x1e]=(next+1)->ToInt();*(unsigned short*)(node+0x44)=data_02108cec.serial;SelectNodeRankFromEntryFlags(data_02108cec.object,node);return 1;}}
