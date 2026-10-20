#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
#pragma optimization_level 4
#pragma always_inline on
// Both compact and extended nodes contain an opcode and variant-dependent payload.
// Compact nodes are 16 bytes with a link at offset 12. Extended nodes are 28
// bytes with a link at offset 20 and a cleared auxiliary pointer at offset 24.
struct CompactNode {
 union { short h[6]; unsigned short u[6]; unsigned char b[12]; int w[3]; };
 CompactNode *next;
};
struct ExtendedNode {
 union { short h[10]; unsigned short u[10]; unsigned char b[20]; int w[5]; };
 ExtendedNode *next;
 void *auxiliary;
};
// Original: arm9/main @ 0x0205EC70; symbol: func_0205ec70; size: 0xD4C.
// Decodes packed script parameters into compact and extended linked records.
// Allocation failure preserves the already appended records. Lists must initially
// be empty: their tail cursors are local to this decoding pass.
// Opcode is signed high16; the remaining word bits carry variant-specific data.
static inline void DecodeRecordParameters(SafeAllocator *allocator, int count, Script::Parameter *params, CompactNode **compactHead, ExtendedNode **extendedHead)
{
 int opcode;
 int encoded;
 ExtendedNode *extendedTail;
 int consumed;
 CompactNode *compactTail;
 compactTail=0;
 consumed=0;
 extendedTail=0;
 for (;consumed<count;consumed++) {
  encoded=params->ToInt(); params++; opcode=encoded>>16;
  if(opcode<100 || opcode>=500) {
   CompactNode *n=(CompactNode*)allocator->Allocate(16); if(!n)return;
   if(!*compactHead)*compactHead=n;else compactTail->next=n;
switch(opcode) {
case 29: {
n->u[0]=opcode; n->h[2]=encoded;
n->h[3]=params[0].ToInt();
Script::Parameter *last=params+1; params+=2;

float angle = (3.1415927410125732421875f * last->ToInt()) / 180.0f;
if (angle > 6.283185482025146484375f) angle -= 6.283185482025146484375f;
else if (angle < 0.0f) angle += 6.283185482025146484375f;
n->h[1]=(int)(4096.0f * angle); consumed+=2;
 break; }
case 32: case 33: {
Script::Parameter *last=params+0; params+=1;

unsigned int color=last->ToInt(); n->u[0]=opcode;
n->b[4]=color>>24; n->b[5]=color>>16; n->b[6]=color>>8; n->b[7]=color;
consumed++;
 break; }
case 44: case 47: case 48: case 49: case 70: case 73: case 75: case 76: case 83: case 90: case 500: {
n->u[0]=opcode; n->h[1]=encoded;
Script::Parameter *last=params+0; params+=1;
 n->h[2]=last->ToInt(); consumed++;
 break; }
case 85: {
n->u[0]=opcode; n->h[1]=encoded;
Script::Parameter *last=params+0; params+=1;
 n->w[1]=last->ToInt(); consumed++;
 break; }
case 46: {
n->u[0]=opcode; n->h[1]=encoded;
Script::Parameter *last=params+0; params+=1;
 int pair=last->ToInt(); n->h[2]=pair>>16; n->h[3]=pair; consumed++;
 break; }
case 66: {
n->u[0]=opcode; n->h[1]=encoded;
Script::Parameter *last=params+0; params+=1;
 int pair=last->ToInt(); n->h[2]=pair>>16; n->h[3]=pair; consumed++;
 break; }
case 50: case 82: {
// These commands span two compact records with the same 16-bit opcode.
opcode=(unsigned short)opcode; int key=opcode; int a=params[0].ToInt(); int b=params[1].ToInt(); int c=params[2].ToInt();
Script::Parameter *last=params+3; params+=4;
 int d=last->ToInt();
n->u[0]=key; n->h[1]=1; n->h[2]=encoded; n->h[3]=a>>16; n->h[4]=a; n->h[5]=b>>16; consumed+=4;
CompactNode *second=(CompactNode*)allocator->Allocate(16);
second->u[0]=key; second->h[1]=2; second->h[2]=b; second->h[3]=c>>16; second->h[4]=c; second->h[5]=d;
n->next=second; n=second;
 break; }
case 69: {
n->u[0]=opcode; n->h[1]=encoded; n->w[1]=(int)allocator->Allocate(11);
Script::Parameter *last=params+0; params+=1;
 memcpy((void*)n->w[1],last->ToString(),11); consumed++;
 break; }
case 52: case 55: case 62: case 63: {
n->u[0]=opcode; n->h[1]=encoded;
Script::Parameter *last=params+0; params+=1;
 int pair=last->ToInt(); n->h[2]=pair>>16; n->h[3]=pair; consumed++;
 break; }
case 53: case 54: case 56: case 57: case 58: case 59: case 60: case 61: {
n->u[0]=opcode; n->h[1]=encoded; int a=params[0].ToInt(); n->h[2]=a>>16; n->h[3]=a;
Script::Parameter *last=params+1; params+=2;

int b=last->ToInt(); n->h[4]=b>>16; n->h[5]=b; consumed+=2;
 break; }
case 64: case 65: {
n->u[0]=opcode; n->h[2]=encoded; int a=params[0].ToInt(); n->h[3]=a>>16; n->h[4]=a;
Script::Parameter *last=params+1; params+=2;

n->h[5]=last->ToInt()>>16; consumed+=2;
 break; }
case 74: {
n->u[0]=opcode;
Script::Parameter *last=params+0; params+=1;
 n->h[1]=last->ToInt(); consumed++;
 break; }
case 78: {
n->u[0]=opcode; n->h[1]=encoded; int a=params[0].ToInt(); n->h[2]=a>>16; n->h[3]=a;
Script::Parameter *last=params+1; params+=2;

n->h[4]=last->ToInt(); consumed+=2;
 break; }
case 79: {
n->u[0]=opcode; n->b[4]=encoded;
Script::Parameter *last=params+0; params+=1;
 n->h[1]=last->ToInt(); consumed++;
 break; }
case 91: {
n->u[0]=opcode; n->b[4]=encoded;
Script::Parameter *last=params+0; params+=1;
 n->h[1]=last->ToInt(); consumed++;
 break; }
default: n->u[0]=opcode; n->h[1]=encoded; break;
}
   n->next=0; compactTail=n;
  } else {
   ExtendedNode *n=(ExtendedNode*)allocator->Allocate(28); if(!n)return;
   if(!*extendedHead)*extendedHead=n;else extendedTail->next=n;
switch(opcode) {
case 116: case 117: case 118: case 130: case 131: case 133: case 134: case 135: case 138: case 144: case 149: case 150: case 155: case 158: case 159: case 176: case 177: case 179: case 180: case 226: case 230: case 232: {
n->u[0]=opcode; n->h[1]=encoded;
Script::Parameter *last=params+0; params+=1;
 n->h[2]=last->ToInt()>>16; consumed++;
 break; }
case 122: {
float a,c,b;
n->u[0]=opcode; n->h[1]=encoded; a=params[0].ToFloat(); b=params[1].ToFloat();
Script::Parameter *last=params+2; params+=3;
 c=last->ToFloat();
n->w[1]=(int)(a>0.0f ? 0.5f+4096.0f*a : 4096.0f*a-0.5f);
n->w[2]=(int)(b>0.0f ? 0.5f+4096.0f*b : 4096.0f*b-0.5f);
n->w[3]=(int)(c>0.0f ? 0.5f+4096.0f*c : 4096.0f*c-0.5f); consumed+=3;
 break; }
case 132: case 148: case 214: {
n->u[0]=opcode; n->h[1]=encoded; n->h[2]=params[0].ToInt(); n->h[3]=params[1].ToInt();
Script::Parameter *last=params+2; params+=3;
 n->h[4]=last->ToInt(); consumed+=3;
 break; }
case 123: {
n->u[0]=opcode; n->h[1]=encoded;
Script::Parameter *last=params+0; params+=1;
 float a=last->ToFloat();
short fixed;
if(a>0.0f) fixed=(int)(0.5f+4096.0f*a);
else fixed=(int)(4096.0f*a-0.5f);
n->h[2]=fixed; consumed++;
 break; }
case 108: case 109: case 136: case 152: case 153: case 154: {
n->u[0]=opcode; n->h[2]=encoded;
n->h[3]=params[0].ToInt();
Script::Parameter *last=params+1; params+=2;

float angle = (3.1415927410125732421875f * last->ToInt()) / 180.0f;
if (angle > 6.283185482025146484375f) angle -= 6.283185482025146484375f;
else if (angle < 0.0f) angle += 6.283185482025146484375f;
n->h[1]=(int)(4096.0f * angle); consumed+=2;
 break; }
case 139: case 140: {
n->u[0]=opcode;
Script::Parameter *last=params+0; params+=1;
 n->w[1]=last->ToInt(); consumed++;
 break; }
case 143: {
n->u[0]=opcode;
Vector3fix first, next;
first.x=(int)(4096.0f*params[0].ToFloat()); first.y=(int)(4096.0f*params[1].ToFloat()); first.z=(int)(4096.0f*params[2].ToFloat());
next.x=(int)(4096.0f*params[3].ToFloat()); next.y=(int)(4096.0f*params[4].ToFloat()); next.z=(int)(4096.0f*params[5].ToFloat());
Script::Parameter *last=params+6; params+=7;
 int g=last->ToInt();
n->h[1]=1; n->w[1]=(unsigned short)encoded; n->w[2]=first.x; n->w[3]=first.y; n->w[4]=first.z;
ExtendedNode *second=(ExtendedNode*)allocator->Allocate(28); second->u[0]=n->u[0]; consumed+=7;
second->h[1]=2; second->w[4]=g; second->w[1]=next.x; second->w[2]=next.y; second->w[3]=next.z;
n->next=second; n->auxiliary=0; n=second;
 break; }
case 156: case 157: {
n->u[0]=opcode; n->h[1]=encoded;
Script::Parameter *last=params+0; params+=1;
 int a=last->ToInt(); n->h[2]=a>>16; n->h[3]=a; consumed++;
 break; }
case 167: case 168: case 169: case 171: case 172: case 174: case 196: case 200: case 201: {
n->u[0]=opcode; n->b[2]=encoded;
Script::Parameter *last=params+0; params+=1;
 n->b[4]=last->ToInt()>>16; consumed++;
 break; }
case 178: {
n->u[0]=opcode; n->b[2]=encoded; int a=params[0].ToInt(); n->b[4]=a>>16; n->b[5]=a;
n->h[3]=params[1].ToInt();
Script::Parameter *last=params+2; params+=3;
 n->b[8]=last->ToInt()>>16; consumed+=3;
 break; }
case 188: {
n->u[0]=opcode; n->h[1]=encoded; int a=params[0].ToInt(); n->h[2]=a>>16; n->h[3]=a;
Script::Parameter *last=params+1; params+=2;

n->h[4]=last->ToInt(); consumed+=2;
 break; }
case 189: {
n->u[0]=opcode; n->b[2]=(unsigned short)encoded!=0;
 break; }
case 190: {
n->u[0]=opcode; n->h[1]=encoded; int a=params[0].ToInt(); n->h[2]=a>>16; n->h[3]=a;
Script::Parameter *last=params+1; params+=2;

n->h[4]=last->ToInt(); consumed+=2;
 break; }
case 195: {
n->u[0]=opcode; n->b[2]=encoded;
Script::Parameter *last=params+0; params+=1;
 n->b[4]=last->ToInt()>>16; consumed++;
 break; }
case 207: {
n->u[0]=opcode; n->h[1]=encoded; int a=params[0].ToInt(); n->h[2]=a>>16; n->h[3]=a;
Script::Parameter *last=params+1; params+=2;

int b=last->ToInt(); n->h[4]=b>>16; n->h[5]=b; consumed+=2;
 break; }
case 213: {
n->u[0]=opcode; n->h[2]=encoded; int a=params[0].ToInt(); n->h[3]=a>>16; n->h[4]=a;
Script::Parameter *last=params+1; params+=2;

n->h[5]=last->ToInt(); consumed+=2;
 break; }
case 215: {
n->u[0]=opcode; n->h[1]=encoded; int a=params[0].ToInt(); n->h[2]=a>>16; n->h[3]=a;
Script::Parameter *last=params+1; params+=2;

int b=last->ToInt(); n->h[4]=b>>16; n->h[5]=b; consumed+=2;
 break; }
case 220: {
n->u[0]=opcode; n->h[1]=(encoded&0xff00)>>8; n->b[4]=encoded;
 break; }
default: n->u[0]=opcode; n->h[1]=encoded; break;
}
   n->next=0; n->auxiliary=0; extendedTail=n;
  }
 }
}

extern "C" void DecodePackedScriptParametersToLists(SafeAllocator *allocator, int count, Script::Parameter *params,
                             CompactNode **compactHead, ExtendedNode **extendedHead)
{
 DecodeRecordParameters(allocator,count,params,compactHead,extendedHead);
}
