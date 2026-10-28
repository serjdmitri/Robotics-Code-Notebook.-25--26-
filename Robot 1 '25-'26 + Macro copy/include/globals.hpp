#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "main.h"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "pros/optical.hpp"

// Function declarations
extern void SkillsMacro();

extern void Colorsort();
extern void L4();
extern void R7();
extern void R4();
extern void R63();
extern void Skills3();
extern void Skills21();
extern void TestAuto();
extern void IntakeSlow();
extern void IntakeCode();
extern void ParkCode();
extern void LoadCode();
extern void WingsCode();
extern void WingsCode1();
extern void WingsCode2();
extern void IntakeCode2();
extern void Autoalign();
extern bool HoodOpen;
extern void outake();
extern void topIntake();
extern void middle();
extern void inStop();
extern void drive();
extern void mcdrive();
extern void turn();
extern void mcturn();
extern void Rmcswing();
extern void Rswing();
extern void Lmcswing();
extern void Lswing();
extern void antiJamTask();

// Toggle variables
static bool WingsToggle = false;
static bool ParkToggle = false;
static bool LoadToggle = false;
static bool WingToggle = false;

// Hardware declarations
extern pros::Controller mController;
extern pros::Motor Top;
extern pros::Motor First;
extern pros::Motor Middle;
extern pros::Optical Color;
extern pros::adi::DigitalOut Park;
extern pros::adi::DigitalOut Load;
extern pros::adi::DigitalOut Wings;
extern pros::adi::DigitalOut Hood;

#endif