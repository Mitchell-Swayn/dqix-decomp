#include <globaldefs.h>
ARM
extern "C" {
float _ffltu(unsigned); void* _ZN9GameState11GetInstanceEv();void* Object_GetGlobalConnectionState();char* GameState_GetObjectWithFlag100(void*,int);int TestIndirectField150FlagsNonzero(char*);unsigned ReadWordFieldAtOffset150(char*);
unsigned ToggleMaskedFlagsAtOffset34(void*,unsigned char);unsigned Object_ReadNestedOffset19CWord8OrZero(char*);unsigned ReadNestedFieldAtOffset150And150And950And16C(char*);int IsFirstWordNonzero(void*);int TestResolvedBitInByteField100C(void*,int);int TestMappedActiveSlotBitSixteen(void*);int ExtractHighSixBitsOrFallback(void*,int,int);extern char* data_ov023_021ffefc;
}
// Original: arm9/ov023 @ 0x021F4098; symbol: func_ov023_021f4098; size: 0x3A0.
extern "C" int GameState_CalculateWeightedPartyValue(char* self,int index,unsigned overrideValue){
 void* state=_ZN9GameState11GetInstanceEv();void* connection=Object_GetGlobalConnectionState();char* member=GameState_GetObjectWithFlag100(state,index);
 if(!member||TestIndirectField150FlagsNonzero(member))return 0;if(!ReadWordFieldAtOffset150(member))return 0;
 float amount=(float)*(unsigned*)(self+0x58c0);_ffltu(*(unsigned short*)(self+0x58cc));
 float level[4]={};float weight[4]={};
 for(int i=0;i<4;i++)if(ToggleMaskedFlagsAtOffset34(*(void**)(self+0x2a0),(unsigned char)i)){
 char* p=GameState_GetObjectWithFlag100(state,i);if(p&&!TestIndirectField150FlagsNonzero(p)){weight[i]=(float)Object_ReadNestedOffset19CWord8OrZero(p);level[i]=(float)ReadNestedFieldAtOffset150And150And950And16C(p);}}
 float count=1.0f;if(IsFirstWordNonzero(connection)){count=0;for(int i=0;i<4;i++)if(ToggleMaskedFlagsAtOffset34(*(void**)(self+0x2a0),(unsigned char)i)&&TestResolvedBitInByteField100C(connection,i))count+=1.0f;}
 if(overrideValue)amount=(float)overrideValue;
 int bonus=ExtractHighSixBitsOrFallback(data_ov023_021ffefc+0xf4,(int)(amount*(1.0f+(count-1.0f)/10.0f)),4);
 float t3=weight[3]*(level[3]+(float)bonus);float t2=weight[2]*(level[2]+(float)bonus);float t0=weight[0]*(level[0]+(float)bonus);float t1=weight[1]*(level[1]+(float)bonus);
 float total=t3+(t2+(t0+t1));if(0.0f==total)total=1.0f;
 float adjusted=amount*(1.0f+(count-1.0f)/10.0f);float result=adjusted*((((float)bonus+level[index])*weight[index])/total);
 if(TestMappedActiveSlotBitSixteen(*(void**)(member+0x150)))result*=1.05f;
 if(0.0f<result-(float)(int)result)result+=1.0f;
 if(!overrideValue)for(int i=0;i<4;i++)if(ToggleMaskedFlagsAtOffset34(*(void**)(self+0x2a0),(unsigned char)i))GameState_GetObjectWithFlag100(state,i);
 return (int)result;
}
