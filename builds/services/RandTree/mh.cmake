SET(ALL_SERVICES ${ALL_SERVICES} RandTree)
SET(RandTreeService_tgt_dep ServiceClass_dep TreeServiceClass_dep OverlayServiceClass_dep TransportServiceClass_dep)
SET(RandTreeService_lib RandTree)
SET(RandTreeService_dep ${ServiceClass_h} ${TreeServiceClass_dep} ${OverlayServiceClass_dep} ${TransportServiceClass_dep})
SET(RandTreeService_sv_dep RandTree ${autoService_sv_dep})
SET(RandTreeService_sv_list  auto)
