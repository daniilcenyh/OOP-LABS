#include <iostream>
#include "Angle.h"
#include <math.h>

double Angle::conversion_to_radians(double _degrees, double _minutes) 
{
	double result_in_radians;
	double minutes_in_degrees = _minutes / 60;
	
	result_in_radians = (minutes_in_degrees + _degrees) * this->one_degrees_in_radian;

	return result_in_radians;
}

int Angle::normalize_360(double _degrees, double _minutes)
{	
	double minutes_in_degrees = _minutes / 60;
	int angle = _degrees + minutes_in_degrees;

	angle = angle % 360;

	if (angle < 0) angle += 360;

	return angle;
}

double Angle::increasing_angle_by_given_amount(double _degrees, double _minutes, double _amount)
{
	double result = _degrees;
	double minutes_in_degrees = _minutes / 60;
	result += minutes_in_degrees;

	result += _amount;

	return result;

}

double Angle::reducing_angle_by_given_amount(double _degrees, double _minutes, double _amount)
{
	double result = _degrees;
	double minutes_in_degrees = _minutes / 60;
	result += minutes_in_degrees;

	result -= _amount;

	return result;
}

double Angle::sinus_angle(double _degrees, double _minutes)
{
	double minutes_in_degrees = _minutes / 60;
	double result = _degrees + minutes_in_degrees;

	return std::sin(result);

}

