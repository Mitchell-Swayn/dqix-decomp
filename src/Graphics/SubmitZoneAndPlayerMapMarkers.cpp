#include <globaldefs.h>
#include <std_library_functions.h>
struct MapVector { int x,y,z; };
struct MapMarker { unsigned short zone; unsigned char type,pad; int x,z; };
struct MapDisplay { char pad[0x20]; unsigned char* background; char gap24[0x538]; unsigned char refresh; char gap55d[0x53c]; unsigned char markerCount; char gapA9a[2]; MapMarker* markers; };
struct MapZoneFlags { char pad[12]; unsigned char mode:4; };
struct MapZone { unsigned short id; char pad02[6]; MapZoneFlags* flags; char pad0c[0x38]; int offsetX,offsetZ; char pad4c[0x2728]; MapVector otherPosition; };
struct MapGameObject { char pad[4]; short markerIndex; char gap06[0x3e]; MapVector position; };
extern "C" {
 void* _ZN9GameState11GetInstanceEv(); void* ReadGlobalValueAt02108844(); void* Graphics_GetGlobalBackgroundState(); MapZone* ReadGlobalValueAt020FB3F0();
 MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);void* _ZN9GameState14GetProtagonistEv(void*);
 void Graphics_SubmitObjectBackgroundParameters(void*,int,int);
 int _ZN6Zone3D17GetZoneRecordFlagEi(MapZone*,unsigned short);
 void Object_ConfigureAndSubmitIndexedRecord(MapDisplay*,int,int,int,unsigned char,int,unsigned short,unsigned short,int,int);
 int ReadNonnegativeIndexedBit(void*,void*,int);
 int fix32_Divide(int,int);
 void Vector3fix_ClampXZToBorderedRectangle(MapDisplay*,MapVector*,int);
 unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
 void ColorEffect_ConfigureAlphaBlend(void*,int,int,int,int);
 extern unsigned data_020fdc4c[];
}
// Original: arm9/main @ 0x02025f28; symbol: func_02025f28; size: 0x3e4.
// Submit zone markers and the player marker on the sub-screen map, with pulsing alpha.
extern "C" void SubmitZoneAndPlayerMapMarkers(MapDisplay* display) {
 void* game=_ZN9GameState11GetInstanceEv();
 void* progress=ReadGlobalValueAt02108844();
 Graphics_GetGlobalBackgroundState();
 MapZone* zone=ReadGlobalValueAt020FB3F0();
 unsigned short zoneID=zone->id;
 MapGameObject* object;
 bool showPlayer,showOther;
 MapZoneFlags* flags=zone->flags;
 object=_ZN9GameState20GetUnknownGameObjectEv(game);
 _ZN9GameState14GetProtagonistEv(game);
 MapVector player=object->position;
 if(display->refresh) { display->refresh=0;Graphics_SubmitObjectBackgroundParameters(display->background+8,0,0); }
 for(int i=0;i<display->markerCount;i++) {
  if(_ZN6Zone3D17GetZoneRecordFlagEi(zone,(unsigned short)(display->markers[i].zone*100))) {
   int x=display->markers[i].x,z=display->markers[i].z;
   if(display->markers[i].type==1) Object_ConfigureAndSubmitIndexedRecord(display,x+0x7d000,z+0x5d000,24,(unsigned char)(i+0x55),1,255,255,4096,4096);
   else if(display->markers[i].type==2) Object_ConfigureAndSubmitIndexedRecord(display,x+0x7d000,z+0x5d000,23,(unsigned char)(i+0x55),0,255,255,4096,4096);
  }
 }
 showPlayer=true;
 showOther=true;
 if(zoneID==10000 || !ReadNonnegativeIndexedBit(progress,(char*)progress+0x8c,43)) showOther=false;
 MapVector position;
 if(zoneID==10000 || zoneID==10100) { position.x=player.x+0x80000;position.z=player.z+0x60000; }
 else if(flags->mode==0) {
  position.x=fix32_Divide(player.x+zone->offsetX,0x6000)+0x80000;
  position.z=fix32_Divide(player.z+zone->offsetZ,0x6000)+0x60000;
 } else if(zone->offsetX && zone->offsetZ) { position.x=zone->offsetX+0x80000;position.z=zone->offsetZ+0x60000; }
 else showPlayer=false;
 if(showOther) {
  MapVector other=zone->otherPosition;
  other.x+=0x80000;other.z+=0x60000;
  Vector3fix_ClampXZToBorderedRectangle(display,&other,0x7000);
  other.x-=0x4000;other.z-=0x4000;
  Object_ConfigureAndSubmitIndexedRecord(display,other.x,other.z,25,0x54,0,255,255,4096,4096);
 }
 int phase=(data_020fdc4c[3]+_ZNK9GameState21GetEffectiveDeltaTimeEv(game))%1376;
 data_020fdc4c[3]=phase;
 int pulse=data_020fdc4c[3];
 pulse-=688;
 pulse/=43;
 pulse=abs(pulse);
 pulse*=75;
 pulse/=100;
 pulse+=5;
 if(pulse>16) pulse=16;
 ColorEffect_ConfigureAlphaBlend((void*)0x04001050,0,3,pulse,16-pulse);
 Vector3fix_ClampXZToBorderedRectangle(display,&position,0x5000);
 position.x-=0x4000;position.z-=0x4000;
 if(showPlayer) {
  int index=object->markerIndex;
  Object_ConfigureAndSubmitIndexedRecord(display,position.x,position.z,5,(unsigned char)(index+0x44),0,(unsigned short)(index+4),255,4096,4096);
 }
}
