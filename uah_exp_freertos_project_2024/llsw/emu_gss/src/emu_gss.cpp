/*
 * emu_gss.cpp
 *
 *  Created on: Jan 3, 2024
 *      Author: opolo70
 */

#include <stdio.h>

#include "public/emu_gss_v1.h"

#include <public/ccexplorermanager_iface_v1.h>
#include <public/emu_hw_timecode_drv_v1.h>
#include "public/tc_queue_drv.h"

#include "public/serialize.h"



void EmuGSS_ShowTM(const struct tm_descriptor *pTMDescriptor) {

	//Get TM Type
	uint8_t tm_type = GSSTMHandler::GetPUSType(pTMDescriptor);
	uint8_t tm_subtype = GSSTMHandler::GetPUSSubtype(pTMDescriptor);

	printf("GSS Rx TM (%i,%i)", tm_type, tm_subtype);

	switch (tm_type) {

	case (1):

		EmuGSS_ShowServ1TM(pTMDescriptor);

		break;

	case (3):
		EmuGSS_ShowServ3TM(pTMDescriptor);
		break;

	case (5):
		EmuGSS_ShowServ5TM(pTMDescriptor);
				break;
	case (12):
		EmuGSS_ShowServ12TM(pTMDescriptor);
				break;
	case (20):
		EmuGSS_ShowServ20TM(pTMDescriptor);
				break;
	};

	printf("\n");

}

void EmuGSS_PassSecond() {

//Emulate Hw TimeCode reception TO_DO

	printf("\nCurrent UniTime is = %i\n", EmuHwTimeCodeGetCurrentUniTimeY2K());

	EmuGSS_SendProgrammedTCs();

}

void EmuGSS_SendProgrammedTCs() {

	uint32_t currentUniTimeY2K = EmuHwTimeCodeGetCurrentUniTimeY2K();

	bool tc_programmed=false;
	while (EmuGSS_TCProgram::SetCurrentTCProgramed(currentUniTimeY2K)) {

		printf("\nGSS Tx TC(%i,%i) ",
				(EmuGSS_TCProgram::sCurrentTCProgram)->GetType(),
				(EmuGSS_TCProgram::sCurrentTCProgram)->GetSubtype());

		printf("%s",EmuGSS_TCProgram::sCurrentTCProgram->GetBrief());
		printf("\n");

		//TC descriptor
		tc_descriptor_t tcDescriptor;

		EmuGSS_TCProgram *ptc_program = EmuGSS_TCProgram::GetCurrentTCProgramed();

		tcDescriptor.p_tc_bytes = TCQueue_GetTailTCMemory();

		ptc_program->BuildTC(tcDescriptor);

		TCQueue_TailTCCompleted(tcDescriptor.tc_num_bytes);

		tc_programmed=true;


	}

	if(tc_programmed){

		CCExplorerManager::EDROOMEventIRQ18.SignalFromTask();

	}

}


