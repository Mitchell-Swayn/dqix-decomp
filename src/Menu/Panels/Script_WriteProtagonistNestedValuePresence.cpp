#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma always_inline on
#pragma opt_propagation off
#pragma opt_rebuildconditionals off
#pragma opt_rebuildlogicals off
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" {
struct Node { unsigned type; unsigned* nested; };
void Script_WriteIntegerReferenceOutput(Node*,unsigned);
}
static inline int ReadNestedValue(char* object){return *(unsigned short*)(*(char**)(object+0x130)+4);}
static inline int HasPositiveNestedValue(char* object){
 int present=0;
 if(object){if(ReadNestedValue(object)>0)present=1;}
 return present;
}
// Original: arm9/ov023 @ 0x021EA77C; symbol: func_ov023_021ea77c; size: 0x64.
// Writes whether the protagonist object exists and its nested halfword value is positive.
extern "C" int Script_WriteProtagonistNestedValuePresence(Node* output){
 GameState* state=GameState::GetInstance();
 int index=GameState_ReadProtagonistObjectIndex(state);
 char* object=(char*)GameState_GetObjectWithFlag100(state,index);
 if(HasPositiveNestedValue(object))Script_WriteIntegerReferenceOutput(output,1);
 else Script_WriteIntegerReferenceOutput(output,0);
 return 1;
}
