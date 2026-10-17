#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
#include <Memory/SafeAllocator.h>
struct State{unsigned char width,height,format,pad;unsigned tileCount;void*tiles;char padc[8];unsigned short id,screen,slot;};extern "C" char data_02105254[];extern "C" unsigned short Graphics_AppendAndUploadBackgroundCharacterData(void*,int,unsigned short,const void*,unsigned,unsigned);
// Original: arm9/main @ 0x0203BB3C; symbol: func_0203bb3c; size: 0x17C.
extern "C" ARM void Graphics_InitializeBackgroundMapFromDataAndPalette(State*p,const char*data,SafeAllocator*allocator,int screen,unsigned short slot){void*table=data_02105254;p->screen=screen;p->slot=slot;memcpy(p,data,8);data+=8;if(p->format==0){CleanInvalidateCacheRange(data,32);switch(screen){case 0:LoadToMainBGStandardPalette(data,0,32);break;case 1:LoadToSubBGStandardPalette(data,0,32);break;}data+=32;p->id=Graphics_AppendAndUploadBackgroundCharacterData(table,screen,slot,data,p->tileCount<<5,p->tileCount);data+=p->tileCount*32;}else if(p->format==1){CleanInvalidateCacheRange(data,512);switch(screen){case 0:LoadToMainBGStandardPalette(data,0,512);break;case 1:LoadToSubBGStandardPalette(data,0,512);break;}data+=512;p->id=Graphics_AppendAndUploadBackgroundCharacterData(table,screen,slot,data,p->tileCount<<6,p->tileCount);data+=p->tileCount*64;}p->tiles=allocator->Allocate(p->width*2*p->height);memcpy(p->tiles,data,p->width*2*p->height);}
