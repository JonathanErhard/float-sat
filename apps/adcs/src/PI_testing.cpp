/*
Kp = 0.5 ; 
Ki = 0,005 ; 
Adcs::error_pi_prev = Adcs::error_pi;
Adcs::error_pi = Adcs::desired_velocity - Adcs::satellite_velocity;
Adcs::control_output_pi_prev = Adcs::control_output_pi
Adcs::control_output_pi = Adcs::control_output_pi_prev + Kp * Adcs::error_pi + Ki * Adcs::error_pi_prev

Speed control of the FloatSat

#define ADCS_MAX_MOTOR_SPEED  3500.0f
#define ADCS_MIN_MOTOR_SPEED -3500.0f
Kp_Velocity = 150;
Ki_Velocity = 1;
Adcs::error_velocity = Adcs::desired_satellite_velocity - Speed; // The speed coded by Simon yesterday
Adcs::error_velocity_sum += Adcs::error_velocity;
Adcs::desired_velocity  = Kp_Velocity * Adcs::error_velocity;
Adcs::desired_velocity += Ki_Velocity * Adcs::error_velocity_sum;

if(Adcs::desired_velocity >  ADCS_MAX_MOTOR_SPEED)  Adcs::desired_velocity = ADCS_PI_SATURATION;
if(Adcs::desired_velocity < -AADCS_MIN_MOTOR_SPEED) Adcs::desired_velocity = - ADCS_MIN_MOTOR_SPEED;
==> start: CONTROL_MODE_PI: // now that we have the new desired motor speed we do motor control

*/
