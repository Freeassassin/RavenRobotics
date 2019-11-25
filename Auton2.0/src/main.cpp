/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\farbo                                            */
/*    Created:      Sat Nov 23 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
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
  // define your global instances of motors and other devices here
  ArmL.setVelocity(40, percentUnits::pct);
  ArmR.setVelocity(40, percentUnits::pct);
  ArmR.spin(directionType::rev);  
  ArmL.spin(directionType::rev);
  vexDelay(2800);
  ArmL.stop();
  ArmR.stop();
  ArmL.setVelocity(40, percentUnits::pct);
  ArmR.setVelocity(40, percentUnits::pct);
  ArmR.spin(directionType::fwd);  
  ArmL.spin(directionType::fwd);
  vexDelay(2500);
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
/*
  LeftDriveF.spin(directionType::rev);  
  RightDriveF.spin(directionType::fwd);
  LeftDriveR.spin(directionType::fwd);
  RightDriveR.spin(directionType::rev);

  vexDelay(900);
  
  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop();

  LeftDriveF.spin(directionType::fwd);  
  RightDriveF.spin(directionType::fwd);
  LeftDriveR.spin(directionType::fwd);
  RightDriveR.spin(directionType::fwd);

  vexDelay(600);
  */
  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop();
  ScooperL.stop();
  ScooperR.stop();
  LeftDriveF.setVelocity(70, percentUnits::pct);
  RightDriveF.setVelocity(70, percentUnits::pct);
  LeftDriveR.setVelocity(70, percentUnits::pct);
  RightDriveR.setVelocity(70, percentUnits::pct);
 
  LeftDriveF.spin(directionType::fwd);  
  RightDriveF.spin(directionType::rev);
  LeftDriveR.spin(directionType::fwd);
  RightDriveR.spin(directionType::rev);
  
  vexDelay(1100);
  
  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop();
  
  LeftDriveF.spin(directionType::fwd);  
  RightDriveF.spin(directionType::rev);
  LeftDriveR.spin(directionType::rev);
  RightDriveR.spin(directionType::fwd); 

  vexDelay(930); 

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

  vexDelay(1400);

  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop(); 
  vexDelay(150);
  ScooperL.stop();
  ScooperR.stop();   


  ArmL.spin(directionType::rev);
  ArmR.spin(directionType::rev);
  vexDelay(3500);
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
  vexDelay(1000);

  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop();}

