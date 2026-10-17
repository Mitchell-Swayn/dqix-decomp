#include <globaldefs.h>
ARM
#pragma opt_dead_assignments off
struct DecodeTemps {unsigned jump;unsigned action19_va;unsigned action18_va;unsigned action18_vb;unsigned action18_vc;unsigned action17_va;unsigned action17_vc;unsigned action17_vb;unsigned action17_vd;unsigned action16_va;unsigned action16_vb;unsigned action16_vd;unsigned action16_vc;unsigned action15_va;unsigned action15_vb;unsigned action15_vc;unsigned action13_va;unsigned action12_va;unsigned action12_vb;unsigned action11_va;unsigned action11_vb;unsigned action10_va;unsigned action9_va;unsigned action9_vb;unsigned action9_vc;unsigned action9_vd;unsigned action8_va;unsigned action8_vb;unsigned action8_vc;unsigned action7_va;unsigned action7_vb;unsigned action6_va;unsigned action6_vb;unsigned action5_va;unsigned action5_vb;unsigned action5_vc;unsigned action4_va;unsigned action3_va;unsigned action3_vb;unsigned action2_va;};
struct Info {unsigned address,size;unsigned char* cursor;unsigned pad[3];unsigned context[1];};
extern "C" {
unsigned _Z15__PopStackFrameP12ThrowContextP13ExceptionInfo(void*,Info*);
void Runtime_FindUnwindDescriptorForAddress(unsigned,Info*);
void RuntimeUnwind_DecodeFlagsAndSelectFramePointer(void*,Info*);
unsigned char* Runtime_DecodeCompactSignedInteger(unsigned char*,unsigned*);
unsigned char* RuntimeUnwind_ReadCompactUnsignedInteger(unsigned char*,unsigned*);
}
// Original: arm9/main @ 0x0200DBF8; symbol: func_0200dbf8; size: 0x388.
extern "C" unsigned Runtime_AdvanceUnwindActionDescriptor(Info* self){
 DecodeTemps temps;
 unsigned char* p;
 while(1){p=self->cursor;
 if(!p||(*p&128)){
   unsigned address=_Z15__PopStackFrameP12ThrowContextP13ExceptionInfo(self->context,self);
   Runtime_FindUnwindDescriptorForAddress(address,self);
   if(!self->size)return 255;
   RuntimeUnwind_DecodeFlagsAndSelectFramePointer(self->context,self);
  if(self->cursor)break;
 }else{
  switch(*p&31){
  case 2:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action2_va);
   self->cursor=q+4;break;}
  case 3:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action3_va);
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action3_vb);
   self->cursor=q+4;break;}
  case 4:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action4_va);
   self->cursor=q+4;break;}
  case 5:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action5_va);
   q=RuntimeUnwind_ReadCompactUnsignedInteger(q,&temps.action5_vb);
   q=RuntimeUnwind_ReadCompactUnsignedInteger(q,&temps.action5_vc);
   self->cursor=q+4;break;}
  case 6:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action6_va);
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action6_vb);
   self->cursor=q+4;break;}
  case 7:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action7_va);
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action7_vb);
   self->cursor=q+4;break;}
  case 8:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action8_va);
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action8_vb);
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action8_vc);
   self->cursor=q+4;break;}
  case 9:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action9_va);
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action9_vb);
   q=RuntimeUnwind_ReadCompactUnsignedInteger(q,&temps.action9_vc);
   q=RuntimeUnwind_ReadCompactUnsignedInteger(q,&temps.action9_vd);
   self->cursor=q+4;break;}
  case 10:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action10_va);
   self->cursor=q+4;break;}
  case 11:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action11_va);
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action11_vb);
   self->cursor=q+4;break;}
  case 12:{
   unsigned char* q=p+5;
   q=RuntimeUnwind_ReadCompactUnsignedInteger(q,&temps.action12_va);
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action12_vb);
   self->cursor=q;break;}
  case 13:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action13_va);
   self->cursor=q;break;}
  case 15:{
   unsigned char* q=p+1;
   q=RuntimeUnwind_ReadCompactUnsignedInteger(q,&temps.action15_va);
   q=RuntimeUnwind_ReadCompactUnsignedInteger(q,&temps.action15_vb);
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action15_vc);
   self->cursor=q+(temps.action15_va<<2);break;}
  case 16:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action16_va);
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action16_vb);
   temps.action16_vc=(unsigned)q[0]|((unsigned)q[1]<<8)|((unsigned)q[2]<<16)|((unsigned)q[3]<<24);q+=4;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action16_vd);
   self->cursor=q+4;break;}
  case 17:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action17_va);
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action17_vb);
   q++;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action17_vc);
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action17_vd);
   self->cursor=q+4;break;}
  case 18:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action18_va);
   q++;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action18_vb);
   q=RuntimeUnwind_ReadCompactUnsignedInteger(q,&temps.action18_vc);
   self->cursor=q+4;break;}
  case 19:{
   unsigned char* q=p+1;
   q=Runtime_DecodeCompactSignedInteger(q,&temps.action19_va);
   self->cursor=q;break;}
  default:return 255;
  }
  break;
 }
 }
 unsigned char* q=self->cursor;
 unsigned code=*q&31;
 if(code!=1)return code;
 do{
  Runtime_DecodeCompactSignedInteger(q+1,&temps.jump);
  self->cursor+=temps.jump;
  q=self->cursor;code=*q&31;
 }while(code==1);
 return code;
}
