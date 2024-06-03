/*
 * sc_channel_drv.c
 *
 *  Created on: Dec 20, 2016
 *      Author: user
 */


#include <public/sc_channel_drv_v1.h>
#include "public/emu_gss_v1.h"
#include "public/tmtc_dyn_mem.h"
#include "public/tc_queue_drv.h"

Pr_Mutex Mutex;
void LockFunction(void) {
	Mutex.Wait();
}
void UnlockFunction(void) {
	Mutex.Signal();
}

void SC_Channel_Init(CEDROOMIRQInterface *irqInterface) {
	init_tmtc_pool();

	TCQueue_Init(LockFunction, UnlockFunction);
}

bool_t SC_Channel_RxData() {

	return false;
}

void SC_Channel_GetNextTC(CDTCHandler *tc) {

	uint16_t tcLength;
	uint8_t *pHeadTCMemory;

	pHeadTCMemory = TCQueue_GetHeadTCMemory(tcLength);

	tc->mTCDescriptor.p_tc_bytes = tmtc_pool_alloc();
	tc->mTCDescriptor.tc_num_bytes = tcLength;

	for (int i = 0; i < tcLength; i++) {
		tc->mTCDescriptor.p_tc_bytes[i] = pHeadTCMemory[i];

	}

	TCQueue_HeadTCExtracted();


}

void SC_Channel_HandlePendingTCs(){

	//Trigger other BottomHalfSignal if Queue is not empty
	if(!TCQueue_IsEmpty())

		CCExplorerManager::EDROOMEventIRQ18.SignalFromTask();
}

void SC_Channel_TxTM(const tm_descriptor_t *pTMDescriptor) {

	EmuGSS_ShowTM(pTMDescriptor);

}

void SC_Channel_TxTMList(CDTMList *pTmList) {
	for (uint8_t i = 0; i < pTmList->GetTMNumber(); i++) {

		SC_Channel_TxTM(pTmList->GetpTM(i));

		tmtc_pool_free(pTmList->GetTM(i).p_tm_bytes);
	}
}

