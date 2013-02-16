#include "WPILib.h"

class SimpleAngle : public SimpleRobot {
	Joystick rightstick; // Initialize joystick class for right stick.


public:
	SimpleAngle(void):
	rightstick(2), // Right stick USB port.
		void OperatorControl(void) {
			while (IsOperatorControl) {
				SmartDashboard::PutNumber("X Gs", ADXL345_I2C::GetAcceleration(XAxis);
				SmartDashboard::PutNumber("Y Gs", ADXL345_I2C::GetAcceleration(YAxis));
				SmartDashboard::PutNumber("Z Gs", ADXL345_I2C::GetAcceleration(ZAxis));
				SmartDashboard::PutNumber("X Angle", arcsin(ADXL345_I2C::GetAcceleration(XAxis)));
				SmartDashboard::PutNumber("Y Angle", arcsin(ADXL345_I2C::GetAcceleration(YAxis)));
				SmartDashboard::PutNumber("Z Angle", arcsin(ADXL345_I2C::GetAcceleration(ZAxis)));

		}
	}
};

START_ROBOT_CLASS(SimpleAngle);