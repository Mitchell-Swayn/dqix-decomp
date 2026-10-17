#include <globaldefs.h>
ARM
struct State;
extern "C" void* Ov023_FindUnusedRecord(void*);
extern "C" void Ov023_ClearFourByteRecord(void*);
extern "C" void* func_ov011_021849c8(State*);
extern "C" void* func_ov023_021f6880(void**,unsigned short);
extern "C" void* _ZN8Vector3iaSERKS_(void*,const void*);
// Original: arm9/ov023 @ 0x021FA078; symbol: func_ov023_021fa078; size: 0x90.
extern "C" void Graphics_InitializeObjectVectorRecord(void* owner,State* state,unsigned id,const void* vector,unsigned a,unsigned b) {
char* record=(char*)Ov023_FindUnusedRecord(owner);
if(record) {
Ov023_ClearFourByteRecord(record);
record[2]=1;
*(unsigned short*)record=id;
void** head=(void**)func_ov011_021849c8(state);
void* object=func_ov023_021f6880(head,*(unsigned short*)record);
if(object) {
*(unsigned*)(record+4)=0;
*(unsigned*)(record+8)=b;
*(unsigned*)(record+12)=a;
int tmp[3];
(*(void(***)(void*,void*))object)[8](tmp,object);
_ZN8Vector3iaSERKS_(record+0x10,tmp);
_ZN8Vector3iaSERKS_(record+0x1c,vector);
}
}
}
