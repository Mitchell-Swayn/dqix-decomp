// Original ARM access widths/callee argument behavior and relocations reviewed.
#include <globaldefs.h>
#include <Resource/Script.h>
#include <System/Interrupts.h>
ARM
#pragma force_active on
// Original data: arm9/main @ 0x20f226c; symbol: data_020f226c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f28fc; symbol: data_020f28fc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6caf0d0254af0d02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109bb0; symbol: data_02109bb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111220; symbol: data_02111220.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111654; symbol: data_02111654.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Bits{unsigned char a:1,b:7;};struct Flags{unsigned char low:6,b:1,c:1;};extern "C"{void NetworkTransfer_InitializeSaveDataSend(void*);void LinkedQueue_AppendAndMarkActive(void*,void*);char* Actor_FindChoiceById(void*,int);void* memcpy(void*,const void*,unsigned);void* memset(void*,int,unsigned);void Grid_InitializeSelectionGeometry(void*);char* TextContext_GetSharedInstance();void TextWindow_SelectFrameTransitionRecord(void*,void*);int UI_IsPanelTransitionHidden(void*);void WindowFrame_BeginCloseTransition(void*);void TextWindow_SelectPrimaryFrameTransition(void*);void Actor_SetChoiceFlags(void*,int,const void*);extern int OSInitVAlarm_UnknownRoleZeroInitializedStorage[];extern char ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage[];extern int(*DisplayOverlayCaptureNormalPlaneMasks_UnknownRoleProcedureReferenceRecords[])();extern unsigned short GXInit_UnknownRoleZeroInitializedStorage,GXInit_UnknownRoleInitializedBytes;}
// Original: arm9/main @ 0x0209BE44; symbol: func_0209be44; size: 0x40.
extern "C" void Actor_AppendScaledChoiceValue(void* p,int n,const short* in){char* q=Actor_FindChoiceById(p,n);if(!q)return;unsigned short i=*(unsigned short*)(q+2);*(unsigned short*)(q+2)=i+1;unsigned short* out=(unsigned short*)(q+8+i*4);out[0]=(unsigned short)in[0];out[1]=in[1];}
