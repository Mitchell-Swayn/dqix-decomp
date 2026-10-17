#include <globaldefs.h>
ARM
struct GameState { static GameState* GetInstance(); void* GetCombatantByIndex(int); };
extern "C" {
int ClassifyField81FE(unsigned char*);
void* GameState_GetObjectWithFlag100(void*,int);
char* GameState_GetValidObjectByIndex(void*,int);
unsigned char* ReadWordFieldAtOffset150(void*);
float AccumulateWeightedValuesFromElevenEntries(void*);
int GameState_SumTypeDependentFlags48And88(void*);
int Object_ReadIndexedBitAtOffset8EC(unsigned char*,int);
float Object_GetHalfwordRatioAt138(void*);
void* Object_FindResourceRecordByKeyCallback(void*,int);
float ReadBoundedFiveEntryLookupTableOrZero(int);
int HasObjectFlag02000000(const void*);
int func_ov000_02156404(void*);
}
struct Record {char pad[16];unsigned a:13,kind:3,b:16;};
// Original: arm9/ov000 @ 0x02156270; symbol: func_ov000_02156270; size: 0x17C.
extern "C" float GameState_CalculateIndexedObjectWeightedValue(unsigned char* self,int index){
if(ClassifyField81FE(self))return 0;
GameState* gs=GameState::GetInstance();
void* obj=GameState::GetInstance()->GetCombatantByIndex(index);
if(!obj)return 0;
float value;
int valid;if(index>=0 && index<=3)valid=1;else valid=0;
if(valid){
void* o=GameState_GetObjectWithFlag100(gs,index);if(!o)return 0;
unsigned char* data=ReadWordFieldAtOffset150(o);if(!data)return 0;
float two=2.0f;
float weighted=AccumulateWeightedValuesFromElevenEntries(data);
float sum=(float)GameState_SumTypeDependentFlags48And88(data);
float base=two+weighted;
value=sum+base;
if(Object_ReadIndexedBitAtOffset8EC(data,0xa6) && Object_GetHalfwordRatioAt138(obj)<0.08f)value*=two;
}else{
char* o=GameState_GetValidObjectByIndex(gs,index);if(!o)return 0;
Record* record=(Record*)Object_FindResourceRecordByKeyCallback(*(char**)(self+0x8e18)+0x684,*(short*)(o+2));
signed char kind=record->kind;
value=ReadBoundedFiveEntryLookupTableOrZero(kind);
}
if(HasObjectFlag02000000(obj))value=2.0f*value;
if(func_ov000_02156404(obj))return 50.0f;
return value;
}
