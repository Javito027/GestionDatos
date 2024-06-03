

#include <public/ccexplorermanager_iface_v1.h>



	// ******************* HANDLING IRQ 10********************

Pr_IRQEvent	CCExplorerManager::EDROOMEventIRQ10(10);
Pr_SemaphoreBin	CCExplorerManager::EDROOMSemEndIRQ10(0);


		// ******************* DATA ***************

CDEvAction	CCExplorerManager::	EDROOMVarIRQ10;


		// ******************* DATA POOL *******

CCExplorerManager::CEDROOMPOOLIRQ10CDEvAction	CCExplorerManager::EDROOMPoolIRQ10;


		// ******************* Aux IRQ Handler **************

void 	CCExplorerManager::EDROOMIRQ10HandlerTopHalfFunction(void){

	bool EDROOMIRQ10BottomHalfSignal=true;
	if (EDROOMIRQ10BottomHalfSignal)
		EDROOMEventIRQ10.Signal();

}



		// ******************* IRQ Handler **************

Pr_IRQHandler_RetType	CCExplorerManager::EDROOMIRQ10Handler(void){

	EDROOMIRQ10HandlerTopHalfFunction();

}



		// ******************* IRQ Idle Handler **************

Pr_IRQHandler_RetType	CCExplorerManager::EDROOMIRQ10IdleHandler(void){

}



		// ******************* Bottom Half Task **************

Pr_TaskRV_t 	CCExplorerManager::EDROOMIRQ10BottomHalfTask(Pr_TaskP_t){

	bool endTask=false;

	do
	{

		EDROOMEventIRQ10.Wait();

		bool EDROOMIRQ10SendMsgToCmp=true;

		if(!EDROOMSemEndIRQ10.WaitCond()){

			 

			 

			 

			EDROOMIRQ10SendMsgToCmp 

			=PUSService19::ExtractEvActionFromQueue(EDROOMVarIRQ10);

			 

			 

					

			if(EDROOMIRQ10SendMsgToCmp){
				CDEvAction	*pEDROOMVarIRQ;

				pEDROOMVarIRQ=EDROOMPoolIRQ10.AllocData();

				*pEDROOMVarIRQ=EDROOMVarIRQ10;

				EvActionQueue.NewIRQMsg(EDROOMIRQsignal, pEDROOMVarIRQ, &EDROOMPoolIRQ10);

			}
			Pr_IRQManager::EnableIRQ(10);

		}else endTask=1;

	}while(!endTask);

}



		// ******************* IRQPort **************

CEDROOMIRQInterface CCExplorerManager::EvActionQueue( 
		CCExplorerManager::EDROOMIRQ10Handler 
		,CCExplorerManager::EDROOMIRQ10IdleHandler 
		,CCExplorerManager::EDROOMEventIRQ10
		,CCExplorerManager::EDROOMSemEndIRQ10
		,10 );


	// ******************* HANDLING IRQ 18********************

Pr_IRQEvent	CCExplorerManager::EDROOMEventIRQ18(18);
Pr_SemaphoreBin	CCExplorerManager::EDROOMSemEndIRQ18(0);


		// ******************* DATA ***************

CDTCHandler	CCExplorerManager::	EDROOMVarIRQ18;


		// ******************* DATA POOL *******

CCExplorerManager::CEDROOMPOOLIRQ18CDTCHandler	CCExplorerManager::EDROOMPoolIRQ18;


		// ******************* Aux IRQ Handler **************

void 	CCExplorerManager::EDROOMIRQ18HandlerTopHalfFunction(void){

	bool EDROOMIRQ18BottomHalfSignal=true;
	#ifdef NEXYS_PLATFORM 

	 

	EDROOMIRQ18BottomHalfSignal=EDROOMVarIRQ18.HandleIRQ();

	 

	#endif

	if (EDROOMIRQ18BottomHalfSignal)
		EDROOMEventIRQ18.Signal();

}



		// ******************* IRQ Handler **************

Pr_IRQHandler_RetType	CCExplorerManager::EDROOMIRQ18Handler(void){

	EDROOMIRQ18HandlerTopHalfFunction();

}



		// ******************* IRQ Idle Handler **************

Pr_IRQHandler_RetType	CCExplorerManager::EDROOMIRQ18IdleHandler(void){

}



		// ******************* Bottom Half Task **************

