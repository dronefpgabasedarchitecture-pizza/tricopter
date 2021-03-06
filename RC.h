/*
 * RC.h
 *
 *  Created on: Feb 25, 2012
 *      Author: jairo
 */

#ifndef RC_H_
#define RC_H_

#include "wirish.h"
#include "ppm-decode.h"

#define CH_ROLL 1
#define CH_PITCH 2
#define CH_THROTTLE 3
#define CH_YAW 4
#define CH_AUX1 5
#define CH_AUX2 6
#define CH_AUX3 7
#define CH_AUX4 8

#define CH_INVALID 0.0
#define ERROR_SYNC_PULSE -1
#define ERROR_SYNC 1
#define SUCCESS 0

#define SYNC_CONFIDENCE_MINIMUM 5

class RC {
public:
	RC();

	void 	init();
	void 	update();
	void 	store_ppm_sum();
	uint16 	status();
	uint16  isOK();
	float 	get_channel(int channel);
	int 	get_sync_pulse();

private:
	uint16 	_ppm_sum[9];

	// ppm-decode types and data
	int 			_sp;
	float 		_rcCmd[8];

	int 	_sync_error;

	float 	_throttle;
	float 	_pitch;
	float 	_yaw;
	float 	_roll;
	float 	_aux1;
	float 	_aux2;
	float 	_aux3;
	float 	_aux4;
};

#endif /* RC_H_ */
