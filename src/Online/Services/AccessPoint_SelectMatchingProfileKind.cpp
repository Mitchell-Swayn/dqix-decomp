#include <globaldefs.h>
#include <std_library_functions.h>
#pragma optimization_level 4
#pragma optimize_for_size off
struct SelectionBits {unsigned char low:4,middle:2,selected:2;};
struct Profile {struct {unsigned char low:4,selected:4;} flags;unsigned char kind,pad,length;char ssid[32];};
struct AccessPoint {unsigned char pad[10];unsigned short length;char ssid[32];unsigned char rest[148];};
extern "C" int WirelessScan_ClassifySpecialAccessPoint(unsigned char*);
extern "C" int Network_ClassifyFreespotSsid(const char*);
// Original: arm9/ov031 @ 0x02213F14; symbol: func_ov031_02213f14; size: 0x19C.
extern "C" unsigned AccessPoint_SelectMatchingProfileKind(void* object){
 unsigned char* self=(unsigned char*)object;
 AccessPoint* ap=(AccessPoint*)(self+0x470+self[0xd13]*0xc0);
 int i;int result=0;int matched;
 if(!((SelectionBits*)(self+0xd0c))->selected){
  matched=0;
  if(ap->length==32){result=WirelessScan_ClassifySpecialAccessPoint((unsigned char*)ap);if(result>0)++matched;else result=0;}
  else if(ap->length==8){result=Network_ClassifyFreespotSsid((const char*)ap);if(result)++matched;else result=0;}
  unsigned char* cursor;char* ssid;Profile* profile;
  i=0;
  if(i<self[0xd10]){cursor=self;ssid=(char*)self+0x304;profile=(Profile*)(self+0x300);do{
   if(ap->length==cursor[0x303]&&!strncmp(ap->ssid,ssid,ap->length)){
    if(!matched)result=cursor[0x301];
    else{profile->flags.selected=1;((SelectionBits*)(self+0xd0c))->selected=1;}
    ++matched;
   }
   ++i;cursor+=36;ssid+=36;++profile;
  }while(i<self[0xd10]);}
 }else{
  Profile* profile;unsigned char* cursor;
  i=0;matched=0;
  if(i<self[0xd10]){profile=(Profile*)(self+0x300);cursor=self;do{
   if(profile->flags.selected==1){
    if(!matched){profile->flags.selected=0;result=cursor[0x301];}
    ++matched;
   }
   ++i;++profile;cursor+=36;
  }while(i<self[0xd10]);}
  if(matched==1)((SelectionBits*)(self+0xd0c))->selected=0;
 }
 return (unsigned char)result;
}
