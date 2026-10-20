#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
unsigned char* _ZN9GameState20GetUnknownGameObjectEv(void*);
unsigned char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
unsigned char* GameObject_GetLadderTraversalState(void*);
void _ZN8Object3D11DisableFlagEi(void*,int);
void _ZN8Object3D10EnableFlagEi(void*,int);
void InitializeRecordWithEnabledAndPercentDefaults(unsigned char*);
void GameState_CopyPartyMemberGroup(int,signed char*,signed char*);
void _ZN8Vector3iaSERKS_(void*,void*);
void _ZN8Object3D17SetInheritedAlphaEi(void*,int);
void GameObject_SuppressPartyRendering(void*);
void* GameObject_ResetFollowTrail(void*);
bool Network_IsClientSession(void*);
void Field_RebuildMemberFollowChain(void*,int,int,int,int);
unsigned short _ZNK8Object3D10GetField06Ev(void*);
void GameObject_ChangeMotionStateAndRefreshAnimation(void*,unsigned);
void GameObject_SetMotionStateAndRefreshAnimation(unsigned char*,unsigned char);
void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);
void _ZN8Object3D23SetCurrentAnimationTimeEi(void*,int);
// Original data: arm9/ov017 @ 0x21d6cfc; symbol: data_ov017_021d6cfc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ff000000ffffffffe0020000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6d08; symbol: data_ov017_021d6d08.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ff000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern char GraphicsApplyPartyMemberAnimationCommand_UnknownRoleInitializedBytes[],GraphicsApplyPartyMemberAnimationCommand_UnknownRoleInitializedBytes_Variant2[],Graphics_ApplyPartyMemberAnimationCommand_TextHasigoIn[],Graphics_ApplyPartyMemberAnimationCommand_TextHasigoOut[],Graphics_ApplyPartyMemberAnimationCommand_TextHasigoLoop[];
}
struct FourPartyIndices{signed char a[4];};
struct CommandBits{unsigned char low:4,high:4;};
struct PartyBits{unsigned char bits:2,rest:6;};
// Original: arm9/ov017 @ 0x021D3FA8; symbol: func_ov017_021d3fa8; size: 0x464.
extern "C" void Graphics_ApplyPartyMemberAnimationCommand(void* unused,unsigned char* command,void* state,void* scene,void* active){
 unsigned char *member,*record;int mode,time;unsigned char high;
 unsigned char* unknown=_ZN9GameState20GetUnknownGameObjectEv(state);
 member=_ZN9GameState21GetPartyMemberByIndexEi(state,command[7]);
 record=GameObject_GetLadderTraversalState(member);
 unsigned char low=((CommandBits*)(command+6))->low;
 high=((CommandBits*)(command+6))->high;
 mode=command[4];time=*(int*)(command+8);
 signed char count1,count2;FourPartyIndices indices1,indices2;
 if(member && high){
   _ZN8Object3D11DisableFlagEi(member,0x1010);
   InitializeRecordWithEnabledAndPercentDefaults(record);
   indices1=*(FourPartyIndices*)GraphicsApplyPartyMemberAnimationCommand_UnknownRoleInitializedBytes;
   count1=0;GameState_CopyPartyMemberGroup((signed char)command[7],indices1.a,&count1);
   for(int i=0;i<count1;i++){
     int id=indices1.a[i];if(id==command[7])continue;
     unsigned char* other=_ZN9GameState21GetPartyMemberByIndexEi(state,id);
     if(!other)continue;
     if(!(((PartyBits*)(other+0xc1))->bits&2)){
       _ZN8Vector3iaSERKS_(other+0x44,member+0x44);
       _ZN8Object3D17SetInheritedAlphaEi(other,31);
       GameObject_SuppressPartyRendering(other);
     }
     GameObject_ResetFollowTrail(other);
   }
   if(Network_IsClientSession(active))Field_RebuildMemberFollowChain(scene,0,1,1,1);
 }
 if(member && _ZNK8Object3D10GetField06Ev(member)==_ZNK8Object3D10GetField06Ev(unknown)){
   if(high || (((PartyBits*)(member+0xc1))->bits&2)){
     InitializeRecordWithEnabledAndPercentDefaults(record);
     if(high){
       indices2=*(FourPartyIndices*)GraphicsApplyPartyMemberAnimationCommand_UnknownRoleInitializedBytes_Variant2;
       count2=0;GameState_CopyPartyMemberGroup((signed char)command[7],indices2.a,&count2);
       for(int i=0;i<count2;i++){
         int id=indices2.a[i];if(id==command[7])continue;
         unsigned char* other=_ZN9GameState21GetPartyMemberByIndexEi(state,id);
         if(!other)continue;
         if(!(((PartyBits*)(other+0xc1))->bits&2)){
           _ZN8Vector3iaSERKS_(other+0x44,member+0x44);
           _ZN8Object3D17SetInheritedAlphaEi(other,31);
           GameObject_ChangeMotionStateAndRefreshAnimation(other,0);
           GameObject_SuppressPartyRendering(other);
         }
         GameObject_ResetFollowTrail(other);
       }
       if(Network_IsClientSession(active))Field_RebuildMemberFollowChain(scene,0,1,1,1);
     }
   }else if(mode==0){
     _ZN8Object3D11DisableFlagEi(member,0x1000);_ZN8Object3D10EnableFlagEi(member,16);
     _ZN8Object3D18SetAnimationByNameEPKci(member,Graphics_ApplyPartyMemberAnimationCommand_TextHasigoIn,1);record[0]=1;record[1]=0;
   }else if(mode==1){
     _ZN8Object3D18SetAnimationByNameEPKci(member,Graphics_ApplyPartyMemberAnimationCommand_TextHasigoIn,1);record[0]=1;record[1]=1;
   }else if(mode==5){
     _ZN8Object3D11DisableFlagEi(member,0x1010);GameObject_SetMotionStateAndRefreshAnimation(member,1);record[0]=1;record[1]=5;
   }else if(mode==4){
     _ZN8Object3D11DisableFlagEi(member,0x1010);_ZN8Object3D18SetAnimationByNameEPKci(member,Graphics_ApplyPartyMemberAnimationCommand_TextHasigoOut,1);record[0]=1;record[1]=4;
   }else if(mode==2){
     if(low==1){
       _ZN8Object3D11DisableFlagEi(member,0x1000);_ZN8Object3D10EnableFlagEi(member,16);
       _ZN8Object3D18SetAnimationByNameEPKci(member,Graphics_ApplyPartyMemberAnimationCommand_TextHasigoLoop,0);
       if(time)_ZN8Object3D23SetCurrentAnimationTimeEi(member,time);record[0]=1;
     }else if(low==2){
       _ZN8Object3D11DisableFlagEi(member,0x1000);_ZN8Object3D10EnableFlagEi(member,16);
       _ZN8Object3D18SetAnimationByNameEPKci(member,Graphics_ApplyPartyMemberAnimationCommand_TextHasigoLoop,4);
       if(time)_ZN8Object3D23SetCurrentAnimationTimeEi(member,time);record[0]=1;
     }else{
       _ZN8Object3D10EnableFlagEi(member,0x1010);_ZN8Object3D18SetAnimationByNameEPKci(member,Graphics_ApplyPartyMemberAnimationCommand_TextHasigoLoop,0);
       if(time)_ZN8Object3D23SetCurrentAnimationTimeEi(member,time);record[0]=1;
     }
   }
 }
}
