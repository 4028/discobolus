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
		shifter.Set(DoubleSolenoid::kForward);	
		Wait(2.0);
		shifter.Set(DoubleSolenoid::kReverse);
	}

	void OperatorControl(void)
	{	
		//some variables
		bool trigger = false;
		bool trigger_previous = false;
		int shifts = 0;
		
		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl())
		{
			//detect trigger button presses
			trigger_previous = trigger;
			trigger = stick.GetTrigger();
			
			//shift gears
			if (trigger and !trigger_previous)
			{
				if (shifter.Get() == DoubleSolenoid::kForward)
					shifter.Set(DoubleSolenoid::kReverse);
				else
					shifter.Set(DoubleSolenoid::kForward);
				
				++shifts;
			}
			
			//myRobot.ArcadeDrive(stick.GetX(), stick.GetY() * -1);
			myRobot.ArcadeDrive(.5, 0);
			
			SmartDashboard::PutNumber("shifts", shifts);
			
			Wait(.005);
		}
	}
	
	void Test()
	{
	}
};

START_ROBOT_CLASS(RobotDemo);

