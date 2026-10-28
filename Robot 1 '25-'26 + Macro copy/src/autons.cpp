#include "main.h"
#include "EZ-Template/util.hpp"
#include "autons.hpp"
#include "globals.hpp"
#include "pros/rtos.hpp"
#include "subsystems.hpp"

void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backward
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered) {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If the robot successfully drove back, return
    else {
      return;
    }
  }
}
void drive(int distance, int speed) {
  chassis.pid_drive_set(distance, speed);
  chassis.pid_wait();
}
void mcdrive(int distance, int speed) {
  chassis.pid_drive_set(distance, speed);
  chassis.pid_wait_quick_chain();
}
void turn(int degrees, int speed) {
  chassis.pid_turn_set(degrees, speed);
  chassis.pid_wait();
}
void mcturn(int degrees, int speed) {
  chassis.pid_turn_set(degrees, speed);
  chassis.pid_wait_quick_chain();
}
void Rmcswing(int degrees, int speedfirst, int speedsecond) {
  chassis.pid_swing_set(ez::RIGHT_SWING, degrees, speedfirst, speedsecond);
  chassis.pid_wait_quick_chain();
}
void Rswing(int degrees, int speedfirst, int speedsecond) {
  chassis.pid_swing_set(ez::RIGHT_SWING, degrees, speedfirst, speedsecond);
  chassis.pid_wait();
}
void Lmcswing(int degrees, int speedfirst, int speedsecond) {
  chassis.pid_swing_set(ez::LEFT_SWING, degrees, speedfirst, speedsecond);
  chassis.pid_wait_quick_chain();
}
void Lswing(int degrees, int speedfirst, int speedsecond) {
  chassis.pid_swing_set(ez::LEFT_SWING, degrees, speedfirst, speedsecond);
  chassis.pid_wait();
}

void topIntake() {
  First.move(127);
  Middle.move(-127);
  Top.move(-127);
  // Hood.set_value(true);
}
void inStop() {
  First.move(0);
  Middle.move(0);
  Top.move(0);
}
void outake() {
  First.move(-127);
  Middle.move(127);
  Top.move(127);
  // Hood.set_value(false);
}
void middle() {
  First.move(127);
  Middle.move(-127);
  Top.move(127);
}


/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 110;



//------------------------------Rush's----------------------------------//
void LRush9() {
  topIntake();
  mcdrive(24,127);
  Load.set_value(true);
  mcturn(-90,127);
  mcdrive(5,83);
  mcdrive(2,55);
  // mcdrive(1,50);
  pros::delay(370);
  chassis.pid_drive_set(-32,120);
  chassis.pid_wait_until(-25);
  Hood.set_value(true);
  Load.set_value(false);
  pros::delay(200);
  chassis.pid_wait_quick_chain();
  // Hood.set_value(false);
  mcdrive(7,127);
  mcturn(143,127);
  Hood.set_value(false);
  chassis.pid_drive_set(35,120);
  chassis.pid_wait_until(13);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  mcturn(45,127);
  Load.set_value(false);
  mcdrive(10,115);
  chassis.pid_swing_set(ez::RIGHT_SWING, 2_deg, SWING_SPEED, 15);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(8,120);
  chassis.pid_wait_until(5);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-10,127);
  chassis.pid_wait_until(-3);
  Load.set_value(false);
  chassis.pid_wait_quick_chain();  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, -SWING_SPEED, -50);
  chassis.pid_wait_quick_chain();
  mcdrive(-11,120);
  mcturn(-45,127);
  mcdrive(-12,127);
  outake();
  pros::delay(75);
  First.move(127);
  Middle.move(-70);
  Top.move(70);

}
void RRush9() {
  // Hood.set_value(true);
  topIntake();
  chassis.pid_drive_set(30_in, 60);
  chassis.pid_wait_until(26);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  chassis.pid_swing_set(ez::LEFT_SWING, 29_deg, SWING_SPEED, 5);
  chassis.pid_wait_quick_chain();
  Load.set_value(false);
  chassis.pid_drive_set(14.4_in, 90);
  chassis.pid_wait_until(7);
  Load.set_value(true);
  pros::delay(75);
  chassis.pid_wait();
  chassis.pid_drive_set(-24_in, 90);
  chassis.pid_wait();
  Load.set_value(false);
  chassis.pid_drive_set(15_in, 60);
  chassis.pid_wait();
  chassis.pid_drive_set(-16_in, 60);
  chassis.pid_wait();
  chassis.pid_turn_set(-77,127); //70
  chassis.pid_wait();
  chassis.pid_drive_set(-39_in, 90); //44.5
  chassis.pid_wait();
  chassis.pid_turn_set(-209,127);
  chassis.pid_wait();
  chassis.pid_drive_set(-21, 80); //-23.5
  chassis.pid_wait_until(-13);
  chassis.pid_speed_max_set(50);
  Hood.set_value(true);
  Load.set_value(true);
  pros::delay(1500);
  chassis.pid_wait();
  Hood.set_value(false);
  chassis.pid_turn_set(-210,127);
  chassis.pid_wait();
  chassis.pid_drive_set(33_in, 70);
  chassis.pid_wait_until(16);
  chassis.pid_speed_max_set(30);
  chassis.pid_wait();
  pros::delay(125);
  chassis.pid_drive_set(-29_in, 70);
  chassis.pid_wait_until(-25);
  Load.set_value(false);
  Hood.set_value(true);
  pros::delay(1150);
  Hood.set_value(false);
}

