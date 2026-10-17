#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadProtagonistObjectIndex(void*);
extern "C" void WriteField17FActiveAndClear180(unsigned char*,int);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
extern "C" int _Z17NextRandomBetweenP6Randomii(void*,int,int);
extern "C" int TestAvailabilityAndFlag1000Clear(void*);
extern "C" void Object_SetByte7EAndFlag1000(char*,int);
extern "C" void AddToField1CHighCounterClampedFFFF(char*,unsigned);
extern "C" int GameState_Copy176BytesAtOffset7540(const void*);
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void*);
extern "C" char* FindIndexedGameStateObjectWithFlag400(void*,int);
struct Chance { unsigned typeA:7,chanceA:7,typeB:7,chanceB:7,rest:4; };
// Original: arm9/ov024 @ 0x021EB08C; symbol: func_ov024_021eb08c; size: 0x160.
extern "C" int TryActivateIndexedObjectByPackedRandomChance(char* self,int party,int index,unsigned type) {
 void* random;
 char* obj=FindIndexedGameStateObjectWithFlag400(*(void**)(self+0x10),index);
 if(!obj) return 0;
 char* data=*(char**)(obj+0x148);
 if(!data) return 0;
 if(!(party>=0 && party<=3 ? 1:0)) return 0;
 int result;
 random=*(void**)(self+0x10);
 unsigned roll=_Z13NextRandomMaxP6Randomi(random,100);
 if(!TestAvailabilityAndFlag1000Clear(*(void**)(obj+0x138))) return 0;
 int amount=_Z17NextRandomBetweenP6Randomii(random,*(unsigned char*)(data+0x28),*(unsigned char*)(data+0x29));
 result=0;
 if(type==((Chance*)(data+0x24))->typeA) {
 if(roll<((Chance*)(data+0x24))->chanceA) {
 Object_SetByte7EAndFlag1000(*(char**)(obj+0x138),(unsigned char)amount);
 WriteField17FActiveAndClear180((unsigned char*)obj,1);
 *(short*)(*(char**)(obj+0x138)+0x2e)=party;
 result=1;
 }
 } else if(type==((Chance*)(data+0x24))->typeB) {
 if(roll<((Chance*)(data+0x24))->chanceB) {
 Object_SetByte7EAndFlag1000(*(char**)(obj+0x138),(unsigned char)amount);
 WriteField17FActiveAndClear180((unsigned char*)obj,1);
 *(short*)(*(char**)(obj+0x138)+0x2e)=party;
 result=1;
 }
 }
 if(result && party==GameState_ReadProtagonistObjectIndex(_ZN9GameState11GetInstanceEv())) {
 char buffer[0xb0];
 GameState_CopyB0ByteStateBufferToOutput(buffer);
 AddToField1CHighCounterClampedFFFF(buffer,1);
 GameState_Copy176BytesAtOffset7540(buffer);
 }
 return result;
}
