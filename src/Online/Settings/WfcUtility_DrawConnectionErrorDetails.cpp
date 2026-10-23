#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
struct EntryTable { int *values; int base; };
struct Canvas {unsigned words[6];void* self;void* settings;unsigned a,b;void* pixels;void* task;};
extern "C" {
extern int WfcUtilitySetConnectionErrorCode_UnknownRoleZeroInitializedStorage;
extern EntryTable* WfcUtilityCreateSlidingDialog_UnknownRoleZeroInitializedStorage;
extern unsigned char WfcUtilityDrawConnectionErrorDetails_UnknownRoleInitializedBytes[];
extern const unsigned short WfcUtilityDrawConnectionErrorDetails_UnknownRoleInitializedBytes_Variant2[][2];
extern const unsigned short WfcUtilityDrawConnectionErrorDetails_UnknownRoleInitializedBytes_Variant3[][2];
extern const char WfcUtilityDrawConnectionErrorDetails_UnknownRoleInitializedBytes_Variant4[];
void WfcUtility_GetScreenOperationArguments(unsigned*,unsigned*);
unsigned WfcUtility_GetLanguage();
Canvas* Graphics_CreateBG0CanvasForScreen(int,int);
int WfcUtility_GetMessageText(EntryTable*,int);
void Text_FormatBoundedVariadicString(void*,unsigned,unsigned,...);
unsigned Util_CopyBytesToHalfwordsAndTerminate(unsigned short*,const unsigned char*,int);
void Graphics_DrawFixedWidthCenteredText(void*,int,int,int,int,const unsigned short*,unsigned);
unsigned WfcUtility_GetLanguageMessageLayoutParameter();
void WfcUtility_RenderCanvasAlignedText(unsigned char*,int,int,unsigned,int,unsigned,unsigned,unsigned);
void WfcUtility_MarkBackgroundTextCanvasDirty(void*);
}
// Original: arm9/ov031 @ 0x0222E484; symbol: func_ov031_0222e484; size: 0x374.
// Selects connection-error help by signed error range and draws its numeric code and localized details.
extern "C" void WfcUtility_DrawConnectionErrorDetails() {
 unsigned mode;int x,y;
 WfcUtility_GetScreenOperationArguments(0,&mode);
 int code=WfcUtilitySetConnectionErrorCode_UnknownRoleZeroInitializedStorage;
 int message;
 if(code>=-20099)message=0;
 else if(code>=-20100)message=2;
 else if(code>=-20101)message=19;
 else if(code>=-20107)message=2;
 else if(code>=-20108)message=18;
 else if(code>=-20109)message=2;
 else if(code>=-20110)message=3;
 else if(code>=-20999)message=2;
 else if(code>=-22999)message=0;
 else if(code>=-23999)message=19;
 else if(code>=-49999)message=0;
 else if(code>=-50002)message=7;
 else if(code>=-50003)message=5;
 else if(code>=-50098)message=0;
 else if(code>=-50099)message=mode==2?5:7;
 else if(code>=-51098)message=0;
 else if(code>=-51099)message=mode==2?5:8;
 else if(code>=-51102)message=9;
 else if(code>=-51103)message=5;
 else if(code>=-51199)message=0;
 else if(code>=-51299)message=20;
 else if(code>=-51302)message=21;
 else if(code>=-51303)message=4;
 else if(code>=-51999)message=0;
 else if(code>=-52002)message=10;
 else if(code>=-52003)message=22;
 else if(code>=-52099)message=0;
 else if(code>=-52103)message=11;
 else if(code>=-52199)message=0;
 else if(code>=-52203)message=11;
 else if(code>=-52299)message=0;
 else if(code>=-52399)message=2;
 else if(code>=-52999)message=0;
 else if(code>=-53299)message=2;
 else message=0;
 Canvas* canvas=Graphics_CreateBG0CanvasForScreen(0,WfcUtilityDrawConnectionErrorDetails_UnknownRoleInitializedBytes[WfcUtility_GetLanguage()]);
 int text=WfcUtility_GetMessageText(WfcUtilityCreateSlidingDialog_UnknownRoleZeroInitializedStorage,message);
 unsigned char ascii[8];unsigned short digits[8];
 Text_FormatBoundedVariadicString(ascii,8,(unsigned)WfcUtilityDrawConnectionErrorDetails_UnknownRoleInitializedBytes_Variant4,0u-(unsigned)WfcUtilitySetConnectionErrorCode_UnknownRoleZeroInitializedStorage);
 Util_CopyBytesToHalfwordsAndTerminate(digits,ascii,8);
 y=WfcUtilityDrawConnectionErrorDetails_UnknownRoleInitializedBytes_Variant3[WfcUtility_GetLanguage()][0];
 x=WfcUtilityDrawConnectionErrorDetails_UnknownRoleInitializedBytes_Variant2[WfcUtility_GetLanguage()][0];
 Graphics_DrawFixedWidthCenteredText(canvas,x,y,2,10,digits,0);
 if(message)WfcUtility_RenderCanvasAlignedText((unsigned char*)canvas,13,60,230,94,2,WfcUtility_GetLanguageMessageLayoutParameter(),text);
 WfcUtility_MarkBackgroundTextCanvasDirty(canvas);
}
