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
int main() { 
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

/* red right */
  //expand(); //2800
  move(1400, 60, true);// +250
  move(-1075, 90,true);// +250 
  strafe(-850, 85); 
  turn(-83,70);
  moveX(800, 60, true);// +250
  //move(-550, 90);
  //vexDelay(150);
  turn(880, 80);
  //strafeX(1300, 90);
  //turn(850, 80);
  moveT(1400, 80);
  ScooperL.setVelocity(90, percentUnits::pct);
  ScooperR.setVelocity(90, percentUnits::pct);  
  ScooperR.spin(directionType::fwd);  
  ScooperL.spin(directionType::fwd);
  vexDelay(300);
  ScooperL.stop();
  ScooperR.stop();  
  stack(); //2880
  move(-500, 100);  
/*  red left
  move(1200, 60, true);// +250
  turn(550, 80);
  move(500, 60, true);// +250
  move(-1500, 60);
  turn(550, 80);
  move(300, 50, true);// +250
  turn(425, 80);
  strafe(-250, 50);
  move(300, 50);
  ScooperL.setVelocity(90, percentUnits::pct);
  ScooperR.setVelocity(90, percentUnits::pct);  
  ScooperR.spin(directionType::fwd);  
  ScooperL.spin(directionType::fwd);
  vexDelay(300);
  ScooperL.stop();
  ScooperR.stop();  
  stack(); //2880
  move(-500, 100);   
  */
}
