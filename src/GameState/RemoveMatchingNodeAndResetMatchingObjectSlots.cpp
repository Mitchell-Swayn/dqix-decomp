#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" void GameState_ClearObjectByIndex(GameState*,int);struct Node { int key;char pad[488];Node* next; };struct Slot { char pad[0xd4]; };struct Owner { Node* head;char pad[0xd4];Slot slots[16]; };
// Original: arm9/main @ 0x02057F00; symbol: func_02057f00; size: 0x8C.
 extern "C" void RemoveMatchingNodeAndResetMatchingObjectSlots(int* p,int key) { Node* current=(Node*)p[0];Node* previous=0;GameState* state=GameState::GetInstance();for(int i=0;i<16;++i)if(*(int*)((char*)p+i*0xd4+0xd8)==key)GameState_ClearObjectByIndex(state,i+0xd0);while(current) { if(key==current->key)break;previous=current;current=current->next; }if(!current)return;if(!previous)p[0]=(int)current->next;else previous->next=current->next; }
