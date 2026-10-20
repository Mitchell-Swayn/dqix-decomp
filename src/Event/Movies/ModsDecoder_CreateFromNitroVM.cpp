#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct CountPrice{unsigned count:7,price:25;};
struct FlagBits{unsigned char a:1,b:1,index:6;};
struct Nibbles{unsigned char low:4,high:4;};
struct SixFlags{unsigned char index:6,a:1,b:1;};
extern "C" unsigned Memory_ClearRecordWordsAtSelectedOffsets(...);
extern "C" unsigned Memory_FreeOverlayAllocation(...);
extern "C" unsigned ModsDecoder_Destroy(...);
extern "C" unsigned System_ReferenceSymbolAndForwardArguments(...);
extern "C" unsigned ModsNitroStream_Initialize(...);
extern "C" unsigned ModsDecoder_AllocateStorage(...);
extern "C" unsigned ModsNitroStream_AllocateStorage(...);
// Original data: arm9/ov016 @ 0x219d07c; symbol: data_ov016_0219d07c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 8ce7180290e7180200000000000000000000000000000000000000000000000000000000.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned char ModsDecoderCreateFromNitroVM_UnknownRoleProcedureReferenceRecords[];
// Original data: arm9/ov016 @ 0x219d0a0; symbol: data_ov016_0219d0a0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex b4f618022ce6180240f518028cf51802fcf5180278f61802a0f6180200000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned char ModsDecoderCreateFromNitroVM_UnknownRoleProcedureReferenceRecords_Variant2[];
// Original: arm9/ov016 @ 0x0218e558; symbol: AllocateRangeMetricsAndInitializeWrapper.
struct MetricsBase{virtual void Keep();virtual void Destroy();};
extern "C" void* ModsDecoder_CreateFromNitroVM(void* input,unsigned mode){char* metrics=(char*)ModsNitroStream_AllocateStorage(20);if(metrics){U(metrics,0)=(unsigned)ModsDecoderCreateFromNitroVM_UnknownRoleProcedureReferenceRecords;U(metrics,4)=0;U(metrics,8)=0;U(metrics,0)=(unsigned)ModsDecoderCreateFromNitroVM_UnknownRoleProcedureReferenceRecords_Variant2;}if(!metrics)return 0;if(!ModsNitroStream_Initialize(metrics,input)){if(metrics)((MetricsBase*)metrics)->Destroy();return 0;}void* wrapper=(void*)ModsDecoder_AllocateStorage(216);if(wrapper)wrapper=(void*)Memory_ClearRecordWordsAtSelectedOffsets(wrapper);if(!System_ReferenceSymbolAndForwardArguments(wrapper,metrics,mode)){if(wrapper){ModsDecoder_Destroy(wrapper);Memory_FreeOverlayAllocation(wrapper);}return 0;}return wrapper;}
