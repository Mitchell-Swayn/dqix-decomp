#include <globaldefs.h>
#pragma opt_propagation off
ARM
typedef unsigned int undefined4;
struct List;
struct Entry;
extern "C" {
unsigned TextContext_GetSharedInstance();
int Selection_GetActiveInputIndex(unsigned char*);
void TextWindow_SelectFrameTransitionRecord(int,unsigned);
void WindowFrame_DrawLinkedScaledRectangle(void*,int,int);
void TextWindow_SelectPrimaryFrameTransition(int);
bool TextLayout_IsPanelVisible(unsigned char*);
void TextLayout_DrawCachedGlyphRun(unsigned,void*,int,int,unsigned,int,int,int,int,int);
void SpriteAnimation_StartTrack(void*,unsigned);
Entry* SpriteAnimation_FindTrackByKey(List*,unsigned);
void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);
}
// Original: arm9/main @ 0x0205C96C; symbol: func_0205c96c; size: 0x1F4.
extern "C" void TextLayout_DrawSelectionPanelAndCursor(unsigned char* self,int mode) {
 if(!self[0x233]||!self[0x232])return;
 unsigned context=TextContext_GetSharedInstance();
 int selected=*(int*)(self+0x50);
 unsigned char* text;
 int end;
 int active=Selection_GetActiveInputIndex(self+0x1c);
 int startY;
 unsigned color=0x7fff;
 if(!self[0x234])color=0x3def;
 if(!mode){
  *(short*)(self+0xcc)=color;
  TextWindow_SelectFrameTransitionRecord((int)context,(unsigned)(self+0xb4));
  WindowFrame_DrawLinkedScaledRectangle((void*)(context+0x19e0),1,1);
  TextWindow_SelectPrimaryFrameTransition((int)context);
 }
 if(!TextLayout_IsPanelVisible(self))return;
 *(unsigned char*)(context+0x19b0)=1;
 int x,y;
 int count=*(int*)(self+0x7c);
 int index=count**(int*)(self+0x84);
 y=*(short*)(self+0xb6)+8;
 end=index+count;
 startY=y;
 x=*(short*)(self+0xb4)+12;
 text=self+0x120;
 while(index<end){
  unsigned drawColor=color;
  if(index==selected&&selected==active)drawColor=0xf0a;
  TextLayout_DrawCachedGlyphRun(context,text+*(unsigned short*)(self+0x220+index*2)*2,x,y,drawColor,12,20,mode,1,17);
  ++index;
  y+=*(int*)(self+0xd8);
 }
 if(!(self[0xb0]|self[0xb1]))return;
 y=*(int*)(self+0x88);
 index=*(int*)(self+0x8c);
 x=y**(int*)(self+0xd4)+(x-16);
 selected=*(int*)(context+0x2d8);
 y=index**(int*)(self+0xd8)+(startY-2);
 color=*(unsigned short*)(context+0x2e4);
 context=*(unsigned*)(context+0x2e0);
 if(!selected||!context)return;
 SpriteAnimation_StartTrack((void*)context,color);
 unsigned char* entry=(unsigned char*)SpriteAnimation_FindTrackByKey((List*)context,color);
 if(entry)entry[21]|=8;
 entry=(unsigned char*)SpriteAnimation_FindTrackByKey((List*)context,color);
 if(entry){*(short*)(entry+4)=x;*(short*)(entry+6)=y;}
 SpriteAnimation_SubmitAllTrackFrames((unsigned char*)selected);
}
