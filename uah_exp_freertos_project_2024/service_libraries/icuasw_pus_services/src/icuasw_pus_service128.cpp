/*
 * icuasw_pus_Service128.cpp
 *
 *  Created on: Dec 22, 2023
 *      Author: user
 */

#include <public/icuasw_pus_services_iface_v1.h>
#include <stdlib.h>

void PUSService128::ExecTC(CDTCHandler &tcHandler, CDTMList &tmList) {

	switch (tcHandler.GetSubType()) {
	case (1):

		Exec128_1TC(tcHandler, tmList);

		break;
	default:
		break;
	}


}

void PUSService128::Exec128_1TC(CDTCHandler &tcHandler, CDTMList &tmList) {


	PUSService1::BuildTM_1_7(tcHandler, tmList);


}

void PUSService128::MngReboot(){

	exit(0);
}
