#include "WPILib.h"

class Launcher : public SimpleRobot {
	Jaguar fwheel; // Create Jaguar instance for the front wheel.
	Jaguar rwheel; // Creat Jaguar instance for the rear wheel.
public:
	Launcher(void):
    fwheel(8), // Set front wheel to port 8 on Jaguar.
    rwheel(9) // Set rear wheel to port 9 on Jaguar.
	{}
	void OperatorControl(void) {
		while (IsOperatorControl())
		{
			fwheel.Set(1.0); // Set one motor to full capacity.
			rwheel.Set(0.9); // Set one motor to 90% capacity.
		}
	}
};

START_ROBOT_CLASS(Launcher);
