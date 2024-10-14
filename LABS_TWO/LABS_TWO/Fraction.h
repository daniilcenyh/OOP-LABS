#pragma once
#include <iostream>

class Fraction {

	long int* integer_part;

	unsigned short* fractonal_part;

	//int count_digits_after_decimal_point;
	
public:

	Fraction() : integer_part(0), fractonal_part(0) {};

	Fraction(long int _integer_part, unsigned short _fractonal_part) {
		integer_part = new long int(_integer_part);
		fractonal_part = new unsigned short(_fractonal_part);
		//count_digits_after_decimal_point = _count_digits_after_decimal_point;
	};

	Fraction(const Fraction& other) {
		integer_part = new long int(*other.integer_part);
		fractonal_part = new unsigned short(*other.fractonal_part);
		//count_digits_after_decimal_point = other.count_digits_after_decimal_point;
	};

	~Fraction() {
		delete integer_part;
		integer_part = nullptr;
		delete fractonal_part;
		fractonal_part = nullptr;
	}

	int get_integer_part() {
		return *integer_part;
	}

	int get_fractonal_part() {
		return *fractonal_part;
	}

	void set_integer_part(int elem) {
		integer_part = new long int(elem);
	}

	void set_fractonal_part(int elem) {
		fractonal_part = new unsigned short(elem);
	}

	void display() {
		std::cout << *integer_part << "." << *fractonal_part << std::endl;
	}

	Fraction operator+(const Fraction& other_fraction) const;
	Fraction operator-(const Fraction& other_fraction) const;
	Fraction operator*(const Fraction& other_fraction) const;
	Fraction operator/(const Fraction& other_fraction) const;

	bool operator<(const Fraction& other_fraction) const;
	bool operator<=(const Fraction& other_fraction) const;
	bool operator>(const Fraction& other_fraction) const;
	bool operator>=(const Fraction& other_fraction) const;
	bool operator==(const Fraction& other_fraction) const;
	bool operator!=(const Fraction& other_fraction) const;

	Fraction& operator=(const Fraction& obj);

	friend std::ostream& operator<<(std::ostream& out,Fraction obj);
	friend std::istream& operator>>(std::istream& in, Fraction obj);
};