#pragma once
#include <iostream>
#include <cmath>


class Angle {
	double degrees;
	double minutes;
	const double one_degrees_in_radian = std::acos(-1.0) / 180; // константа - 1 градус в радианах
public:
	// конструктор без параметров
	Angle() {
		this->degrees = 0;
		this->minutes = 0;
	}
	// конструктор задающий величину переменным degrees, minutes
	Angle(double _degrees, double _minutes) {
		this->degrees = _degrees;
		this->minutes = _minutes;
	}

	int get_degrees() {
		return this->degrees;
	}
	int get_minutes() {
		return this->minutes;
	}
	void set_degrees(double _degrees) {
		this->degrees = _degrees;
	}
	void set_minutes(double _minutes) {
		this->minutes = _minutes;
	}
	void to_string() const{
		std::cout << "degrees: " << this->degrees << "\nminutes: " << this->minutes;
	}

	double conversion_to_radians(double _degrees, double _minutes);

	int normalize_360(double _degrees, double _minutes);

	double increasing_angle_by_given_amount(double _degrees, double _minutes, double _amount);

	double reducing_angle_by_given_amount(double _degrees, double _minutes, double _amount);



};