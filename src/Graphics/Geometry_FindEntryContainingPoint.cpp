#include <globaldefs.h>
ARM
struct Record { short* ids; short pad4[3]; short x,y; char pad14[5]; unsigned char count; };
struct Entry {int pad;short key,x,y,w,h;char pad14[4];unsigned char state;char pad19[5];int a,b,c,d;short dx;unsigned char flags;};
extern "C" int Geometry_TestPointWithinScaledTextureRectangle(void*,int,int,int);
extern "C" Record* DisplayLayout_FindGroupById(void*,int);
extern "C" Entry* DisplayLayout_FindPartById(void*,int);
// Original: arm9/main @ 0x02080E40; symbol: func_02080e40; size: 0x14C.
extern "C" int Geometry_FindEntryContainingPoint(char* owner,int index,int x,int y) {
 if(!Geometry_TestPointWithinScaledTextureRectangle(owner,index,x,y)) return -1;
 Record* record=DisplayLayout_FindGroupById(owner+12,index);
 if(!record)return -1;
 short ox=record->x*8, oy=record->y*8;
 for(unsigned char i=0;i<record->count;i++) {
 int id=record->ids[i];
 Entry* e=DisplayLayout_FindPartById(owner+4,id);
 if(!e || e->state==1)continue;
 if(e->flags&1)continue;
 if(!e->a&&!e->b&&!e->c&&!e->d)continue;
 short left=e->x+e->dx;
 short top=e->y;
 short right=left+e->w;
 short bottom=top+e->h;
 left+=ox;top+=oy;right+=ox;bottom+=oy;
 if(y>=top && bottom>y && x>=left && right>x)return id;
 }
 return -1;
}