//-----------------------------Quals----------------------------------//
void RQuals() {

  turn(90,127);


  // pros::delay(10000000000000000000);
  // topIntake();
  // chassis.pid_drive_set(30_in, 60);
  // chassis.pid_wait_until(26);
  // Load.set_value(true);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_swing_set(ez::LEFT_SWING, 29_deg, SWING_SPEED, 5);
  // chassis.pid_wait_quick_chain();
  // Load.set_value(false);
  // chassis.pid_drive_set(14.4_in, 90);
  // chassis.pid_wait_until(7);
  // Load.set_value(true);
  // pros::delay(75);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-24_in, 90);
  // chassis.pid_wait();
  // Load.set_value(false);
  // chassis.pid_drive_set(15_in, 40);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-9.8_in, 40);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_turn_set(-80,127);
  // chassis.pid_wait();
  // chassis.pid_drive_set(10_in, 60);
  // chassis.pid_wait_quick_chain();
  // First.move(-90);
  // Middle.move(127);
  // Top.move(127);
  // pros::delay(1350);
  // Hood.set_value(false);
  // inStop();
  // chassis.pid_wait();
  // topIntake();
  // chassis.pid_drive_set(-49_in, 88);
  // chassis.pid_wait_until(32);
  // chassis.pid_speed_max_set(60);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_turn_set(147,127);
  // Load.set_value(true);
  // chassis.pid_wait();
  // topIntake();
  // Hood.set_value(false);
  // chassis.pid_drive_set(18.5_in, 40);
  // chassis.pid_wait();
  // pros::delay(150);
  // chassis.pid_drive_set(-29_in, 60);
  // chassis.pid_wait_until(-25);
  // Hood.set_value(true);
  // pros::delay(400);
  // outake();
  // pros::delay(100);
  // topIntake();
  // pros::delay(1500);
  // Hood.set_value(false);

}
void LQuals() {
  // Hood.set_value(true);
  topIntake();
  chassis.pid_drive_set(30_in, 60);
  chassis.pid_wait_until(26);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  chassis.pid_swing_set(ez::RIGHT_SWING, -29_deg, SWING_SPEED, 5);
  chassis.pid_wait_quick_chain();
  Load.set_value(false);
  chassis.pid_drive_set(14.4_in, 90);
  chassis.pid_wait_until(7);
  Load.set_value(true);
  pros::delay(75);
  chassis.pid_wait();
  chassis.pid_drive_set(-24_in, 90);
  chassis.pid_wait();
  Load.set_value(false);
  chassis.pid_drive_set(15_in, 40);
  chassis.pid_wait();
  chassis.pid_drive_set(-10.5_in, 40);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(-98,127);
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, 60);
  chassis.pid_wait_quick_chain();
  outake();
  pros::delay(350);
  middle();
  pros::delay(725);
  Hood.set_value(false);
  inStop();
  chassis.pid_wait();
  chassis.pid_drive_set(43_in, 80);
  chassis.pid_wait_until(32);
  chassis.pid_speed_max_set(60);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(-147,127);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  topIntake();
  Hood.set_value(false);
  chassis.pid_drive_set(17.5_in, 30);
  chassis.pid_wait();
  pros::delay(150);
  chassis.pid_drive_set(-29_in, 60);
  chassis.pid_wait_until(-25);
  Hood.set_value(true);
  pros::delay(400);
  outake();
  pros::delay(100);
  topIntake();
  pros::delay(1500);
  Hood.set_value(false);

}

//-----------------------------Left----------------------------------//
void L7() {
  topIntake();
  Wings.set_value(true);
  chassis.pid_drive_set(25,120);
  chassis.pid_wait_until(11);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  mcturn(-100,127);
  Load.set_value(false);
  chassis.pid_drive_set(29,127);
  chassis.pid_wait_quick_chain();
  Load.set_value(true);
  mcturn(-148,127);
  mcdrive(17,60);
  pros::delay(550);
  mcdrive(-28,127);
  outake();
  Load.set_value(false);
  pros::delay(100);
  Hood.set_value(true);
  topIntake();
  pros::delay(650);
  Hood.set_value(true);
  chassis.pid_wait_quick_chain();
  drive(6,127);
  Hood.set_value(false);
  turn(-55,127);
  drive(-14,127);
  mcturn(-157,127);
  Wings.set_value(false);
  mcdrive(-24,55);
  Hood.set_value(false);


}
void L63() {
  //4 and 3 long first
  topIntake();
  mcdrive(24,127);
  Load.set_value(true);
  mcturn(-90,127);
  mcdrive(5,73);
  mcdrive(2,55);
  // mcdrive(1,50);
  pros::delay(360);
  chassis.pid_drive_set(-32,120);
  chassis.pid_wait_until(-20);
  Hood.set_value(true);
  Load.set_value(false);
  pros::delay(105);
  chassis.pid_wait_quick_chain();
  // Hood.set_value(false);
  mcdrive(7.4,127);
  mcturn(143,127);
  Hood.set_value(false);
  chassis.pid_drive_set(29,120);
  chassis.pid_wait_until(13);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  mcdrive(4,120);
  mcturn(135,120);
  mcdrive(3,120);
  mcdrive(-3,120);
  Load.set_value(false);
  mcturn(-45,120);
  mcdrive(-18.7,120);
  pros::delay(20);
  outake();
  pros::delay(185);
  First.move(127);
  Middle.move(-127);
  Top.move(127);
  pros::delay(1450);
  topIntake();
  mcdrive(29,115);
  mcturn(-94,120);
  mcdrive(-21,55);
  // chassis.drive_set(-600,-600);
  // pros::delay(500);
  // chassis.drive_set(0,0);




  // //4and3 middle first
  // topIntake();
  // chassis.pid_drive_set(32_in, 80);
  // chassis.pid_wait_until(10);
  // Load.set_value(true);
  // chassis.pid_wait_quick_chain();
  // mcturn(-93,127);
  // mcdrive(-15,105);
  // outake();
  // pros::delay(40);
  // chassis.pid_wait_quick_chain();
  // First.move(127);
  // Middle.move(-50);
  // Top.move(50);
  // Load.set_value(false);
  // pros::delay(1500); //900
  // outake();
  // pros::delay(20);
  // topIntake();
  // chassis.pid_drive_set(48,120);
  // chassis.pid_wait_until(40);
  // Load.set_value(true);
  // chassis.pid_wait_quick_chain();
  // mcturn(-147,127);

  // pros::delay(1000000000);
  // mcdrive(14,75);
  // pros::delay(450);
  // chassis.pid_drive_set(-32,120);
  // chassis.pid_wait_until(-25);
  // Hood.set_value(true);
  // Load.set_value(false);
  







  // //new 6 and 3 but not finished
  // topIntake();
  // chassis.pid_drive_set(38_in, 80);
  // chassis.pid_wait_until(10);
  // Load.set_value(true);
  // chassis.pid_wait_quick_chain();
  // Load.set_value(false);
  // mcturn(-55,127);
  // topIntake();
  // chassis.pid_drive_set(15_in, 80);
  // chassis.pid_wait_until(11);
  // Load.set_value(true);
  // pros::delay(50);
  // mcdrive(-15,110);
  // chassis.pid_swing_set(ez::RIGHT_SWING, -125_deg, -SWING_SPEED, -15);
  // Load.set_value(false);
  // chassis.pid_wait_quick_chain();
  // mcdrive(40,110);
  // mcturn(-125,127);

  //end of new but not done

  // topIntake();
  // chassis.pid_drive_set(31_in, 80);
  // chassis.pid_wait_until(23);
  // Load.set_value(true);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_swing_set(ez::RIGHT_SWING, -43_deg, SWING_SPEED, 5);
  // chassis.pid_wait();
  // Load.set_value(false);
  // chassis.pid_drive_set(15_in, 90);
  // chassis.pid_wait_until(5);
  // Load.set_value(true);
  // pros::delay(75);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-26_in, 90);
  // Load.set_value(false);
  // chassis.pid_wait();
  // chassis.pid_drive_set(14_in, 80);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-15_in, 80);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_turn_set(-100,127);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-6_in, 80);
  // chassis.pid_wait_quick_chain();
  // outake();
  // pros::delay(100);
  // First.move(127);
  // Middle.move(-65);
  // Top.move(65);
  // pros::delay(875);
  // Hood.set_value(false);
  // chassis.pid_wait();
  // outake();
  // chassis.pid_drive_set(47_in, 120);
  // chassis.pid_wait_until(32);
  // topIntake();
  // chassis.pid_speed_max_set(60);
  // Load.set_value(true);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_turn_set(-149,127);
  // chassis.pid_wait_quick_chain();
  // topIntake();
  // Hood.set_value(false);
  // chassis.pid_drive_set(17_in, 80);
  // chassis.pid_wait();
  // pros::delay(100);
  // chassis.pid_drive_set(-33_in, 80);
  // chassis.pid_wait_until(-25);
  // Hood.set_value(true);
  // pros::delay(400);
  // outake();
  // pros::delay(100);
  // topIntake();
  // pros::delay(1400);
  // Hood.set_value(false);


}
void L4() {
  topIntake();
  Wings.set_value(true);
  chassis.pid_drive_set(25,120);
  chassis.pid_wait_until(11);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  mcturn(-100,127);
  Load.set_value(false);
  chassis.pid_drive_set(30,127);
  chassis.pid_wait_quick_chain();
  mcturn(-148,127);
  mcdrive(-13,127);
  outake();
  pros::delay(50);
  Hood.set_value(true);
  topIntake();
  pros::delay(300);
  Hood.set_value(true);
  pros::delay(540);
  drive(6,127);
  Hood.set_value(false);
  turn(-55,127);
  drive(-14,127);
  mcturn(-157,127);
  Wings.set_value(false);
  mcdrive(-24,55);
  Hood.set_value(false);

}

