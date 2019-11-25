/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
vex::controller Controller; 
//vex::brain       Brain;

// define your global instances of motors and other devices here
vex::motor RightDriveF(PORT8,false); 
vex::motor RightDriveR(PORT14,true);
vex::motor LeftDriveF(PORT1,true);
vex::motor LeftDriveR(PORT10,false); 
vex::motor ScooperL(PORT5,true);
vex::motor ScooperR(PORT2,false);
vex::motor ArmL(PORT9, true);
vex::motor ArmR(PORT11,false);
// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

//vex::brain       Brain;
vex::controller Controller; 
// define your global instances of motors and other devices here
vex::motor RightDriveF(PORT8,false); 
vex::motor RightDriveR(PORT14,true);
vex::motor LeftDriveF(PORT1,true);
vex::motor LeftDriveR(PORT10,false); 
vex::motor ScooperL(PORT5,true);
vex::motor ScooperR(PORT2,false);
vex::motor ArmL(PORT9, true);
vex::motor ArmR(PORT11,false);
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) 
{
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  ArmL.setVelocity(50, percentUnits::pct);
  ArmR.setVelocity(50, percentUnits::pct);
  ArmR.spin(directionType::rev);  
  ArmL.spin(directionType::rev);
  vexDelay(2400);
  ArmL.stop();
  ArmR.stop();
  ArmL.setVelocity(60, percentUnits::pct);
  ArmR.setVelocity(60, percentUnits::pct);
  ArmR.spin(directionType::fwd);  
  ArmL.spin(directionType::fwd);
  vexDelay(2000);
  ArmL.stop();
  ArmR.stop();

  LeftDriveF.setVelocity(50, percentUnits::pct);
  RightDriveF.setVelocity(50, percentUnits::pct);
  LeftDriveR.setVelocity(50, percentUnits::pct);
  RightDriveR.setVelocity(50, percentUnits::pct);
  ScooperL.setVelocity(90, percentUnits::pct);
  ScooperR.setVelocity(90, percentUnits::pct); 
  LeftDriveF.spin(directionType::fwd);  
  RightDriveF.spin(directionType::fwd);
  LeftDriveR.spin(directionType::fwd);
  RightDriveR.spin(directionType::fwd);
  ScooperL.spin(directionType::rev);
  ScooperR.spin(directionType::rev);

  vexDelay(2300);

  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop();
  vexDelay(150);
  ScooperL.stop();
  ScooperR.stop();
  LeftDriveF.setVelocity(70, percentUnits::pct);
  RightDriveF.setVelocity(70, percentUnits::pct);
  LeftDriveR.setVelocity(70, percentUnits::pct);
  RightDriveR.setVelocity(70, percentUnits::pct);
 
  LeftDriveF.spin(directionType::rev);  
  RightDriveF.spin(directionType::rev);
  LeftDriveR.spin(directionType::rev);
  RightDriveR.spin(directionType::rev);
  
  vexDelay(1100);
  
  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop();
  
  LeftDriveF.spin(directionType::fwd);  
  RightDriveF.spin(directionType::rev);
  LeftDriveR.spin(directionType::fwd);
  RightDriveR.spin(directionType::rev); 

  vexDelay(1100); 

  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop(); 

  LeftDriveF.setVelocity(80, percentUnits::pct);
  RightDriveF.setVelocity(80, percentUnits::pct);
  LeftDriveR.setVelocity(80, percentUnits::pct);
  RightDriveR.setVelocity(80, percentUnits::pct);
  LeftDriveF.spin(directionType::fwd);  
  RightDriveF.spin(directionType::fwd);
  LeftDriveR.spin(directionType::fwd);
  RightDriveR.spin(directionType::fwd);

  vexDelay(1200);

  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop(); 
  vexDelay(150);
  ScooperL.stop();
  ScooperR.stop();   

  ArmL.setVelocity(68, percentUnits::pct);
  ArmR.setVelocity(68, percentUnits::pct);
  ArmL.spin(directionType::rev);
  ArmR.spin(directionType::rev);
  vexDelay(2000);
  ArmL.stop();
  ArmR.stop();
  LeftDriveF.setVelocity(10, percentUnits::pct);
  RightDriveF.setVelocity(10, percentUnits::pct);
  LeftDriveF.spin(directionType::fwd);  
  RightDriveF.spin(directionType::fwd);
  vexDelay(300);
  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveF.setVelocity(100, percentUnits::pct);
  RightDriveF.setVelocity(100, percentUnits::pct);
  LeftDriveR.setVelocity(100, percentUnits::pct);
  RightDriveR.setVelocity(100, percentUnits::pct);  
  LeftDriveF.spin(directionType::rev);
  LeftDriveR.spin(directionType::rev);
  RightDriveF.spin(directionType::rev);
  RightDriveR.spin(directionType::rev);
  vexDelay(500);

  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop();
 
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (true)
  {
    vexDelay(100);
  int  joystickY = Controller.Axis3.position();
  int  joystickX = Controller.Axis4.position();
  int  StrafeX = Controller.Axis1.position();
  int  StrafeY = Controller.Axis2.position();

   

    if ( StrafeX !=0)
    {
     
      LeftDriveF.setVelocity(StrafeX , percentUnits::pct);
      RightDriveF.setVelocity(-StrafeX, percentUnits::pct);
      LeftDriveR.setVelocity(-StrafeX, percentUnits::pct);
      RightDriveR.setVelocity(StrafeX, percentUnits::pct);      
    }
    else
    {

      LeftDriveF.setVelocity(joystickY + joystickX/2, percentUnits::pct);
      RightDriveF.setVelocity(joystickY -joystickX/2, percentUnits::pct);
      LeftDriveR.setVelocity(joystickY + joystickX/2, percentUnits::pct);
      RightDriveR.setVelocity(joystickY -joystickX/2 , percentUnits::pct);
    }


    ArmL.setVelocity(-StrafeY, percentUnits::pct);
    ArmR.setVelocity(-StrafeY, percentUnits::pct);
    if(StrafeY ==0)
    {
        ArmL.stop();
        ArmR.stop();
         ArmL.setBrake(brakeType::hold);
        ArmR.setBrake(brakeType::hold);     
    }else {
      ArmL.spin(directionType::fwd);
     ArmR.spin(directionType::fwd);
    }





/*
    //Arm Controls
    if (Controller.ButtonDown.pressing())
    {
        ArmL.spin(directionType::fwd);
        ArmR.spin(directionType::fwd);
        vexDelay(100);
    }
    else if (Controller.ButtonUp.pressing())
    {
        ArmL.spin(directionType::rev);
        ArmR.spin(directionType::rev);
        vexDelay(200);
    }
    else
    {
        ArmL.stop();
        ArmR.stop();
        ArmL.setBrake(brakeType::hold);
        ArmR.setBrake(brakeType::hold);
        
        
    }
*/
    //Collecter Controls
    if (Controller.ButtonR1.pressing())
    {

      ScooperL.spin(directionType::rev);
      ScooperR.spin(directionType::rev);
      
    }
    else if (Controller.ButtonR2.pressing())
    {

      ScooperL.spin(directionType::fwd);
      ScooperR.spin(directionType::fwd);
    }
    else
    {

      ScooperL.stop();
      ScooperR.stop();
    }
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
