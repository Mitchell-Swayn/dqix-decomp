#include <globaldefs.h>
ARM
#include <Resource/Script.h>
struct Record{short a,b;short values[18];short rate;unsigned char flag;};struct State{int pad;void* object;};extern "C" {extern State data_02108da8;void AppendPointRecordWithinCapacity(void*,Record*);
// Original: arm9/main @ 0x02072398; symbol: func_02072398; size: 0xF0.
int Script_BuildEighteenValueRecordWithOptionalRateFlag(Script::Parameter* p,int count){Record record;record.a=-1;record.b=-1;for(unsigned char i=0;i<18;i++)record.values[i]=-1;record.rate=100;record.flag=0;record.a=p->ToInt();Script::Parameter* old=p+1;p+=2;record.b=old->ToInt();count-=2;for(int i=0;i<18;i++){record.values[i]=p->ToInt();p++;count--;}if(count){record.rate=p->ToInt();p++;count--;}if(count)record.flag=p->ToInt();AppendPointRecordWithinCapacity(data_02108da8.object,&record);return 1;}}