//-----------------------------Right----------------------------------//
void R7() {
  topIntake();
  Wings.set_value(true);
  chassis.pid_drive_set(25,120);
  chassis.pid_wait_until(11);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  mcturn(100,127);
  Load.set_value(false);
  chassis.pid_drive_set(29,127);
  chassis.pid_wait_quick_chain();
  Load.set_value(true);
  mcturn(148,127);
  mcdrive(16,80);
  mcdrive(2,55);
  pros::delay(150);
  mcdrive(-28,127);
  outake();
  Load.set_value(false);
  pros::delay(100);
  Hood.set_value(true);
  topIntake();
  pros::delay(650);
  Hood.set_value(true);
  chassis.pid_wait_quick_chain();
  drive(6,127);
  turn(-125,127);
  drive(-15,127);
  mcturn(147,127);
  Wings.set_value(false);
  mcdrive(-24,55);
  Hood.set_value(false);

}
void R4() {
  topIntake();
  Wings.set_value(true);
  chassis.pid_drive_set(25,120);
  chassis.pid_wait_until(11);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  mcturn(100,127);
  Load.set_value(false);
  chassis.pid_drive_set(29,127);
  chassis.pid_wait_quick_chain();
  // Load.set_value(true);
  mcturn(148,127);
  // mcdrive(18,80);
  // pros::delay(400);
  mcdrive(-11,127);
  outake();
  pros::delay(30);
  Hood.set_value(true);
  topIntake();
  pros::delay(130);
  Hood.set_value(true);
  pros::delay(540);
  drive(6,127);
  Hood.set_value(false);
  turn(-125,127);
  drive(-15,127);
  Wings.set_value(false);
  mcturn(147,127);
  mcdrive(-24,55);
  Hood.set_value(false);
  inStop();

}
void R63() {
  topIntake();
  mcdrive(26,127);
  Load.set_value(true);
  mcturn(90,127);
  mcdrive(7,73);
  pros::delay(460);
  chassis.pid_drive_set(-32,120);
  chassis.pid_wait_until(-20);
  outake();
  pros::delay(60);
  topIntake();
  Hood.set_value(true);
  Load.set_value(false);
  pros::delay(150);
  chassis.pid_wait_quick_chain();
  Hood.set_value(false);
  mcdrive(10,127);
  mcturn(-143,127);
  chassis.pid_drive_set(29,120);
  chassis.pid_wait_until(12);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  mcdrive(4,120);
  mcturn(-138,120);
  mcdrive(3,120);
  mcdrive(-3,120);
  Load.set_value(false);
  mcdrive(7,120);
  pros::delay(150);
  First.move(-100);
  Middle.move(127);
  Top.move(127);
  pros::delay(1450);
  mcturn(-145,127);
  mcdrive(-23,115);
  mcturn(-85,120);
  mcdrive(21,55);

}

