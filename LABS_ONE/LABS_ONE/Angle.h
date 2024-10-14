#pragma once
#include <iostream>
#include <cmath>
#include <string>
//using std::string;


class Angle {

	int degrees;
	int minutes;
	const double one_degrees_in_radian = std::acos(-1.0) / 180; // константа - 1 градус в радианах

public:
	// конструктор без параметров
	Angle() {
		degrees = 0;
		minutes = 0;
	}
	// конструктор задающий величину переменным degrees, minutes
	Angle(int _degrees, int _minutes) {
		degrees = _degrees;
		minutes = _minutes;
	}

	int get_degrees() {
		return degrees;
	}
	int get_minutes() {
		return minutes;
	}
	void set_degrees(int _degrees) {
		degrees = _degrees;
	}
	void set_minutes(int _minutes) {
		minutes = _minutes;
	}
	std::string to_string();

	double conversion_to_radians(double _degrees, double _minutes);

	void normalize_360();

	void reducing_angle_by_given_amount(Angle other_angle);

	double sin_angle();

	bool comparing_two_angles(Angle other_angle);

	void increasing_angle_by_given_amount(Angle other_angle);

	~Angle() = default;
};