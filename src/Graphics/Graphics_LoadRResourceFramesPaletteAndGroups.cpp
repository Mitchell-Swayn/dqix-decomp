#include <Memory/SafeAllocator.h>
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" unsigned strlen(const char*);
extern "C" char* strcpy(char*,const char*);
extern "C" unsigned AllocateTexturePaletteVRAM(unsigned,unsigned,unsigned);
extern "C" unsigned short data_020e7a0c[];
struct Image { unsigned short x,y,width,height; int size; unsigned char* pixels; };
struct Frame { unsigned short a,b,count,pad; Image* images; unsigned size; unsigned char* pixels; };
struct Group { char* name; unsigned count; unsigned* a; unsigned* b; unsigned* c; };
struct Resource { unsigned loaded; unsigned short format,count; Frame* frames; int paletteCount; unsigned short* palette; unsigned paletteKey; unsigned groupCount; Group* groups; unsigned maxImages,maxPixels; };
// Original: arm9/main @ 0x0203FD5C; symbol: func_0203fd5c; size: 0x428.
// Parses an R-suffixed graphic resource into frames, pixels, palette, and named groups.
extern "C" void Graphics_LoadRResourceFramesPaletteAndGroups(Resource* self,const char* filename,SafeAllocator* allocator,unsigned char* input)
{
 if(*(filename+strlen(filename)-1)!='r') return;
 int offset=0;
 char name[30];
 memcpy(&self->count,input,2);
 memcpy(&self->format,input+2,2);
 offset+=4;
 self->frames=(Frame*)allocator->Allocate(self->count*20);
 int i=0;
 self->maxImages=0; self->maxPixels=0;
 Frame* frame=self->frames;
 for(;i<self->count;i++,frame++) {
 unsigned imageCount;
 memcpy(&frame->a,input+offset,2);
 memcpy(&frame->b,input+(offset+2),2);
 memcpy(&imageCount,input+(offset+4),4);
 offset+=8; frame->count=imageCount;
 if(self->maxImages<imageCount) self->maxImages=imageCount;
 frame->images=(Image*)allocator->Allocate(imageCount*16);
 frame->size=0;
 Image* image=frame->images;
 for(unsigned j=0;j<imageCount;j++,image++) {
 memcpy(&image->x,input+offset,2);offset+=2;
 memcpy(&image->y,input+offset,2);offset+=2;
 memcpy(&image->width,input+offset,2);offset+=2;
 memcpy(&image->height,input+offset,2);offset+=2;
 int w=image->width;
 bool half=self->format==3;
 int h=image->height;
 int width=data_020e7a0c[w];
 int height=data_020e7a0c[h];
 if(half) image->size=(width*height)/2;
 else image->size=width*height;
 image->pixels=input+offset;
 offset+=image->size;
 frame->size+=image->size;
 }
 if(self->maxPixels<frame->size) self->maxPixels=frame->size;
 frame->pixels=(unsigned char*)allocator->Allocate(frame->size);
 unsigned sum=0;
 image=frame->images;
 for(unsigned j=0;j<imageCount;j++,image++) {
 unsigned char* old=image->pixels;
 image->pixels=frame->pixels+sum;
 memcpy(image->pixels,old,image->size);
 sum+=image->size;
 }
 }
 int paletteCount;
 memcpy(&paletteCount,input+offset,4); offset+=4;
 self->paletteCount=paletteCount;
 if(self->paletteCount<=16) self->paletteCount=16;
 else if(self->paletteCount<=256) self->paletteCount=256;
 self->paletteKey=(unsigned short)AllocateTexturePaletteVRAM(self->paletteCount*2,0,0)*8;
 self->palette=(unsigned short*)allocator->Allocate(self->paletteCount*2);
 memcpy(self->palette,input+offset,self->paletteCount*2);
 offset+=paletteCount*2;
 memcpy(&self->groupCount,input+(offset+30),4);offset+=34;
 self->groups=(Group*)allocator->Allocate(self->groupCount*20);
 for(unsigned i=0;i<self->groupCount;i++) {
 Group* group=&self->groups[i];
 memcpy(name,input+offset,30);offset+=30;
 int length=strlen(name)+1;
 if(length%4) length=(length/4+1)*4;
 char* stored=(char*)allocator->Allocate(length);
 group->name=stored;
 strcpy(stored,name);
 }
 for(unsigned i=0;i<self->groupCount;i++) {
 Group* group=&self->groups[i];
 memcpy(&group->count,input+offset,4);offset+=4;
 unsigned count=group->count;unsigned bytes=count*4;
 group->a=(unsigned*)allocator->Allocate(bytes);
 group->b=(unsigned*)allocator->Allocate(bytes);
 group->c=(unsigned*)allocator->Allocate(bytes);
 memcpy(group->a,input+offset,bytes);offset+=count*4;
 memcpy(group->b,input+offset,bytes);offset+=count*4;
 memcpy(group->c,input+offset,bytes);offset+=count*4;
 }
 self->loaded=1;
}
