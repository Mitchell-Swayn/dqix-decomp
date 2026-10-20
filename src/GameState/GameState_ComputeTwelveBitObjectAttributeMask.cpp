#include <globaldefs.h>
#include <GameState/GameState.h>
struct Unit {char pad[0x150];char* records;};
extern "C" Unit* GameState_GetObjectWithFlag100(GameState*,unsigned);
extern "C" int CharacterState_GetLearnedSkillMask(void*,unsigned short);
extern "C" unsigned Vocation_GetSkillLineId(unsigned,unsigned);
extern "C" int CountPositiveGroupedValuesMatchingMask(unsigned);
// Original data: arm9/main @ 0x20f29f4; symbol: data_020f29f4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 090014001f00400061004b0077008200b900c400fb00da00.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short GameStateComputeTwelveBitObjectAttributeMask_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x020DD3CC; symbol: func_020dd3cc; size: 0xF8.
extern "C" unsigned GameState_ComputeTwelveBitObjectAttributeMask(unsigned id){Unit* p=GameState_GetObjectWithFlag100(GameState::GetInstance(),id);if(!p)return 0;unsigned result=0;for(unsigned short i=0;i<=11;i++)if(CharacterState_GetLearnedSkillMask(p->records,GameStateComputeTwelveBitObjectAttributeMask_UnknownRoleInitializedBytes[i]))result|=1u<<i;unsigned flags=*(unsigned*)(p->records+0x950);for(unsigned char i=0;i<4;i++){unsigned value=Vocation_GetSkillLineId(flags&0xff,i);if(value&&value>=1&&value<=12)result|=1u<<((value-1)&0xff);}for(unsigned i=0;i<=11;i++){unsigned bit=1u<<i;if((result&(1u<<i))&&CountPositiveGroupedValuesMatchingMask(bit)==0)result&=~bit;}return result;}
