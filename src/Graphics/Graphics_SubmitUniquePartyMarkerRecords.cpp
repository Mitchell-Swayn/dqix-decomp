#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" void WorldMap_SubmitMarkerSprite(char*,unsigned,unsigned,int,unsigned char,unsigned char,unsigned short,unsigned char,unsigned,unsigned);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" bool SystemState_TestAnyFlags(const unsigned*,unsigned);
extern "C" const unsigned* SystemState_GetGlobalFlags();
struct Keys {int keys[4];};
// Original data: arm9/main @ 0x20e7064; symbol: data_020e7064.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffffffffffffffffffffffff.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Keys GraphicsSubmitUniquePartyMarkerRecords_UnknownRoleInitializedBytes;
struct Marker { int x,y,z; int pad[2]; unsigned char member; char rest[3]; };
// Original: arm9/main @ 0x02023D84; symbol: func_02023d84; size: 0x27C.
extern "C" void Graphics_SubmitUniquePartyMarkerRecords(char* self,Marker* markers,int count,int offsetX,int offsetY,int baseX,int baseY,int flip) {
 if(!*(unsigned char*)(self+0x9c0)) return;
 Keys keys=GraphicsSubmitUniquePartyMarkerRecords_UnknownRoleInitializedBytes;
 unsigned char used=0;
 unsigned flags;
 long long scale;
 void* game=_ZN9GameState11GetInstanceEv();
 void* protagonist=_ZN9GameState14GetProtagonistEv(game);
 if(!protagonist) return;
 const unsigned* global=SystemState_GetGlobalFlags();
 for(int member=0;member<4;member++) {
 char* obj=_ZN9GameState21GetPartyMemberByIndexEi(game,member);
 if(!obj || !*(unsigned short*)(obj+0x1b2)) continue;
 unsigned key=*(unsigned short*)(obj+0x1b2);
 if(SystemState_TestAnyFlags(global,0x80000)) continue;
 unsigned short zone=_ZNK8Object3D10GetField06Ev(protagonist);
 if(zone!=_ZNK8Object3D10GetField06Ev(obj)) continue;
 int unique=1;
 for(int i=0;i<used;i++) if(key==keys.keys[i]) unique=0;
 if(!unique) continue;
 keys.keys[used]=key;
 used++;
 flags=member+0x54;
 Marker* marker=markers;
 for(int i=0;i<count;i++,marker++) {
 if(member==marker->member) {
 scale=*(int*)(self+0x38);
 int x=(int)((float)(int)(((long long)marker->x*scale+2048)>>12)/4096.0f)-offsetX;
 int y=(int)((float)(int)(((long long)marker->z*scale+2048)>>12)/4096.0f)-offsetY;
 if(flip) y=-((int)((float)(int)(((long long)marker->y*scale+2048)>>12)/4096.0f)-offsetY);
 WorldMap_SubmitMarkerSprite(self,(x+baseX-1)<<12,(y+baseY-1)<<12,8,flags,0,255,255,4096,4096);
 }
 }
 }
}
