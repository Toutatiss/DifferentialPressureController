/*
  Deformation System Terminal
  Written by Tat Kalintsev
  02/10/2023
  Created for the School of Earth, Atmosphere and Environment, Monash University.
  Software Version 1.0
*/

// Include the UI library
#include <PressureControllerSerialUI.h>

// Instantiate UI library
PressureControllerSerialUI serialUI;

void setup()
{
  // Configure Interrupt
  pinMode(ALARM_INTERRUPT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ALARM_INTERRUPT_PIN), isrAlarmTriggered, FALLING);

  // Setup the serial UI
  serialUI.begin(9600);
}

void loop()
{
  serialUI.run();
}

// Interrupt Routine
static void isrAlarmTriggered()
{
  serialUI.alarmDone = true;
  return;
}