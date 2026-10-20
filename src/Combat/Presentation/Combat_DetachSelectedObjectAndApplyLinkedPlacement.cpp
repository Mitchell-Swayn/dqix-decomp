#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void _ZN8Object3D6DetachEv(void*);
extern "C" void* Combat_GetCommandActorSnapshot(void*,int);
extern "C" int Combat_DispatchSelectionProcedure(void*,void*,int,int*);
extern "C" void Field_ApplyMemberWeaponAttachmentVariant(int,int);
// Original: arm9/ov025 @ 0x021E73C8; symbol: func_ov025_021e73c8; size: 0x88.
extern "C" int Combat_DetachSelectedObjectAndApplyLinkedPlacement(unsigned char* p,void* action,void*,void* context){
 int out[12];
 if(!Combat_DispatchSelectionProcedure(context,action,p[8],out))return 1;
 void* obj=_ZN9GameState20GetGameObjectByIndexEi(_ZN9GameState11GetInstanceEv(),out[0]);
 if(!obj)return 1;
 _ZN8Object3D6DetachEv(obj);
 if(p[8]>=0x22 && p[8]<=0x25){
 unsigned char* record=(unsigned char*)Combat_GetCommandActorSnapshot(action,p[8]-0x22);
 if(record)Field_ApplyMemberWeaponAttachmentVariant(*(unsigned short*)(record+0x20),1);
 }
 return 1;
}
