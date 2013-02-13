#include "WPILib.h"
#include "math.h"

class SimpleShooter : public SimpleRobot {
	Jaguar fwheel;
	Jaguar rwheel;
public:
	SimpleShooter(void):
		fwheel(8),
		rwheel(9)
	void OperatorControl(void) {
		bool fwstate = 0;
		bool rwstate = 0;
		int fwdir = 1;
		int rwdir = 1;

		while (IsOperatorControl())
		{
			fwheel.Set(1.0);
			rwheel.Set(0.9);
		}
	}
};

START_ROBOT_CODE(SimpleShooter);