//-------------------------------------AWP's----------------------------------------//
void TSAWP() {
  topIntake();
  mcdrive(5,127);
  mcdrive(-52,100);
  Load.set_value(true);
  mcturn(-90,127);
  mcdrive(9,73);
  pros::delay(430);
  chassis.pid_drive_set(-34,120);
  chassis.pid_wait_until(-20);
  Hood.set_value(true);
  Load.set_value(false);
  pros::delay(230);
  chassis.pid_wait_quick_chain();
  Hood.set_value(false);
  mcdrive(9,127);
  mcturn(-323,127);
  chassis.pid_drive_set(28,120);
  chassis.pid_wait_until(15);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  mcturn(1,127);
  Load.set_value(false);
  chassis.pid_drive_set(22,120);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(20,75);
  chassis.pid_wait_until(17);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  // mcdrive(-2,100);
  mcturn(-45,127);
  mcdrive(-11,120);
  // chassis.pid_drive_set(-15,120);
  // chassis.pid_wait_until(-14);
  outake();
  pros::delay(25);
  First.move(127);
  Middle.move(-110);
  Top.move(110);
  Load.set_value(false);
  pros::delay(550); //900
  // First.move(127);
  // Middle.move(127);
  // Top.move(-127);
  // pros::delay(70);
  topIntake();
  chassis.pid_drive_set(47,120);
  chassis.pid_wait_until(40);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  mcturn(-90,127);
  mcdrive(9,95);
  mcdrive(5,60);
  pros::delay(300);
  chassis.pid_drive_set(-32,120);
  chassis.pid_wait_until(-25);
  Hood.set_value(true);
  Load.set_value(false);
  pros::delay(25);
  chassis.pid_wait_quick_chain();

}
void sigSoloAWPRight(){
  // Hood.set_value(true);
  chassis.pid_drive_set(23.5,105);
  chassis.pid_wait_until(20);
  chassis.pid_speed_max_set(40);
  chassis.pid_wait_quick_chain();
  Load.set_value(true);
  turn(-91,127);
  topIntake();
  mcdrive(6,30);
  pros::delay(30);
  pros::delay(40);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-30,85);
  outake();
  pros::delay(50);
  topIntake();
  chassis.pid_wait_until(13);
  chassis.pid_speed_max_set(30);
  Hood.set_value(true);
  // outake();
  // pros::delay(5);
  // Hood.set_value(false);
  // topIntake();
  pros::delay(1100);
  // outake();
  Hood.set_value(false);
  Load.set_value(false);
  // pros::delay(100);
  //chassis.pid_wait();

  // mcdrive(13,90);
  // // inStop();

  // turn(135,127);

  // pros::delay(1000000000000);

  topIntake();
  mcdrive(3,120);
  chassis.pid_swing_set(ez::RIGHT_SWING, 131_deg, SWING_SPEED, 5);
  chassis.pid_wait_quick_chain();
  topIntake();
  Hood.set_value(false);
  mcdrive(25,65);
  Load.set_value(true);
  topIntake();
  pros::delay(150);
  mcturn(-45,127);
  // middle();

  // pros::delay(9099999999);

  mcdrive(-8, 100);
  // outake();
  pros::delay(50);
  chassis.pid_wait_quick_chain();
  outake();
  pros::delay(150);
  // inStop();
  Load.set_value(false);
  First.move(127);
  Middle.move(-100);
  Top.move(127);
  pros::delay(750);
  chassis.pid_wait();
  topIntake();
  chassis.pid_swing_set(ez::RIGHT_SWING, -179_deg, SWING_SPEED, 10);
  chassis.pid_wait();
  // drive(33,90);
  chassis.pid_drive_set(38,90);
  chassis.pid_wait_until(28);
  Load.set_value(true);
  pros::delay(50);
  drive(-2,50);
  mcturn(52,127);
  Load.set_value(false);
  inStop();
  chassis.pid_drive_set(14,105);
  chassis.pid_wait_until(11);
  outake();

  // chassis.pid_swing_set(ez::LEFT_SWING, -90_deg, SWING_SPEED, 10);


}
void sigSoloAWP() {
  topIntake();
  mcdrive(26,127);
  Load.set_value(true);
  mcturn(90,127);
  mcdrive(7,73);
  pros::delay(430);
  chassis.pid_drive_set(-32,120);
  chassis.pid_wait_until(-20);
  Hood.set_value(true);
  Load.set_value(false);
  pros::delay(230);
  chassis.pid_wait_quick_chain();
  Hood.set_value(false);
  mcdrive(9,127);
  mcturn(-143,127);
  chassis.pid_drive_set(29,120);
  chassis.pid_wait_until(15);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  mcturn(-183,127);
  Load.set_value(false);
  chassis.pid_drive_set(22,120);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(21,75);
  chassis.pid_wait_until(17);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  // mcdrive(-2,100);
  mcturn(-225,127);
  mcdrive(-15,120);
  // chassis.pid_drive_set(-15,120);
  // chassis.pid_wait_until(-14);
  outake();
  pros::delay(75);
  First.move(127);
  Middle.move(-93);
  Top.move(93);
  Load.set_value(false);
  pros::delay(950); //900
  First.move(127);
  Middle.move(127);
  Top.move(-127);
  pros::delay(70);
  topIntake();
  chassis.pid_drive_set(47,120);
  chassis.pid_wait_until(40);
  Load.set_value(true);
  chassis.pid_wait_quick_chain();
  mcturn(-270,127);
  mcdrive(9,95);
  mcdrive(5,60);
  pros::delay(340);
  chassis.pid_drive_set(-32,120);
  chassis.pid_wait_until(-25);
  Hood.set_value(true);
  Load.set_value(false);
  pros::delay(25);
  chassis.pid_wait_quick_chain();

  


}

