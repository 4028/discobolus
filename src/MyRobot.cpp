                                                                     
                                                                     
                                                                     
                                             
#include "WPILib.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
/**
 *(classes)users.wpi.edu/~bamiller/WPIRoboticsLibrary/d5/d77/class_joystick.html#3d460dce3eb9017fbc1b344cb4aaec82
 *(putNumber) http://www.virtualroadside.com/WPILib/class_smart_dashboard.html
 * (camera)http://wpilib.screenstepslive.com/s/3120/m/7912/l/80205-writing-a-simple-networktables-program-with-a-java-client-pc-side#!prettyPhoto
 */

class RobotDemo : public SimpleRobot
{		
	//RobotDrive myRobot; // robot drive system
	Joystick leftstick; //single stick driving
	Joystick rightstick; // shooting & climbing
	Jaguar feed_belt;
	Jaguar shoot_wheel_1; //first wheel of the shooter
	Jaguar shoot_wheel_2; //second wheel of the shooter
	
public:	
	RobotDemo(void):
		//myRobot(1, 2), //left motor, right motor
		leftstick(1), //usb port on driver station
		rightstick(2),
		feed_belt(3), //assumed slot, port 3
		shoot_wheel_1(4), //port 4
		shoot_wheel_2(5) //port 5
		//myRobot(1, 2),	// these must be initialized in the same order
// left motor, right motor for driving
		//feed_belt(4),		// digital module slot 2 (cRIO), port 3
		//leftstick(1),		// as they are declared above.
		//rightstick(2)
		//shoot_wheel_1(2, 4), // slot 2, port 4
		//shoot_wheel_2(2, 5)	// slot 2, port 5
	
		{
			//myRobot.SetExpiration(0.1);
		}
		

	
	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous(void)
	{
		
		//myRobot.SetSafetyEnabled(false);
		//myRobot.Drive(-0.5, 0.0); 	// drive forwards half speed
		//Wait(2.0); 				//    for 2 seconds
		//myRobot.Drive(0.0, 0.0); 	// stop robot
		
	}
	
	
	/**
	 *Runs the motors with arcade steering. 
	 */

	void OperatorControl(void)
	{
		//myRobot.SetSafetyEnabled(true);
		
		//driving
		double belt_speed = 0;
		bool prev_state_inc = 0;
		bool prev_state_dec = 0;
		//double count = 0;
		
		while (IsOperatorControl())
		{
			SmartDashboard::PutNumber("Left Stick X", leftstick.GetX());
			SmartDashboard::PutNumber("Left Stick Y", leftstick.GetY());
			
			// arcade drive style (use the single operating stick)
			//myRobot.ArcadeDrive(leftstick.GetX(), leftstick.GetY() * -1);
			//Wait(0.005);		// wait for a motor update time
			
			
			// hold trigger to slow down the robot
			// Trigger: right x = positive; down y = positive
			if (leftstick.GetTrigger())
			{
			
				//myRobot.ArcadeDrive(leftstick.GetX(), leftstick.GetY() * -0.5);
			}
			
			// shooting mechanism
			
			// belt, hold trigger
			 
			//double belt_speed;
			
			SmartDashboard:: PutNumber("Shoot wheel 1", 0.5 * (rightstick.GetThrottle() + 1));
			SmartDashboard:: PutNumber("Shoot wheel 2", 0.5 * (leftstick.GetThrottle() + 1));
			//need multitask here
			
			if (rightstick.GetThrottle())
			{
				shoot_wheel_1.Set(0.5 * (rightstick.GetThrottle() + 1));
			}
			
			if (leftstick.GetThrottle())
			{
				shoot_wheel_2.Set(0.5 * (leftstick.GetThrottle() + 1));
			}
			
			
			if (rightstick.GetRawButton(6))
			{
				belt_speed = 0;
			}
			
			if (rightstick.GetRawButton(11))
			{
				if (prev_state_inc == 0)
				{	
					belt_speed += 0.02;
					prev_state_inc = 1;
					//count ++;
				}
			}
			else
				prev_state_inc = 0;
				
			
			if (rightstick.GetRawButton(10))
			{
				if (prev_state_dec == 0)
				{
					belt_speed -= 0.02;
					prev_state_dec = 1;
				}
			}
			else 
			prev_state_dec = 0;
			
			if (belt_speed > 1)
			{
				belt_speed = 1;
			}
			
			if (belt_speed < 0)
			{
				belt_speed = 0;
			}
				
			SmartDashboard:: PutNumber("Belt Speed", belt_speed);
			feed_belt.Set(belt_speed);
			//SmartDashboard:: PutNumber("Count", count);
			/**if (rightstick.GetRawButton(4))
				// press and release trigger to start the belt
			{	
				
				feed_belt.Set(belt_speed);
				SmartDashboard:: GetNumber("Belt speed");
			}
			
			while (rightstick.GetRawButton(4) == 1)										
				{
					feed_belt.Drive(0, 0);		
					SmartDashboard:: GetNumber("Belt speed");
				}
				
				while (rightstick.GetRawButton(4) == 0)
				{
					feed_belt.Drive(0, 0);//belt_speed);	
					SmartDashboard:: GetNumber("Belt speed");
				}		
				
			}
			
			
			  /**to do: input value
			  multitask
			  */			  
			/**double motor1_speed;
			SmartDashboard:: PutNumber("Motor1 speed", motor1_speed);
			if (motor1_speed > 0 && rightstick.GetRawButton(3))
			{
				shoot_wheel_1.Drive(0, 0);//motor1_speed);
				SmartDashboard:: GetNumber("Motor1 speed");
			}
			
			double motor2_speed;
			  /** to do: input value
			   multitask
			   max motor 2 speed
			   */
			
			/**SmartDashboard:: PutNumber("Motor2 speed", motor2_speed);
			if (motor2_speed > 0 && rightstick.GetRawButton(5))
			{
				shoot_wheel_2.Drive(0, 0);//motor2_speed);
				SmartDashboard:: GetNumber("Motor2 speed");
			}   
				
			Wait (0.005); 		//wait for a motor update time
			
			
			*/
		}
	}
			
	/**
	 * Runs during test mode
	 */
	void Test() {

	}

};
START_ROBOT_CLASS(RobotDemo);