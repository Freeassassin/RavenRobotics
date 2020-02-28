/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*
  inertial::quaternion  Inertial_quaternion;
  Inertial.calibrate(); 
  while(1) {
      // get the quaternion data
      Inertial_quaternion = Inertial.orientation();

      Brain.Screen.clearScreen();        

      Brain.Screen.setFont( mono15 );
      Brain.Screen.setPenColor( white );
      Brain.Screen.setFillColor( black );
      
      Brain.Screen.printAt( 20,  30, "GX  %8.3f", Inertial.gyroRate( xaxis, dps ) );
      Brain.Screen.printAt( 20,  45, "GY  %8.3f", Inertial.gyroRate( yaxis, dps ) );
      Brain.Screen.printAt( 20,  60, "GZ  %8.3f", Inertial.gyroRate( zaxis, dps ) );

      Brain.Screen.printAt( 20,  90, "AX  %8.3f", Inertial.acceleration( xaxis ) );
      Brain.Screen.printAt( 20, 105, "AY  %8.3f", Inertial.acceleration( yaxis ) );
      Brain.Screen.printAt( 20, 120, "AZ  %8.3f", Inertial.acceleration( zaxis ) );

      Brain.Screen.printAt( 20, 150, "A   %8.3f", Inertial_quaternion.a );
      Brain.Screen.printAt( 20, 165, "B   %8.3f", Inertial_quaternion.b );
      Brain.Screen.printAt( 20, 180, "C   %8.3f", Inertial_quaternion.c );
      Brain.Screen.printAt( 20, 195, "D   %8.3f", Inertial_quaternion.d );

      Brain.Screen.printAt( 150, 30, "Roll     %7.2f", Inertial.roll() );
      Brain.Screen.printAt( 150, 45, "Pitch    %7.2f", Inertial.pitch() );
      Brain.Screen.printAt( 150, 60, "Yaw      %7.2f", Inertial.yaw() );

      Brain.Screen.printAt( 150, 90, "Heading  %7.2f", Inertial.heading() );
      Brain.Screen.printAt( 150,105, "Rotation %7.2f", Inertial.rotation() );

      if( Inertial.isCalibrating() )
        Brain.Screen.printAt( 20,225, "Calibration  In Progress" );
      else
        Brain.Screen.printAt( 20,225, "Calibration  Done" );

      Brain.Screen.render();

      // Allow other tasks to run
      this_thread::sleep_for(10);
  }
*/
// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <math.h>

using namespace vex;

vex::motor FrontR(PORT13,true); 
vex::motor FrontL(PORT3,false);
vex::motor BackR(PORT18,true);
vex::motor BackL(PORT1,false); 
vex::motor CollectorL(PORT10,false);
vex::motor CollectorR(PORT16,true);
vex::motor Tilter(PORT14, false);
vex::motor Arm(PORT11, false);


 
 

