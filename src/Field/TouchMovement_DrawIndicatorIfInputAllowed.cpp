#include <globaldefs.h>
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* SystemState_GetGlobalFlags(); extern "C" int SystemState_TestAnyFlags(void*,unsigned); extern "C" char* TextContext_GetSharedInstance(); extern "C" void TouchMovement_DrawDragDirectionIndicator(void*,unsigned char,unsigned char,unsigned char,unsigned char); extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original: arm9/main @ 0x02096824; symbol: func_02096824; size: 0x80.
extern "C" ARM void TouchMovement_DrawIndicatorIfInputAllowed(unsigned char* object) { if(SystemState_TestAnyFlags(SystemState_GetGlobalFlags(),0x4000)) return; if(!Main_UnknownRoleZeroInitializedStorage_Variant4[0x5f] || !*(unsigned short*)(Main_UnknownRoleZeroInitializedStorage_Variant4+0x24)) return; char* state=TextContext_GetSharedInstance(); if(state && *(void**)(state+0x998)) return; if(object[0x225]) TouchMovement_DrawDragDirectionIndicator(object,object[0x220],object[0x221],object[0x222],object[0x223]); }
