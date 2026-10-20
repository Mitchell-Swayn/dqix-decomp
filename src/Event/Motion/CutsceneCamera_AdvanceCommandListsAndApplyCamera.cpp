#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Matrix.h>
#include <GameState/GameState.h>
ARM
extern "C" void* GameState_ReadUnknownB0(GameState*);
extern "C" void ComputeRotatedEndpointFromAngleHeightAndLength(char*,int,int,int);
extern "C" void Camera_GetOrbitParameters(int*,int*,int*,int*);
extern "C" void Camera_RecalculateOrbitAndEye(void*);
extern "C" void Object_ResetMotionStateAndChildRecords(char*);
extern "C" char* CutsceneCamera_ReleaseCompletedCommandAndGetNext(char*,char*,int);
typedef int(*MotionHandler)(int*,char*);
// Original data: arm9/ov001 @ 0x2164c54; symbol: data_ov001_02164c54.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex f47b1502fc7b15021c7c15023c7c1502187e1502107f150224831502388315024883150284831502088015021880150228801502388015028080150270841502 ...; full span in module reference.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" MotionHandler CutsceneCameraAdvanceCommandListsAndApplyCamera_UnknownRoleProcedureReferenceRecords[];
#define I(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(char**)((p)+(o)))
#define V(p,o) (*(Vector3fix*)((p)+(o)))
// Original: arm9/ov001 @ 0x02158AE4; symbol: func_ov001_02158ae4; size: 0x2A8.
// Advances five motion command lists, applying changed vectors and endpoint parameters to the owner.
extern "C" void CutsceneCamera_AdvanceCommandListsAndApplyCamera(char *self) {
 char *command;
 GameState *game=GameState::GetInstance();
 if(!game) {Object_ResetMotionStateAndChildRecords(self);return;}
 char *object=(char*)GameState_ReadUnknownB0(game);
 if(!object) {Object_ResetMotionStateAndChildRecords(self);return;}
 V(self,0x4c)=V(object,4);
 V(self,0x58)=V(object,0x10);
 Camera_GetOrbitParameters((int*)object,(int*)(self+0x64),(int*)(self+0x68),(int*)(self+0x6c));
 Vector3fix oldPosition=V(self,0x4c),oldTarget=V(self,0x58);
 int oldAngle=I(self,0x64),oldHeight=I(self,0x68),oldLength=I(self,0x6c);
 if(I(self,0x134)) {memcpy(self+0x4c,self+0x144,12);memcpy(self+0x58,self+0x150,12);}
 int i;char **head;int *active;
 for(i=0;i<5;++i) {
  switch(i) {
  case 0:head=(char**)(self+8);active=(int*)(self+12);break;
  case 1:head=(char**)(self+16);active=(int*)(self+20);break;
  case 2:head=(char**)(self+24);active=(int*)(self+28);break;
  case 3:head=(char**)(self+32);active=(int*)(self+36);break;
  case 4:head=(char**)(self+40);active=(int*)(self+44);break;
  }
  command=*head;
  while(command) {
   int opcode=*(int*)command;
   if(opcode>0 && opcode<19) {
    int result=CutsceneCameraAdvanceCommandListsAndApplyCamera_UnknownRoleProcedureReferenceRecords[opcode]((int*)command,self);
    switch(result) {
    case 0:break;
    case 1:goto commandStopped;
    case 2: {
     switch(i) {
     case 0:command=P(self,0x30);break;
     case 1:command=P(self,0x34);break;
     case 2:break;
     }
     break;
    }
    }
   } else {command=0;break;}
   command=CutsceneCamera_ReleaseCompletedCommandAndGetNext(self,command,i);
  }
 commandStopped:
  *head=command;if(!command)*active=0;
 }
 if(oldTarget.x!=I(self,0x58)||oldTarget.y!=I(self,0x5c)||oldTarget.z!=I(self,0x60))V(object,0x10)=V(self,0x58);
 if(oldAngle!=I(self,0x64)||oldHeight!=I(self,0x68)||oldLength!=I(self,0x6c))ComputeRotatedEndpointFromAngleHeightAndLength(object,I(self,0x64),I(self,0x68),I(self,0x6c));
 if(oldPosition.x!=I(self,0x4c)||oldPosition.y!=I(self,0x50)||oldPosition.z!=I(self,0x54)) {
  V(object,4)=V(self,0x4c);Camera_RecalculateOrbitAndEye(object);
 }
 if(I(self,0xa24)) {ComputeRotatedEndpointFromAngleHeightAndLength(object,I(self,0x64),I(self,0x68),I(self,0x6c));I(self,0xa24)=0;}
}
