/******************************************************************************
 * Project      : Obstacle Avoiding Robot
 * Platform     : Arduino UNO
 * Author       : Ramasamy V
 * Year         : Prefinal Year Project
 *
 * Description:
 * ------------
 * This firmware controls a four-wheel obstacle avoiding robot using an
 * ultrasonic sensor mounted on a servo motor.
 *
 * Working Principle:
 * 1. Robot moves forward continuously.
 * 2. Measures distance using HC-SR04 ultrasonic sensor.
 * 3. If an obstacle is detected within 15 cm:
 *      - Stop
 *      - Move backward
 *      - Scan right
 *      - Scan left
 *      - Compare distances
 *      - Turn towards the direction with more free space
 *      - Continue moving forward
 *
 * Hardware Used:
 * --------------
 * Arduino UNO
 * L293D Motor Shield
 * HC-SR04 Ultrasonic Sensor
 * SG90 Servo Motor
 * 4 DC Geared Motors
 ******************************************************************************/

#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

/*===========================================================================
    Pin Configuration
===========================================================================*/
#define TRIG_PIN       A0
#define ECHO_PIN       A1

/*===========================================================================
    Robot Configuration
===========================================================================*/
#define MAX_DISTANCE   200      // Maximum ultrasonic sensing distance (cm)
#define MAX_SPEED      190      // Motor speed (0 - 255)

/*===========================================================================
    Hardware Objects
===========================================================================*/
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

Servo scannerServo;

/*===========================================================================
    Global Variables
===========================================================================*/
bool goesForward = false;

int distance = 100;
int speedSet = 0;

/*===========================================================================
    Function Prototypes
===========================================================================*/
int  readPing();
int  lookRight();
int  lookLeft();

void moveForward();
void moveBackward();
void moveStop();

void turnRight();
void turnLeft();

/*===========================================================================
    Setup
===========================================================================*/
void setup()
{
    scannerServo.attach(10);

    // Center the ultrasonic sensor
    scannerServo.write(115);

    delay(2000);

    // Initial distance readings for stable startup
    for (int i = 0; i < 4; i++)
    {
        distance = readPing();
        delay(100);
    }
}

/*===========================================================================
    Main Loop
===========================================================================*/
void loop()
{
    int distanceRight = 0;
    int distanceLeft  = 0;

    delay(40);

    // Obstacle detected
    if (distance <= 15)
    {
        moveStop();
        delay(100);

        moveBackward();
        delay(300);

        moveStop();
        delay(200);

        distanceRight = lookRight();
        delay(200);

        distanceLeft = lookLeft();
        delay(200);

        // Select the direction with greater free space
        if (distanceRight >= distanceLeft)
        {
            turnRight();
        }
        else
        {
            turnLeft();
        }

        moveStop();
    }
    else
    {
        moveForward();
    }

    // Update distance measurement
    distance = readPing();
}

/*===========================================================================
    Scan Right
===========================================================================*/
int lookRight()
{
    scannerServo.write(50);
    delay(500);

    int distance = readPing();

    delay(100);
    scannerServo.write(115);

    return distance;
}

/*===========================================================================
    Scan Left
===========================================================================*/
int lookLeft()
{
    scannerServo.write(170);
    delay(500);

    int distance = readPing();

    delay(100);
    scannerServo.write(115);

    return distance;
}

/*===========================================================================
    Read Ultrasonic Sensor
===========================================================================*/
int readPing()
{
    delay(70);

    int cm = sonar.ping_cm();

    // If no object is detected, assume maximum distance
    if (cm == 0)
    {
        cm = 250;
    }

    return cm;
}

/*===========================================================================
    Stop Robot
===========================================================================*/
void moveStop()
{
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}

/*===========================================================================
    Move Forward
===========================================================================*/
void moveForward()
{
    if (!goesForward)
    {
        goesForward = true;

        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);

        // Gradually increase motor speed
        for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2)
        {
            motor1.setSpeed(speedSet);
            motor2.setSpeed(speedSet);
            motor3.setSpeed(speedSet);
            motor4.setSpeed(speedSet);

            delay(5);
        }
    }
}

/*===========================================================================
    Move Backward
===========================================================================*/
void moveBackward()
{
    goesForward = false;

    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);

    // Gradually increase reverse speed
    for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2)
    {
        motor1.setSpeed(speedSet);
        motor2.setSpeed(speedSet);
        motor3.setSpeed(speedSet);
        motor4.setSpeed(speedSet);

        delay(5);
    }
}

/*===========================================================================
    Turn Right
===========================================================================*/
void turnRight()
{
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);

    delay(500);

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

/*===========================================================================
    Turn Left
===========================================================================*/
void turnLeft()
{
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);

    delay(500);

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}