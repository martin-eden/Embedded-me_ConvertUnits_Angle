// Convert planar angle units

/*
  Author: Martin Eden
  Last mod.: 2024-09-12
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_ConvertUnits_Angle
{
  // Map float to [0, 360)
  TFloat NormalizeDeg(TFloat ArcLen_Deg);

  // Map float to [0, 2*Pi)
  TFloat NormalizeRad(TFloat ArcLen_Rad);

  // Degrees to radians
  TFloat DegToRad(TFloat ArcLen_Deg);
  // Radians to degrees
  TFloat RadToDeg(TFloat ArcLen_Rad);

  // Map float to [0, 400)
  TFloat NormalizeGrad(TFloat ArcLen_Grad);

  // Degrees to gradians
  TFloat DegToGrad(TFloat ArcLen_Deg);
  // Gradians to degrees
  TFloat GradToDeg(TFloat ArcLen_Grad);
}

/*
  2024-03-23
  2024-05-17
*/
