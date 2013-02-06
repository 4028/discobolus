#include "WPILib.h"

class Drive : public SimpleRobot {

	RobotDrive drive; // Robot drive class.
	Joystick leftstick; // Initialize joystick class for left stick.
	Joystick rightstick; // Initialize joystick class for right stick.
	
public:
	Drive(void):
	leftstick(1), // Left stick USB port.
	rightstick(2), // Right stick USB port.
	drive(1, 2) // Initialize drive class.
		
		void OperatorControl(void) {
			drive.SetSafetyEnabled(true);
			
			while (IsOperatorControl) {
				/* Update SmartDashboard with X and Y values. */
				SmartDashboard::PutNumber("Left Stick X", leftstick.GetX());
				SmartDashboard::PutNumber("Left Stick Y", leftstick.GetY());
				
				drive.ArcadeDrive(leftstick.GetX, rightstick.GetX); // Drive using X and Y coordinates supplied by joysticks.
				Wait(0.005); // Wait for motors to update.
			}
		}
}