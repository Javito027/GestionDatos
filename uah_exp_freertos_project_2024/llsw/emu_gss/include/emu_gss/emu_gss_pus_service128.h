/*
 * emu_sc_pus_service17.h
 *
 *  Created on: Nov 12, 2023
 *      Author: user
 */

#ifndef EMU_SC_PUS_SERVICE128_H_
#define EMU_SC_PUS_SERVICE128_H_

class EmuGSS_TCProgram128_1:public EmuGSS_TCProgram{

  friend class EmuGSS_TCProgram19_1_Action_128_1;
  void BuildTCAppData(tc_descriptor_t &tc_descriptor);


public:

  EmuGSS_TCProgram128_1(uint32_t uniTime2YK,
                 const char * brief);


  //Constructor for 19_1 event action program
  EmuGSS_TCProgram128_1();
};




#endif /* EMU_SC_PUS_SERVICE17_H_ */
