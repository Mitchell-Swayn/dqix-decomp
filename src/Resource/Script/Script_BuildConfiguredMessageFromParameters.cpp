#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"
#include <std_library_functions.h>
struct Configuration {short kind,angle;int x,y,z;};
struct Message {unsigned char operation;unsigned char unused;unsigned char subtype;unsigned char pad;char* text;Configuration configuration;short param,height,width;short reserved;int a,b,c;};
struct State {SafeAllocator* allocator;void* context;};
extern "C" State data_02109fe0;
extern "C" char data_020f1b94[];
extern "C" void ClearTwoHalfwordsAndThreeWords(Configuration*),Object_Initialize44ByteRecordAndEmbeddedState(Message*),AppendCopiedEntryWithinCapacity(void*,Message*);
extern "C" unsigned int String_CountBytesUntilTerminator(const char*);
// Original: arm9/main @ 0x020A7F88; symbol: func_020a7f88; size: 0x184.
extern "C" ARM int Script_BuildConfiguredMessageFromParameters(Script::Parameter* params) {
 Message message;
 ClearTwoHalfwordsAndThreeWords(&message.configuration);Object_Initialize44ByteRecordAndEmbeddedState(&message);Object_Initialize44ByteRecordAndEmbeddedState(&message);
 message.operation=params[0].ToInt();message.subtype=params[1].ToInt();const char* text=params[2].ToString();
 message.param=params[3].ToInt();
 Configuration* config=&message.configuration;
 config->kind=params[4].ToInt();
 config->angle=(int)(params[5].ToFloat()*4096.0f);config->x=(int)(params[6].ToFloat()*4096.0f);config->y=(int)(params[7].ToFloat()*4096.0f);config->z=(int)(params[8].ToFloat()*4096.0f);
 message.height=params[9].ToInt();message.width=params[10].ToInt();message.a=(int)(params[11].ToFloat()*4096.0f);message.b=(int)(params[12].ToFloat()*4096.0f);
 int length=String_CountBytesUntilTerminator(text);message.text=(char*)data_02109fe0.allocator->Allocate(length+1);sprintf(message.text,data_020f1b94,text);message.text[length]=0;
 AppendCopiedEntryWithinCapacity(data_02109fe0.context,&message);return 1;
}