void move(int distance,int speed, bool collect = false, int tower = 0)
{ 
  if(tower == 0)
  {
    if(collect)
    {
      CollectorL.setVelocity(100, percentUnits::pct);
      CollectorR.setVelocity(100, percentUnits::pct);
      CollectorL.rotateFor((distance+3000), rotationUnits::deg, false);
      CollectorR.rotateFor((distance+3000), rotationUnits::deg, false);
    }
    Arm.rotateTo(-2200, rotationUnits::deg, 100, velocityUnits::pct,false);
    FrontL.setVelocity(speed, percentUnits::pct);
    FrontR.setVelocity(speed, percentUnits::pct);
    BackL.setVelocity(speed, percentUnits::pct);
    BackR.setVelocity(speed, percentUnits::pct);
    FrontL.rotateFor(distance, rotationUnits::deg, false);
    FrontR.rotateFor(distance, rotationUnits::deg, false);
    BackL.rotateFor(distance, rotationUnits::deg, false);
    BackR.rotateFor(distance, rotationUnits::deg, true);
    FrontL.setVelocity(0, percentUnits::pct);
    FrontR.setVelocity(0, percentUnits::pct);
    BackL.setVelocity(0, percentUnits::pct);
    BackR.setVelocity(0, percentUnits::pct);
  }
  else if(tower == 1)
  {
    if(collect)
    {
      CollectorL.setVelocity(100, percentUnits::pct);
      CollectorR.setVelocity(100, percentUnits::pct);
      CollectorL.rotateFor((distance+3000), rotationUnits::deg, false);
      CollectorR.rotateFor((distance+3000), rotationUnits::deg, false);
    }
    Arm.rotateTo(2200, rotationUnits::deg, 100, velocityUnits::pct,false);
    FrontL.setVelocity(speed, percentUnits::pct);
    FrontR.setVelocity(speed, percentUnits::pct);
    BackL.setVelocity(speed, percentUnits::pct);
    BackR.setVelocity(speed, percentUnits::pct);
    FrontL.rotateFor(distance, rotationUnits::deg, false);
    FrontR.rotateFor(distance, rotationUnits::deg, false);
    BackL.rotateFor(distance, rotationUnits::deg, false);
    BackR.rotateFor(distance, rotationUnits::deg, true);
    FrontL.setVelocity(0, percentUnits::pct);
    FrontR.setVelocity(0, percentUnits::pct);
    BackL.setVelocity(0, percentUnits::pct);
    BackR.setVelocity(0, percentUnits::pct);
  }
  else if(tower == 2)
  {
    if(collect)
    {
      CollectorL.setVelocity(100, percentUnits::pct);
      CollectorR.setVelocity(100, percentUnits::pct);
      CollectorL.rotateFor((distance+3000), rotationUnits::deg, false);
      CollectorR.rotateFor((distance+3000), rotationUnits::deg, false);
    }
    Arm.rotateTo(2900, rotationUnits::deg, 100, velocityUnits::pct,false);
    FrontL.setVelocity(speed, percentUnits::pct);
    FrontR.setVelocity(speed, percentUnits::pct);
    BackL.setVelocity(speed, percentUnits::pct);
    BackR.setVelocity(speed, percentUnits::pct);
    FrontL.rotateFor(distance, rotationUnits::deg, false);
    FrontR.rotateFor(distance, rotationUnits::deg, false);
    BackL.rotateFor(distance, rotationUnits::deg, false);
    BackR.rotateFor(distance, rotationUnits::deg, true);
    FrontL.setVelocity(0, percentUnits::pct);
    FrontR.setVelocity(0, percentUnits::pct);
    BackL.setVelocity(0, percentUnits::pct);
    BackR.setVelocity(0, percentUnits::pct);
  }
}



