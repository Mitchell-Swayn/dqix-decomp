#include <Resource/Script.h>
struct Record {short fields[16];};extern "C" Record data_02109dcc[];
// Original: arm9/main @ 0x020A6090; symbol: func_020a6090; size: 0xF0.
extern "C" int Script_FillIndexedRecordFieldsFromIntegerParameters(const Script::Parameter *params){unsigned short raw=params[0].ToInt();unsigned char index=raw;Record *out=data_02109dcc+index;
out->fields[0]=params[1].ToInt();
out->fields[1]=params[2].ToInt();
out->fields[2]=params[3].ToInt();
out->fields[3]=params[4].ToInt();
out->fields[4]=params[5].ToInt();
out->fields[5]=params[6].ToInt();
out->fields[6]=params[7].ToInt();
out->fields[7]=params[8].ToInt();
out->fields[8]=params[9].ToInt();
out->fields[9]=params[10].ToInt();
out->fields[10]=params[11].ToInt();
out->fields[11]=params[12].ToInt();
out->fields[12]=params[13].ToInt();
out->fields[13]=params[14].ToInt();
out->fields[14]=params[15].ToInt();
out->fields[15]=params[16].ToInt();
return 1;}
