/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Raven Robotics                                            */
/*    Created:      Sat Nov 16 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
#include <math.h>

using namespace vex;

vex::controller Controller; 
vex::motor FrontR(PORT13,true); 
vex::motor FrontL(PORT3,false);
vex::motor BackR(PORT18,true);
vex::motor BackL(PORT1,false); 
vex::motor CollectorL(PORT19,false);
vex::motor CollectorR(PORT16,true);
vex::motor Tilter(PORT14, false);
vex::motor Arm(PORT11, false);

int  joystickY;
int  joystickX;
int  StrafeX; 
int  StrafeY;
bool tilting = false;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  FrontR.spin(directionType::fwd);
  FrontL.spin(directionType::fwd);
  BackR.spin(directionType::fwd);
  BackL.spin(directionType::fwd); 
  Arm.spin(directionType::fwd);
  Tilter.spin(directionType::fwd);
  FrontR.setVelocity(0, percentUnits::pct);
  FrontL.setVelocity(0, percentUnits::pct);
  BackR.setVelocity(0, percentUnits::pct);
  BackL.setVelocity(0, percentUnits::pct);
  CollectorL.setVelocity(90, percentUnits::pct);
  CollectorR.setVelocity(90, percentUnits::pct);
  Arm.setVelocity(0, percentUnits::pct);
  Tilter.setVelocity(0, percentUnits::pct);
/*
    FrontL.setVelocity(70, percentUnits::pct);
    FrontR.setVelocity(70, percentUnits::pct);
    BackL.setVelocity(70, percentUnits::pct);
    BackR.setVelocity(70, percentUnits::pct);
    vexDelay(500);
    FrontL.setVelocity(0, percentUnits::pct);
    FrontR.setVelocity(0, percentUnits::pct);
    BackL.setVelocity(0, percentUnits::pct);
    BackR.setVelocity(0, percentUnits::pct);
  double i = 0;
  // While loop because I was too lazy to look up for loop syntaxt
  while(i <18)
  {
    // Move the robot forward slightly based on an exponential function
    FrontL.setVelocity(-0.08*(pow(i,2))+20, percentUnits::pct);
    FrontR.setVelocity(-0.08*(pow(i,2))+20, percentUnits::pct);
    BackL.setVelocity(-0.08*(pow(i,2))+20, percentUnits::pct);
    BackR.setVelocity(-0.08*(pow(i,2))+20, percentUnits::pct);
    // Lift the storage tray to stack cubes that slows down based on an exponential function
    Tilter.setVelocity(-0.2*(pow(i,2))+65, percentUnits::pct);
    FrontL.spin(directionType::fwd);  
    FrontR.spin(directionType::fwd);
    BackL.spin(directionType::fwd);
    BackR.spin(directionType::fwd);
    Tilter.spin(directionType::fwd);
    // Keep every new speed for 145 miliseconds
    vexDelay(150);
    i += 1;    
  }
  // stop all movement 
  Tilter.stop();
  FrontL.stop();  
  FrontR.stop();
  BackL.stop();
  BackR.stop();
*/
  Tilter.rotateTo(700, rotationUnits::deg, 70, velocityUnits::pct,true);
  Tilter.rotateTo(0, rotationUnits::deg, 100, velocityUnits::pct,true);

  while(true)
  {
    vexDelay(100);
    joystickY = Controller.Axis3.position();
    joystickX = Controller.Axis4.position();
    StrafeX = Controller.Axis1.position();
    StrafeY = Controller.Axis2.position();

    FrontL.setVelocity(joystickY + joystickX/2, percentUnits::pct);
    FrontR.setVelocity(joystickY - joystickX/2, percentUnits::pct);
    BackL.setVelocity(joystickY + joystickX/2, percentUnits::pct);
    BackR.setVelocity(joystickY - joystickX/2, percentUnits::pct);
    
/*
Strafe 
    FrontL.setVelocity(joystickY + joystickX/2, percentUnits::pct);
    FrontR.setVelocity(joystickY - joystickX/2, percentUnits::pct);
    BackL.setVelocity(joystickY - joystickX/2, percentUnits::pct);
    BackR.setVelocity(joystickY + joystickX/2, percentUnits::pct);
*/
    if (Tilter.rotation(rotationUnits::deg) == 0)
    {
      tilting = false;
    }
    if( StrafeY != 0 and not tilting)
    {
      Tilter.setVelocity(StrafeY, percentUnits::pct);
    }
    else if(StrafeY == 0 and not tilting)
    {
      Tilter.setVelocity(0, percentUnits::pct);
      Tilter.setBrake(brakeType::hold); 
      Tilter.spin(directionType::fwd);
    }


    if (Controller.ButtonR1.pressing()) 
    {
      CollectorL.spin(directionType::fwd);
      CollectorR.spin(directionType::fwd);          
    }
    else if (Controller.ButtonL1.pressing()) 
    {
      CollectorL.spin(directionType::rev);
      CollectorR.spin(directionType::rev);
    }
    else 
    {
      CollectorL.stop();
      CollectorR.stop();
      CollectorL.setBrake(brakeType::hold);
      CollectorR.setBrake(brakeType::hold); 
    }
    if (Controller.ButtonR2.pressing())
    {
      FrontL.setVelocity(70, percentUnits::pct);
      FrontR.setVelocity(-70, percentUnits::pct);
      BackL.setVelocity(-70, percentUnits::pct);
      BackR.setVelocity(70, percentUnits::pct);
    }
    else if (Controller.ButtonL2.pressing())
    {
      FrontL.setVelocity(-70, percentUnits::pct);
      FrontR.setVelocity(70, percentUnits::pct);
      BackL.setVelocity(70, percentUnits::pct);
      BackR.setVelocity(-70, percentUnits::pct);
    }



    if(Controller.ButtonX.pressing())
    {
      Arm.setVelocity(70, percentUnits::pct);
      Arm.rotateFor(150, rotationUnits::deg, false);         
    }
    else if (Controller.ButtonB.pressing()) 
    {
      Arm.setVelocity(70, percentUnits::pct);
      Arm.rotateFor(-150, rotationUnits::deg, false);
    }
    if(Controller.ButtonA.pressing())
    {
      double i = 0;
      // While loop because I was too lazy to look up for loop syntaxt
      while(i <18)
      {
        // Move the robot forward slightly based on an exponential function

        // Lift the storage tray to stack cubes that slows down based on an exponential function
        Tilter.setVelocity(-0.2*(pow(i,2))+90, percentUnits::pct);
        // Keep every new speed for 145 miliseconds
        vexDelay(110);
        i += 1;
      }
    }
    if (Controller.ButtonY.pressing())
    {
      Tilter.rotateTo(0, rotationUnits::deg, 100, velocityUnits::pct,false);
      tilting = true;

    }



    if(Controller.ButtonRight.pressing())
    {
      Arm.rotateTo(2200, rotationUnits::deg, 100, velocityUnits::pct,false);
    }
    else if(Controller.ButtonUp.pressing())
    {
      Arm.rotateTo(2900, rotationUnits::deg, 100, velocityUnits::pct,false);
    }
    else if(Controller.ButtonDown.pressing()) 
    {
      Arm.rotateTo(0, rotationUnits::deg, 90, velocityUnits::pct,false);
    }
    else if (Controller.ButtonLeft.pressing())
    {
      Arm.rotateTo(1100, rotationUnits::deg, 100, velocityUnits::pct,false);
    }
  }
}