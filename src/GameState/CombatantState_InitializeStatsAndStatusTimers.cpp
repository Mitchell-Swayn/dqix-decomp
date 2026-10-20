#include <globaldefs.h>
#include <std_library_functions.h>
struct WordFlags{unsigned a:10,b:10,c:10,d:2;};struct ByteFlags{unsigned char a:1,b:1,c:1,d:1,e:1,f:1,g:2;};
struct FlagsA{unsigned char a:1,b:1,c:1,d:1,tail:4;};
// Original: arm9/main @ 0x020891CC; symbol: func_020891cc; size: 0x1A0.
extern "C" ARM void CombatantState_InitializeStatsAndStatusTimers(unsigned short*p){p[0]=0;p[1]=0;p[2]=0;p[3]=0;p[6]=0;p[4]=0;p[5]=0;WordFlags*f=(WordFlags*)(p+8);f->a=0;f->b=0;f->c=0;memset(p+31,100,22);unsigned*w=(unsigned*)(p+10);w[0]=0;w[1]=0;w[2]=0;unsigned char*b=(unsigned char*)p;b[32]=0;b[33]=0;p[17]&=~3u;p[17]&=~0xe00u;p[17]&=~0x3cu;p[17]&=~0x1c0u;p[17]&=~0x3000u;b[36]=0;p[17]&=~0x4000u;b[37]=0;b[38]=0;((short*)p)[20]=-1;((short*)p)[21]=-1;((short*)p)[22]=-1;((short*)p)[23]=-1;p[24]=0;((short*)p)[25]=-1;((short*)p)[26]=-1;p[27]=0;b[56]=0;b[57]=0;b[58]=0;FlagsA*first=(FlagsA*)(b+59);first->a=0;first->b=0;first->c=0;first->d=0;first->tail=0;ByteFlags*s=(ByteFlags*)(b+60);s->a=0;s->b=0;s->c=0;s->d=0;s->e=0;s->f=0;b[61]=0;memset(b+88,0,4);memset(b+92,0,35);memset(b+127,0,35);}
