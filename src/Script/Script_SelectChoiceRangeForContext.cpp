#include <globaldefs.h>
#include <Resource/Script.h>
ARM
struct ScriptContext {unsigned owner,a,b,c,enabled,count,reserved;};
extern "C" ScriptContext* ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x0209BB6C; symbol: func_0209bb6c; size: 0x118.
extern "C" int Script_SelectChoiceRangeForContext(Script::Parameter* params,int count) {
 ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->count=0;
 if(!ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->enabled)return 1;
 int id=params[0].ToInt();
 if(id!=(int)ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->a)return 1;
 int first=0,second=0,third=0,fourth=0;
 if(count>1) {
 first=params[1].ToInt();second=params[2].ToInt();third=params[3].ToInt();fourth=params[4].ToInt();
 }
 int minimum=first*100+second;
 int maximum=third*100+fourth;
 int current=ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->b*100+ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->c;
 if(first==0&&second==0&&third==0&&fourth==0) {
 ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->count=1;
 *(int*)(ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->owner+0xc0)=0;
 }else if(minimum<=current&&current<=maximum) {
 ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->count=1;
 ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->enabled=0;
 *(int*)(ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->owner+0xc0)=0;
 }
 return 1;
}
