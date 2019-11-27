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
#include <math.h>
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

//The function for movement of the robot straight and collection of cubes 
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
  vexDelay(250);
  ScooperL.stop();
  ScooperR.stop();  
}
//The fucntion to orient the robot based on seconds and speed
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
//The fucntion to make the robot strafe(sideways) based on time and speed
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
//The function to fully expand the robot
void expand()
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
//The fucntion to Stack the Cubes
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
  double i = 0;
  while(i <18)
  {
    
    ArmL.setVelocity(-0.2*(pow(i,2))+70, percentUnits::pct);
    ArmR.setVelocity(-0.2*(pow(i,2))+70, percentUnits::pct);
    ArmL.spin(directionType::rev);
    ArmR.spin(directionType::rev);
    vexDelay(155);
    i += 1;    
  }
  ArmL.stop();
  ArmR.stop();
}
int main() { 
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // Expand the Robot
  //expand(); //2800

  move(1850, 60, true);
  move(1000, -90);
  strafe(1100, -70);
  move(1500, 60, true);
  move(600, -90,true);
  strafe(1300, 70);
  turn(1100, 70);
  move(1200, 70);
  stack(); //2880
  move(500, -100);



}
