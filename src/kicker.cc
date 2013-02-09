#include "WPILib.h"

class Kicker : public SimpleRobot {
	Joystick rstick; // Right stick for trigger.
	Jaguar kicker; // Create instance of Jaguar for kicker.
	DigitalInput swtch; /* Creates an instance of the digital input class
						   in order to get signals from the switch. Named
						   to avoid conflict with case-switch in C++. */
public:
	kicker (void):
		rstick (2), // set rightstick to the second USB port
		kicker(4), // set kicker motor to port 4 on jag.
	void OperatorControl(void) {
		bool state; // State of kicker. true means kicker is currently pushing, false means kicker is in home position.
		
		while (IsOperatorControl()) {
			SmartDashboard::PutNumber("Switch", swtch.Get()) // Output 1 or 0 to SmartDashboard depending on the state of the switch.
			if (rstick.GetTrigger()) {
				state = false;
			}
			if (state == false) {
				kicker.Set(0.5); // Subject to future change.
				if (swtch.Get() == 0) { // Switch is no longer pressed by kicker.
					state == true;
				}
			}
			else if (swtch.Get() == 0) {
				kicker.Set(0.5); // Subject to future change.
			}
			else if (swtch.Get() == 1 && state == true) {
				kicker.Set(0); // Stop the kicker motor.
			}
		}
	}
}