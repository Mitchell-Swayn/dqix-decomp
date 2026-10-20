#include <globaldefs.h>
struct Header {unsigned first;char pad[6];unsigned char width,height;};
struct State {char pad0[8];Header* header;char padc[24];unsigned first,second;unsigned char zero1,zero2,width,height;unsigned offset1,offset2;char pad38[2];unsigned char limitWidth,limitHeight;};
struct Context {char* base;State* state;};
struct Dimensions {char pad[8];unsigned short width,height;};
struct Transfer {char pad[12];};
extern "C" void Window_ResetSpriteRegion(void*),TextCanvas_ResetRegionDescriptor(Dimensions*),TextCanvas_InitializeRegionCanvas(Transfer*),TextCanvas_SetPixelBuffer(Transfer*,void*),TextCanvas_SetRegions(Transfer*,Dimensions*,int),TextCanvas_FillRegionRectangle4Bpp(Transfer*,int,int,unsigned,unsigned,int);
// Original: arm9/main @ 0x020E2018; symbol: func_020e2018; size: 0xF8.
extern "C" void Window_InitializeFillPatternCanvas(Context* p){State* state=p->state;Header* header=state->header;Window_ResetSpriteRegion(&state->first);state->first=header->first;state->second=0;state->zero1=0;state->zero2=0;state->width=header->width-4;state->height=header->height-4;int limit=p->state->limitWidth-4;if(limit<=state->width)state->width=limit;limit=p->state->limitHeight-4;if(limit<=state->height)state->height=limit;Dimensions dimensions;Transfer transfer;TextCanvas_ResetRegionDescriptor(&dimensions);dimensions.width=header->width;dimensions.height=header->height;TextCanvas_InitializeRegionCanvas(&transfer);TextCanvas_SetPixelBuffer(&transfer,p->base+(p->state->offset1+p->state->offset2));TextCanvas_SetRegions(&transfer,&dimensions,1);TextCanvas_FillRegionRectangle4Bpp(&transfer,0,0,state->width,state->height,1);}