Pr_TaskRV_t 	CCExplorerManager::EDROOMIRQ18BottomHalfTask(Pr_TaskP_t){

	bool endTask=false;

	do
	{

		EDROOMEventIRQ18.Wait();

		bool EDROOMIRQ18SendMsgToCmp=true;

		if(!EDROOMSemEndIRQ18.WaitCond()){

			 

			 

			 

			SC_Channel_GetNextTC(&EDROOMVarIRQ18);

			 

			 

			if(EDROOMIRQ18SendMsgToCmp){
				CDTCHandler	*pEDROOMVarIRQ;

				pEDROOMVarIRQ=EDROOMPoolIRQ18.AllocData();

				*pEDROOMVarIRQ=EDROOMVarIRQ18;

				RxTC.NewIRQMsg(EDROOMIRQsignal, pEDROOMVarIRQ, &EDROOMPoolIRQ18);

			}
			Pr_IRQManager::EnableIRQ(18);

		}else endTask=1;

	}while(!endTask);

}



		// ******************* IRQPort **************

CEDROOMIRQInterface CCExplorerManager::RxTC( 
		CCExplorerManager::EDROOMIRQ18Handler 
		,CCExplorerManager::EDROOMIRQ18IdleHandler 
		,CCExplorerManager::EDROOMEventIRQ18
		,CCExplorerManager::EDROOMSemEndIRQ18
		,18 );




// ******************************* CONSTRUCTOR ************************************



CCExplorerManager::CCExplorerManager(TEDROOMComponentID id,
		TEDROOMUInt32 roomNumMaxMens,
		TEDROOMPriority roomtaskPrio,
		TEDROOMStackSizeType roomStack,
		CEDROOMMemory *pActorMemory ) : 

		CEDROOMComponent(id,EDROOMprioMINIMUM+1,roomNumMaxMens,
				roomtaskPrio,roomStack, pActorMemory ),

		// ***************   BOTTOM HALF IRQ TASKS  ********************

		EDROOMIRQ10BottomHalfT( EDROOMIRQ10BottomHalfTask,EDROOMprioURGENT,256),

		// ***************   BOTTOM HALF IRQ TASKS  ********************

		EDROOMIRQ18BottomHalfT( EDROOMIRQ18BottomHalfTask,EDROOMprioURGENT,256),

		// ***************	Top State  *****************

		edroomTopState(*this,pActorMemory)


{


}


//**************************************************************************
//**************************   PUBLIC METHODS  *****************************



//************************** EDROOMConfig **********************************


int CCExplorerManager::EDROOMConfig()
{


 return 0; 
}



//************************** EDROOMStart **********************************

int CCExplorerManager::EDROOMStart()
{


	//***************** CEDROOMComponent::EDROOMStart*********

	CEDROOMComponent::EDROOMStart(); 	// Call to EDROOMStart method of CEDROOMComponent

	return 0;
}


//**************************************************************************
//***************************    PROTECTED METHODS *************************



//*****************************  EDROOMBehaviour ***************************



void CCExplorerManager::EDROOMBehaviour()
{

	edroomTopState.EDROOMInit();
	edroomTopState.EDROOMBehaviour();


		// *************** PUERTOS IRQ ********************

	EvActionQueue.EndIRQHandlerTask();

		// *************** PUERTOS IRQ ********************

	RxTC.EndIRQHandlerTask();
}




//********************* ComponentIsFinished **********************************


#ifdef _EDROOM_SYSTEM_CLOSE

bool CCExplorerManager::EDROOMIsComponentFinished()
{


	return ( CEDROOMComponent::EDROOMIsComponentFinished());

}

#endif


//****************** EDROOMMemory::SetMemory *******************************

void CCExplorerManager::CEDROOMMemory::SetMemory(TEDROOMUInt32 numMessages_ ,
		CEDROOMMessage * MessagesMem_,
		bool * MessagesMemMarks_,
		TEDROOMUInt32 numberOfNodes_,
		CEDROOMQueue::CQueueNode * QueueNodesMem_,
		bool * QueueNodesMemMarks_)
{

		CEDROOMComponentMemory::SetMemory( numMessages_,MessagesMem_, MessagesMemMarks_,
			numberOfNodes_,QueueNodesMem_, QueueNodesMemMarks_, QueueHeads);


}

