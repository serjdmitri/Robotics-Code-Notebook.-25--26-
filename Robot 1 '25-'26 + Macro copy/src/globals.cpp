#include "pros/misc.hpp"
#include "pros/motors.h"
#include "api.h"
#include "EZ-Template/api.hpp"
#include "autons.hpp"
#include "pros/motors.hpp"
#include "subsystems.hpp"
#include "globals.hpp"
#include <iostream>

pros::Controller mController(pros:: E_CONTROLLER_MASTER);
pros::adi::DigitalOut Park('A');
pros::adi::DigitalOut Load('B');
pros::adi::DigitalOut Wings('C');
pros::adi::DigitalOut Hood('D');
pros::Motor Middle(1, pros::v5::MotorGears::green, pros::v5::MotorUnits(pros::E_MOTOR_ENCODER_DEGREES));
pros::Motor Top(3, pros::v5::MotorGears::green, pros::v5::MotorUnits(pros::E_MOTOR_ENCODER_DEGREES));
pros::Motor First(10, pros::v5::MotorGears::blue, pros::v5::MotorUnits(pros::E_MOTOR_ENCODER_DEGREES));
pros::Optical Color (9);

bool BoolOpen = false;

void WingsCode() {
  if (mController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    WingsToggle = !WingsToggle;
  } else if (WingsToggle == true) {
    Wings.set_value(true);
  } else {
    Wings.set_value(false);
  }
}

void ParkCode() {
  if (mController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    ParkToggle = !ParkToggle;
  } else if (ParkToggle == true) {
    Park.set_value(true);
  } else {
    Park.set_value(false);
  }
}

void LoadCode() {
  if (mController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    LoadToggle = !LoadToggle;
  } else if (LoadToggle == true) {
    Load.set_value(true);
  } else {
    Load.set_value(false);
  }
}

void IntakeCode() {
  if (mController.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    First.move(127);
    Middle.move(-127);
    Top.move(-127);
    Hood.set_value(false);
  } else if (mController.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    First.move(-100);
    Middle.move(127);
    Top.move(100);
  } else if (mController.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    First.move(127);
    Middle.move(-127);
    Top.move(-127);
    Hood.set_value(true);
  } else if (mController.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    First.move(127);
    Middle.move(-55);
    Top.move(40);
  } else {
    First.move(0);
    Middle.move(0);
    Top.move(0);
  }
}

void SkillsMacro() {
  if (mController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) { 
    //outake
    First.move(-127);
    Middle.move(110);
    Top.move(50);
    pros::delay(190);

    //intake
    First.move(120);
    Middle.move(-60);
    Top.move(50);
    pros::delay(500);

    //outake
    First.move(-127);
    Middle.move(90);
    Top.move(127);
    pros::delay(100);

    //intake
    First.move(120);
    Middle.move(-65);
    Top.move(45);
    pros::delay(70);

    First.move(120);
    Middle.move(-60);
    Top.move(40);
    pros::delay(1000);

    //outake
    First.move(-127);
    Middle.move(70);
    Top.move(127);
    pros::delay(50);

    //intake
    First.move(120);
    Middle.move(-50);
    Top.move(35);
    pros::delay(350);

    First.move(120);
    Middle.move(-35);
    Top.move(30);
    pros::delay(200);

     First.move(120);
    Middle.move(-30);
    Top.move(25);
    pros::delay(210);

    // First.move(-127);
    // Middle.move(70);
    // Top.move(127);
    // pros::delay(80);
  }
}

void Colorsort() {
  
}

void Autoalign() {
  if (mController.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
    chassis.drive_angle_set(0_deg);
    chassis.pid_wait_quick_chain();
    chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, 120, 40);
    chassis.pid_wait_quick_chain();
    chassis.drive_angle_set(0_deg);
    chassis.pid_turn_set(45,127);

  }
}

void IntakeSlow() {
  if (mController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
  // First.set_voltage_limit(10);
  // Middle.set_voltage_limit(10);
  // Top.set_voltage_limit(70);
  First.set_voltage_limit_all(70);
  Middle.set_voltage_limit_all(70);
  Top.set_voltage_limit_all(70);

  }
}




// void setHood(bool state) {
//   Hood.set_value(state);
//   HoodOpen = state;
// }
// void antiJamTask() {
//   HoodOpen = false;
//   while (true) {
//     std::cout << First.get_power() << endl;
//     std::cout << Middle.get_power() << endl;
//     std::cout << Top.get_power() << endl;
//     bool middleRun =
//       (First.get_power() >= 30) &&
//       (Middle.get_power() <= -30) &&
//       (Top.get_power() >= 30);
  
//     if (HoodOpen || middleRun) {

//       // Jam test
//       bool jamNow =
//         (std::abs(First.get_power())  > 80 && std::abs(First.get_actual_velocity())  < 5) ||
//         (std::abs(Middle.get_power()) > 80 && std::abs(Middle.get_actual_velocity()) < 5) ||
//         (std::abs(Top.get_power())    > 80 && std::abs(Top.get_actual_velocity())    < 5);

//       if (jamNow) {
//         pros::delay(250);

      
//         middleRun =
//           (First.get_power() >= 30) &&
//           (Middle.get_power() <= -30) &&
//           (Top.get_power() >= 30);

//         if (HoodOpen || middleRun) {

//           bool jamStill =
//             (std::abs(First.get_power())  > 80 && std::abs(First.get_actual_velocity())  < 5) ||
//             (std::abs(Middle.get_power()) > 80 && std::abs(Middle.get_actual_velocity()) < 5) ||
//             (std::abs(Top.get_power())    > 80 && std::abs(Top.get_actual_velocity())    < 5);

//           if (jamStill) {
//             int f = First.get_power();
//             int m = Middle.get_power();
//             int t = Top.get_power();

//             // reverse
//             First.move(-127);
//             Middle.move(127);
//             Top.move(-127);

//             pros::delay(250);

//             // restore exactly what it was doing
//             First.move(f);
//             Middle.move(m);
//             Top.move(t);
//           }
//         }
//       }
//     }

//     pros::delay(10);
//   }
// }