void moveT(int seconds,int speed, bool collect = false,int tower = 0)
{ 
  if (tower == 0)
  {
    if(collect)
    {
      CollectorL.setVelocity(100, percentUnits::pct);
      CollectorR.setVelocity(100, percentUnits::pct);
      CollectorL.spin(directionType::fwd);
      CollectorR.spin(directionType::fwd);  
    }
    Arm.rotateTo(0, rotationUnits::deg, 100, velocityUnits::pct,false); //change back to 0 when we run through
    FrontL.setVelocity(speed, percentUnits::pct);
    FrontR.setVelocity(speed, percentUnits::pct);
    BackL.setVelocity(speed, percentUnits::pct);
    BackR.setVelocity(speed, percentUnits::pct);
    FrontL.spin(directionType::fwd);  
    FrontR.spin(directionType::fwd);
    BackL.spin(directionType::fwd);
    BackR.spin(directionType::fwd);
    vexDelay(seconds);
    FrontL.stop();
    FrontR.stop();
    BackL.stop();
    BackR.stop();
    vexDelay(250);
    CollectorL.stop();
    CollectorR.stop();  
  }
  else if (tower == 1)
  {
    if(collect)
    {
      CollectorL.setVelocity(100, percentUnits::pct);
      CollectorR.setVelocity(100, percentUnits::pct);
      CollectorL.spin(directionType::fwd);
      CollectorR.spin(directionType::fwd);  
    }
    Arm.rotateTo(2200, rotationUnits::deg, 100, velocityUnits::pct,false);
    FrontL.setVelocity(speed, percentUnits::pct);
    FrontR.setVelocity(speed, percentUnits::pct);
    BackL.setVelocity(speed, percentUnits::pct);
    BackR.setVelocity(speed, percentUnits::pct);
    FrontL.spin(directionType::fwd);  
    FrontR.spin(directionType::fwd);
    BackL.spin(directionType::fwd);
    BackR.spin(directionType::fwd);
    vexDelay(seconds);
    FrontL.stop();
    FrontR.stop();
    BackL.stop();
    BackR.stop();
    vexDelay(250);
    CollectorL.stop();
    CollectorR.stop();  
  }
  else if (tower == 2)
  {
    if(collect)
    {
      CollectorL.setVelocity(100, percentUnits::pct);
      CollectorR.setVelocity(100, percentUnits::pct);
      CollectorL.spin(directionType::fwd);
      CollectorR.spin(directionType::fwd);  
    }
    Arm.rotateTo(2900, rotationUnits::deg, 100, velocityUnits::pct,false);
    FrontL.setVelocity(speed, percentUnits::pct);
    FrontR.setVelocity(speed, percentUnits::pct);
    BackL.setVelocity(speed, percentUnits::pct);
    BackR.setVelocity(speed, percentUnits::pct);
    FrontL.spin(directionType::fwd);  
    FrontR.spin(directionType::fwd);
    BackL.spin(directionType::fwd);
    BackR.spin(directionType::fwd);
    vexDelay(seconds);
    FrontL.stop();
    FrontR.stop();
    BackL.stop();
    BackR.stop();
    vexDelay(250);
    CollectorL.stop();
    CollectorR.stop();  
  }
}



void turn(int distance,int speed, bool collect = false)
{
  FrontL.setVelocity(speed, percentUnits::pct);
  FrontR.setVelocity(speed, percentUnits::pct);
  BackL.setVelocity(speed, percentUnits::pct);
  BackR.setVelocity(speed, percentUnits::pct);
  FrontL.rotateFor(distance, rotationUnits::deg, false);
  FrontR.rotateFor(-distance, rotationUnits::deg, false);
  BackL.rotateFor(distance, rotationUnits::deg, false);
  BackR.rotateFor(-distance, rotationUnits::deg, true); 
  if (collect){
    CollectorL.setVelocity(100, percentUnits::pct);
    CollectorR.setVelocity(100, percentUnits::pct);
    CollectorL.rotateFor((distance+3000), rotationUnits::deg, false);
    CollectorR.rotateFor((distance+3000), rotationUnits::deg, false);  
  } 
}



void strafe(int distance,int speed)
{
  FrontL.setVelocity(speed, percentUnits::pct);
  FrontR.setVelocity(speed, percentUnits::pct);
  BackL.setVelocity(speed, percentUnits::pct);
  BackR.setVelocity(speed, percentUnits::pct);
  FrontL.rotateFor(distance, rotationUnits::deg, false);
  FrontR.rotateFor(-distance, rotationUnits::deg, false);
  BackL.rotateFor(-distance, rotationUnits::deg, false);
  BackR.rotateFor(distance, rotationUnits::deg, true);  
}



void expand()
{
  Tilter.rotateTo(760, rotationUnits::deg, 100, velocityUnits::pct,true);
  Tilter.rotateTo(0, rotationUnits::deg, 100, velocityUnits::pct,false);
  vexDelay(300);
  CollectorL.setVelocity(90, percentUnits::pct);
  CollectorR.setVelocity(90, percentUnits::pct);
  CollectorL.rotateFor(800, rotationUnits::deg, false);
  CollectorR.rotateFor(800, rotationUnits::deg, false);
}



