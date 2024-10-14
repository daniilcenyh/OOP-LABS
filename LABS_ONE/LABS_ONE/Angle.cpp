#include <iostream>
#include "Angle.h"
#include <math.h>
#include <string>


std::string Angle::to_string()
{
	return "degreess: " + std::to_string(degrees) + " " + "minutes: " + std::to_string(minutes);
}

double Angle::conversion_to_radians(double _degrees, double _minutes)
{
	double result_in_radians;
	double minutes_in_degrees = _minutes / 60;
	
	result_in_radians = (minutes_in_degrees + _degrees) * this->one_degrees_in_radian;

	return result_in_radians;
}

void Angle::normalize_360()
{
	degrees = (degrees + (minutes / 60)) % 360;
	if (degrees < 0) degrees += 360;
	minutes = 0;
}


void Angle::reducing_angle_by_given_amount(Angle other_angle)
{
	int other_angle_in_degrees = other_angle.get_minutes() / 60 + other_angle.get_degrees();

	degrees -= other_angle_in_degrees;
}

double Angle::sin_angle()
{
	double result = degrees + minutes / 60;

	return std::sin(result);
}

bool Angle::comparing_two_angles(Angle other_angle)
{
	double degrees_other_angle = other_angle.get_degrees() + other_angle.get_minutes() / 60;
	double degrees_original_angle = degrees + minutes / 60;

	if (degrees_original_angle == degrees_other_angle) {
		return true;
	}

	return false;
}

void Angle::increasing_angle_by_given_amount(Angle other_angle)
{
	int other_angle_in_degrees = other_angle.get_minutes() / 60 + other_angle.get_degrees();
	
	degrees += other_angle_in_degrees;
}




