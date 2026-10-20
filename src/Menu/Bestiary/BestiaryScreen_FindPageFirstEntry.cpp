extern "C" { struct Node { Node* next; }; struct Owner { unsigned char pre[0xb8]; Node* head; Node* selected; };
// Original: arm9/ov014 @ 0x02187340; symbol: func_ov014_02187340; size: 0x60.
 Node* BestiaryScreen_FindPageFirstEntry(Owner* p,int page) { Node* n=p->head;int count=0;Node* result=n;short current=0;while(n) {if(count==0){result=n;if(current==page)break;++current;}count=(short)(count+1)%16;n=n->next;}return result; } }
