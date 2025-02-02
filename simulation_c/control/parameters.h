/* =============================================================================
 *
 * parameters.h
 *
 * =============================================================================
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//Begin of simulation parameters
#define TS_SIMULATION 1/100
#define START_TIME 0
#define END_TIME 200
#define TS_PLOTTING 0.02
#define TS_VIDEO 0.1
#define TS_CONTROL TS_SIMULATION
//End of simulation parameters

//Begin of sensor parameters
#define TS_SENSORS 0.01
#define ACCEL_SIGMA 0.0025*9.8
#define GYRO_X_BIAS 0
#define GYRO_Y_BIAS 0
#define GYRO_Z_BIAS 0
//gyro_sigma = np.radians(0.13)
#define STATIC_PRES_SIGMA 0.01*1000
#define DIFF_PRESS_SIGMA 0.002*1000
//mag_beta = np.radians(1.0)
//mag_sigma = np.radians(0.03)
/*
ts_gps = 1.0
gps_k = 1. / 1100.  # 1 / s
gps_n_sigma = 0.21
gps_e_sigma = 0.21
gps_h_sigma = 0.40
gps_Vg_sigma = 0.05
gps_course_sigma = gps_Vg_sigma / 10
*/
//End of sensor parameters

typedef struct {
	//gravity = MAV.gravity  # gravity constant			Investigar o MAVLINK para gravity e rho
	//rho = MAV.rho  # density of air
	float sigma; //  =  0.5 // low pass filter gain for derivative

	//----------roll loop-------------
	float roll_kp; // = 1
	float roll_ki; // = 0.4000
	float roll_kd; // = 0.1209

	//----------course loop-------------
	float course_kp; // = 5.8067
	float course_ki; // = 0.7285

	//----------pitch loop-------------

	float pitch_kp; // = -3
	float pitch_kd; // = -1.1622
	float theta_c_climb; // = 0.5236
	float delta_e_max; // = 0.5236

	//----------altitude--------------

	float altitude_state; // = 0
	float altitude_kp; // = 0.0190
	float altitude_ki; // = 6.3312e-04
	float altitude_hold_zone; // = 25  / moving saturation limit around current altitude
	float altitude_take_off_zone; // = 40

	//---------airspeed hold using throttle---------------
	float airspeed_throttle_kp; // = 0.0049
	float airspeed_throttle_ki; // = 0.0013

	//---------airspeed hold using pitch---------------
	float airspeed_pitch_kp; // = -0.1355
	float airspeed_pitch_ki; // = -0.0270

	//----------sideslip-------------
	float sideslip_kp; // 3
	float sideslip_ki; // 2.5378

	//----------throttle-------------
	float throttle_trim; // = 0.6031

	//--------surface_limits------------
	float delta_a_max; // = 0.3491
	float delta_r_max; // = 0.7854
} parameters;

/* =============================================================================
 *
 * End of parameters.h
 *
 * =============================================================================
 */