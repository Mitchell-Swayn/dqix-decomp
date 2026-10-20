#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void Bank_UpdateDialogSelection(unsigned char*,unsigned),DisplayContext_ProcessPendingCommand(unsigned char*),Ov003_CancelPendingBackgroundTask(void*),Bank_AdvanceDialogResourceLoading(void*),AdvanceProtagonistTransferPrompt(void*),Bank_ApplyTransactionMenuChoice(void*),Bank_AdvanceDepositOrWithdrawal(unsigned char*,int,int),Bank_AdvanceFarewellMessage(void*),Bank_RefreshMenuAmountAndGoldText(void*);
// Original: arm9/ov003 @ 0x02168438; symbol: GameState_UpdateTransferDialogStateAndDispatchInput; size 0x128.
extern "C" int GameState_UpdateTransferDialogStateAndDispatchInput(char* self,unsigned input){W(self,0x4dc)=input;unsigned state=B(self,0x4ec);if(state!=0&&state!=3&&state!=4){unsigned flags=B(self,0x59f);if(!(flags&2)||(flags&4))Bank_UpdateDialogSelection((unsigned char*)self,input);}if(B(self,0x4ec)!=0)DisplayContext_ProcessPendingCommand((unsigned char*)self);unsigned flags=B(self,0x59f);if((flags&2)&&!(flags&4)){Ov003_CancelPendingBackgroundTask(self);return B(self,0x4ec)==6;}switch(B(self,0x4ec)){case 0:Bank_AdvanceDialogResourceLoading(self);break;case 1:AdvanceProtagonistTransferPrompt(self);break;case 2:Bank_ApplyTransactionMenuChoice(self);break;case 3:Bank_AdvanceDepositOrWithdrawal((unsigned char*)self,input,1010);break;case 4:Bank_AdvanceDepositOrWithdrawal((unsigned char*)self,input,1020);break;case 5:Bank_AdvanceFarewellMessage(self);break;case 6:return 1;}Bank_RefreshMenuAmountAndGoldText(self);return 0;}
