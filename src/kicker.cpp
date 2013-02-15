#include "WPILib.h"

class Kicker : public SimpleRobot {
	Joystick rstick; // Right stick for trigger.
	Jaguar kicker; // Create instance of Jaguar for kicker.
	DigitalInput swtch; /* Creates an instance of the digital input class
						   in order to get signals from the switch. Named
						   to avoid conflict with case-switch in C++. */
public:
	Kicker (void):
		rstick (2), // set rightstick to the second USB port
		kicker(10) // set kicker motor to port 10 on jag.
	void OperatorControl(void) {
		bool state; // State of launcher. true means kicker is currently pushing, false means kicker is in home position.
		
		while (IsOperatorControl()) {
			SmartDashboard::PutNumber("Switch", swtch.Get()); // Output 1 or 0 to SmartDashboard depending on the state of the switch.
			if (rstick.GetTrigger()) {
				state = false;
			}
			if (state == false) {
				kicker.Set(1.0);
				if (swtch.Get() == 1) { // Switch is no longer pressed by kicker.
					state == true;
				}
			}
			else if (swtch.Get() == 1) {
				kicker.Set(1.0);
			}
			else if (swtch.Get() == 0 && state == true) {
				kicker.Set(0); // Stop the kicker motor.
			}
		}
	}
};

START_ROBOT_CLASS(Kicker);