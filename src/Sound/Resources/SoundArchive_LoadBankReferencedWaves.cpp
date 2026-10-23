#include <globaldefs.h>
ARM
#pragma optimize_for_size off
struct Cursor {unsigned a,b;};struct Entry {unsigned char type,pad;unsigned short key,owner;char rest[6];};extern "C" void SND_GetFirstInstDataPos(Cursor*);extern "C" int SND_GetNextInstData(void*,Entry*,Cursor*);struct SNDWaveArc;extern "C" int SoundArchive_LoadSingleWave(SNDWaveArc*,int,unsigned,unsigned char*);
// Original: arm9/main @ 0x020BE604; symbol: func_020be604; size: 0xC0.
extern "C" int SoundArchive_LoadBankReferencedWaves(void* p,void* file,unsigned owner,int a,int b){Entry entry;Cursor cursor,original;SND_GetFirstInstDataPos(&original);cursor=original;Cursor* next=&cursor;if(!file)return 0;int n=SND_GetNextInstData(file,&entry,next);if(n){do{if(entry.type==1&&owner==entry.owner&&!SoundArchive_LoadSingleWave((SNDWaveArc*)p,entry.key,(unsigned)a,(unsigned char*)b))return 0;n=SND_GetNextInstData(file,&entry,&cursor);}while(n);}return 1;}