void Tower(bool Mid = false)
{
  if(Mid)
  {
    CollectorL.setVelocity(70, percentUnits::pct);
    CollectorR.setVelocity(70, percentUnits::pct);
    Arm.rotateTo(2900, rotationUnits::deg, 90, velocityUnits::pct,true);
    move(270,30,false,2);
    CollectorL.spin(directionType::rev);
    CollectorR.spin(directionType::rev);
    vexDelay(1000);
    CollectorL.stop();
    CollectorR.stop();
    CollectorL.setBrake(brakeType::hold);
    CollectorR.setBrake(brakeType::hold);
    move(-200,30,false,2);
  }
  else
  {
    CollectorL.setVelocity(70, percentUnits::pct);
    CollectorR.setVelocity(70, percentUnits::pct);
    Arm.rotateTo(2200, rotationUnits::deg, 90, velocityUnits::pct,true);
    move(130,30,false,1);
    CollectorL.spin(directionType::rev);
    CollectorR.spin(directionType::rev);
    vexDelay(1000);
    CollectorL.stop();
    CollectorR.stop();
    CollectorL.setBrake(brakeType::hold);
    CollectorR.setBrake(brakeType::hold);
    move(-140,30,false,1);
  }
}



void stack()
{
  double i = 0;
  // While loop because I was too lazy to look up for loop syntaxt
  while(i <18)
  {
    // Move the robot forward slightly based on an exponential function
    FrontL.setVelocity(-0.08*(pow(i,2))+25, percentUnits::pct);
    FrontR.setVelocity(-0.08*(pow(i,2))+25, percentUnits::pct);
    BackL.setVelocity(-0.08*(pow(i,2))+25, percentUnits::pct);
    BackR.setVelocity(-0.08*(pow(i,2))+25, percentUnits::pct);
    // Lift the storage tray to stack cubes that slows down based on an exponential function
    Tilter.setVelocity(-0.2*(pow(i,2))+90, percentUnits::pct);
    FrontL.spin(directionType::fwd);  
    FrontR.spin(directionType::fwd);
    BackL.spin(directionType::fwd);
    BackR.spin(directionType::fwd);
    Tilter.spin(directionType::fwd);
    // Keep every new speed for 145 miliseconds
    vexDelay(118);
    i += 1;   
 
  }
  // stop all movement 
  Tilter.stop();
  FrontL.stop();  
  FrontR.stop();
  BackL.stop();
  BackR.stop();
    
}

int main()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  
  expand();
  move(180,30,false,1);//1
  Tower();
  move(-180,20);

  turn(-190,25);//2
  strafe(-90,20);
  move(650,20,true);
  move(-630,20,true);
  strafe(-510,20);//3
  turn(10,30);//4
  move(620,20,true); 
  turn(630,30,true);


  moveT(3000,35);


  stack();
  
  CollectorL.setVelocity(100, percentUnits::pct);
  CollectorR.setVelocity(100, percentUnits::pct);   
  CollectorL.spin(directionType::rev);
  CollectorR.spin(directionType::rev);       
  vexDelay(100);
  CollectorL.setVelocity(0, percentUnits::pct);
  CollectorR.setVelocity(0, percentUnits::pct);


  move(-550,40);//5
  Tilter.rotateTo(0, rotationUnits::deg, 100, velocityUnits::pct,false);

  turn(730,30);
  move(450,30,true);
  move(-170,20);
  Tower(true);
  


  move(-270,15);
  turn(435,30);//6
  move(690,30,true);
  move(-112,15);
    
  Tower();





  Arm.rotateTo(0, rotationUnits::deg, 100, velocityUnits::pct,true);
  strafe(140,20);
  move(300,20,true);
  strafe(140,20);
  move(400,20,true);
  strafe(-70,20);
  move(1100,40,true);
  turn(300,30);
  moveT(1000,30);

  stack();

  CollectorL.setVelocity(100, percentUnits::pct);
  CollectorR.setVelocity(100, percentUnits::pct);   
  CollectorL.spin(directionType::rev);
  CollectorR.spin(directionType::rev);       
  vexDelay(100);
  CollectorL.setVelocity(0, percentUnits::pct);
  CollectorR.setVelocity(0, percentUnits::pct);
  move(-550,100);


}