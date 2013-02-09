#include "WPILib.h"

class RobotDemo : public SimpleRobot
{
	RobotDrive myRobot;
	Joystick stick;
	DoubleSolenoid shifter;
	Compressor compressor;

public:
	RobotDemo(void):
		myRobot(1, 2),
		stick(1),
		shifter(1, 2),
		compressor(1, 1)
	{
		myRobot.SetExpiration(0.1);
		compressor.Start();
	}

	void Autonomous(void)
	{
		//solenoid test
		shifter.Set(1);
		//SmartDashboard::PutBoolean("solenoid state", shifter.Get());	
		Wait(2.0);
		shifter.Set(-1);
		//SmartDashboard::PutBoolean("solenoid state", shifter.Get());
	}

	void OperatorControl(void)
	{
		//driving
		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl())
		{
			myRobot.ArcadeDrive(stick.GetX(), stick.GetY() * -1);
			Wait(0.005);
		}
	}
	
	void Test()
	{
	}
};

START_ROBOT_CLASS(RobotDemo);

