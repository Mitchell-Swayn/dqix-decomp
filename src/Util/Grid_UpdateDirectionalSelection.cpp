#include <globaldefs.h>
ARM
struct Grid {int count,pages,cols,rows;int unknown10,unknown14,col,row;int other[4];int delta;unsigned short key;unsigned char vertical,horizontal,delay,initialDelay,repeatDelay,pad3b,wrapCol,wrapRow;};
struct Keys {unsigned short v[5];};struct Deltas {int v[4];};struct Flags {unsigned char v[4];};
extern "C" {
int Input_TestKeyMask(unsigned short*,unsigned short);
int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
int Input_IsKeyMaskReleased(unsigned short*,unsigned);
void Grid_SelectIndexAndComputePageCoordinates(Grid*,int);
int Grid_ComputeSelectedLinearIndex(Grid*);
void Grid_ResetDirectionalRepeat(void*);
void Grid_AdvanceWrappedPageAndClampSelection(Grid*,int);
// Original data: arm9/main @ 0x20e7db0; symbol: data_020e7db0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01010000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e7db4; symbol: data_020e7db4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000101.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e7db8; symbol: data_020e7db8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 4000800020001000ffff0000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e7dc4; symbol: data_020e7dc4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffff01000000ffffffff01000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Keys GridUpdateDirectionalSelection_UnknownRoleInitializedBytes_Variant3;extern Deltas GridUpdateDirectionalSelection_UnknownRoleInitializedBytes_Variant4;extern Flags GridUpdateDirectionalSelection_UnknownRoleInitializedBytes,GridUpdateDirectionalSelection_UnknownRoleInitializedBytes_Variant2;extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/main @ 0x0205BF58; symbol: func_0205bf58; size: 0x550.
extern "C" int Grid_UpdateDirectionalSelection(Grid* self,int ticks){
 if(!self->count)return 0;if(self->cols<=0)return 0;if(self->rows<=0)return 0;
 int initial=self->initialDelay,repeat=self->repeatDelay;
 Keys keys=GridUpdateDirectionalSelection_UnknownRoleInitializedBytes_Variant3;
 for(int i=0;keys.v[i]!=0xffff&&!self->key;i++){
  unsigned short key=keys.v[i];
  if(!Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,key))continue;
  if(self->vertical|self->horizontal){Grid_ResetDirectionalRepeat(self);break;}
  Deltas delta=GridUpdateDirectionalSelection_UnknownRoleInitializedBytes_Variant4;Flags vertical=GridUpdateDirectionalSelection_UnknownRoleInitializedBytes;Flags horizontal=GridUpdateDirectionalSelection_UnknownRoleInitializedBytes_Variant2;
  self->key=key;self->delay=initial;self->delta=delta.v[i];self->vertical=vertical.v[i];self->horizontal=horizontal.v[i];
  if(self->key==0x40||self->key==0x80){
   int old=self->row;self->row+=self->delta;
   int row=*(volatile int*)&self->row;
   if(self->wrapRow){
    int rows=self->rows;
    if(rows<=row)self->row=0;else if(row<0)self->row=rows-1;
    if(self->key==0x40){int count=self->count;if(count<=Grid_ComputeSelectedLinearIndex(self))Grid_SelectIndexAndComputePageCoordinates(self,count-1);}
    else if(self->key==0x80){if(self->count<=Grid_ComputeSelectedLinearIndex(self))self->row=0;}
   }else{
    int rows=self->rows;
    if(rows<=row)self->row=old;else if(row<0)self->row=old;
    if(Grid_ComputeSelectedLinearIndex(self)>=self->count)self->row=old;
   }
  }else if(self->key==0x20||self->key==0x10){
   int old=self->col;self->col+=self->delta;
   if(self->cols<=self->col){
    if(self->wrapCol){self->col=0;if(self->pages>1)Grid_AdvanceWrappedPageAndClampSelection(self,1);}
    else{if(self->pages==1)self->col=old;else{self->col=0;Grid_AdvanceWrappedPageAndClampSelection(self,1);}}
   }else if(self->col<0){
    if(self->wrapCol){self->col=self->cols-1;if(self->pages>1)Grid_AdvanceWrappedPageAndClampSelection(self,-1);}
    else{if(self->pages==1)self->col=old;else{self->col=self->cols-1;Grid_AdvanceWrappedPageAndClampSelection(self,-1);}}
   }
   if(Grid_ComputeSelectedLinearIndex(self)>=self->count){if(self->pages==1)self->col=old;else{self->col=0;Grid_AdvanceWrappedPageAndClampSelection(self,1);}}
  }
  return 1;
 }
 if(self->vertical){
  if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0xf0)){
   if((unsigned char)ticks<self->delay)self->delay-=(unsigned char)ticks;
   else{
    self->delay=repeat;self->vertical=1;self->horizontal=0;
    self->row+=self->delta;
    if(self->rows<=self->row)self->row=self->rows-1;else if(self->row<0)self->row=0;
    int count=self->count;if(count<=Grid_ComputeSelectedLinearIndex(self))Grid_SelectIndexAndComputePageCoordinates(self,count-1);
    if(self->key==0x40||self->key==0x20){int count=self->count;if(count<=Grid_ComputeSelectedLinearIndex(self))Grid_SelectIndexAndComputePageCoordinates(self,count-1);}
    else if(self->key==0x80||self->key==0x10){if(self->count<=Grid_ComputeSelectedLinearIndex(self))self->row=0;}
   }
  }
  if(Input_IsKeyMaskReleased(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0xf0))Grid_ResetDirectionalRepeat(self);
  return 1;
 }
 if(self->horizontal){
  if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0xf0)){
   if((unsigned char)ticks<self->delay)self->delay-=(unsigned char)ticks;
   else{
    self->delay=repeat;self->vertical=0;self->horizontal=1;
    self->col+=self->delta;
    if(self->cols<=self->col){self->col=self->cols-1;Grid_AdvanceWrappedPageAndClampSelection(self,1);}
    else if(self->col<0){self->col=0;Grid_AdvanceWrappedPageAndClampSelection(self,-1);}
    if(Grid_ComputeSelectedLinearIndex(self)>=self->count){if(self->pages==1)self->col=0;else{self->col=0;Grid_AdvanceWrappedPageAndClampSelection(self,1);}}
   }
  }
  if(Input_IsKeyMaskReleased(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0xf0))Grid_ResetDirectionalRepeat(self);
  return 1;
 }
 return 0;
}
