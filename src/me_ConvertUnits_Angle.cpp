// Planar angle units conversion

/*
  Author: Martin Eden
  Last mod.: 2024-05-17
*/

#include "me_ConvertUnits_Angle.h"

#include <math.h> // fabs(), fmod()

#include <me_BaseTypes.h>

using namespace me_BaseTypes;

/*
  Return always positive fractional remainder

     10  3 -> 1
     10 -3 -> 1
    -10  3 -> 2
    -10 -3 -> 2

  We are just rowing to positive number closest to zero.

  Please do not provide zero <BaseUnit>.
*/
TFloat Normalize(TFloat Variable, TFloat BaseUnit)
{
  if (BaseUnit < 0)
    BaseUnit = fabs(BaseUnit);

  TFloat Result;

  Result = fmod(Variable, BaseUnit);

  if (Result < 0)
    Result = Result + BaseUnit;

  return Result;
}

const TFloat CircleLen_Deg = 360.0;

// Map float to [0, 360)
TFloat me_ConvertUnits_Angle::NormalizeDeg(TFloat ArcLen_Deg)
{
  return Normalize(ArcLen_Deg, CircleLen_Deg);
}

const TFloat CircleLen_Rad = 2 * M_PI;

// Convert degrees to radians
TFloat me_ConvertUnits_Angle::DegToRad(TFloat ArcLen_Deg)
{
  ArcLen_Deg = NormalizeDeg(ArcLen_Deg);
  return (ArcLen_Deg / CircleLen_Deg * CircleLen_Rad);
}

// Map float to [0, 2*Pi)
TFloat me_ConvertUnits_Angle::NormalizeRad(TFloat ArcLen_Rad)
{
  return Normalize(ArcLen_Rad, CircleLen_Rad);
}

// Convert radians to degrees
TFloat me_ConvertUnits_Angle::RadToDeg(TFloat ArcLen_Rad)
{
  ArcLen_Rad = NormalizeRad(ArcLen_Rad);
  return (ArcLen_Rad / CircleLen_Rad * CircleLen_Deg);
}

/*
  Gradian also known as "gon".
*/
const TFloat CircleLen_Grad = 400.0;

// Convert degrees to gradians
TFloat me_ConvertUnits_Angle::DegToGrad(TFloat ArcLen_Deg)
{
  ArcLen_Deg = NormalizeDeg(ArcLen_Deg);
  return (ArcLen_Deg / CircleLen_Deg * CircleLen_Grad);
}

// Map float to [0, 400)
TFloat me_ConvertUnits_Angle::NormalizeGrad(TFloat ArcLen_Grad)
{
  return Normalize(ArcLen_Grad, CircleLen_Grad);
}

// Convert gradians to degrees
TFloat me_ConvertUnits_Angle::GradToDeg(TFloat ArcLen_Grad)
{
  ArcLen_Grad = NormalizeGrad(ArcLen_Grad);
  return (ArcLen_Grad / CircleLen_Grad * CircleLen_Deg);
}

/*
  Can we have mathematically sane unit [0, 1)?

  Yes, just fractional part to describe length of non-overlapping arc
  winded on circle.
*/

/*
  2024-03-23
  2024-04-23
  2024-05-17
*/
