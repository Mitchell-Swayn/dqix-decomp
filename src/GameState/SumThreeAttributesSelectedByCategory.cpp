#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
// Original data: arm9/main @ 0x20e8a8c; symbol: data_020e8a8c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffffffff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" short SumThreeAttributesSelectedByCategory_UnknownRoleInitializedBytes[4];
extern "C" int CharacterState_GetLearnedSkillMask(void*,int);
extern "C" int GameState_ReadAttributeBits12To19(GameState*,int);
// Original: arm9/main @ 0x02085CD0; symbol: func_02085cd0; size: 0x24C.
extern "C" int SumThreeAttributesSelectedByCategory(char* self,int category) {
 if(category<0){if(*(short*)(self+0x2ac)>0)category=((unsigned)*(int*)(self+0x29c)<<23)>>27;else category=0x21;}
 GameState* state=GameState::GetInstance();
 struct Choices { short value[4]; };Choices choices=*(Choices*)SumThreeAttributesSelectedByCategory_UnknownRoleInitializedBytes;
 switch(category) {
case 0x21:choices.value[0]=0x84;choices.value[1]=0x8a;choices.value[2]=0x8d;break;
case 0:choices.value[0]=1;choices.value[1]=5;choices.value[2]=7;break;
case 1:choices.value[0]=11;choices.value[1]=15;choices.value[2]=17;break;
case 2:choices.value[0]=23;choices.value[1]=25;choices.value[2]=29;break;
case 3:break;
case 4:choices.value[0]=89;choices.value[1]=91;choices.value[2]=93;break;
case 5:choices.value[0]=66;choices.value[1]=68;choices.value[2]=74;break;
case 6:choices.value[0]=111;choices.value[1]=115;choices.value[2]=117;break;
case 7:choices.value[0]=121;choices.value[1]=123;choices.value[2]=127;break;
case 8:choices.value[0]=177;choices.value[1]=179;choices.value[2]=183;break;
case 9:choices.value[0]=187;choices.value[1]=191;choices.value[2]=193;break;
case 10:choices.value[0]=243;choices.value[1]=245;choices.value[2]=247;break;
case 11:choices.value[0]=209;choices.value[1]=211;choices.value[2]=215;break;
 }
 int total=0;
 for(unsigned char index=0;choices.value[index]!=-1;++index){int choice=choices.value[index];if(CharacterState_GetLearnedSkillMask(self,choice))total+=GameState_ReadAttributeBits12To19(state,choice);}
 return total;
}
