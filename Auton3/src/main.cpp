/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\farbo                                            */
/*    Created:      Mon Nov 25 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
vex::controller Controller; 
vex::motor RightDriveF(PORT8,false); 
vex::motor RightDriveR(PORT14,true);
vex::motor LeftDriveF(PORT1,true);
vex::motor LeftDriveR(PORT10,false); 
vex::motor ScooperL(PORT5,true);
vex::motor ScooperR(PORT2,false);
vex::motor ArmL(PORT9, true);
vex::motor ArmR(PORT11,false);

void move(int seconds,int speed, bool collect = false)
{ 
  if(collect)
  {
    ScooperL.setVelocity(90, percentUnits::pct);
    ScooperR.setVelocity(90, percentUnits::pct);
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
  vexDelay(200);
  ScooperL.stop();
  ScooperR.stop();  
}
void turn(int seconds,int speed)
{
  LeftDriveF.setVelocity(speed, percentUnits::pct);
  RightDriveF.setVelocity(speed, percentUnits::pct);
  LeftDriveR.setVelocity(speed, percentUnits::pct);
  RightDriveR.setVelocity(speed, percentUnits::pct);
  LeftDriveF.spin(directionType::fwd);  
  RightDriveF.spin(directionType::rev);
  LeftDriveR.spin(directionType::fwd);
  RightDriveR.spin(directionType::rev);
  vexDelay(seconds);
  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop();
}
void strafe(int seconds,int speed)
{
  LeftDriveF.setVelocity(speed, percentUnits::pct);
  RightDriveF.setVelocity(speed, percentUnits::pct);
  LeftDriveR.setVelocity(speed, percentUnits::pct);
  RightDriveR.setVelocity(speed, percentUnits::pct);
  LeftDriveF.spin(directionType::fwd);  
  RightDriveF.spin(directionType::rev);
  LeftDriveR.spin(directionType::rev);
  RightDriveR.spin(directionType::fwd);
  vexDelay(seconds);
  LeftDriveF.stop();
  RightDriveF.stop();
  LeftDriveR.stop();
  RightDriveR.stop();
}
void open()
{
  ArmL.setVelocity(90, percentUnits::pct);
  ArmR.setVelocity(90, percentUnits::pct);
  ArmR.spin(directionType::rev);  
  ArmL.spin(directionType::rev);
  vexDelay(1600);
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
void stack()
{
/*  
  ArmL.setVelocity(55, percentUnits::pct);
  ArmR.setVelocity(55, percentUnits::pct);
  ArmL.spin(directionType::rev);
  ArmR.spin(directionType::rev);
  vexDelay(2200);
  ArmL.stop();
  ArmR.stop();
*/
  int i = 0;
  while(i <50)
  {
    
    ArmL.setVelocity(-12*(i^2)+50, percentUnits::pct);
    ArmR.setVelocity(-12*(i^2)+50, percentUnits::pct);
    ArmL.spin(directionType::fwd);
    ArmR.spin(directionType::fwd);
    vexDelay(25);
    i +=1;    
  }
  ArmL.stop();
  ArmR.stop();
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  //open();
/*
  move(2300, 50, true);
  move(1100, -70);
  turn(1100, 70);
  move(1100, 80);
  stack();
  move(500, -100);
*/
/*
  move(2300, 50, true);
  move(1000, -90);
  strafe(1100, -70);
  move(1900, 50, true);
  move(800, -90);
  strafe(1300, 70);
  turn(1100, 70);
  move(900, 70);
  stack();
  move(500, -100);
*/
  //stack();

}
