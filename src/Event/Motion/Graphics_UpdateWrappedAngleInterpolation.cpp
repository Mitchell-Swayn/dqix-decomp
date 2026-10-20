#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" int fix32_Divide(int,int);
static inline int Mul(int a,int b){return (int)(((long long)a*b+0x800)>>12);}
#define F(p,o) (*(int*)((p)+(o)))
// Original: arm9/ov001 @ 0x021594CC; symbol: func_ov001_021594cc; size: 0x338.
extern "C" int Graphics_UpdateWrappedAngleInterpolation(char* a,char* b){
void* game=_ZN9GameState11GetInstanceEv();int step=_ZNK9GameState12GetTickCountEv(game)<<12;
if(F(a,16)<0){
F(b,128)+=F(a,4);
F(b,132)+=F(a,8);
F(b,136)+=F(a,12);
if(F(b,128)>0x6487) F(b,128)-=0x6487;else if(F(b,128)<=0)F(b,128)+=0x6487;
if(F(b,132)>0x6487) F(b,132)-=0x6487;else if(F(b,132)<=0)F(b,132)+=0x6487;
if(F(b,136)>0x6487) F(b,136)-=0x6487;else if(F(b,136)<=0)F(b,136)+=0x6487;
}else {
if(F(b,76)>=F(a,16)*2){memcpy(b+128,a+4,12);F(b,76)=0;return 0;}
if(F(b,76)<=0){int duration=F(a,16)<<13;
{int diff;if(F(a,20))diff=F(b,128)-F(a,4);else diff=F(a,4)-F(b,128);if(diff>0x6487)diff-=0x6487;else if(diff<0)diff+=0x6487;F(b,160)=fix32_Divide(diff,duration);}
{int diff;if(F(a,20))diff=F(b,132)-F(a,8);else diff=F(a,8)-F(b,132);if(diff>0x6487)diff-=0x6487;else if(diff<0)diff+=0x6487;F(b,164)=fix32_Divide(diff,duration);}
{int diff;if(F(a,20))diff=F(b,136)-F(a,12);else diff=F(a,12)-F(b,136);if(diff>0x6487)diff-=0x6487;else if(diff<0)diff+=0x6487;F(b,168)=fix32_Divide(diff,duration);}
if(F(a,20)){F(b,160)=-F(b,160);F(b,164)=-F(b,164);F(b,168)=-F(b,168);}
}else{
{int value=F(b,128)+Mul(F(b,160),step);F(b,128)=value;if(value>0x6487)F(b,128)-=0x6487;else if(value<=0)F(b,128)+=0x6487;}
{int value=F(b,132)+Mul(F(b,164),step);F(b,132)=value;if(value>0x6487)F(b,132)-=0x6487;else if(value<=0)F(b,132)+=0x6487;}
{int value=F(b,136)+Mul(F(b,168),step);F(b,136)=value;if(value>0x6487)F(b,136)-=0x6487;else if(value<=0)F(b,136)+=0x6487;}
}
F(b,76)+=_ZNK9GameState12GetTickCountEv(game);
}
return 1;
}
