/*
	Copyright 2016 Benjamin Vedder	benjamin@vedder.se

	This file is part of the VESC firmware.

	The VESC firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The VESC firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "datatypes.h"

// Functions
void terminal_process_string(char *str);
void terminal_add_fault_data(fault_data *data);
void terminal_register_command_callback(
		const char* command,
		const char *help,
		const char *arg_names,
		void(*cbf)(int argc, const char **argv));
void terminal_unregister_callback(void(*cbf)(int argc, const char **argv));

// EarthSense Commands
void earthsense_detect_and_apply_r_l(void);
void earthsense_detect_and_apply_foc_linkage(float current_, float min_rpm_, float duty_);
void earthsense_detect_and_apply_hall_sensors(float current_);
void earthsense_detect_and_apply_foc_all(void);
void earthsense_set_current_kp(float current_kp_);
void earthsense_set_current_ki(float current_ki_);
void earthsense_set_observer_gain(float observer_gain_);

#endif /* TERMINAL_H_ */
