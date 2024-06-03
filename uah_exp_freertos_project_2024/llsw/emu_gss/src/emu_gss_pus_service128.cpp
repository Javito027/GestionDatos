/*
 * emu_sc_pus_service17.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: user
 */



#include "public/emu_gss_v1.h"
#include "emu_gss/emu_gss_pus_service17.h"

#define TC_128_1_APPDATA_LENGTH 0

EmuGSS_TCProgram128_1::EmuGSS_TCProgram128_1(uint32_t uniTime2YK,
		const char * brief)
                        :EmuGSS_TCProgram(uniTime2YK,128,1,
                        		TC_128_1_APPDATA_LENGTH,brief){

     NewProgram(this);
}

//Constructor for event-action
EmuGSS_TCProgram128_1::EmuGSS_TCProgram128_1()
                        :EmuGSS_TCProgram(0,128,1,TC_128_1_APPDATA_LENGTH,"NULL"){

	//No Program
    // NewProgram(this);
}

void EmuGSS_TCProgram128_1::BuildTCAppData(tc_descriptor_t &tc_descriptor){


}


