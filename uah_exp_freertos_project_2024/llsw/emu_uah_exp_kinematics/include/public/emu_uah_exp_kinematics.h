/*
 * emu_exp_sim_cinematics.h
 *
 *  Created on: May 7, 2024
 *      Author: opolo70
 */

#ifndef LLSW_EMU_UAH_EXP_KINEMATICS_INCLUDE_PUBLIC_EMU_UAH_EXP_CINEMATICS_H_
#define LLSW_EMU_UAH_EXP_KINEMATICS_INCLUDE_PUBLIC_EMU_UAH_EXP_CINEMATICS_H_

#include "public/edroombp.h"

struct UAHExpKinematic {
	float Vx;
	float Vy;
	float Vz;
	float Mass;
};

class UAHExpEmuKinematic {

	//Veloc
	struct UAHExpKinematic mExpKinematic;

	//Time of this information

	Pr_Time mRefTime;

public:

	/**
	 * \brief	Constructor. Init Vx,Vy and Vz to zero, Mass is 1 Kg
	 */
	UAHExpEmuKinematic() {
		mExpKinematic.Mass = 1.0;
		mExpKinematic.Vx = 0.0;
		mExpKinematic.Vy = 0.0;
		mExpKinematic.Vz = 0.0;
	}

	/**
	 * \brief	EmuKinematic.
	 * @param Fx_Ti_1 Force in x axis applied from previous period T(i-1) until now
	 * @param Fy_Ti_1 Force in y axis applied from previous period T(i-1) until now
	 * @param Fz_Ti_1 Force in z axis applied from previous period T(i-1) until now
	 *
	 * @return the updated kinematic info (velocity [Vx, Vy, Vz] and Mass).
	 */

	UAHExpKinematic EmuKinematic(float Fx_Ti_1, float Fy_Ti_1, float Fz_Ti_1);

};

#endif /* LLSW_EMU_UAH_EXP_CINEMATICS_INCLUDE_PUBLIC_EMU_UAH_EXP_CINEMATICS_H_ */
