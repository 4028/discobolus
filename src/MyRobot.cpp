#include "WPILib.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class RobotDemo : public SimpleRobot
{
	RobotDrive myRobot; // robot drive system
	Joystick leftstick; // only joystick
	Joystick rightstick;

public:
	RobotDemo(void):
		myRobot(1, 2),	// these must be initialized in the same order
		leftstick(1),		// as they are declared above.
		rightstick(2)
	{	
		myRobot.SetExpiration(0.1);
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous(void)
	{
		myRobot.SetSafetyEnabled(false);
		myRobot.Drive(-0.5, 0.0); 	// drive forwards half speed
		Wait(2.0); 				//    for 2 seconds
		myRobot.Drive(0.0, 0.0); 	// stop robot
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl(void)
	{
		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl())
		{
			//driving
			SmartDashboard::PutNumber("Left stick X", leftstick.GetX());
			SmartDashboard::PutNumber("Left stick Y", leftstick.GetY());
			SmartDashboard::PutNumber("Right stick X", rightstick.GetX());
			SmartDashboard::PutNumber("Right stick Y", rightstick.GetY());
			if (leftstick.GetTrigger())
			{
				myRobot.ArcadeDrive(leftstick.GetX(), leftstick.GetY() * -.5);
			}
			else
			{
				myRobot.ArcadeDrive(leftstick.GetX(), leftstick.GetY() * -1);
			}
			Wait(0.005);				// wait for a motor update time
		}
	}
	
	/**
	 * Runs during test mode
	 */
	void Test() {

	}
};

START_ROBOT_CLASS(RobotDemo);

