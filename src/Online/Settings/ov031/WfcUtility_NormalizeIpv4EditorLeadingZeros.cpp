#include <globaldefs.h>
ARM
extern "C" unsigned char* WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_DrawIpv4EditorDigits();
// Original: arm9/ov031 @ 0x0222E1AC; symbol: WfcUtility_NormalizeIpv4EditorLeadingZeros; size: 0x78.
// Normalizes each three-byte group's leading zero/space/NUL cells to spaces and a final ASCII zero, then draws all twelve cells.
extern "C" void WfcUtility_NormalizeIpv4EditorLeadingZeros(){
 unsigned char* row;int group=0,cell,offset=0;
 do{
  row=WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage+8+offset;
  cell=0;
  do{unsigned char value=row[cell];if(value!='0'&&value!=' '&&value!=0)break;
   row[cell]=cell==2?'0':' ';++cell;
  }while(cell<3);
  ++group;offset+=3;
 }while(group<4);
 WfcUtility_DrawIpv4EditorDigits();
}
