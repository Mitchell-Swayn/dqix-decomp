#include <globaldefs.h>
ARM
struct State;
extern "C" {
extern "C" void* Menu_GetDisplayRecordRegistry(State* self);
extern "C" void *MenuRecordList_LocateByKey(void **head, unsigned short value);
extern "C" unsigned MenuRecord_GetType(void* self);
extern "C" void *GameState_GetSerializedProgressState();
extern "C" unsigned int BitArray_ReadNonnegativeIndexMask(void*,unsigned char* bits,int bit);
extern "C" int Menu_WriteGridEntry(char* p,int v,unsigned x,unsigned y);
extern "C" void Menu_SetGridNavigationWrapEnabled(void* object, unsigned char value);
extern "C" void Resource_SelectPreviousNonzeroGridEntry(char* self,void* context);
extern "C" void MenuTextCanvas_SetPageIndexAndCountByKey(void* owner, unsigned short id, unsigned short valueA, unsigned short valueB);
extern "C" int Menu_ShowSelectedCompletedAlternateCatalogueRecord(void* p);
}
struct Node;
// Unmodeled virtual slots retain the observed GetList slot at vtable offset 0xEC.
struct ListView { virtual void Pad00(); virtual void Pad01(); virtual void Pad02(); virtual void Pad03(); virtual void Pad04(); virtual void Pad05(); virtual void Pad06(); virtual void Pad07(); virtual void Pad08(); virtual void Pad09(); virtual void Pad10(); virtual void Pad11(); virtual void Pad12(); virtual void Pad13(); virtual void Pad14(); virtual void Pad15(); virtual void Pad16(); virtual void Pad17(); virtual void Pad18(); virtual void Pad19(); virtual void Pad20(); virtual void Pad21(); virtual void Pad22(); virtual void Pad23(); virtual void Pad24(); virtual void Pad25(); virtual void Pad26(); virtual void Pad27(); virtual void Pad28(); virtual void Pad29(); virtual void Pad30(); virtual void Pad31(); virtual void Pad32(); virtual void Pad33(); virtual void Pad34(); virtual void Pad35(); virtual void Pad36(); virtual void Pad37(); virtual void Pad38(); virtual void Pad39(); virtual void Pad40(); virtual void Pad41(); virtual void Pad42(); virtual void Pad43(); virtual void Pad44(); virtual void Pad45(); virtual void Pad46(); virtual void Pad47(); virtual void Pad48(); virtual void Pad49(); virtual void Pad50(); virtual void Pad51(); virtual void Pad52(); virtual void Pad53(); virtual void Pad54(); virtual void Pad55(); virtual void Pad56(); virtual void Pad57(); virtual void Pad58(); virtual Node** GetList(); };
struct Node { Node* next; unsigned int* value; };
// Original: arm9/ov004 @ 0x0215534C; symbol: Menu_PopulateAlternateCataloguePage; size: 0x1F8.
// Fills sixteen grid entries from a paged linked list, exposing values with enabled indexed bits.
extern "C" int Menu_PopulateAlternateCataloguePage(State* self){
 void** head=(void**)Menu_GetDisplayRecordRegistry(self);
 int page, position;
 char* grid=(char*)MenuRecordList_LocateByKey(head,44);
 if(!grid) return 0;
 if(MenuRecord_GetType(grid)!=7) return 0;
 page=*(short*)(grid+0x5c); position=*(short*)(grid+0x5e);
 char* list=(char*)MenuRecordList_LocateByKey(head,57);
 if(!list) return 0;
 if(MenuRecord_GetType(list)!=18) return 0;
 Node** holder=((ListView*)list)->GetList();
 if(!holder) return 0;
 Node* node=*holder;
 if(!node) return 0;
 void* flags=GameState_GetSerializedProgressState();
 short start=(short)(page*16);
 short skip=0;
 while(node){ if(skip==start) break; skip++; node=node->next; }
 for(short i=0;i<16;i++){
  int id=i+26;
  char* cell=(char*)((void*(*)(void**,int))MenuRecordList_LocateByKey)(head,id);
  if(cell && MenuRecord_GetType(cell)==8){
   *(unsigned int*)(cell+32)=0;
   ((unsigned char*)cell)[12]&=~8;
   if(!node){
    Menu_WriteGridEntry(grid,0,(unsigned short)(i>>1),(unsigned short)(i&1));
    ((unsigned char*)cell)[12]|=8;
   } else {
    Menu_WriteGridEntry(grid,(unsigned short)id,(unsigned short)(i>>1),(unsigned short)(i&1));
    unsigned int* value=node->value;
    if(value){
     int bit=(unsigned short)((value[3]<<9)>>21);
     if(bit>0 && BitArray_ReadNonnegativeIndexMask(flags,(unsigned char*)flags+140,bit+3190))
      *(unsigned int*)(cell+32)=value[1];
    }
    node=node->next;
   }
  }
 }
 Menu_SetGridNavigationWrapEnabled(grid,1);
 Resource_SelectPreviousNonzeroGridEntry(grid,self);
 ((void(*)(void*,int,int,int))MenuTextCanvas_SetPageIndexAndCountByKey)(self,3,page,position);
 Menu_ShowSelectedCompletedAlternateCatalogueRecord(self);
 return 0;
}
