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
#include <math.h>
using namespace vex;
vex::controller Controller; 
//vex::brain       Brain;


// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
vex::motor RightDriveF(PORT8,false); 
vex::motor RightDriveR(PORT14,true);
vex::motor LeftDriveF(PORT1,true);
vex::motor LeftDriveR(PORT10,false); 
vex::motor ScooperL(PORT5,true);
vex::motor ScooperR(PORT2,false);
vex::motor ArmL(PORT9, true);
vex::motor ArmR(PORT11,false);
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
//The function for movement of the robot straight and collection of cubes 
void move(int distance,int speed, bool collect = false)
{ 
  if(collect)
  {
    ScooperL.setVelocity(90, percentUnits::pct);
    ScooperR.setVelocity(90, percentUnits::pct);
    ScooperL.rotateFor(-(distance+1300), rotationUnits::deg, false);
    ScooperR.rotateFor(-(distance+1300), rotationUnits::deg, false);
  }
  LeftDriveF.setVelocity(speed, percentUnits::pct);
  RightDriveF.setVelocity(speed, percentUnits::pct);
  LeftDriveR.setVelocity(speed, percentUnits::pct);
  RightDriveR.setVelocity(speed, percentUnits::pct);
  LeftDriveF.rotateFor(distance, rotationUnits::deg, false);
  RightDriveF.rotateFor(distance, rotationUnits::deg, false);
  LeftDriveR.rotateFor(distance, rotationUnits::deg, false);
  RightDriveR.rotateFor(distance, rotationUnits::deg, true);
  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop();

}
void moveX(int distance,int speed, bool collect = false)
{ 
  if(collect)
  {
    ScooperL.setVelocity(90, percentUnits::pct);
    ScooperR.setVelocity(90, percentUnits::pct);
    ScooperL.rotateFor(-(distance+900), rotationUnits::deg, false);
    ScooperR.rotateFor(-(distance+900), rotationUnits::deg, false);
  }
  LeftDriveF.setVelocity(speed, percentUnits::pct);
  RightDriveF.setVelocity(speed, percentUnits::pct);
  LeftDriveR.setVelocity(speed, percentUnits::pct);
  RightDriveR.setVelocity(speed, percentUnits::pct);
  LeftDriveF.rotateFor(distance, rotationUnits::deg, false);
  RightDriveF.rotateFor(distance, rotationUnits::deg, false);
  LeftDriveR.rotateFor(distance, rotationUnits::deg, false);
  RightDriveR.rotateFor(distance, rotationUnits::deg, true);
  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop();

}
void moveT(int seconds,int speed, bool collect = false)
{ 
  if(collect)
  {
    ScooperL.setVelocity(80, percentUnits::pct);
    ScooperR.setVelocity(80, percentUnits::pct);
    ScooperL.spin(directionType::rev);
    ScooperR.spin(directionType::rev);  
  }
  LeftDriveF.setVelocity(speed, percentUnits::pct);
  RightDriveF.setVelocity(speed, percentUnits::pct);
  LeftDriveR.setVelocity(speed, percentUnits::pct);
  RightDriveR.setVelocity(speed, percentUnits::pct);
  LeftDriveF.spin(directionType::fwd);  
  RightDriveF.spin(directionType::fwd);
  LeftDriveR.spin(directionType::fwd);
  RightDriveR.spin(directionType::fwd);
  vexDelay(seconds);
  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop();
  vexDelay(250);
  ScooperL.stop();
  ScooperR.stop();  
}
//The fucntion to orient the robot based on seconds and speed
void turn(int distance,int speed)
{
  LeftDriveF.setVelocity(speed, percentUnits::pct);
  RightDriveF.setVelocity(speed, percentUnits::pct);
  LeftDriveR.setVelocity(speed, percentUnits::pct);
  RightDriveR.setVelocity(speed, percentUnits::pct);
  LeftDriveF.rotateFor(distance, rotationUnits::deg, false);
  RightDriveF.rotateFor(-distance, rotationUnits::deg, false);
  LeftDriveR.rotateFor(distance, rotationUnits::deg, false);
  RightDriveR.rotateFor(-distance, rotationUnits::deg, true);  
}
//The fucntion to make the robot strafe(sideways) based on time and speed
void strafe(int distance,int speed)
{
  LeftDriveF.setVelocity(speed, percentUnits::pct);
  RightDriveF.setVelocity(speed, percentUnits::pct);
  LeftDriveR.setVelocity(speed, percentUnits::pct);
  RightDriveR.setVelocity(speed, percentUnits::pct);
  LeftDriveF.rotateFor(distance, rotationUnits::deg, false);
  RightDriveF.rotateFor(-distance, rotationUnits::deg, false);
  LeftDriveR.rotateFor(-distance, rotationUnits::deg, false);
  RightDriveR.rotateFor(distance, rotationUnits::deg, true);  
}
void strafeX(int distance,int speed)
{
  LeftDriveF.setVelocity(speed, percentUnits::pct);
  RightDriveF.setVelocity(speed, percentUnits::pct);
  LeftDriveR.setVelocity(speed-20,percentUnits::pct);
  RightDriveR.setVelocity(speed-20, percentUnits::pct);
  LeftDriveF.rotateFor(distance, rotationUnits::deg, false);
  RightDriveF.rotateFor(-distance, rotationUnits::deg, false);
  LeftDriveR.rotateFor(-distance+200, rotationUnits::deg, false);
  RightDriveR.rotateFor(distance-200, rotationUnits::deg, true);  
}
//The function to fully expand the robot
void expand()
{
  ArmL.setVelocity(90, percentUnits::pct);
  ArmR.setVelocity(90, percentUnits::pct);
  ArmR.spin(directionType::rev);  
  ArmL.spin(directionType::rev);
  vexDelay(1400);
  ArmL.stop();
  ArmR.stop();
  ArmL.setVelocity(100, percentUnits::pct);
  ArmR.setVelocity(100, percentUnits::pct);
  ArmR.spin(directionType::fwd);  
  ArmL.spin(directionType::fwd);
  vexDelay(1200);
  ArmL.stop();
  ArmR.stop();   
}
//The fucntion to Stack the Cubes
void stack()
{
  double i = 0;
  while(i <18)
  {
    LeftDriveF.setVelocity(-0.08*(pow(i,2))+20, percentUnits::pct);
    RightDriveF.setVelocity(-0.08*(pow(i,2))+20, percentUnits::pct);
    LeftDriveR.setVelocity(-0.08*(pow(i,2))+20, percentUnits::pct);
    RightDriveR.setVelocity(-0.08*(pow(i,2))+20, percentUnits::pct);
    ArmL.setVelocity(-0.2*(pow(i,2))+65, percentUnits::pct);
    ArmR.setVelocity(-0.2*(pow(i,2))+65, percentUnits::pct);
    LeftDriveF.spin(directionType::fwd);  
    RightDriveF.spin(directionType::fwd);
    LeftDriveR.spin(directionType::fwd);
    RightDriveR.spin(directionType::fwd);
    ArmL.spin(directionType::rev);
    ArmR.spin(directionType::rev);
    vexDelay(145);
    i += 1;    
  }
  ArmL.stop();
  ArmR.stop();
  LeftDriveF.stop();  
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop();
}
void pre_auton(void) 
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
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
/*
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
*/ 
  expand(); //2800
  move(1400, 60, true);// +250
  move(-1075, 90,true);// +250 
  strafe(-850, 85); 
  turn(-83,70);
  moveX(800, 60, true);// +250
  turn(880, 80);
  moveT(1400, 80);
  ScooperL.setVelocity(90, percentUnits::pct);
  ScooperR.setVelocity(90, percentUnits::pct);  
  ScooperR.spin(directionType::fwd);  
  ScooperL.spin(directionType::fwd);
  vexDelay(300);
  ScooperL.stop();
  ScooperR.stop();  
  stack(); //2610
  move(-500, 100); 
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

void usercontrol(void) 
{
  LeftDriveF.spin(directionType::fwd);
  LeftDriveR.spin(directionType::fwd);
  RightDriveF.spin(directionType::fwd);
  RightDriveR.spin(directionType::fwd); 
  ScooperR.setVelocity(100, percentUnits::pct);
  ScooperL.setVelocity(100, percentUnits::pct);  
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
    }else 
    {
      ArmL.spin(directionType::fwd);
      ArmR.spin(directionType::fwd);
    }






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
    if (Controller.ButtonUp.pressing())
    {
      double i = 0;
      while(i <18)
      {
        
        ArmL.setVelocity(-0.2*(pow(i,2))+65, percentUnits::pct);
        ArmR.setVelocity(-0.2*(pow(i,2))+65, percentUnits::pct);
        ArmL.spin(directionType::rev);
        ArmR.spin(directionType::rev);
        vexDelay(145);
        i += 1;    
      }
      ArmL.stop();
      ArmR.stop();
    }
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() 
{
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
