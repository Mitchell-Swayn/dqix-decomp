#include <globaldefs.h>
ARM
extern "C" void* data_ov025_021ef988[];
extern "C" void* Object_GetGlobalSixteenEntryDisplayState();
extern "C" void* GetIndexedEntryPointerOrNull(void*,int);
extern "C" unsigned char* GetRecordForObjectIndex208Through223(unsigned char*,int);
extern "C" int _ZN7Model3D12GetBoneIndexEPKc(void*,const char*);
// Original: arm9/ov025 @ 0x021E509C; symbol: func_ov025_021e509c; size: 0xB0.
extern "C" int Graphics_SetSelectedDisplayRecordParentAndBone(unsigned char* command) {
 unsigned char* display=(unsigned char*)Object_GetGlobalSixteenEntryDisplayState();
 int* childEntry=(int*)GetIndexedEntryPointerOrNull(data_ov025_021ef988[3],command[8]);
 int* parentEntry=(int*)GetIndexedEntryPointerOrNull(data_ov025_021ef988[3],command[9]);
 if(!childEntry || !parentEntry) return 1;
 int parentIndex=*parentEntry;
 unsigned char* child=GetRecordForObjectIndex208Through223(display,*childEntry);
 unsigned char* parent=GetRecordForObjectIndex208Through223(display,parentIndex);
 if(!child || !parent) return 1;
 if(*(int*)(parent+0xac)) return 1;
 *(short*)(child+0xb2)=parentIndex;
 const char* bone=*(const char**)(command+12);
 if(bone && *(void**)(parent+8)) *(short*)(child+0xb4)=_ZN7Model3D12GetBoneIndexEPKc(*(void**)(parent+8),bone);
 return 1;
}
