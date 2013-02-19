#include "WPILib.h"


/**
 * This is the main code file for The Beak Squad (FRC Team 4028) for the 2013 season
 *
 * Functionality currently integrated:
 * - Arcade Drive
 * - Solenoid Shifting
 * - Shooter & Kicker
 * - Lifter
 * 
 * Functionality yet to integrate:
 * - Accelerometer
 * - Camera & Driver Station Video
 * - Smart Dashboard
 *
 */

class Discobolus : public SimpleRobot {
	RobotDrive myRobot;			// robot drive system
	Joystick lstick;			// lstick is the Left Joystick, the Driver's Stick
	Joystick rstick;			// rstick is the Right Joystick, the Operator's Stick
	Compressor compressor;		// guess what the compressor is called?
	DoubleSolenoid shifter;		// shifter is the solenoid that controls high/low gear state
	Jaguar lifter;				// lifter controls the lead screw which controls the angle of the shooter
	Jaguar kicker;				//  controls the kicker mechanism for pushing discs to the shooter wheels
	DigitalInput swtch;			// Limit switch that determines kicker home position
	Jaguar shooter_front;		// Controls shooter front wheel
	Jaguar shooter_rear;		// Controls shooter rear wheel

	static const double shooter_front_speed = -1.0;		// Shooter Front Wheel runs at 100%
	static const double shooter_rear_speed = 0.9;		// Shooter Rear Wheel runs at 90%

public:
	Discobolus(void) :
		myRobot(1, 2), 				// these must be initialized in the same order
				lstick(1), 			// leftstick
				rstick(2), 			// rightstick 
				compressor(1, 1),	// necessary to run the compressor when attached
				shifter(1, 2), 		// Double Solenoid on Digital ports #1&2
				lifter(7), 			// Lead Screw is assigned to cRIO port #7
				kicker(10), 		// kicker motor is assigned to port #10
				swtch(14), 			// set switch to digital port #14 (senses when kicker is in home position)
				shooter_front(8), 	// Front Shooter Wheel is assigned to port #8
				shooter_rear(9) 	// Rear Shooter Wheel is assigned to port #9
				
	{
		/* Initialization of objects */
		myRobot.SetExpiration(0.1); 		// Drive motors will time out if not receiving a signal 
		compressor.Start(); 				// Runs the compressor
		shifter.Set(DoubleSolenoid::kForward); 	// Set default for shifter solenoid (high gear)
	}

	void Autonomous(void) {
/* 
 * Autonomous Code
 **/
	}

	
	void OperatorControl(void) {
/* 
 * Teleop Code
 **/

		/* initialize local variables */
		bool trigger = false; 				// 
		bool trigger_previous = false; 		// 
		myRobot.SetSafetyEnabled(true); 	// ??
		bool swtch_lag = false; 			// lagging value of swtch
		bool trigger_lag = false;			// lagging value of trigger
		bool b4_lag = false;				// lagging value of button 4
		int shot_count = 0; 				// shot_count:  1 = single fire, 4 = auto fire

/* main functions */
		while (IsOperatorControl()) {
			/****TEST AND THEN DELETE *****/			
			/*Shooter functions */

			//Check if fire buttons are pressed and assign shot_count
			if (rstick.GetTrigger() && !trigger_lag) {
				// if trigger is newly pressed, initiate auto-fire
					shot_count = 4;				// tell the shooter to shoot 4 discs
					//swtch_lag = false;			// pretend that the switch is not pressed
			} else if (rstick.GetRawButton(4) && !b4_lag) {
				// if button 4 is newly pressed, initiate single fire
				shot_count = 1;					// tell the shooter to shoot 1 disc
				//swtch_lag = false;				// pretend the switch is not pressed
			}
			trigger_lag = rstick.GetTrigger();	// update trigger lagger
			b4_lag = rstick.GetRawButton(4);	// update button 4 lagger
			kicker_fire(swtch_lag, shot_count);	// 

			//Only execute kicker_fire() when shot_count > 0
//			switch (shot_count) {
//			case 1:
//			case 2:
//			case 3:
//			case 4:
//				kicker_fire(swtch_lag, shot_count);
//				break;
//			default:
//				break;
//			};

			/* shooter wheels */
			shooter_control();

			/* Drive functions */
			drive_robot();								// Control robot drive (movement) 
			shift_gears(trigger, trigger_previous);		// shift gears

			/* Lifter function */
			move_lifter();

			/*Display to SmartDashboard  */
//			display_dashboard();
		}
	}

/* integrated operations */
	void drive_robot() // Variables declared globally, no need to pass parameters
	{
		myRobot.ArcadeDrive(lstick.GetY(), lstick.GetX()); // drive with arcade style (using right stick)
		Wait(0.005); 									// wait for a motor update time 	[purpose??]
	}

	void shift_gears(bool &trigger, bool &trigger_previous) {
		trigger_previous = trigger; 			// updates lagging state
		trigger = lstick.GetTrigger(); 			// updates current state

		/* shift gears */
		if (trigger and !trigger_previous) {	// if trigger is newly pressed
			if (shifter.Get() == DoubleSolenoid::kForward)	// switch the state of the solenoid
				shifter.Set(DoubleSolenoid::kReverse);
			else
				shifter.Set(DoubleSolenoid::kForward);
		}										
		Wait(.005); // wait					[purpose??]
	}

	void move_lifter() {
		/* Use right joystick to adjust lifter height manually
		 * push forward = lower lifter angle
		 * sensitivity is set by the throttle and acts as a multiplier
		 * (throttle returns a value between 0.2 and 1)
		 **/
		lifter.Set(rstick.GetY() * -1 * ((rstick.GetThrottle() + 1.5) / 2.5)); //Use joystick to adjust lifter angle	
	}

	void kicker_fire(bool &swtch_lag, int &shot_count) {

		if (shot_count >= 1)
			kicker.Set(1.0);

		if (swtch.Get() && !swtch_lag) {
		// if swtch is newly pressed 
			shot_count--;
			if (shot_count <= 0)	// if there are no more shots to spend	
				kicker.Set(0);		// stop the kicker
		}
		swtch_lag = swtch.Get();	

		}

	void shooter_control() {
		if (rstick.GetRawButton(3)) {
			shooter_front.Set(shooter_front_speed);
			shooter_rear.Set(shooter_rear_speed);
		}

		if (rstick.GetRawButton(2)) {
			shooter_front.Set(0);
			shooter_rear.Set(0);
		}
	}

	void display_dashboard() {

		SmartDashboard::PutNumber("Left Stick X", lstick.GetX()); //X-direction rotation speed based on joystick
		SmartDashboard::PutNumber("Left Stick Y", lstick.GetY()); //Y-direction speedvalue based on joystick
		SmartDashboard::PutNumber("Right Stick Y", rstick.GetY()); //Display Lifter speed based on right Joystick movement
		SmartDashboard::PutNumber("Switch", swtch.Get());
		

	}

};

START_ROBOT_CLASS(Discobolus);
