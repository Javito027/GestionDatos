/*
 * sc_channel_queue.cpp
 *
 *  Created on: Apr 27, 2024
 *      Author: opolo70
 */

#include "public/tc_queue_drv.h"

#define TC_QUEUE_MAX_NOE 20

//Elements that need a critical section
//The producer and consumer can handle
static uint16_t TCQueueHead;
static uint16_t TCQueueNumOfElements;

//These elements does not need a critical section
static uint8_t TCQueueCurrentTailIndex;
static uint8_t TCQueueElements[TC_QUEUE_MAX_NOE][TMTC_MAX_SIZE_IN_BYTES];
static uint16_t TCQueueElementLengths[TC_QUEUE_MAX_NOE];

static void (*LockFunction)(void)=NULL;

static void (*UnLockFunction)(void)=NULL;

void TCQueue_Init(void (*lockFunction)(void), void (*unlockFunction)(void)) {

	TCQueueNumOfElements = 0;
	TCQueueHead = 0;
	LockFunction = lockFunction;
	UnLockFunction = unlockFunction;

}

bool TCQueue_IsFull() {
	bool isFull;

	//***********************************************************
	//CRITICAL SECTION ENTRY
	LockFunction();

	isFull = (TCQueueNumOfElements == TC_QUEUE_MAX_NOE);

	UnLockFunction();
	//CRITICAL SECTION EXIT
	//***********************************************************

	return (isFull);
}

bool TCQueue_IsEmpty(){
	bool isEmpty;

	//***********************************************************
	//CRITICAL SECTION ENTRY
	LockFunction();

	isEmpty = (TCQueueNumOfElements == 0);

	UnLockFunction();
	//CRITICAL SECTION EXIT
	//***********************************************************

	return (isEmpty);
}

uint8_t* TCQueue_GetTailTCMemory() {

	uint8_t *pRxMemory;

	//***********************************************************
	//CRITICAL SECTION ENTRY
	LockFunction();

	TCQueueCurrentTailIndex = TCQueueHead
			+ TCQueueNumOfElements % TC_QUEUE_MAX_NOE;

	UnLockFunction();
	//CRITICAL SECTION EXIT
	//***********************************************************

	pRxMemory = &TCQueueElements[TCQueueCurrentTailIndex][0];

	return pRxMemory;
}

void TCQueue_TailTCCompleted(uint16_t tcLength) {

	//TC Complete
	TCQueueElementLengths[TCQueueCurrentTailIndex] = tcLength;

	//***********************************************************
	//CRITICAL SECTION ENTRY
	LockFunction();

	TCQueueNumOfElements++;

	UnLockFunction();
	//CRITICAL SECTION EXIT
	//***********************************************************

}

uint8_t* TCQueue_GetHeadTCMemory(uint16_t &tcLength) {

	uint8_t *pRxMemory;

	//***********************************************************
	//CRITICAL SECTION ENTRY
	LockFunction();

	pRxMemory = &TCQueueElements[TCQueueHead][0];

	tcLength = TCQueueElementLengths[TCQueueHead];

	UnLockFunction();
	//CRITICAL SECTION EXIT
	//***********************************************************

	return pRxMemory;
}

void TCQueue_HeadTCExtracted() {

	//***********************************************************
	//CRITICAL SECTION ENTRY
	LockFunction();

	TCQueueHead = (TCQueueHead + 1) % TC_QUEUE_MAX_NOE;
	TCQueueNumOfElements--;

	UnLockFunction();
	//CRITICAL SECTION EXIT
	//***********************************************************

}

