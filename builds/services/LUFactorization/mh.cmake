SET(ALL_SERVICES ${ALL_SERVICES} LUFactorization)
SET(LUFactorizationService_sv_dep LUFactorization ${TcpTransportService_sv_dep})
SET(LUFactorizationService_sv_list  TcpTransport)
SET(LUFactorizationService_tgt_dep ServiceClass_dep TransportServiceClass_dep)
SET(LUFactorizationService_lib LUFactorization)
SET(LUFactorizationService_dep ${ServiceClass_h} ${TransportServiceClass_dep})
