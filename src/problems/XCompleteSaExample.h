/*  Copyright 2011-2013 Alexis Herault, Giuseppe Bilotta, Robert A. Dalrymple, Eugenio Rustico, Ciro Del Negro

    Istituto Nazionale di Geofisica e Vulcanologia
        Sezione di Catania, Catania, Italy

    Università di Catania, Catania, Italy

    Johns Hopkins University, Baltimore, MD

    This file is part of GPUSPH.

    GPUSPH is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    GPUSPH is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with GPUSPH.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _XCOMPLETESAEXAMPLE_H
#define	_XCOMPLETESAEXAMPLE_H

#include "XProblem.h"

// Water level simulated by the pressure inlet
#define INLET_WATER_LEVEL	0.9

class XCompleteSaExample: public XProblem {
	private:
	public:
		XCompleteSaExample(GlobalData *);
		//virtual ~XCompleteSaExample(void);

		uint max_parts(uint);

		void
		setboundconstants(
			const	PhysParams	*physparams,
			float3	const&		worldOrigin,
			uint3	const&		gridSize,
			float3	const&		cellSize);

		void
		imposeBoundaryConditionHost(
					float4*			newVel,
					float4*			newEulerVel,
					float*			newTke,
					float*			newEpsilon,
			const	particleinfo*	info,
			const	float4*			oldPos,
					uint*			IOwaterdepth,
			const	float			t,
			const	uint			numParticles,
			const	uint			numObjects,
			const	uint			particleRangeEnd,
			const	hashKey*		particleHash);

		/*
		void
		imposeForcedMovingObjects(
			float3	&centerOfGravity,
			float3	&translation,
			float*	rotationMatrix,
	const	uint	ob,
	const	double	t,
	const	float	dt);
		// */

		// override standard split
		void fillDeviceMap();
};
#endif	/* _XCOMPLETESAEXAMPLE_H */
