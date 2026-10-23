// Original: arm9/ov023 @ 0x021D8F2C; symbol: PartyGrowthPanel_AdvanceExperienceReveal; size: 0x1A4.
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
ARM
struct State;struct Owner;
extern "C" {
void Window_PopCanvasesAndResetSelection(State*,int);
void PartyGrowthPanel_AppendExperienceAwardRows(void*,char*,int);
void PartyGrowthPanel_OpenCenteredWindow(void*,void*,int,int);
int Window_ReplaceCanvasTextById(Owner*,unsigned,void*,unsigned,unsigned char);
}
extern "C" void PartyGrowthPanel_AdvanceExperienceReveal(unsigned char* self){
unsigned ticks=GameState::GetInstance()->GetTickCount();if(!ticks)ticks=1;
if((unsigned char)self[0x11c]==0){Window_PopCanvasesAndResetSelection((State*)(self+0x20),1);++self[0x11c];}
else if((unsigned char)self[0x11c]==1){self[0x118]=1;self[0x11d]=5;self[0x119]=0;for(int i=0;i<4;++i)if(*(void**)(self+0xdc+i*4))++self[0x119];int height=12;switch((unsigned char)self[0x119]){case 1:height=5;break;case 2:height=7;break;case 3:height=10;break;case 4:height=12;break;case 0:self[0x118]=4;height=5;break;}
memset(*(void**)(self+4),0,0x960);PartyGrowthPanel_AppendExperienceAwardRows(self,*(char**)(self+4),(unsigned char)self[0x118]);PartyGrowthPanel_OpenCenteredWindow(self,*(void**)(self+4),24,height);++self[0x11c];}
else if((unsigned char)self[0x11c]==2){signed char countdown=self[0x11d];if(countdown>0){self[0x11d]=countdown-(signed char)ticks;return;}self[0x11d]=5;++self[0x118];memset(*(void**)(self+4),0,0x960);PartyGrowthPanel_AppendExperienceAwardRows(self,*(char**)(self+4),(unsigned char)self[0x118]);Window_ReplaceCanvasTextById((Owner*)(self+0x20),0,*(void**)(self+4),1,0);if((unsigned char)self[0x118]==4)++self[0x11c];}
}
