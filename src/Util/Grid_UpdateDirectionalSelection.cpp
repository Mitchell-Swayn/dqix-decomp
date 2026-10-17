#include <globaldefs.h>
ARM
struct Grid {int count,pages,cols,rows;int unknown10,unknown14,col,row;int other[4];int delta;unsigned short key;unsigned char vertical,horizontal,delay,initialDelay,repeatDelay,pad3b,wrapCol,wrapRow;};
struct Keys {unsigned short v[5];};struct Deltas {int v[4];};struct Flags {unsigned char v[4];};
extern "C" {
int Input_TestKeyMask(unsigned short*,unsigned short);
int Object_TestNewlySetHalfwordMask(unsigned short*,unsigned);
int TestReleasedInputMask(unsigned short*,unsigned);
void ComputePageRowAndColumn(Grid*,int);
int Grid_ComputeSelectedLinearIndex(Grid*);
void Object_ClearWord30AndTrailingStatusBytes(void*);
void AdvanceWrappedOffsetAndClampSelection(Grid*,int);
extern Keys data_020e7db8;extern Deltas data_020e7dc4;extern Flags data_020e7db0,data_020e7db4;extern unsigned short data_02114e30[];
}
// Original: arm9/main @ 0x0205BF58; symbol: func_0205bf58; size: 0x550.
extern "C" int Grid_UpdateDirectionalSelection(Grid* self,int ticks){
 if(!self->count)return 0;if(self->cols<=0)return 0;if(self->rows<=0)return 0;
 int initial=self->initialDelay,repeat=self->repeatDelay;
 Keys keys=data_020e7db8;
 for(int i=0;keys.v[i]!=0xffff&&!self->key;i++){
  unsigned short key=keys.v[i];
  if(!Object_TestNewlySetHalfwordMask(data_02114e30,key))continue;
  if(self->vertical|self->horizontal){Object_ClearWord30AndTrailingStatusBytes(self);break;}
  Deltas delta=data_020e7dc4;Flags vertical=data_020e7db0;Flags horizontal=data_020e7db4;
  self->key=key;self->delay=initial;self->delta=delta.v[i];self->vertical=vertical.v[i];self->horizontal=horizontal.v[i];
  if(self->key==0x40||self->key==0x80){
   int old=self->row;self->row+=self->delta;
   int row=*(volatile int*)&self->row;
   if(self->wrapRow){
    int rows=self->rows;
    if(rows<=row)self->row=0;else if(row<0)self->row=rows-1;
    if(self->key==0x40){int count=self->count;if(count<=Grid_ComputeSelectedLinearIndex(self))ComputePageRowAndColumn(self,count-1);}
    else if(self->key==0x80){if(self->count<=Grid_ComputeSelectedLinearIndex(self))self->row=0;}
   }else{
    int rows=self->rows;
    if(rows<=row)self->row=old;else if(row<0)self->row=old;
    if(Grid_ComputeSelectedLinearIndex(self)>=self->count)self->row=old;
   }
  }else if(self->key==0x20||self->key==0x10){
   int old=self->col;self->col+=self->delta;
   if(self->cols<=self->col){
    if(self->wrapCol){self->col=0;if(self->pages>1)AdvanceWrappedOffsetAndClampSelection(self,1);}
    else{if(self->pages==1)self->col=old;else{self->col=0;AdvanceWrappedOffsetAndClampSelection(self,1);}}
   }else if(self->col<0){
    if(self->wrapCol){self->col=self->cols-1;if(self->pages>1)AdvanceWrappedOffsetAndClampSelection(self,-1);}
    else{if(self->pages==1)self->col=old;else{self->col=self->cols-1;AdvanceWrappedOffsetAndClampSelection(self,-1);}}
   }
   if(Grid_ComputeSelectedLinearIndex(self)>=self->count){if(self->pages==1)self->col=old;else{self->col=0;AdvanceWrappedOffsetAndClampSelection(self,1);}}
  }
  return 1;
 }
 if(self->vertical){
  if(Input_TestKeyMask(data_02114e30,0xf0)){
   if((unsigned char)ticks<self->delay)self->delay-=(unsigned char)ticks;
   else{
    self->delay=repeat;self->vertical=1;self->horizontal=0;
    self->row+=self->delta;
    if(self->rows<=self->row)self->row=self->rows-1;else if(self->row<0)self->row=0;
    int count=self->count;if(count<=Grid_ComputeSelectedLinearIndex(self))ComputePageRowAndColumn(self,count-1);
    if(self->key==0x40||self->key==0x20){int count=self->count;if(count<=Grid_ComputeSelectedLinearIndex(self))ComputePageRowAndColumn(self,count-1);}
    else if(self->key==0x80||self->key==0x10){if(self->count<=Grid_ComputeSelectedLinearIndex(self))self->row=0;}
   }
  }
  if(TestReleasedInputMask(data_02114e30,0xf0))Object_ClearWord30AndTrailingStatusBytes(self);
  return 1;
 }
 if(self->horizontal){
  if(Input_TestKeyMask(data_02114e30,0xf0)){
   if((unsigned char)ticks<self->delay)self->delay-=(unsigned char)ticks;
   else{
    self->delay=repeat;self->vertical=0;self->horizontal=1;
    self->col+=self->delta;
    if(self->cols<=self->col){self->col=self->cols-1;AdvanceWrappedOffsetAndClampSelection(self,1);}
    else if(self->col<0){self->col=0;AdvanceWrappedOffsetAndClampSelection(self,-1);}
    if(Grid_ComputeSelectedLinearIndex(self)>=self->count){if(self->pages==1)self->col=0;else{self->col=0;AdvanceWrappedOffsetAndClampSelection(self,1);}}
   }
  }
  if(TestReleasedInputMask(data_02114e30,0xf0))Object_ClearWord30AndTrailingStatusBytes(self);
  return 1;
 }
 return 0;
}
