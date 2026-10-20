#include <globaldefs.h>
#include <System/Matrix.h>
ARM
struct Entry; struct Slot; struct Record; struct Vector;
extern "C" void CutsceneActor_InitializeCommandSession(char*);
extern "C" unsigned int Event_ReleaseMotionCommandAndGetNext(void*,void*);
extern "C" int Graphics_SetIndexedSlotThreeValues(Slot*,int,unsigned,unsigned,unsigned);
extern "C" int Event_SetIndexedObjectRotation(char*,int,int,int,int);
extern "C" int Util_ReadTypedTableEntryVector(Entry*,int,Vector3i*);
extern "C" int Graphics_ReadIndexedRecordPosition(Record*,int,Vector*);
extern "C" int Graphics_SetIndexedObjectInheritedAlpha(unsigned,int,int);
extern "C" int GameState_SetRadiusForActiveEntry(Entry*,int,int);
// Original data: arm9/ov001 @ 0x2165884; symbol: data_ov001_02165884.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" char *AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage;
typedef int (*CommandHandler)(int*,char*);
// Original data: arm9/ov001 @ 0x2164ca4; symbol: data_ov001_02164ca4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex f49c15029c921502bc921502089415021c9415022c9415024c941502ac941502cc941502dc991502009a1502749a1502049b15022c9b1502349b1502549b1502 ...; full span in module reference.
// Observed span: 108 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" CommandHandler AdvanceSessionCommandLists_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov001 @ 0x0215A134; symbol: func_ov001_0215a134; size: 0x1FC.
// Advances eight command lists and propagates vectors, alpha and radius to the typed slot.
extern "C" void AdvanceSessionCommandLists(char *self) {
 if(*(int*)(self+0x70)<=-1) return;
 if(!Util_ReadTypedTableEntryVector((Entry*)AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage,*(int*)(self+0x70),(Vector3i*)(self+0x74))) {
  CutsceneActor_InitializeCommandSession(self);
  return;
 }
 Graphics_ReadIndexedRecordPosition((Record*)AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage,*(int*)(self+0x70),(Vector*)(self+0x80));
 int *command; int i; int **head; int *active;
 for(i=0;i<8;++i) {
  switch(i) {
  case 0: head=(int**)(self+8); active=(int*)(self+12); break;
  case 1: head=(int**)(self+16); active=(int*)(self+20); break;
  case 2: head=(int**)(self+24); active=(int*)(self+28); break;
  case 3: head=(int**)(self+32); active=(int*)(self+36); break;
  case 4: head=(int**)(self+40); active=(int*)(self+44); break;
  case 5: head=(int**)(self+48); active=(int*)(self+52); break;
  case 6: head=(int**)(self+56); active=(int*)(self+60); break;
  case 7: head=(int**)(self+64); active=(int*)(self+68); break;
  }
  command=*head;
  while(command) {
   int opcode=*command;
   if(opcode>0 && opcode<26) {
    if(AdvanceSessionCommandLists_UnknownRoleProcedureReferenceRecords[opcode](command,self)) break;
   } else { command=0; break; }
   command=(int*)Event_ReleaseMotionCommandAndGetNext(self,command);
  }
  *head=command;
  if(!command) *active=0;
 }
 Vector3i a=*(Vector3i*)(self+0x74);
 Graphics_SetIndexedSlotThreeValues((Slot*)AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage,*(int*)(self+0x70),a.x,a.y,a.z);
 Vector3i b=*(Vector3i*)(self+0x80);
 Event_SetIndexedObjectRotation(AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage,*(int*)(self+0x70),b.x,b.y,b.z);
 Graphics_SetIndexedObjectInheritedAlpha((unsigned)AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage,*(int*)(self+0x70),(int)*(float*)(self+0x8c));
 GameState_SetRadiusForActiveEntry((Entry*)AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage,*(int*)(self+0x70),*(int*)(self+0x90));
}
