#include <globaldefs.h>
ARM
struct State;
extern "C" {void func_ov011_021848a0(State*,unsigned);void* func_ov011_021849c8(State*);void* func_ov023_021f6880(void*,unsigned);unsigned OV023_ReadHalfwordField04(void*);unsigned ComputeRowMajorIndexFromThreeHalfwords(unsigned short*);void Ov023_ForwardObjectAt20(void*,int);extern short data_ov004_0216fffa[];}
// Original: arm9/ov004 @ 0x02168290; symbol: func_ov004_02168290; size: 0x88.
extern "C" int ApplyIndexedRecordValueAndSetState68(State* p){
void* a=func_ov023_021f6880(func_ov011_021849c8(p),7);
if(a && OV023_ReadHalfwordField04(a)==16){
void* b=func_ov023_021f6880(func_ov011_021849c8(p),14);
if(!b)return 0;
if(OV023_ReadHalfwordField04(b)!=7)return 0;
unsigned index=ComputeRowMajorIndexFromThreeHalfwords((unsigned short*)b);
Ov023_ForwardObjectAt20(a,data_ov004_0216fffa[index*2]);
}
func_ov011_021848a0(p,0x68);
return 0;
}
