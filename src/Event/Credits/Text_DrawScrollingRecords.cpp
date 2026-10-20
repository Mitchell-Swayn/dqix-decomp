#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Record { short id,y; unsigned flags; char* text; };
struct List { float speed; Record* records; unsigned short used,capacity; };
struct Pair64 { unsigned lo,hi; inline Pair64& operator=(const Pair64& r) { lo=r.lo;hi=r.hi;return *this; } };
struct State { List list; unsigned char base[0x14]; unsigned char resource[0x20]; void* tiles; unsigned char alloc[0x14]; unsigned mainLayers,subLayers; int scroll,nextScroll; unsigned unk68; unsigned short index; unsigned char dirty,pad; int request; unsigned saved1,saved2,saved3; unsigned char phase,step,pad2[2]; Pair64 start,now; unsigned prior,elapsed; unsigned char toggle,pad3[3]; Pair64 epoch,delta; };
struct Sprite { unsigned char head[8]; void* tiles; unsigned char body[0x94]; unsigned fielda0,fielda4; unsigned char extra[12]; unsigned short width,height,x,y; unsigned char tail[0x24]; };
struct CreditRecord { short id,y;unsigned type:4;unsigned alignment:2;unsigned gap:1;unsigned style:4;unsigned rest:21;char* text; };
extern "C" {
void StaffRoll_InitializeTextCanvas(Sprite*,void*);void StaffRoll_AdvanceScrollAccumulators(int*,float);void StaffRoll_ClearConsumedTileStrip(int*,void*);
Record* StaffRoll_GetRecord(List*,unsigned short);
int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
void TextCanvas_RenderStyledTextAndMeasure(Sprite*,short,short,char*,unsigned char,unsigned char,short*,short*,int);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
int Input_TestKeyMask(unsigned short*,unsigned short);extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov028 @ 0x021D9208; symbol: func_ov028_021d9208; size: 0x224.
// Draws scrolling records, aligning text and repeating across the 256-line boundary.
extern "C" void Text_DrawScrollingRecords(State* p,int ticks) {
float speed=p->list.speed;StaffRoll_AdvanceScrollAccumulators(&p->scroll,0.5f*((float)ticks*speed));
StaffRoll_ClearConsumedTileStrip(&p->scroll,p->tiles);
void* tiles=p->tiles; short prior=-1;short b,a;int font;short y;bool done;
for (;;) {
CreditRecord* r=(CreditRecord*)StaffRoll_GetRecord(&p->list,p->index);if(!r){done=true;goto finished;}
if (prior!=r->id) {
if ((unsigned)((p->scroll>>12)+192)<(unsigned)(r->y+(p->nextScroll>>12))) break;
p->nextScroll+=r->y<<12;
}
font=0;y=(p->nextScroll>>12)&255;if(r->type==12)font=1;prior=0;
if(r->alignment) {
int width=TextLayout_ComputeWidthWithGlyphSpacing(r->text,font);prior=136;
switch(r->alignment) {case 1:prior=(256-width)>>1;break;case 2:prior=120-width;break;}
}
Sprite sprite;StaffRoll_InitializeTextCanvas(&sprite,tiles);
unsigned type=r->type;sprite.width=type;sprite.height=type+1;
TextCanvas_RenderStyledTextAndMeasure(&sprite,prior,y,r->text,r->type,r->style,&a,&b,font);
if(y+r->type>256)TextCanvas_RenderStyledTextAndMeasure(&sprite,prior,y-256,r->text,r->type,r->style,&a,&b,font);
++p->index;p->dirty=1;prior=r->id;
}
done=false;
finished:
Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,8192);
if(done){p->phase=2;p->step=0;}
}
