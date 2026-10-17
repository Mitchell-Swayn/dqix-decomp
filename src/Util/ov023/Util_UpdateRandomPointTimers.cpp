#include <globaldefs.h>
ARM
extern "C" int rand();
extern "C" int abs(int);
extern "C" unsigned long long _Z19GetCurrentTimestampv();
struct Point {short timer,duration,x,y;};
struct State {Point points[3];unsigned long long timestamp;short frame,cooldown;unsigned char active;};
// Original: arm9/ov023 @ 0x021DB110; symbol: func_ov023_021db110; size: 0x1A8.
extern "C" void Util_UpdateRandomPointTimers(State* p){
if(!p->active)return;
unsigned long long now=(_Z19GetCurrentTimestampv()<<6)/0x82ea;
if(now-p->timestamp>30)p->timestamp=now;else return;
for(int i=0;i<3;i++){p->points[i].timer--;if(p->points[i].timer<=0)p->points[i].timer=0;}
p->cooldown--;if(p->cooldown<=0){
p->cooldown=0;
for(int i=0;i<3;i++){
Point* point=&p->points[i];
if(point->timer<=0 && rand()%5==0){
point->timer=point->duration;
point->x=rand()%50;
point->y=rand()%15;
for(int j=0;j<3;j++){
if(i==j)continue;
if(p->points[j].timer<=0)continue;
if(abs(point->x-p->points[j].x)<=12 && abs(point->y-p->points[j].y)<=12){point->timer=0;break;}
}
p->cooldown=2;break;
}
}
}
p->frame++;if(p->frame>=40)p->frame=0;
}
