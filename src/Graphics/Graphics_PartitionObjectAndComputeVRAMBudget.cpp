#include <globaldefs.h>
ARM
struct RectPart {unsigned int attr,offset;unsigned char x,y,width,height;};
struct Info {unsigned int unknown0[2];RectPart* parts;unsigned char pad[0x24];unsigned int freeBytes,usedBytes;unsigned char pad2[2];unsigned char width,height,capacity,unknown3d,screen;};
struct Owner {unsigned int unknown;Info* info;};
extern "C" void Graphics_UploadObjectPaletteByScreenSelector(Owner*);
extern "C" unsigned int Graphics_SplitRectangleIntoParts(RectPart*,unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" int Graphics_ReadObjectMappingAlignmentShift(int);
extern "C" int Graphics_ComputeObjectVRAMCapacity(int);
extern "C" unsigned int Object_ReadHalfProductOfTwoNestedBytes(char*);
extern "C" void ResourceBuffer_InvokeIndexedTransformWithCacheMaintenance(unsigned char*);
// Original: arm9/main @ 0x020E1B2C; symbol: func_020e1b2c; size: 0x18C.
extern "C" unsigned int Graphics_PartitionObjectAndComputeVRAMBudget(Owner* self,unsigned int limit) {
 if(!self->info) return 0;
 Graphics_UploadObjectPaletteByScreenSelector(self);

 RectPart* parts=self->info->parts;
 unsigned int height=self->info->height;
 unsigned int capacity=self->info->capacity;
 unsigned int partWidth;
 unsigned int x;
 unsigned int width=self->info->width;
 unsigned int count;
 if(!parts || !capacity || !width || !height) { count=0; goto generated; }
 {
  width=(width+7)&~7;
  height=(height+7)&~7;
  count=0;
  x=0;
  while(x<width) {
   if(count>=capacity) break;
   partWidth=64;
   while(partWidth>8 && partWidth>width-x) partWidth>>=1;
   count+=Graphics_SplitRectangleIntoParts(parts+count,capacity-count,x,0,partWidth,height);
   x+=partWidth;
  }
 }
 generated:
 self->info->capacity=count;
 capacity=0;
 unsigned int screen=self->info->screen;
 width=self->info->capacity;
 int product;
 RectPart* parts2=self->info->parts;
 for(count=0;count<width;++count) {
  parts2[count].offset=capacity;
  product=parts2[count].width*parts2[count].height;
  unsigned int mask=1u<<Graphics_ReadObjectMappingAlignmentShift(screen);
  if(mask) --mask;
  capacity+=(mask+(product>>1))&~mask;
 }
 self->info->usedBytes=capacity;
 unsigned int available=Graphics_ComputeObjectVRAMCapacity(self->info->screen);
 Info* info=self->info;
 if(limit!=~0u) available=limit;
 info->freeBytes=available-(info->usedBytes+Object_ReadHalfProductOfTwoNestedBytes((char*)info));
 ResourceBuffer_InvokeIndexedTransformWithCacheMaintenance((unsigned char*)self->info+0xc);
 return self->info->freeBytes;
}
