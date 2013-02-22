#include <WPILib.h>

class AccTest : public SimpleRobot {
	ADXL345_I2C acc;
public:
	AccTest(void):
	acc(1, ADXL345_I2C::kRange_2G)
	{
	}
	void OperatorControl (void) {
		while(IsOperatorControl()) {
			SmartDashboard::PutNumber("X", acc.GetAcceleration(ADXL345_I2C::kAxis_X));
			SmartDashboard::PutNumber("Y", acc.GetAcceleration(ADXL345_I2C::kAxis_Y));
			SmartDashboard::PutNumber("Z", acc.GetAcceleration(ADXL345_I2C::kAxis_Z));
		}
	}
};

START_ROBOT_CLASS(AccTest);