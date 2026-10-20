struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#pragma always_inline on
#define W(p,o) (*(unsigned*)((p)+(o)))
#define P(p,o) (*(char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
extern "C" {void* _ZN9GameState11GetInstanceEv();char* TextContext_GetSharedInstance();char* GameState_GetIndexList(void*);void Window_SetCanvasDisplayAttribute(void*,int,int);void* memset(void*,int,unsigned);const char* ResourceStringTable_GetTextByKey(void*,int);int Text_AppendFormatString(char*,const char*);void Bank_AppendBalanceOrEmptyAccountMessage(void*,const char*);void TextWindow_StartFormattedMessage(void*,const char*,int,int);void TextLayout_ResetFormattingWorkspace(void*);void TextContext_SetNumericArgument(void*,int,unsigned);void TextContext_SetNumericArgumentWidth(void*,int,int);void Bank_OpenTransferAmountWindow(void*);int Bank_PollTransferAmountEntry(void*,int);void Window_PopTextCanvases(void*,unsigned);WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);int Bank_AdjustHeldGoldWithLimit(void*,int);void TextMarkup_ExpandAndWrapText(void*,int,const char*,char*,int,int,unsigned);}
static inline void ShowMessage(unsigned char* self,char* global,short key){memset(P(self,0x7c),0,2400);Text_AppendFormatString(P(self,0x7c),ResourceStringTable_GetTextByKey(self+0x64,key));Bank_AppendBalanceOrEmptyAccountMessage(self,P(self,0x7c));TextWindow_StartFormattedMessage(global,P(self,0x7c),0,227);}
static inline void SetDigits(unsigned char* self,unsigned value){int i;unsigned divisor=1;for(i=3;i>=0;--i){unsigned digit=value/divisor-(value/(divisor*10))*10;(self+i)[0x4f3]=digit;divisor*=10;}W(self,0x4f8)=value*1000;}
// Original: arm9/ov003 @ 0x02168D3C; symbol: GameState_AdvanceThousandUnitTransferDialog; size: 0x6f4.
// Drives bounded thousand-unit transfers and their numeric entry/message state.
extern "C" void Bank_AdvanceDepositOrWithdrawal(unsigned char* self,int input,int message){
 void* state=_ZN9GameState11GetInstanceEv();char* global=TextContext_GetSharedInstance();char* list=GameState_GetIndexList(state);if(W(global,0x9a0)==3)global[0x19ae]=0;
 if(self[0x4e8]==0){
  Window_SetCanvasDisplayAttribute(self+0xe4,1,1);
  if(message==1010){short error=-1;if(W(list,0xf68)>=0x3b9ac618)error=(short)(message+5);else if(W(list,0xf6c)<1000)error=(short)(message+3);if(error>=0){ShowMessage(self,global,error);self[0x4e8]=3;return;}unsigned value=W(list,0xf6c)/1000;SetDigits(self,value);}
  else if(message==1020){short error=-1;if(W(list,0xf68)==0)error=(short)(message+3);else if(W(list,0xf6c)>=0x989298)error=(short)(message+4);if(error>=0){ShowMessage(self,global,error);self[0x4e8]=3;return;}TextLayout_ResetFormattingWorkspace(global);TextContext_SetNumericArgument(global,0,W(list,0xf68));TextContext_SetNumericArgumentWidth(global,0,0);unsigned value=W(list,0xf68)/1000;unsigned available=9999-W(list,0xf6c)/1000;if(available<value)value=available;SetDigits(self,value);}
  TextWindow_StartFormattedMessage(global,ResourceStringTable_GetTextByKey(self+0x64,(short)message),0,227);++self[0x4e8];
 }else if(self[0x4e8]==1){
  if(W(global,0x9a0)!=3)return;Bank_OpenTransferAmountWindow(self);Window_SetCanvasDisplayAttribute(self+0xe4,0,0);Window_SetCanvasDisplayAttribute(self+0xe4,2,0);++self[0x4e8];
 }else if(self[0x4e8]==2){
  int status=Bank_PollTransferAmountEntry(self,input);if(status==-1)return;
  if(status==-2){Window_PopTextCanvases(self+0xe4,1);Window_SetCanvasDisplayAttribute(self+0xe4,1,1);ShowMessage(self,global,1030);++self[0x4e8];return;}
  if(status!=0)return;Window_PopTextCanvases(self+0xe4,1);H((char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self+0xe4),1),0xc2)=1;int succeeded=0;int exceeded=0;short key=(short)message;
  if(key==1010){unsigned amount=W(self,0x5a0);if(W(list,0xf68)+amount>0x3b9ac618){key=(short)(key+4);exceeded=1;}else if(Bank_AdjustHeldGoldWithLimit(self,-(int)amount)){W(list,0xf68)+=W(self,0x5a0);succeeded=1;}}
  else if(key==1020){unsigned amount=W(self,0x5a0);unsigned held=W(list,0xf68);if(amount<=held){if(W(list,0xf6c)+amount>0x98967f){key=(short)(key+4);exceeded=1;}else{W(list,0xf68)=held-amount;Bank_AdjustHeldGoldWithLimit(self,W(self,0x5a0));succeeded=1;}}}
  if(succeeded){self[0x4eb]=1;memset(P(self,0x7c),0,2400);TextLayout_ResetFormattingWorkspace(global);TextContext_SetNumericArgument(global,0,W(self,0x5a0));TextContext_SetNumericArgumentWidth(global,0,0);const char* text=ResourceStringTable_GetTextByKey(self+0x64,(short)(key+1));TextMarkup_ExpandAndWrapText(global,12,text,P(self,0x7c),227,0,1);Bank_AppendBalanceOrEmptyAccountMessage(self,P(self,0x7c));TextWindow_StartFormattedMessage(global,P(self,0x7c),0,227);++self[0x4e8];}
  else if(exceeded){TextLayout_ResetFormattingWorkspace(global);TextContext_SetNumericArgument(global,0,0x3b9ac618-W(list,0xf68));TextContext_SetNumericArgumentWidth(global,0,0);const char* text=ResourceStringTable_GetTextByKey(self+0x64,key);TextMarkup_ExpandAndWrapText(global,12,text,P(self,0x7c),227,0,1);Bank_AppendBalanceOrEmptyAccountMessage(self,P(self,0x7c));TextWindow_StartFormattedMessage(global,P(self,0x7c),0,227);++self[0x4e8];}
  else{memset(P(self,0x7c),0,2400);Text_AppendFormatString(P(self,0x7c),ResourceStringTable_GetTextByKey(self+0x64,(short)(key+2)));Text_AppendFormatString(P(self,0x7c),ResourceStringTable_GetTextByKey(self+0x64,key));TextWindow_StartFormattedMessage(global,P(self,0x7c),0,227);for(int i=0;i<4;++i)(self+i)[0x4ef]=0;W(self,0x5a0)=0;self[0x4e8]=1;}
 }else if(self[0x4e8]==3){if(W(global,0x998)==0){self[0x4ec]=6;self[0x4e8]=0;}}
}
