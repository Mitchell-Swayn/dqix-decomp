#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* GameState_FindIndexedObjectWithFlag400(GameState*,unsigned);
extern "C" void* ActionData_GetGlobalTables();
extern "C" void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
extern "C" unsigned GameState_GetIndexedObjectStateBits3And4(int,unsigned);
struct Dispatcher {int context;typedef int(Dispatcher::*Handler)(unsigned char,char*,int,int);};
// Original data: arm9/ov024 @ 0x21ff790; symbol: data_ov024_021ff790.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6cdf1e0200000000a0df1e0200000000f0e01e02000000000ce21e02000000000ce21e0200000000fce21e02000000003ce31e02.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" Dispatcher::Handler CombatDispatchTransformedRecordHandler_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov024 @ 0x021F66CC; symbol: func_ov024_021f66cc; size: 0x12C.
// Selects a member handler using the transformed record's state-dependent code; zero entries and codes >=161 use the default handler.
extern "C" int Combat_DispatchTransformedRecordHandler(Dispatcher* self,int context,int recordId,int index,int arg4,int arg5){
 self->context=context;
 GameState_FindIndexedObjectWithFlag400((GameState*)_ZN9GameState11GetInstanceEv(),index);
 char* record=(char*)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)ActionData_GetGlobalTables(),(short)recordId);
 int code=0;
 switch(GameState_GetIndexedObjectStateBits3And4(self->context,(short)index)){
 case 1:code=*(unsigned short*)(record+12);break;
 case 2:code=*(unsigned short*)(record+14);break;
 }
 if(code>=161)return (self->*CombatDispatchTransformedRecordHandler_UnknownRoleProcedureReferenceRecords[0])((unsigned char)index,record,arg4,arg5);
 if(!CombatDispatchTransformedRecordHandler_UnknownRoleProcedureReferenceRecords[code])return (self->*CombatDispatchTransformedRecordHandler_UnknownRoleProcedureReferenceRecords[0])((unsigned char)index,record,arg4,arg5);
 return (self->*CombatDispatchTransformedRecordHandler_UnknownRoleProcedureReferenceRecords[code])((unsigned char)index,record,arg4,arg5);
}
