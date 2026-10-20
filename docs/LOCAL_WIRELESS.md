# Local wireless member disconnect notices

The connection manager stores a per-slot disconnect-notice mask in the byte at
`+0x1010`. `Network_MarkMemberDisconnectNoticeQueued` and
`Network_ClearMemberDisconnectNoticeQueued` translate a member ID to a wireless
slot and set or clear its bit. Both leave the mask unchanged in client sessions.
`Network_TestMemberDisconnectNoticeQueued` returns the masked bit, without
normalizing the result to one.

`Field_UpdateMultiplayerPartySynchronization` checks the member's disconnect flag
and the notice mask before calling `Network_QueueMemberDisconnectNotice`. It marks
the slot immediately afterward, suppressing repeated notices during later updates.
The notice-producing branch also queues a formatted member-name notification.
The join/synchronization path and
`Field_RemoveRemoteMemberAndSynchronizationState` clear the marker as the member's
synchronization/disconnect state is reset.

The helpers retain their original identities in their source comments:
`arm9/main:0202c6dc`, `arm9/main:0202c718` and `arm9/main:0202c758`.
The naming registry records the relevant caller evidence. The reconstructed test
helper has an incomplete member-ID prototype; naming does not repair its ABI
projection or change its instructions.
