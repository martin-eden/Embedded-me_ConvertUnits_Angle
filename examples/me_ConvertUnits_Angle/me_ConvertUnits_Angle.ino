// [me_ConvertUnits_Angle] test/demo

/*
  Author: Martin Eden
  Last mod.: 2025-08-22
*/

/*
  Code size

    2025-08-22 Code Mem
      6140 412
      3512 199 -- departed from printf()'s
*/

#include <me_ConvertUnits_Angle.h>

#include <me_BaseTypes.h>
#include <me_Console.h>

void setup()
{
  Console.Init();

  Console.Print("[me_ConvertUnits_Angle] Start");

  using namespace me_ConvertUnits_Angle;

  /*
    Sorry guys, Atmel's printf() doesn't support printing floats
    out of the box.

    vfprintf() documentation in "stdio.h" mentions it's possible
    by rebuilding but I hadn't figure it out how to achieve it.

    Anyway, floats for calculations, not for printing.
  */

  Console.Print("");

  // Degrees to radians and gradians:
  {
    Console.Print("  # |   Deg  |   Rad  |  Grad");
    Console.Print("----+--------+--------+-------");

    TFloat Angle_Deg = 0.0;
    for (TUint_1 Iteration = 1; Iteration <= 13; ++Iteration)
    {
      Console.Print(Iteration);
      Console.Write("|");
      Console.Print((TSint_2) Angle_Deg);
      Console.Write("|");
      Console.Print((TSint_2) DegToRad(Angle_Deg));
      Console.Write("|");
      Console.Print((TSint_2) DegToGrad(Angle_Deg));
      Console.EndLine();

      Angle_Deg += 30.0;
    }
  }

  Console.Print("");

  // Radians to degrees
  {
    Console.Print("  # |   Rad  |   Deg");
    Console.Print("----+--------+--------");

    TFloat Angle_Rad = 0.0;
    for (TUint_1 Iteration = 1; Iteration <= 13; ++Iteration)
    {
      Console.Print(Iteration);
      Console.Write("|");
      Console.Print((TSint_2) Angle_Rad);
      Console.Write("|");
      Console.Print((TSint_2) RadToDeg(Angle_Rad));
      Console.EndLine();

      Angle_Rad += M_PI / 6;
    }
  }

  Console.Print("");

  // Gradians to degrees
  {
    Console.Print("  # |  Grad  |  Deg");
    Console.Print("----+--------+--------");

    TFloat Angle_Grad = 0.0;
    for (TUint_1 Iteration = 1; Iteration <= 13; ++Iteration)
    {
      Console.Print(Iteration);
      Console.Write("|");
      Console.Print((TSint_2) Angle_Grad);
      Console.Write("|");
      Console.Print((TSint_2) GradToDeg(Angle_Grad));
      Console.EndLine();

      Angle_Grad += 100.0 / 3;
    }
  }

  Console.Print("");

  Console.Print("[me_ConvertUnits_Angle] Done");
}

void loop()
{
}

/*
  2024-05-17
  2025-08-22
*/
