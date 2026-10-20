#include <globaldefs.h>
ARM
#include <Resource/Script.h>
// Original data: arm9/main @ 0x2108da8; symbol: data_02108da8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Record{short a,b;short values[18];short rate;unsigned char flag;};struct State{int pad;void* object;};extern "C" {extern State ScriptConvertParameterToHalfwordAndDispatch_UnknownRoleZeroInitializedStorage;void ScriptValueTable_AppendRecord(void*,Record*);
// Original: arm9/main @ 0x02072398; symbol: func_02072398; size: 0xF0.
int Script_BuildEighteenValueRecordWithOptionalRateFlag(Script::Parameter* p,int count){Record record;record.a=-1;record.b=-1;for(unsigned char i=0;i<18;i++)record.values[i]=-1;record.rate=100;record.flag=0;record.a=p->ToInt();Script::Parameter* old=p+1;p+=2;record.b=old->ToInt();count-=2;for(int i=0;i<18;i++){record.values[i]=p->ToInt();p++;count--;}if(count){record.rate=p->ToInt();p++;count--;}if(count)record.flag=p->ToInt();ScriptValueTable_AppendRecord(ScriptConvertParameterToHalfwordAndDispatch_UnknownRoleZeroInitializedStorage.object,&record);return 1;}}
