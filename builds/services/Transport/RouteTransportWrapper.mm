route( const MaceKey& dest,  const std::string& s, registration_uid_t rid)--route13--1
maceInit()--maceInit19--1
maceReset()--maceReset22--1
hashState() const--hashState24--1
error( const MaceKey& nodeId, TransportError::type errorCode,  const std::string& message, registration_uid_t rid)--error25--1
deliver( const MaceKey& source,  const MaceKey& destination,  const Data& s_deserialized, registration_uid_t rid)--deliver26--1
messageError( const MaceKey& dest, TransportError::type errorCode,  const Data& message_deserialized, registration_uid_t rid)--messageError27--1
suspendDeliver(registration_uid_t rid)--suspendDeliver0--1
suspendDeliver( const MaceKey& dest, registration_uid_t rid)--suspendDeliver1--1
resumeDeliver(registration_uid_t rid)--resumeDeliver2--1
resumeDeliver( const MaceKey& dest, registration_uid_t rid)--resumeDeliver3--1
route( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)--route4--1
route( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)--route5--1
route( const MaceKey& src,  const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)--route6--1
route( const MaceKey& src,  const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)--route7--1
send( const MaceKey& dest,  const Message& s_deserialized, registration_uid_t rid)--send8--1
send( const MaceKey& dest,  const Data& s_deserialized, registration_uid_t rid)--send9--1
