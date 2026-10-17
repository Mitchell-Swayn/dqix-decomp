#include <globaldefs.h>
ARM
#include <Resource/Script.h>
struct Object{unsigned char pad[0x1c8];int key;int pad1cc;int index;};struct Context{Object* object;int pad;int enabled;};extern "C" {extern Context* data_02109bac;void Object_CopyWordToIndexedSeventySixByteEntry(Object*,int,int,int*);unsigned char* GetBounded76ByteRecord(Object*,int);
// Original: arm9/main @ 0x0209AE10; symbol: func_0209ae10; size: 0x8C.
int Script_AppendIndexedWordAndIncrementRecordCount(Script::Parameter* p){if(!data_02109bac->enabled)return 1;int key=data_02109bac->object->key;int index=data_02109bac->object->index;int value=p->ToInt();Object_CopyWordToIndexedSeventySixByteEntry(data_02109bac->object,key,index,&value);data_02109bac->object->index=index+1;unsigned char* record=GetBounded76ByteRecord(data_02109bac->object,key);if(record)record[3]++;return 1;}}