//--------------------------------SKILLS AUTONOMOUS--------------------------------//
void Skills() {

  // Hood.set_value(false);
  // Load.set_value(true);
  // topIntake();
  Wings.set_value(true);
  chassis.pid_drive_set(29.5,80);
  chassis.pid_wait_until(20);
  chassis.pid_speed_max_set(40);
  chassis.pid_wait();
  Load.set_value(true);
  turn(-89,127);
  topIntake();
  drive(11,30);
  pros::delay(200);
  drive(-1,100);
  pros::delay(100);
  drive(2,70);
  pros::delay(1800);
  turn(-93,127);
  chassis.pid_drive_set(-30,80);
  chassis.pid_wait_until(13);
  chassis.pid_speed_max_set(30);
  outake();
  pros::delay(150);
  topIntake();
  Hood.set_value(true);
  pros::delay(1475);
  Load.set_value(false);
  outake();
  pros::delay(200);
  Hood.set_value(false);
  topIntake();
  chassis.pid_wait();
  drive(13,80);
  pros::delay(100);
  // turn(0,127);
  // drive(12,45);
  // turn(-272,127);
  chassis.pid_swing_set(ez::LEFT_SWING, -269_deg, SWING_SPEED, 5);
  chassis.pid_wait();
  chassis.pid_drive_set(77,110);
  chassis.pid_wait_until(55);
  chassis.pid_speed_max_set(50);
  chassis.pid_wait();
  turn(-225,127);
  Load.set_value(true);
  drive(19,80);
  turn(-270,127);
  drive(14,30);
  pros::delay(200);
  drive(-1,100);
  pros::delay(100);
  drive(2,70);
  pros::delay(1800);
  chassis.pid_drive_set(-29,80);
  chassis.pid_wait_until(13);
  chassis.pid_speed_max_set(30);
  outake();
  pros::delay(50);
  topIntake();
  Hood.set_value(true);
  pros::delay(2000);
  chassis.pid_wait();
  Hood.set_value(false);
  pros::delay(25);
  drive(12,100);
  Load.set_value(false);
  turn(-181,127);
  chassis.pid_drive_set(96.5,95);
  chassis.pid_wait_until(60);
  chassis.pid_speed_max_set(50);
  Load.set_value(true);
  chassis.pid_wait();
  turn(-271,127);
  drive(22,30);
  pros::delay(200);
  drive(-1,100);
  pros::delay(100);
  drive(2,70);
  pros::delay(2100);
  chassis.pid_drive_set(-31,80);
  chassis.pid_wait_until(13);
  chassis.pid_speed_max_set(30);
  outake();
  pros::delay(50);
  topIntake();
  Hood.set_value(true);
  pros::delay(1050);
  outake();
  pros::delay(200);
  Hood.set_value(false);
  Load.set_value(false);
  outake();
  pros::delay(300);
  topIntake();
  chassis.pid_wait();
  drive(17,90);
  pros::delay(200);
  // turn(-180,127);
  // drive(13,60);
  // turn(-93,127);
  chassis.pid_swing_set(ez::LEFT_SWING, -93_deg, SWING_SPEED, 5);
  chassis.pid_wait();
  // turn(-92,127);
  chassis.pid_drive_set(81,110);
  chassis.pid_wait_until(55);
  chassis.pid_speed_max_set(50);
  chassis.pid_wait();
  turn(-45,127);
  Load.set_value(true);
  drive(20,80);
  turn(-91,127);
  drive(19,30);
  pros::delay(200);
  drive(-1,100);
  pros::delay(100);
  drive(2,70);
  pros::delay(2100);
  chassis.pid_drive_set(-30,80);
  chassis.pid_wait_until(13);
  chassis.pid_speed_max_set(30);
  outake();
  pros::delay(75);
  topIntake();
  Hood.set_value(true);
  pros::delay(300);
  outake();
  pros::delay(75);
  topIntake();
  pros::delay(2700);
  Hood.set_value(false);
  Load.set_value(false);
  outake();
  pros::delay(100);
  topIntake();
  chassis.pid_wait();
  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 66);
  chassis.pid_wait();
  outake();
  turn(-13,120);
  chassis.pid_drive_set(8,110);
  chassis.pid_wait_until(7);
  Load.set_value(true);
  pros::delay(75);
  drive(36,127);
  Hood.set_value(false);
  topIntake();
  Load.set_value(false);


}
void Skills2() {
  Wings.set_value(true);
  topIntake();
  mcdrive(24,127);
  Load.set_value(true);
  mcturn(-89,127);
  mcdrive(5,115);
  mcdrive(2,55);
  pros::delay(250);
  drive(-2,80);
  pros::delay(100);
  mcdrive(1,80);
  pros::delay(1250);
  mcdrive(-10,127);
  Load.set_value(false);
  chassis.pid_swing_set(ez::LEFT_SWING, -272_deg, SWING_SPEED, 5);
  chassis.pid_wait_quick_chain();
  mcdrive(73,127);
  chassis.pid_swing_set(ez::LEFT_SWING, -220_deg, SWING_SPEED, 50);
  chassis.pid_wait_quick_chain();
  mcdrive(10,115);
  mcturn(-270,127);
  mcdrive(-18,100);
  Hood.set_value(true); 
  Load.set_value(true);
  outake();
  pros::delay(250);
  topIntake();
  pros::delay(1950);
  outake();
  Hood.set_value(false);
  pros::delay(100);
  topIntake();
  mcdrive(25,61);
  mcdrive(4,50);
  pros::delay(570);
  drive(-3,80);
  pros::delay(100);
  mcdrive(1,80);
  pros::delay(1250);
  mcdrive(-32,120);
  Load.set_value(false);
  outake();
  Hood.set_value(true);
  pros::delay(200);
  topIntake();
  pros::delay(2150);
  Hood.set_value(false);
  mcdrive(9,120);
  turn(-182,127);
  // mcdrive(92,120); //here
  outake();
  chassis.pid_drive_set(92,120);
  chassis.pid_wait_until(83);
  topIntake();
  chassis.pid_speed_max_set(80);
  chassis.pid_wait_quick_chain();
  Load.set_value(true);
  turn(-269,127);
  mcdrive(13,65);
  mcdrive(4,50);
  pros::delay(220);
  drive(-2,80); //maybe -3?
  pros::delay(100);
  mcdrive(1,80);
  pros::delay(1100);
  mcturn(-270,127); //test
  mcdrive(-10,127);
  Load.set_value(false);
  chassis.pid_swing_set(ez::LEFT_SWING, -96_deg, SWING_SPEED, 5);
  chassis.pid_wait_quick_chain();
  mcdrive(71,127);
  chassis.pid_swing_set(ez::LEFT_SWING, -46_deg, SWING_SPEED, 50);
  chassis.pid_wait_quick_chain();
  mcdrive(15,127);
  mcturn(-90,127);
  mcdrive(-19,120);
  outake();
  pros::delay(175);
  Hood.set_value(true);
  topIntake();
  Load.set_value(true);
  pros::delay(1900);
  // outake();
  Hood.set_value(false);
  // mcturn(-91,120);
  chassis.pid_drive_set(32,60);
  chassis.pid_wait_until(15);
  topIntake();
  chassis.pid_wait_quick_chain();
  mcturn(-90,120);
  pros::delay(75);
  drive(-2,80);
  pros::delay(75);
  mcdrive(1,80);
  pros::delay(790);
  mcdrive(-30,120);
  Load.set_value(false);
  outake();
  Hood.set_value(true);
  pros::delay(175);
  topIntake();
  pros::delay(2150);
  Hood.set_value(false);
  mcdrive(9.5,127);
  mcturn(37,127);
  chassis.pid_drive_set(30,80);
  chassis.pid_wait_until(11);
  Load.set_value(true);
  pros::delay(100);
  chassis.pid_wait_quick_chain();
  // mcdrive(2,120);
  pros::delay(550);
  Load.set_value(false);
  // mcdrive(2,120);
  // pros::delay(300);
  // mcdrive(1,120);
  // pros::delay(150);
  // mcturn(40,127);
  // mcdrive(1,60);
  // First.move(-90);
  // Middle.move(127);
  // Top.move(127);
  // pros::delay(2000);
  // topIntake();
  // mcdrive(-14,120);
  mcdrive(-3,115);
  mcturn(-1.5,127);
  mcdrive(23,120);
  mcdrive(21,45);
  // Load.set_value(true);
  mcdrive(15,120);
  pros::delay(100);
  mcdrive(-1,120);
  mcturn(-45,127);
  chassis.pid_drive_set(-19,120);
  chassis.pid_wait_until(-5);
  chassis.pid_wait_quick_chain();
  outake();
  pros::delay(100);
  First.move(127);
  Middle.move(-100);
  Top.move(100);
  pros::delay(1400);
  First.move(127);
  Middle.move(-70);
  Top.move(70);
  pros::delay(600);
  mcdrive(22,105);
  Hood.set_value(true);
  Load.set_value(false);
  chassis.pid_swing_set(ez::RIGHT_SWING, -180_deg, 127, 40);
  chassis.pid_wait_quick_chain();
  mcturn(-182.5,120);
  // mcdrive(50,115);
  // chassis.pid_swing_set(ez::RIGHT_SWING, -183_deg, 127, 5);
  // mcdrive(-5,115);
  outake();
  chassis.pid_drive_set(50_in, 95);
  chassis.pid_wait_until(40);
  chassis.pid_speed_max_set(60);
  chassis.pid_wait_quick_chain();
  topIntake();
  Hood.set_value(false);
  mcdrive(4,30);





  // mcturn(-10,127);
  // Load.set_value(false);
  // chassis.pid_drive_set(29,120);
  // chassis.pid_wait_quick_chain();
  // mcdrive(10,75);
  // Load.set_value(true);
  // mcturn(-45,127);
  // chassis.pid_drive_set(-14,120);
  // chassis.pid_wait_until(-5);
  // outake();
  // chassis.pid_wait_quick_chain();
  // First.move(127);
  // Middle.move(-90);
  // Top.move(127);
  // pros::delay(800);
  // topIntake();
}
void Skills3() {
  // Wings.set_value(true);
  // topIntake();
  // mcdrive(24,127);
  // Load.set_value(true);
  // mcturn(-89,127);
  // mcdrive(4,115);
  // mcdrive(2,55);
  // pros::delay(250);
  // drive(-2,80);
  // pros::delay(100);
  // mcdrive(1,80);
  // pros::delay(1250);
  // mcdrive(-10,127);
  // Load.set_value(false);
  // chassis.pid_swing_set(ez::LEFT_SWING, -272_deg, SWING_SPEED, 5);
  // chassis.pid_wait_quick_chain();
  // mcdrive(73,127);
  // chassis.pid_swing_set(ez::LEFT_SWING, -220_deg, SWING_SPEED, 50);
  // chassis.pid_wait_quick_chain();
  // mcdrive(10,115);
  // mcturn(-270,127);
  // mcdrive(-18,100);
  // Hood.set_value(true); 
  // Load.set_value(true);
  // outake();
  // pros::delay(250);
  // topIntake();
  // pros::delay(1950);
  // outake();
  // Hood.set_value(false);
  // pros::delay(100);
  // topIntake();
  // mcdrive(25,61);
  // mcdrive(4,50);
  // pros::delay(570);
  // drive(-3,80);
  // pros::delay(100);
  // mcdrive(1,80);
  // pros::delay(1250);
  // mcdrive(-32,120);
  // Load.set_value(false);
  // outake();
  // Hood.set_value(true);
  // pros::delay(200);
  // topIntake();
  // pros::delay(2150);
  // Hood.set_value(false);

  //new stuff here
  topIntake();
  chassis.drive_angle_set(90_deg);
  // mcdrive(9,120);
  // mcturn(180,127);
  // chassis.pid_drive_set(50,120);
  // chassis.pid_wait_until(37);
  // chassis.pid_speed_max_set(60);
  // chassis.pid_wait();
  // mcturn(90,105);
  // chassis.pid_drive_set(30,120);
  // chassis.pid_wait_until(20);
  // chassis.pid_speed_max_set(50);
  // chassis.pid_wait_quick_chain();
  // mcdrive(-3,127);
  // mcdrive(7,90 );
  // mcdrive(-3,127);
  // mcdrive(7,90 );
  // // mcdrive(-3,127);
  // // mcdrive(6,90 );
  // mcdrive(-20,127);
  // mcdrive(5,30);
  //pid reset here
  mcturn(220,127);
  mcdrive(23,100);
  mcturn(131,127);
  mcdrive(-13,80);
  outake();
  pros::delay(75);
  First.move(127);
  Middle.move(-90);
  Top.move(90);
  pros::delay(300);
  First.move(127);
  Middle.move(-60);
  Top.move(60);




  pros::delay(1000000000000000000);
  chassis.pid_swing_set(ez::LEFT_SWING, 175_deg, SWING_SPEED, 60);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(50_in, 75);
  chassis.pid_wait_until(40);
  chassis.pid_speed_max_set(70);
  chassis.pid_wait_quick_chain();
  pros::delay(100);
  mcdrive(20,85);
  mcturn(-90,127);
  mcdrive(-5,120);
  

  pros::delay(1000000000000000000);
  //here stop
  turn(-182,127);
  // mcdrive(92,120); //here
  outake();
  chassis.pid_drive_set(92,120);
  chassis.pid_wait_until(83);
  topIntake();
  chassis.pid_speed_max_set(80);
  chassis.pid_wait_quick_chain();
  Load.set_value(true);
  turn(-269,127);
  mcdrive(13,65);
  mcdrive(4,50);
  pros::delay(220);
  drive(-2,80); //maybe -3?
  pros::delay(100);
  mcdrive(1,80);
  pros::delay(1100);
  mcturn(-270,127); //test
  mcdrive(-10,127);
  Load.set_value(false);
  chassis.pid_swing_set(ez::LEFT_SWING, -96_deg, SWING_SPEED, 5);
  chassis.pid_wait_quick_chain();
  mcdrive(71,127);
  chassis.pid_swing_set(ez::LEFT_SWING, -46_deg, SWING_SPEED, 50);
  chassis.pid_wait_quick_chain();
  mcdrive(15,127);
  mcturn(-90,127);
  mcdrive(-19,120);
  outake();
  pros::delay(175);
  Hood.set_value(true);
  topIntake();
  Load.set_value(true);
  pros::delay(1900);
  // outake();
  Hood.set_value(false);
  // mcturn(-91,120);
  chassis.pid_drive_set(32,60);
  chassis.pid_wait_until(15);
  topIntake();
  chassis.pid_wait_quick_chain();
  mcturn(-90,120);
  pros::delay(75);
  drive(-2,80);
  pros::delay(75);
  mcdrive(1,80);
  pros::delay(790);
  mcdrive(-30,120);
  Load.set_value(false);
  outake();
  Hood.set_value(true);
  pros::delay(175);
  topIntake();
  pros::delay(2150);
  Hood.set_value(false);
  mcdrive(9.5,127);
  mcturn(37,127);
  chassis.pid_drive_set(30,80);
  chassis.pid_wait_until(11);
  Load.set_value(true);
  pros::delay(100);
  chassis.pid_wait_quick_chain();
  // mcdrive(2,120);
  pros::delay(550);
  Load.set_value(false);
  // mcdrive(2,120);
  // pros::delay(300);
  // mcdrive(1,120);
  // pros::delay(150);
  // mcturn(40,127);
  // mcdrive(1,60);
  // First.move(-90);
  // Middle.move(127);
  // Top.move(127);
  // pros::delay(2000);
  // topIntake();
  // mcdrive(-14,120);
  mcdrive(-3,115);
  mcturn(-1.5,127);
  mcdrive(23,120);
  mcdrive(21,45);
  // Load.set_value(true);
  mcdrive(15,120);
  pros::delay(100);
  mcdrive(-1,120);
  mcturn(-45,127);
  chassis.pid_drive_set(-19,120);
  chassis.pid_wait_until(-5);
  chassis.pid_wait_quick_chain();
  outake();
  pros::delay(100);
  First.move(127);
  Middle.move(-100);
  Top.move(100);
  pros::delay(1400);
  First.move(127);
  Middle.move(-70);
  Top.move(70);
  pros::delay(600);
  mcdrive(22,105);
  Hood.set_value(true);
  Load.set_value(false);
  chassis.pid_swing_set(ez::RIGHT_SWING, -180_deg, 127, 40);
  chassis.pid_wait_quick_chain();
  mcturn(-182.5,120);
  // mcdrive(50,115);
  // chassis.pid_swing_set(ez::RIGHT_SWING, -183_deg, 127, 5);
  // mcdrive(-5,115);
  outake();
  chassis.pid_drive_set(50_in, 95);
  chassis.pid_wait_until(40);
  chassis.pid_speed_max_set(60);
  chassis.pid_wait_quick_chain();
  topIntake();
  Hood.set_value(false);
  mcdrive(4,30);
  
} 
void Skills21() {
  Wings.set_value(true);
  topIntake();
  mcdrive(15,127);
  Load.set_value(true);
  mcturn(-89,127);
  mcdrive(5,115);
  mcdrive(2,55);
  pros::delay(250);
  drive(-2,80);
  pros::delay(100);
  drive(2,80);
  pros::delay(1250);
  drive(-14,127);
  Load.set_value(false);
  chassis.pid_swing_set(ez::LEFT_SWING, -270_deg, SWING_SPEED, 5);
  chassis.pid_wait_quick_chain();
  mcdrive(73,127);
  chassis.pid_swing_set(ez::LEFT_SWING, -220_deg, SWING_SPEED, 50);
  chassis.pid_wait_quick_chain();
  mcdrive(10,115);
  mcturn(-270,127);
  mcdrive(-17.5,100);
  Hood.set_value(true); 
  Load.set_value(true);
  outake();
  pros::delay(250);
  topIntake();
  pros::delay(1950);
  outake();
  Hood.set_value(false);
  pros::delay(100);
  topIntake();
  mcdrive(25,61);
  mcdrive(4,50);
  pros::delay(270);
  drive(-2,80);
  pros::delay(100);
  drive(3,80);
  pros::delay(1250);
  mcdrive(-32,120);
  Load.set_value(false);
  outake();
  Hood.set_value(true);
  pros::delay(200);
  topIntake();
  pros::delay(2150);
  Hood.set_value(false);
  mcdrive(5,120);
  turn(-182,127);
  mcdrive(81,120);
  Load.set_value(true);
  turn(-268,127);
  mcdrive(14,65);
  mcdrive(4,50);
  pros::delay(220);
  drive(-2,80);
  pros::delay(100);
  mcdrive(1,80);
  pros::delay(1100);
  mcturn(-270,127); //test
  mcdrive(-10,127);
  Load.set_value(false);
  chassis.pid_swing_set(ez::LEFT_SWING, -94_deg, SWING_SPEED, 5);
  chassis.pid_wait_quick_chain();
  mcdrive(71,127);
  chassis.pid_swing_set(ez::LEFT_SWING, -46_deg, SWING_SPEED, 50);
  chassis.pid_wait_quick_chain();
  mcdrive(9,127);
  mcturn(-90,127);
  mcdrive(-19,120);
  outake();
  pros::delay(175);
  Hood.set_value(true);
  topIntake();
  Load.set_value(true);
  pros::delay(1900);
  outake();
  Hood.set_value(false);
  mcturn(-89,120);
  chassis.pid_drive_set(32,60);
  chassis.pid_wait_until(25);
  topIntake();
  chassis.pid_wait_quick_chain();
  mcturn(-90,120);
  pros::delay(75);
  drive(-2,80);
  pros::delay(75);
  drive(3,80);
  pros::delay(790);
  mcdrive(-30,120);
  Load.set_value(false);
  outake();
  Hood.set_value(true);
  pros::delay(175);
  topIntake();
  pros::delay(2150);
  Hood.set_value(false);
  mcdrive(6,127);
  mcturn(37,127);
  chassis.pid_drive_set(30,80);
  chassis.pid_wait_until(11);
  Load.set_value(true);
  pros::delay(100);
  chassis.pid_wait_quick_chain();
  // mcdrive(2,120);
  pros::delay(550);
  Load.set_value(false);
  // mcdrive(2,120);
  // pros::delay(300);
  // mcdrive(1,120);
  // pros::delay(150);
  // mcturn(40,127);
  // mcdrive(1,60);
  // First.move(-90);
  // Middle.move(127);
  // Top.move(127);
  // pros::delay(2000);
  // topIntake();
  // mcdrive(-14,120);
  mcdrive(-3,115);
  mcturn(-2,127);
  mcdrive(23,120);
  mcdrive(21,45);
  // Load.set_value(true);
  mcdrive(10,120);
  pros::delay(100);
  mcdrive(-5,120);
  mcturn(-45,127);
  chassis.pid_drive_set(-16,120);
  chassis.pid_wait_until(-5);
  outake();
  chassis.pid_wait_quick_chain();
  First.move(127);
  Middle.move(-100);
  Top.move(100);
  pros::delay(2000);
  mcdrive(20,105);
  Hood.set_value(true);
  Load.set_value(false);
  chassis.pid_swing_set(ez::RIGHT_SWING, -180_deg, 127, 40);
  chassis.pid_wait_quick_chain();
  mcturn(-177,120);
  // mcdrive(50,115);
  // chassis.pid_swing_set(ez::RIGHT_SWING, -183_deg, 127, 5);
  // mcdrive(-5,115);
  outake();
  chassis.pid_drive_set(55_in, 95);
  chassis.pid_wait_until(40);
  chassis.pid_speed_max_set(60);
  chassis.pid_wait_quick_chain();
  topIntake();

}

