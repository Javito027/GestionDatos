/*
 * sc_channel_queue.h
 *
 *  Created on: Apr 27, 2024
 *      Author: opolo70
 */

#ifndef LLSW_SC_CHANNEL_DRV_INCLUDE_SC_CHANNEL_QUEUE_H_
#define LLSW_SC_CHANNEL_DRV_INCLUDE_SC_CHANNEL_QUEUE_H_

#include "public/icuasw_pus_services_iface_v1.h"
#include "public/config.h"
#include "public/basic_types.h"

/**
 * \brief	Init TC Queue.*/

void TCQueue_Init(void (*lockFunction)(void), void (*unlockFunction)(void));

/**
 * \brief	Return true if TCQueueIsFull */

bool TCQueue_IsFull();

/**
 * \brief	Return true if TCQueueIsEmpty*/

bool TCQueue_IsEmpty();


/**
 * \brief	Get the memory of the Tail TC */
uint8_t* TCQueue_GetTailTCMemory();

/**
 * \brief	Tail TC is Completed, update Tail*/
void TCQueue_TailTCCompleted(uint16_t length);

/**
 * \brief	Get the memory of the Head TC */

uint8_t* TCQueue_GetHeadTCMemory(uint16_t &headtclength);

/**
 * \brief	Head TC has been extracted, update head*/

void TCQueue_HeadTCExtracted();

#endif /* LLSW_SC_CHANNEL_DRV_INCLUDE_SC_CHANNEL_QUEUE_H_ */
