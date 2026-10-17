#include <globaldefs.h>
ARM
struct PackedPosition {short x,y,z;};
struct Command {int unused;unsigned char type,index;unsigned short id;PackedPosition position;};
struct Saved {unsigned short id;PackedPosition position;};
extern "C" void* Object_GetBoundedEightByteRecordAtOffset74DE(void*,int);
extern "C" bool TestInactiveOrPrimaryIndexState(unsigned*);
extern "C" void _Z16Vector3fix16CopyP8Vector3sPKS_(PackedPosition*,const PackedPosition*);
extern "C" void Network_QueueTypeB6PackedPosition(int,unsigned,unsigned short,PackedPosition);
extern "C" char* GameState_FindFlag20ObjectByKey(void*,int);
extern "C" char* _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(void*,int);
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" void Object_SetPackedOffsetC4ValueAndNotifyCurrentZone(char*,unsigned short);
extern "C" void SetByteFieldAtOffset253ToOne(void*);
extern "C" int ReadByteFieldAtOffset26C(void*);
extern "C" int ReadIndexedSignedField1038(char*);
// Original: arm9/ov017 @ 0x021D36B4; symbol: func_ov017_021d36b4; size: 0x244.
extern "C" void Network_ApplyPackedPositionRecord(int remote,Command* cmd,void* gs,int unused,unsigned* conn) {
 Saved* saved=(Saved*)Object_GetBoundedEightByteRecordAtOffset74DE(gs,cmd->index);
 if(!saved)return;
 if(cmd->type==0) {
  if(TestInactiveOrPrimaryIndexState(conn)) {
   saved->id=cmd->id;
   _Z16Vector3fix16CopyP8Vector3sPKS_(&saved->position,&cmd->position);
   Network_QueueTypeB6PackedPosition(cmd->type,cmd->index,cmd->id,cmd->position);
  } else if(!remote) {
   saved->id=cmd->id;
   _Z16Vector3fix16CopyP8Vector3sPKS_(&saved->position,&cmd->position);
  }
 } else if(cmd->type==1) {
  int isParty=(cmd->id<=3)?1:0;
  if(!isParty) {
   char* obj=GameState_FindFlag20ObjectByKey(gs,cmd->id-4);
   if(!obj)return;
   cmd->id=*(short*)(obj+4);
  }
  char* obj=_ZN9GameState31GetMaybeWanderingMonsterByIndexEi(gs,cmd->id);
  void* member=_ZN9GameState21GetPartyMemberByIndexEi(gs,cmd->id);
  if(!obj)return;
  if(TestInactiveOrPrimaryIndexState(conn)) {
   if(!saved->id)return;
   int index=*(short*)(obj+4);
   int valid=0; if(index>=0)valid=(index<=3);
   if(!valid) {
    Object_SetPackedOffsetC4ValueAndNotifyCurrentZone(obj,5000);
    if(member)SetByteFieldAtOffset253ToOne(member);
   }
   saved->id=0;
   Network_QueueTypeB6PackedPosition(cmd->type,cmd->index,cmd->id,cmd->position);
  } else if(!remote) {
   int index=*(short*)(obj+4);
   int valid=0; if(index>=0)valid=(index<=3);
   if(valid) {
    if(index==ReadIndexedSignedField1038((char*)conn) && member && !ReadByteFieldAtOffset26C(member)) {
     Object_SetPackedOffsetC4ValueAndNotifyCurrentZone(obj,5000);
     if(member)SetByteFieldAtOffset253ToOne(member);
    }
   } else {
    Object_SetPackedOffsetC4ValueAndNotifyCurrentZone(obj,5000);
    if(member)SetByteFieldAtOffset253ToOne(member);
   }
   saved->id=0;
  }
 }
}
