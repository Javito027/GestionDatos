/*
 * icuasw_pus_Service17.h
 *
 *  Created on: Dec 22, 2024
 *      Author: user
 */



#ifndef PUBLIC__ICUASW_PUS_SERVICE128_H
#define PUBLIC__ICUASW_PUS_SERVICE128_H

#include "public/basic_types.h"

#include "public/icuasw_pus_services_iface_v1.h"
#include "public/cdtchandler.h"
#include "public/cdtmlist.h"
#include "public/ccexplorermanager_iface_v1.h"

class PUSService128{

 friend class PUSPrioTCExecutor;
 friend class CCEPDManager;
protected:
  static void ExecTC( CDTCHandler &tcHandler, CDTMList &tmList);

  static void Exec128_1TC( CDTCHandler &tcHandler, CDTMList &tmList);

public:
  static void MngReboot();

};
#endif
