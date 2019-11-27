/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\farbo                                            */
/*    Created:      Tue Nov 26 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <math.h>
using namespace vex;
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
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  LeftDriveF.spin(directionType::fwd);
  LeftDriveR.spin(directionType::fwd);
  RightDriveF.spin(directionType::fwd);
  RightDriveR.spin(directionType::fwd); 
  ScooperR.setVelocity(100, percentUnits::pct);
  ScooperL.setVelocity(100, percentUnits::pct);
  while (true)
  {
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
        
        ArmL.setVelocity(-0.2*(pow(i,2))+70, percentUnits::pct);
        ArmR.setVelocity(-0.2*(pow(i,2))+70, percentUnits::pct);
        ArmL.spin(directionType::rev);
        ArmR.spin(directionType::rev);
        vexDelay(122);
        i += 1;    
      }
      ArmL.stop();
      ArmR.stop();
    }
  }
}
