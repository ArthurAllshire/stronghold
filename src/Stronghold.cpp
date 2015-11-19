#include <Stronghold.h>
#include "WPILib.h"
#include "Commands/ExampleCommand.h"
// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* Stronghold::exampleSubsystem = NULL;
OI* Stronghold::oi = NULL;


void Stronghold::RobotInit()
{
    // intialize subsystem objects here
    oi = new OI();
    autonomousCommand = new ExampleCommand();
    lw = LiveWindow::GetInstance();

    // Show what command your subsystem is running on the SmartDashboard
    SmartDashboard::PutData(exampleSubsystem);
}

void Stronghold::DisabledPeriodic()
{
    Scheduler::GetInstance()->Run();
}

void Stronghold::AutonomousInit()
{
    if (autonomousCommand != NULL)
        autonomousCommand->Start();
}

void Stronghold::AutonomousPeriodic()
{
    Scheduler::GetInstance()->Run();
}

void Stronghold::TeleopInit()
{
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to
    // continue until interrupted by another command, remove
    // this line or comment it out.
    if (autonomousCommand != NULL)
        autonomousCommand->Cancel();
}

void Stronghold::TeleopPeriodic()
{
    Scheduler::GetInstance()->Run();
}

void Stronghold::TestPeriodic()
{
    lw->Run();
}


START_ROBOT_CLASS(Stronghold);

