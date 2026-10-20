#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20ef6d0; symbol: data_020ef6d0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 256400.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);extern "C" char FormatThreeIndexedTextAndValueSlots_UnknownRoleInitializedBytes[];extern "C" char TreasureMapPanel_SetClearerName_Text[];extern "C" char FormatThreeIndexedTextAndValueSlots_Text[];
// Original: arm9/main @ 0x020265A8; symbol: func_020265a8; size: 0x94.
extern "C" void FormatThreeIndexedTextAndValueSlots(unsigned char* p,unsigned index,const char* text,unsigned value){if(index>=3)return;if(text&&*text){strcpy((char*)p+0x5fc+index*72,text);sprintf((char*)p+0x6d4+index*8,FormatThreeIndexedTextAndValueSlots_UnknownRoleInitializedBytes,value);return;}strcpy((char*)p+0x5fc+index*72,TreasureMapPanel_SetClearerName_Text);strcpy((char*)p+0x6d4+index*8,FormatThreeIndexedTextAndValueSlots_Text);}
