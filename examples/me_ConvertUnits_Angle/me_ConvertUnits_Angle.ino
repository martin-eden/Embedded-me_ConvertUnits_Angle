// [me_ConvertUnits_Angle] test/demo

/*
  Author: Martin Eden
  Last mod.: 2024-09-12
*/

#include <me_ConvertUnits_Angle.h>

#include <me_UartSpeeds.h>
#include <me_InstallStandardStreams.h>
#include <me_BaseTypes.h>

void setup()
{
  Serial.begin(me_UartSpeeds::Arduino_Normal_Bps);
  delay(1500);
  InstallStandardStreams();
  printf("[me_ConvertUnits_Angle]\n");

  using namespace me_ConvertUnits_Angle;

  /*
    Sorry guys, Atmel's printf() doesn't support printing floats
    out of the box.

    vfprintf() documentation in "stdio.h" mentions it's possible
    by rebuilding but I hadn't figure it out how to achieve it.

    Anyway, floats for calculations, not for printing.
  */

  // Degrees to radians and gradians:
  {
    printf("\n");
    printf(" # | Deg | Rad | Grad\n");
    printf("---+-----+-----+-----\n");
    TFloat Angle_Deg = 0.0;
    for (TUint_1 Iteration = 1; Iteration <= 13; ++Iteration)
    {
      printf(
        "%2u | %3d | %3d | %3d\n",
        Iteration,
        (TSint_2) Angle_Deg,
        (TSint_2) DegToRad(Angle_Deg),
        (TSint_2) DegToGrad(Angle_Deg)
      );
      Angle_Deg += 30.0;
    }
  }

  // Radians to degrees
  {
    printf("\n");
    printf(" # | Rad | Deg \n");
    printf("---+-----+-----\n");
    TFloat Angle_Rad = 0.0;
    for (TUint_1 Iteration = 1; Iteration <= 13; ++Iteration)
    {
      printf(
        "%2u | %3d | %3d\n",
        Iteration,
        (TSint_2) Angle_Rad,
        (TSint_2) RadToDeg(Angle_Rad)
      );
      Angle_Rad += M_PI / 6;
    }
  }

  // Gradians to degrees
  {
    printf("\n");
    printf(" # | Grad | Deg \n");
    printf("---+------+-----\n");
    TFloat Angle_Grad = 0.0;
    for (TUint_1 Iteration = 1; Iteration <= 13; ++Iteration)
    {
      printf(
        "%2u |  %3d | %3d\n",
        Iteration,
        (TSint_2) Angle_Grad,
        (TSint_2) GradToDeg(Angle_Grad)
      );
      Angle_Grad += 100.0 / 3;
    }
  }
}

void loop()
{
}

/*
  2024-05-17
*/
