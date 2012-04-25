canSend( const MaceKey& peer, registration_uid_t rid)--canSend48--1
outgoingBufferedDataSize( const MaceKey& peer, registration_uid_t rid)--outgoingBufferedDataSize50--1
setWindowSize( const MaceKey& peer, uint64_t microsec, registration_uid_t rid)--setWindowSize54--1
getStatistics( const MaceKey& peer, TransportServiceClass::Connection::type d, registration_uid_t rid)--getStatistics56--1
requestToSend( const MaceKey& peer, registration_uid_t rid)--requestToSend57--1
hasBufferedData(registration_uid_t rid)--hasBufferedData59--1
hasOutgoingBufferedData(registration_uid_t rid)--hasOutgoingBufferedData60--1
outgoingBufferedDataSize(registration_uid_t rid)--outgoingBufferedDataSize61--1
routeRTS( const MaceKey& dest,  const std::string& s, registration_uid_t rid)--routeRTS62--1
requestFlushedNotification(registration_uid_t rid)--requestFlushedNotification64--1
route( const MaceKey& dest,  const std::string& s, registration_uid_t rid)--route65--1
maceInit()--maceInit71--1
maceReset()--maceReset74--1
hashState() const--hashState76--1
deliver( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid)--deliver78--1
deliver( const MaceKey& source,  const MaceKey& destination,  const DataFragment& s_deserialized, registration_uid_t rid)--deliver79--1
deliver( const MaceKey& source,  const MaceKey& destination,  const Fragment& s_deserialized, registration_uid_t rid)--deliver80--1
deliver( const MaceKey& source,  const MaceKey& destination,  const Ack& s_deserialized, registration_uid_t rid)--deliver81--1
deliver( const MaceKey& source,  const MaceKey& destination,  const Reset& s_deserialized, registration_uid_t rid)--deliver82--1
messageError( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid)--messageError83--1
messageError( const MaceKey& dest, TransportError::type errorCode,  const DataFragment& message_deserialized, registration_uid_t rid)--messageError84--1
messageError( const MaceKey& dest, TransportError::type errorCode,  const Fragment& message_deserialized, registration_uid_t rid)--messageError85--1
messageError( const MaceKey& dest, TransportError::type errorCode,  const Ack& message_deserialized, registration_uid_t rid)--messageError86--1
messageError( const MaceKey& dest, TransportError::type errorCode,  const Reset& message_deserialized, registration_uid_t rid)--messageError87--1
expire_retransmissionTimer(MaceKey& p0, MessageInfoPtr& p1)--expire_retransmissionTimer88--1
expire_localTimer(std::string& p0, registration_uid_t& p1)--expire_localTimer89--1
expire_ctsTimer(MaceKey& p0)--expire_ctsTimer90--1
suspendDeliver(registration_uid_t rid)--suspendDeliver23--1
suspendDeliver( const MaceKey& dest, registration_uid_t rid)--suspendDeliver24--1
resumeDeliver(registration_uid_t rid)--resumeDeliver25--1
resumeDeliver( const MaceKey& dest, registration_uid_t rid)--resumeDeliver26--1
route( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)--route27--1
route( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)--route28--1
route( const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid)--route29--1
route( const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid)--route30--1
route( const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid)--route31--1
route( const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid)--route32--1
route( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)--route33--1
route( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)--route34--1
route( const MaceKey& src,  const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid)--route35--1
route( const MaceKey& src,  const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid)--route36--1
route( const MaceKey& src,  const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid)--route37--1
route( const MaceKey& src,  const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid)--route38--1
send( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)--send39--1
send( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)--send40--1
send( const MaceKey& dest,  const DataFragment& s_deserialized, registration_uid_t rid)--send41--1
send( const MaceKey& dest,  const Fragment& s_deserialized, registration_uid_t rid)--send42--1
send( const MaceKey& dest,  const Ack& s_deserialized, registration_uid_t rid)--send43--1
send( const MaceKey& dest,  const Reset& s_deserialized, registration_uid_t rid)--send44--1
notifyFlushed(registration_uid_t rid)--upcall_notifyFlushed22--1
incrementAcked(OutgoingConnection& c, uint32_t size)--incrementAcked0--1
closeIncomingConnection( const MaceKey& src, TransportError::type error,  const std::string& errstr, bool upcallError)--closeIncomingConnection1--1
closeOutgoingConnection( const MaceKey& dest, OutgoingConnection& c, TransportError::type error,  const std::string& errstr, bool upcallError)--closeOutgoingConnection2--1
closeBidirectionalConnection( const MaceKey& dest, OutgoingConnection& c, TransportError::type error,  const std::string& errstr)--closeBidirectionalConnection3--1
deliverBuffered(IncomingConnection& c,  const MaceKey& src,  const MaceKey& dest)--deliverBuffered4--1
upcallDeliver(IncomingConnection& c,  const MaceKey& src,  const MaceKey& dest,  const std::string& payload, registration_uid_t rid)--upcallDeliver5--1
processDeliver( const MaceKey& src,  const MaceKey& dest, seq_t seq, mace::string payload, uint32_t ssize, registration_uid_t rid, mace::MonotoneTime syn, mace::MonotoneTime synecho, uint32_t nfrag, uint32_t frag)--processDeliver10--1
sendAck( const MaceKey& src, seq_t seq, mace::MonotoneTime syn, mace::MonotoneTime synecho, uint32_t sz, seq_t& ackseq, bool& discard)--sendAck11--1
sendReset( const MaceKey& dest, mace::MonotoneTime id, seq_t seq)--sendReset12--1
sendPackets(OutgoingConnection& c)--sendPackets13--1
enqueue(OutgoingConnection& c,  const std::string& s, registration_uid_t rid)--enqueue14--1
updateFlushed(OutgoingConnection& c)--updateFlushed15--1
checkAndNotifyFlushed()--checkAndNotifyFlushed16--1
printConnection( const OutgoingConnection& c,  const std::string& s) const--printConnection17--1
inflightSize() const--inflightSize18--1
checkRetransmissionTimer() const--checkRetransmissionTimer19--1
checkRetransmissionTimerCount() const--checkRetransmissionTimerCount20--1
outgoingBufferedDataSize() const--outgoingBufferedDataSize21--1
updateRTO( const MaceTime& ts)--ConnectionInfo_updateRTO--1
increaseCWND()--ConnectionInfo_increaseCWND--1
timeout()--ConnectionInfo_timeout--1
canSend() const--OutgoingConnection_canSend--1
updateCanSendOnWrite(uint64_t maxsize, uint64_t threshold)--OutgoingConnection_updateCanSendOnWrite--1
updateCanSendOnEnqueue(uint64_t maxsize)--OutgoingConnection_updateCanSendOnEnqueue--1
bufferedDataSize() const--OutgoingConnection_bufferedDataSize--1
hasQueuedMessages() const--OutgoingConnection_hasQueuedMessages--1
queuedMessagesSize() const--OutgoingConnection_queuedMessagesSize--1
nextSeq()--OutgoingConnection_nextSeq--1
getSyn()--OutgoingConnection_getSyn--1
setLast(seq_t s)--OutgoingConnection_setLast--1
fastRetransmit() const--OutgoingConnection_fastRetransmit--1
