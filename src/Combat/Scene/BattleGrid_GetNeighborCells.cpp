#include <globaldefs.h>

// Original: arm9/ov000 @ 0x0216F82C; symbol: func_ov000_0216f82c; size: 0x4D0.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM void BattleGrid_GetNeighborCells(unsigned char* out,int* cell) {
 int column=*cell%9; int row=*cell/9; unsigned char neighbors[6];
 if(row%2==0) {
  if(column==0) {
   if(row==0) {neighbors[0]=255; neighbors[1]=column+(row+1)*9; neighbors[2]=255; neighbors[3]=column+1+row*9; neighbors[4]=255; neighbors[5]=255;}
   else if(row==8) {neighbors[0]=255; neighbors[1]=255; neighbors[2]=255; neighbors[3]=column+1+row*9; neighbors[4]=255; neighbors[5]=column+(row-1)*9;}
   else {neighbors[0]=255; neighbors[1]=column+(row+1)*9; neighbors[2]=255; neighbors[3]=column+1+row*9; neighbors[4]=255; neighbors[5]=column+(row-1)*9;}
  } else if(column==8) {
   if(row==0) {neighbors[0]=column-1+(row+1)*9; neighbors[1]=255; neighbors[2]=column-1+row*9; neighbors[3]=255; neighbors[4]=255; neighbors[5]=255;}
   else if(row==8) {neighbors[0]=255; neighbors[1]=255; neighbors[2]=column-1+row*9; neighbors[3]=255; neighbors[4]=column-1+(row-1)*9; neighbors[5]=255;}
   else {neighbors[0]=column-1+(row+1)*9; neighbors[1]=255; neighbors[2]=column-1+row*9; neighbors[3]=255; neighbors[4]=column-1+(row-1)*9; neighbors[5]=255;}
  } else {
   if(row==0) {neighbors[0]=column-1+(row+1)*9; neighbors[1]=column+(row+1)*9; neighbors[2]=column-1+row*9; neighbors[3]=column+1+row*9; neighbors[4]=255; neighbors[5]=255;}
   else if(row==8) {neighbors[0]=255; neighbors[1]=255; neighbors[2]=column-1+row*9; neighbors[3]=column+1+row*9; neighbors[4]=column-1+(row-1)*9; neighbors[5]=column+(row-1)*9;}
   else {neighbors[0]=column-1+(row+1)*9; neighbors[1]=column+(row+1)*9; neighbors[2]=column-1+row*9; neighbors[3]=column+1+row*9; neighbors[4]=column-1+(row-1)*9; neighbors[5]=column+(row-1)*9;}
  }
 } else {
  if(column==0) {
   if(row==8) {neighbors[0]=255; neighbors[1]=255; neighbors[2]=255; neighbors[3]=column+1+row*9; neighbors[4]=column+(row-1)*9; neighbors[5]=column+1+(row-1)*9;}
   else {neighbors[0]=column+(row+1)*9; neighbors[1]=column+1+(row+1)*9; neighbors[2]=255; neighbors[3]=column+1+row*9; neighbors[4]=column+(row-1)*9; neighbors[5]=column+1+(row-1)*9;}
  } else if(column==7) {
   if(row==8) {neighbors[0]=255; neighbors[1]=255; neighbors[2]=column-1+row*9; neighbors[3]=255; neighbors[4]=column+(row-1)*9; neighbors[5]=column+1+(row-1)*9;}
   else {neighbors[0]=column+(row+1)*9; neighbors[1]=column+1+(row+1)*9; neighbors[2]=column-1+row*9; neighbors[3]=255; neighbors[4]=column+(row-1)*9; neighbors[5]=column+1+(row-1)*9;}
  } else if(column<7) {
   if(row==8) {neighbors[0]=255; neighbors[1]=255; neighbors[2]=column-1+row*9; neighbors[3]=column+1+row*9; neighbors[4]=column+(row-1)*9; neighbors[5]=column+1+(row-1)*9;}
   else {neighbors[0]=column+(row+1)*9; neighbors[1]=column+1+(row+1)*9; neighbors[2]=column-1+row*9; neighbors[3]=column+1+row*9; neighbors[4]=column+(row-1)*9; neighbors[5]=column+1+(row-1)*9;}
  } else {neighbors[0]=255; neighbors[1]=255; neighbors[2]=255; neighbors[3]=255; neighbors[4]=255; neighbors[5]=255;}
 }
 unsigned char* source=neighbors; int count=6; do {*out++=*source++;} while(--count);
}
