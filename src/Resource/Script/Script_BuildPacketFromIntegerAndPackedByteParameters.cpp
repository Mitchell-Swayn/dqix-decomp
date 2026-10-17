#include <globaldefs.h>
ARM
#include <Resource/Script.h>
extern unsigned char** data_02109bac;extern "C" void CopyIndexedEntryValueAndTag(void*,unsigned,int,void*);extern "C" unsigned char* GetBounded76ByteRecord(void*,unsigned);struct Packet{int value;unsigned short a:8,b:8;};
// Original: arm9/main @ 0x0209AD40; symbol: func_0209ad40; size: 0xD0.
extern "C" int Script_BuildPacketFromIntegerAndPackedByteParameters(Script::Parameter* param){if(!data_02109bac[2])return 1;{unsigned char* object=data_02109bac[0];unsigned id=*(unsigned*)(object+0x1c8);int count=*(int*)(object+0x1cc);Packet packet;packet.value=param->ToInt();int value=(param+1)->ToInt();packet.a=value&0xff;packet.b=(value>>8)&0xff;CopyIndexedEntryValueAndTag(data_02109bac[0],id,count,&packet);*(int*)(data_02109bac[0]+0x1cc)=count+1;unsigned char* entry=GetBounded76ByteRecord(data_02109bac[0],id);if(entry)entry[2]++;}return 1;}
