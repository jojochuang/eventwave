SET(ALL_SERVICES ${ALL_SERVICES} Pastry)
SET(PastryService_tgt_dep ServiceClass_dep OverlayRouterServiceClass_dep OverlayServiceClass_dep TransportServiceClass_dep TransportServiceClass_dep)
SET(PastryService_lib Pastry)
SET(PastryService_sv_list  auto auto)
SET(PastryService_dep ${ServiceClass_h} ${OverlayRouterServiceClass_dep} ${OverlayServiceClass_dep} ${TransportServiceClass_dep} ${TransportServiceClass_dep})
SET(PastryService_sv_dep Pastry ${autoService_sv_dep} ${autoService_sv_dep})
