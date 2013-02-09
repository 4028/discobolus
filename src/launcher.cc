#include "WPILib.h"
#include "math.h"

class ShooterDemo : public SimpleRobot {
	RobotDrive myRobot; // Robot drive system
	Joystick lstick; // Front wheel throttle.
	Joystick rstick; // Rear wheel throttle.
	Jaguar fwheel; // Front wheel.
	Jaguar rwheel; // Rear wheel.
public:
	ShooterDemo(void):
		lstick(1),
		rstick(2),
		fwheel(9), // Front wheel set to port 9 on Jaguar.
		rwheel(5), // Rear wheel set to port 5 on Jaguar.
	void OperatorControl(void) {
		bool fwstate = 0; // State of front wheel, off.
		bool rwstate = 0; // State of rear wheel, off.
		int fwdir = 1; // Direction of the front wheel.
		int rwdir = 1; // Direction of the rear wheel.
		
		while (IsOperatorControl())
		{
			SmartDashboard::PutNumber("Shoot wheel 1", 0.5 * (rightstick.GetThrottle() + 1));
			SmartDashboard::PutNumber("Shoot wheel 2", 0.5 * (leftstick.GetThrottle() + 1));
			if (rstick.GetThrottle()) {
				fwheel.Set(fwdir * 0.5 * (rstick.GetThrottle() + 1));
			}
			else if (lstick.GetThrottle()) {
				rwheel.Set(rwdir * 0.5 * (lstick.GetThrottle() + 1));
			}
		}
	}
}