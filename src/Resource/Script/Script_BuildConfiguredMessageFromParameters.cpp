#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"
#include <std_library_functions.h>
struct Configuration {short kind,angle;int x,y,z;};
struct Message {unsigned char operation;unsigned char unused;unsigned char subtype;unsigned char pad;char* text;Configuration configuration;short param,height,width;short reserved;int a,b,c;};
struct State {SafeAllocator* allocator;void* context;};
// Original data: arm9/main @ 0x2109fe0; symbol: data_02109fe0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" State ObjectAllocate44ByteArrayForPositiveCount_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20f1b94; symbol: data_020f1b94.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 257300.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char ScriptBuildConfiguredMessageFromParameters_UnknownRoleInitializedBytes[];
extern "C" void ZoomDestination_ClearPlacementConfiguration(Configuration*),ZoomDestination_InitializeEntry(Message*),ZoomDestination_AppendEntry(void*,Message*);
extern "C" unsigned int String_CountBytesUntilTerminator(const char*);
// Original: arm9/main @ 0x020A7F88; symbol: func_020a7f88; size: 0x184.
extern "C" ARM int Script_BuildConfiguredMessageFromParameters(Script::Parameter* params) {
 Message message;
 ZoomDestination_ClearPlacementConfiguration(&message.configuration);ZoomDestination_InitializeEntry(&message);ZoomDestination_InitializeEntry(&message);
 message.operation=params[0].ToInt();message.subtype=params[1].ToInt();const char* text=params[2].ToString();
 message.param=params[3].ToInt();
 Configuration* config=&message.configuration;
 config->kind=params[4].ToInt();
 config->angle=(int)(params[5].ToFloat()*4096.0f);config->x=(int)(params[6].ToFloat()*4096.0f);config->y=(int)(params[7].ToFloat()*4096.0f);config->z=(int)(params[8].ToFloat()*4096.0f);
 message.height=params[9].ToInt();message.width=params[10].ToInt();message.a=(int)(params[11].ToFloat()*4096.0f);message.b=(int)(params[12].ToFloat()*4096.0f);
 int length=String_CountBytesUntilTerminator(text);message.text=(char*)ObjectAllocate44ByteArrayForPositiveCount_UnknownRoleZeroInitializedStorage.allocator->Allocate(length+1);sprintf(message.text,ScriptBuildConfiguredMessageFromParameters_UnknownRoleInitializedBytes,text);message.text[length]=0;
 ZoomDestination_AppendEntry(ObjectAllocate44ByteArrayForPositiveCount_UnknownRoleZeroInitializedStorage.context,&message);return 1;
}
