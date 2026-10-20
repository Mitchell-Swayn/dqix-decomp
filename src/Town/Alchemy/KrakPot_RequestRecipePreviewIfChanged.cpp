#include <globaldefs.h>
ARM
extern "C" void CancelTwoBackgroundTasksAndResetObject(unsigned char*);
extern "C" void SetPendingZoneSelectionAndCancelTasks(unsigned char*,short*,char*,int);
// Original: arm9/ov006 @ 0x021555B0; symbol: UpdateBackgroundRecordUnlessAlreadyQueued; size: 0x80.
// Resets missing/unflagged background records, skipping already queued identifiers.
extern "C" void KrakPot_RequestRecipePreviewIfChanged(unsigned char* self,short* entry,char* record,int extra){
 if(!entry||!record){if(*(char**)(self+0x1c0)==record)return;CancelTwoBackgroundTasksAndResetObject(self);return;}
 struct Bits{unsigned short a:1;unsigned short flag:1;unsigned short rest:14;};if(record&& !((Bits*)(record+2))->flag){CancelTwoBackgroundTasksAndResetObject(self);return;}
 short* current=*(short**)(self+0x1b4);if(current&&*current==*entry)return;
 current=*(short**)(self+0x1b8);if(current&&*current==*entry)return;
 SetPendingZoneSelectionAndCancelTasks(self,entry,record,extra);
}
