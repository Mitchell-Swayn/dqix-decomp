#include <globaldefs.h>
ARM
extern "C" unsigned char data_020f00a9[],data_020f00b0[],data_020f00b6[],data_020f00bc[],data_020f00c3[];
extern "C" int TestCaseFoldedStringPrefix(const char*,const void*);
extern "C" int Runtime_ParseStringAsBaseTenInteger(const char*);
extern "C" void SetRectangleCoordinatesAndDerivedCenter(void*,int,int,int,int);
// Original: arm9/main @ 0x020449A4; symbol: func_020449a4; size: 0x2D0.
extern "C" char* TextMarkup_ParseViewportSpacingAndDisplayTags(char* self,char* text) {
 bool active=true;
 while(active) {
 if(TestCaseFoldedStringPrefix(text,data_020f00a9)) {
 bool terminated=false;int end,index,x,y;end=6;index=end;
 while(text[index]!='>'){if(!text[index])return text+index;++index;}
 x=Runtime_ParseStringAsBaseTenInteger(text+6);
 while(text[end]!=','){if(text[end]=='>'){text+=end+1;terminated=true;break;}++end;}
 if(terminated)return text;
 ++end;y=Runtime_ParseStringAsBaseTenInteger(text+end);
 while(text[end]!=','){if(text[end]=='>'){text+=end+1;terminated=true;break;}++end;}
 if(terminated)return text;
 ++end;int width=Runtime_ParseStringAsBaseTenInteger(text+end);
 while(text[end]!=','){if(text[end]=='>'){text+=end+1;terminated=true;break;}++end;}
 if(terminated)return text;
 int height=Runtime_ParseStringAsBaseTenInteger(text+(end+1));
 if(x<0)x=0;if(x>256)x=256;if(y<0)y=0;if(y>192)y=192;
 if(width<0)width=256-x;if(width>256)width=256-x;
 if(height<0)height=192-y;if(height>192)height=192-y;
 SetRectangleCoordinatesAndDerivedCenter(self,x,y,width,height);text+=index+1;
 }else if(TestCaseFoldedStringPrefix(text,data_020f00b0)){self[0x19b1]=0;text+=5;}
 else if(TestCaseFoldedStringPrefix(text,data_020f00b6)){self[0x19b8]=1;text+=5;}
 else if(TestCaseFoldedStringPrefix(text,data_020f00bc)) {
 int end=6,index=end;while(text[index]!='>'){if(!text[index])return text+index;++index;}
 int horizontal=Runtime_ParseStringAsBaseTenInteger(text+6);if(horizontal<=0)horizontal=12;
 while(text[end]!=','){if(text[end]=='>'){text+=end+1;break;}++end;}
 int vertical=Runtime_ParseStringAsBaseTenInteger(text+(end+1));if(vertical<=0)vertical=16;
 *(int*)(self+0x1860)=horizontal;*(int*)(self+0x1864)=vertical;text+=index+1;
 }else if(TestCaseFoldedStringPrefix(text,data_020f00c3)){self[0x19bb]=0;text+=6;}
 else active=false;
 }
 return text;
}
