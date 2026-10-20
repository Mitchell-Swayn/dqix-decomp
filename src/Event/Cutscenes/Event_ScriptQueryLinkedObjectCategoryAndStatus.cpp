#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameResources_GetInstance();
extern "C" int Script_ReadParameterAsInteger(char*);
extern "C" void Script_WriteIntegerReferenceOutput(void*,int);
extern "C" char* GameState_FindIndexedObjectWithFlag1000(void*,int);
extern "C" int GameObject_HasLinkedStatusNibble(char*);
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
struct Nibble{unsigned char low:4;unsigned char high:4;};
// Original: arm9/ov001 @ 0x02161AB8; symbol: func_ov001_02161ab8; size: 0x230.
extern "C" int Event_ScriptQueryLinkedObjectCategoryAndStatus(char* params,int argc){
 void* state=_ZN9GameState11GetInstanceEv();
 char* resources=GameResources_GetInstance();
 char* owner=*(char**)(resources+0x3734);
 int key=Script_ReadParameterAsInteger(params);
 char* record=*(char**)(owner+0xd0);
 while(record){if(*(unsigned char*)(record+1)==key)break;record=*(char**)(record+0x34);}
 if(!record){Script_WriteIntegerReferenceOutput(params+8,-1);Script_WriteIntegerReferenceOutput(params+16,2);return 1;}
 int category;int id=-1;
 category=((Nibble*)record)->high;
 if(!category){Script_WriteIntegerReferenceOutput(params+8,category);Script_WriteIntegerReferenceOutput(params+16,0);return 1;}
 int status;
 if(((Nibble*)record)->low==10){
  char* object=GameState_FindIndexedObjectWithFlag1000(state,0xce);
  if(object)status=0;
  else{
   int i;
   for(i=0;i<4;i++){object=GameState_FindIndexedObjectWithFlag1000(state,i);if(object && GameObject_HasLinkedStatusNibble(object))break;}
   if(i==4){Script_WriteIntegerReferenceOutput(params+8,category);Script_WriteIntegerReferenceOutput(params+16,2);return 1;}
   status=(int)*(unsigned short*)(*(char**)(object+0x130)+4)<=0;
  }
 }else{
  char* object=GameState_GetObjectWithFlag100(state,*(short*)(record+2));if(!object)return 0;
  id=*(short*)(record+2);
  char* nested=*(char**)(object+0x150);int hasKind;
  if(nested)hasKind=((Nibble*)(nested+0x56b))->high!=0;else hasKind=0;
  if(hasKind){int kind;if(nested)kind=((Nibble*)(nested+0x56b))->high;else kind=0;category=kind+7;}
  else if(!(*(unsigned short*)object&0x1000) && *(short*)(object+4)>0 && *(short*)(object+4)<4)category=14;
  if(object){char* data=*(char**)(object+0x130);if((int)*(unsigned short*)(data+4)<=0 && (*(unsigned*)data&1))status=1;else status=0;}else status=2;
 }
 Script_WriteIntegerReferenceOutput(params+8,category);Script_WriteIntegerReferenceOutput(params+16,status);
 if(argc>3)Script_WriteIntegerReferenceOutput(params+24,id);
 return 1;
}
