#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int data_021015a0[];
extern "C" char data_021023c0[],data_02102be0[];
extern "C" void SetGlobalValueExceptModesNineAndTen(unsigned);
extern "C" int StartCallbackOperationAndClassifyResult();
extern "C" int TransitionGlobalStateTwoToThree();
extern "C" int StartCallbackInGlobalStateThree();
extern "C" void Network_RestartOperationAndTrackFailure();
extern "C" int ClearActiveHalfwordsAndCancelStoredId(int);
extern "C" int ForwardRecordQuery(void*);
// Original: arm9/main @ 0x0202DD98; symbol: func_0202dd98; size: 0x178.
extern "C" void Network_RestartCallbackForCurrentOperation() {
 int state=data_021015a0[4];
 if(state==1)return;
 if(state==2) {
  if(!TransitionGlobalStateTwoToThree())Network_RestartOperationAndTrackFailure();
  return;
 }
 if(state!=6 && state!=5 && state!=4) {
  data_021015a0[4]=3;
  Network_RestartOperationAndTrackFailure();return;
 }
 data_021015a0[4]=3;
 switch(data_021015a0[13]) {
 case 3: {
  int result;
  if(data_021015a0[4]!=6)result=0;
  else {
   data_021015a0[4]=3;
   if((result=ForwardRecordQuery(data_021023c0))!=0) { SetGlobalValueExceptModesNineAndTen(result);result=0; }
   else { if(!StartCallbackInGlobalStateThree())result=0;else result=1; }
  }
  if(!result)Network_RestartOperationAndTrackFailure();
  break;
 }
 case 5:
  if(ClearActiveHalfwordsAndCancelStoredId((int)data_02102be0)){Network_RestartOperationAndTrackFailure();break;}
 case 1:
  if(!StartCallbackInGlobalStateThree())Network_RestartOperationAndTrackFailure();
  break;
 case 2: {
  int result;
  if((result=ForwardRecordQuery(data_021023c0))!=0) {SetGlobalValueExceptModesNineAndTen(result);result=0;}
  else if(StartCallbackOperationAndClassifyResult())result=1;
  else {Network_RestartOperationAndTrackFailure();result=0;}
  if(!result)Network_RestartOperationAndTrackFailure();
  break;
 }
 case 4:
  if(ClearActiveHalfwordsAndCancelStoredId((int)data_02102be0)){Network_RestartOperationAndTrackFailure();break;}
 case 0:
  if(!StartCallbackOperationAndClassifyResult())Network_RestartOperationAndTrackFailure();
  break;
 }
}
