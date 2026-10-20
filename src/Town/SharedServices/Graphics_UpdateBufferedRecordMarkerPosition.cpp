struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" int TextCanvas_HasActiveTilemap(char*);
extern "C" void SpriteAnimation_AdvanceAllTracks(char*,unsigned);
extern "C" void SpriteAnimation_StartTrack(char*,int);
extern "C" char* SpriteAnimation_FindTrackByKey(char*,unsigned);
extern "C" void SpriteAnimation_SetTrackOamStartIndex(void*,int,unsigned char);
extern "C" void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);
extern "C" WindowCanvasRecord* Window_GetSelectedTextCanvas(WindowCanvasOwner*);
// Original: arm9/ov003 @ 0x0215E2A8; symbol: func_ov003_0215e2a8; size: 0x154.
extern "C" void Graphics_UpdateBufferedRecordMarkerPosition(char* self) {
 if(!*(unsigned char*)(self+0x3c2)) return;
 char* record=(char*)(unsigned)Window_GetSelectedTextCanvas((WindowCanvasOwner*)(self+0x98));
 if(!record)return;
 if(*(unsigned char*)(record+0xc4)!=1)return;
 if(!TextCanvas_HasActiveTilemap(record))return;
 if(*(unsigned char*)(record+0xc5)&0x20)return;
 short x=(short)(*(short*)(record+0xbc)+(short)(*(short*)(record+0xac)*8));
 short y=(short)(*(short*)(record+0xbe)+(short)(*(short*)(record+0xae)*8));
 x-=8;y-=2;
 if(*(unsigned char*)(self+0x3f2)) {
  char* data=(char*)TextContext_GetSharedInstance();
  x-=2;y+=(short)(*(short*)(data+0x916)%8);
 }
 void* state=_ZN9GameState11GetInstanceEv();
 char* marker=*(char**)(self+0x394);
 if(!marker)return;
 SpriteAnimation_StartTrack(marker,0);
 char* entry=SpriteAnimation_FindTrackByKey(marker,0);
 if(entry) *(unsigned char*)(entry+0x15)|=8;
 SpriteAnimation_AdvanceAllTracks(marker,_ZNK9GameState12GetTickCountEv(state));
 entry=SpriteAnimation_FindTrackByKey(marker,0);
 if(entry){*(short*)(entry+4)=x;*(short*)(entry+6)=y;}
 SpriteAnimation_SetTrackOamStartIndex(marker,0,0x3f);
 SpriteAnimation_SubmitAllTrackFrames((unsigned char*)self+0x358);
}