//--------------------------------TEST AUTONOMOUS----------------------------------//
void TestAuto() {
  // pros::Task antiJam(antiJamTask);
  outake();
  pros::delay(60);
  First.move(127);
  Middle.move(-70);
  Top.move(70);
  pros::delay(200);
  mcdrive(0.4,50);
  First.move(127);
  Middle.move(-50);
  Top.move(50);
  pros::delay(150);
  First.move(127);
  Middle.move(-40);
  Top.move(40);
  pros::delay(200);
  First.move(127);
  Middle.move(-30);
  Top.move(30);
  
}





















// PID Drive Example
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater than the slew distance + a few inches

  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
}

///
// Constants
///
void default_constants() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(13.0, 0.0, 110.0);         // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(11.0, 0.0, 20.0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(3.7, 0.05, 25.0, 15.0);     // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 65.0);           // Swing constants
  chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5);  // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(4_deg); //5
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in); //10
  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

///
// Interference example
///

// If there is no interference, the robot will drive forward and turn 90 degrees.
// If interfered, the robot will drive forward and then attempt to drive backward.
void interfered_example() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}


///
// Odom Drive PID
///
void odom_drive_example() {
  // This works the same as pid_drive_set, but it uses odom instead!
  // You can replace pid_drive_set with pid_odom_set and your robot will
  // have better error correction.

  chassis.pid_odom_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
}

