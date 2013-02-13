#include "WPILib.h"
class Angle : public SimpleRobot
{
	Gyro gyro;

public:
	Angle(void):
		gyro(1)
	{
	}
	void Autonomous(void)
	{	gyro.Reset();
		while (IsAutonomous())
		{
			float angle = gyro.GetAngle(); // current heading (0 = target)
			SmartDashboard::PutNumber("Gyro Angle", angle); // Output angle to SmartDashboard
		}
	}
};

START_ROBOT_CLASS(Angle);
