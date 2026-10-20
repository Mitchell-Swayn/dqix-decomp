extern "C" { void Window_UpdateCanvasesAndSelection(void*); void PartyTalk_AdvanceProfileResourceLoading(void*); void PartyTalk_AdvanceProfileDialogueAndRegistration(void*); void PartyTalk_AdvanceRecordsPanelEntry(void*); void RecordsScreen_UpdatePanelSession(void*); void PartyTalk_AdvanceRecordsPanelExit(void*); }
// Original: arm9/ov008 @ 0x0218936C; symbol: func_ov008_0218936c; size: 0x98.
extern "C" unsigned PartyTalk_UpdateProfileSession(signed char* object) {
    Window_UpdateCanvasesAndSelection(object+0x18);
    switch(object[0xe99]) { case 0:PartyTalk_AdvanceProfileResourceLoading(object);break;case 1:PartyTalk_AdvanceProfileDialogueAndRegistration(object);break;case 2:object[0xe9a]=0;break; }
    switch(object[0xe9b]) { case 0:PartyTalk_AdvanceRecordsPanelEntry(object);break;case 1:RecordsScreen_UpdatePanelSession(object+0x2a8);break;case 2:PartyTalk_AdvanceRecordsPanelExit(object);break; }
    return ((unsigned char*)object)[0xeb8];
}
