#include <globaldefs.h>
#include <Resource/Script.h>
struct Record { unsigned char id,flag; Vector3fix16 a,b;unsigned char mode,pad;Vector3fix16 c,d; };extern "C" Record data_02109a54[];
// Original: arm9/main @ 0x02099EF4; symbol: func_02099ef4; size: 0x6C.
extern "C" int Script_SetIndexedFourVectorConfigurationRecord(Script::Parameter* input) { int index=input->ToInt();Record* record=data_02109a54+index;record->id=index;record->flag=(input+1)->ToInt();input=(input+2)->ToVec3fix16(&record->a);input=input->ToVec3fix16(&record->b);record->mode=input->ToInt();input=(input+1)->ToVec3fix16(&record->c);input->ToVec3fix16(&record->d);return 1; }
