SET(ALL_SERVICES ${ALL_SERVICES} SimAggregateApp)
SET(ALL_SERVICES ${ALL_SERVICES} SimConsensusApp)
SET(ALL_SERVICES ${ALL_SERVICES} SimGTreeApp)
SET(ALL_SERVICES ${ALL_SERVICES} SimOverlayRouterApp)
SET(ALL_SERVICES ${ALL_SERVICES} SimPTransportApp)
SET(ALL_SERVICES ${ALL_SERVICES} SimTransportApp)
SET(ALL_SERVICES ${ALL_SERVICES} SimTreeApp)
SET(SimTreeAppService_dep ${ServiceClass_h} ${SimApplicationServiceClass_dep} ${TreeServiceClass_dep} ${OverlayServiceClass_dep})
SET(SimTreeAppService_sv_list   )
SET(SimTransportAppService_sv_dep SimTransportApp ${Service_sv_dep})
SET(SimAggregateAppService_lib SimApplication)
SET(SimTransportAppService_tgt_dep ServiceClass_dep SimApplicationServiceClass_dep BufferedTransportServiceClass_dep)
SET(SimAggregateAppService_dep ${ServiceClass_h} ${SimApplicationServiceClass_dep} ${OverlayServiceClass_dep} ${AggregateServiceClass_dep})
SET(SimGTreeAppService_sv_list    )
SET(SimGTreeAppService_sv_dep SimGTreeApp ${Service_sv_dep} ${Service_sv_dep} ${Service_sv_dep})
SET(SimPTransportAppService_sv_dep SimPTransportApp ${autoService_sv_dep} ${ProvisionalTransportService_sv_dep})
SET(SimConsensusAppService_dep ${ServiceClass_h} ${SimApplicationServiceClass_dep} ${ConsensusServiceClass_dep})
SET(SimConsensusAppService_sv_dep SimConsensusApp ${Service_sv_dep})
SET(SimConsensusAppService_sv_list  )
SET(SimTreeAppService_tgt_dep ServiceClass_dep SimApplicationServiceClass_dep TreeServiceClass_dep OverlayServiceClass_dep)
SET(SimConsensusAppService_tgt_dep ServiceClass_dep SimApplicationServiceClass_dep ConsensusServiceClass_dep)
SET(SimTreeAppService_sv_dep SimTreeApp ${Service_sv_dep} ${Service_sv_dep})
SET(SimConsensusAppService_lib SimApplication)
SET(SimTransportAppService_sv_list  )
SET(SimGTreeAppService_lib SimApplication)
SET(SimTransportAppService_lib SimApplication)
SET(SimAggregateAppService_sv_list   )
SET(SimAggregateAppService_sv_dep SimAggregateApp ${Service_sv_dep} ${Service_sv_dep})
SET(SimPTransportAppService_sv_list  auto ProvisionalTransport)
SET(SimOverlayRouterAppService_tgt_dep ServiceClass_dep SimApplicationServiceClass_dep OverlayRouterServiceClass_dep)
SET(SimOverlayRouterAppService_sv_dep SimOverlayRouterApp ${Service_sv_dep})
SET(SimPTransportAppService_lib SimApplication)
SET(SimOverlayRouterAppService_lib SimApplication)
SET(SimPTransportAppService_tgt_dep ServiceClass_dep SimApplicationServiceClass_dep BufferedTransportServiceClass_dep ProvisionalTransportServiceClass_dep)
SET(SimGTreeAppService_tgt_dep ServiceClass_dep SimApplicationServiceClass_dep OverlayServiceClass_dep GroupServiceClass_dep TreeServiceClass_dep)
SET(SimTreeAppService_lib SimApplication)
SET(SimTransportAppService_dep ${ServiceClass_h} ${SimApplicationServiceClass_dep} ${BufferedTransportServiceClass_dep})
SET(SimOverlayRouterAppService_sv_list  )
SET(SimOverlayRouterAppService_dep ${ServiceClass_h} ${SimApplicationServiceClass_dep} ${OverlayRouterServiceClass_dep})
SET(SimGTreeAppService_dep ${ServiceClass_h} ${SimApplicationServiceClass_dep} ${OverlayServiceClass_dep} ${GroupServiceClass_dep} ${TreeServiceClass_dep})
SET(SimAggregateAppService_tgt_dep ServiceClass_dep SimApplicationServiceClass_dep OverlayServiceClass_dep AggregateServiceClass_dep)
SET(SimPTransportAppService_dep ${ServiceClass_h} ${SimApplicationServiceClass_dep} ${BufferedTransportServiceClass_dep} ${ProvisionalTransportServiceClass_dep})
