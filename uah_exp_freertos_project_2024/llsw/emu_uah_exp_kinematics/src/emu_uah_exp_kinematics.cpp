/*
 * emu_uah_exp_cinematics.cpp
 *
 *  Created on: May 7, 2024
 *      Author: opolo70
 */

#include "public/emu_uah_exp_kinematics.h"

#define MoonGC 1.625

struct UAHExpKinematic UAHExpEmuKinematic::EmuKinematic(float Fx_Ti_1,
		float Fy_Ti_1, float Fz_Ti_1) {

	Pr_Time aux;
	double interval;
	double FxAbs;
	double FyAbs;
	double FzAbs;

	//Calculate Interval from previous invocation
	aux.GetTime();
	aux -= mRefTime;
	interval = aux.FineTime();

	//Update reference time (It will be used in the next invocation)
	mRefTime.GetTime();

	//Calculate Velocity  v= a*t, where a=Force/Mass
	mExpKinematic.Vx += (Fx_Ti_1 / mExpKinematic.Mass) * interval;
	mExpKinematic.Vy += (Fy_Ti_1 / mExpKinematic.Mass) * interval;
	mExpKinematic.Vz += ((Fz_Ti_1 + MoonGC * mExpKinematic.Mass)
										/ mExpKinematic.Mass) * interval;

	//Abs value of forces
	FxAbs = Fx_Ti_1;
	if (FxAbs < 0)
		FxAbs = -FxAbs;
	FyAbs = Fy_Ti_1;
	if (FyAbs < 0)
		FyAbs = -FyAbs;
	FzAbs = Fz_Ti_1;
	if (FzAbs < 0)
		FzAbs = -FzAbs;

	//Mass decrement. 10 gram per Newton/sec
	mExpKinematic.Mass -= ((FxAbs + FyAbs + FzAbs) * interval) / 100;
	return mExpKinematic;
}
