#include <globaldefs.h>
ARM
struct GameState;struct GameResources;struct ZoneTintState;struct List;struct Node;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" ZoneTintState* GameState_ReadUnkF8(GameState*);
extern "C" void Flags_ClearWordMask(unsigned*,unsigned);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned*,unsigned);
extern "C" void LinkedList_PrependAndMarkNodeActive(List*,Node*);
extern "C" void LinkedQueue_InsertAfterHeadAndMarkLinked(char*,char*);
extern "C" void RemoveLinkedNodeByPointer(int*,int);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void Ov017_InitializeZoneTintRecord(int);
extern "C" void ResetTypeThreeRecordPreservingOptionalPayload(void*,int);
// Original: arm9/ov017 @ 0x0219BD1C; symbol: func_ov017_0219bd1c; size: 0xC0.
extern "C" void Resource_ResetAndInsertTypeThreeRecord(int prepend,int id,int afterHead,int argument){
 unsigned char* state;
 void* gs=_ZN9GameState11GetInstanceEv();
 unsigned char* resources=(unsigned char*)GameResources_GetInstance();
 int* list;
 unsigned char* node=*(unsigned char**)(resources+0x370c);
 list=*(int**)(resources+0x36fc);
 state=(unsigned char*)GameState_ReadUnkF8((GameState*)gs);
 if(node[3])return;
 if(node[2])RemoveLinkedNodeByPointer(list,(int)node);
 Ov017_InitializeZoneTintRecord(argument);
 state[2]=0;state[0x6e]=id;
 ResetTypeThreeRecordPreservingOptionalPayload(node,0);
 if(prepend)LinkedList_PrependAndMarkNodeActive((List*)list,(Node*)node);
 else if(afterHead)LinkedQueue_InsertAfterHeadAndMarkLinked((char*)list,(char*)node);
 else AppendLinkedNodeAndMarkActive((unsigned*)list,(unsigned)node);
 Flags_ClearWordMask((unsigned*)resources,4);
}