///
// Odom Pure Pursuit
///
void odom_pure_pursuit_example() {
  // Drive to 0, 30 and pass through 6, 10 and 0, 20 on the way, with slew
  chassis.pid_odom_set({{{6_in, 10_in}, fwd, DRIVE_SPEED},
                        {{0_in, 20_in}, fwd, DRIVE_SPEED},
                        {{0_in, 30_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait();

  // Drive to 0, 0 backwards
  chassis.pid_odom_set({{0_in, 0_in}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Odom Pure Pursuit Wait Until
///
void odom_pure_pursuit_wait_until_example() {
  chassis.pid_odom_set({{{0_in, 24_in}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait_until_index(1);  // Waits until the robot passes 12, 24
  // Intake.move(127);  // Set your intake to start moving once it passes through the second point in the index
  chassis.pid_wait();
  // Intake.move(0);  // Turn the intake off
}

///
// Odom Boomerang
///
void odom_boomerang_example() {
  chassis.pid_odom_set({{0_in, 24_in, 45_deg}, fwd, DRIVE_SPEED},
                       true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Odom Boomerang Injected Pure Pursuit
///
void odom_boomerang_injected_pure_pursuit_example() {
  chassis.pid_odom_set({{{0_in, 24_in, 45_deg}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Calculate the offsets of your tracking wheels
///
void measure_offsets() {
  // Number of times to test
  int iterations = 10;

  // Our final offsets
  double l_offset = 0.0, r_offset = 0.0, b_offset = 0.0, f_offset = 0.0;

  // Reset all trackers if they exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->reset();
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->reset();
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->reset();
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->reset();
  
  for (int i = 0; i < iterations; i++) {
    // Reset pid targets and get ready for running an auton
    chassis.pid_targets_reset();
    chassis.drive_imu_reset();
    chassis.drive_sensor_reset();
    chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    double imu_start = chassis.odom_theta_get();
    double target = i % 2 == 0 ? 90 : 270;  // Switch the turn target every run from 270 to 90

    // Turn to target at half power
    chassis.pid_turn_set(target, 63, ez::raw);
    chassis.pid_wait();
    pros::delay(250);

    // Calculate delta in angle
    double t_delta = util::to_rad(fabs(util::wrap_angle(chassis.odom_theta_get() - imu_start)));

    // Calculate delta in sensor values that exist
    double l_delta = chassis.odom_tracker_left != nullptr ? chassis.odom_tracker_left->get() : 0.0;
    double r_delta = chassis.odom_tracker_right != nullptr ? chassis.odom_tracker_right->get() : 0.0;
    double b_delta = chassis.odom_tracker_back != nullptr ? chassis.odom_tracker_back->get() : 0.0;
    double f_delta = chassis.odom_tracker_front != nullptr ? chassis.odom_tracker_front->get() : 0.0;

    // Calculate the radius that the robot traveled
    l_offset += l_delta / t_delta;
    r_offset += r_delta / t_delta;
    b_offset += b_delta / t_delta;
    f_offset += f_delta / t_delta;
  }

  // Average all offsets
  l_offset /= iterations;
  r_offset /= iterations;
  b_offset /= iterations;
  f_offset /= iterations;

  // Set new offsets to trackers that exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->distance_to_center_set(l_offset);
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->distance_to_center_set(r_offset);
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->distance_to_center_set(b_offset);
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->distance_to_center_set(f_offset);
}

// . . .
// Make your own autonomous functions here!
// . . .

//top intake
//instop
//bottom intake


