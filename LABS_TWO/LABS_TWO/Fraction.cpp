#include "Fraction.h"

Fraction Fraction::operator+(const Fraction& other_fraction) const {
    long int  new_integer_part = *other_fraction.integer_part + *integer_part;
    unsigned short  new_fractional_part = *other_fraction.fractonal_part + *fractonal_part;

    if (new_fractional_part >= 100) {
        new_integer_part += new_fractional_part / 100;
        new_fractional_part %= 100;
    }

    return Fraction(new_integer_part, new_fractional_part);
}

Fraction Fraction::operator-(const Fraction& other_fraction) const
{
    long int  new_integer_part = *integer_part - *other_fraction.integer_part;
    unsigned short  new_fractional_part = *fractonal_part - *other_fraction.fractonal_part;

    if (new_fractional_part < 0) {
        --new_integer_part;
        new_fractional_part += 100;
    }

    return Fraction(new_integer_part, new_fractional_part);
}

Fraction Fraction::operator*(const Fraction& other_fraction) const
{
    long int new_integer_part = (*integer_part * 100 + *fractonal_part) * (*other_fraction.integer_part * 100 + *other_fraction.fractonal_part) / 10000;
    unsigned short  new_fractional_part = (*integer_part * 100 + *fractonal_part) * (*other_fraction.integer_part * 100 + *other_fraction.fractonal_part) % 10000 % 100;

    return Fraction(new_integer_part, new_fractional_part);
}

Fraction Fraction::operator/(const Fraction& other_fraction) const
{
    if ((*other_fraction.integer_part == 0) && (*other_fraction.fractonal_part == 0)) {
        throw std::runtime_error("division by ZERO!");
    }

    long int total_num1 = *integer_part * 100 + *fractonal_part;
    long int total_num2 = *other_fraction.integer_part * 100 + *other_fraction.fractonal_part;

    long int new_integer_part = total_num1 / total_num2;
    unsigned short  new_fractional_part = (total_num1 % total_num2) * 100 / total_num2;

    return Fraction(new_integer_part, new_fractional_part);
}

bool Fraction::operator<(const Fraction& other_fraction) const
{
    return (*integer_part < *other_fraction.integer_part) && (*fractonal_part < *other_fraction.fractonal_part);
}

bool Fraction::operator<=(const Fraction& other_fraction) const
{
    return (*integer_part <= *other_fraction.integer_part) && (*fractonal_part <= *other_fraction.fractonal_part);
}

bool Fraction::operator>(const Fraction& other_fraction) const
{
    return (*integer_part > *other_fraction.integer_part) && (*fractonal_part > *other_fraction.fractonal_part);
}

bool Fraction::operator>=(const Fraction& other_fraction) const
{
    return (*integer_part >= *other_fraction.integer_part) && (*fractonal_part >= *other_fraction.fractonal_part);
}

bool Fraction::operator==(const Fraction& other_fraction) const
{
    return (*integer_part == *other_fraction.integer_part) && (*fractonal_part == *other_fraction.fractonal_part);
}

bool Fraction::operator!=(const Fraction& other_fraction) const
{
    return (*integer_part != *other_fraction.integer_part) && (*fractonal_part != *other_fraction.fractonal_part);
}

Fraction& Fraction::operator=(const Fraction& obj)
{
    *integer_part = *obj.integer_part;
    *fractonal_part = *obj.fractonal_part;
     return *this;
}

std::ostream& operator<<(std::ostream& out, Fraction obj)
{
    return out << *obj.integer_part << " " << *obj.fractonal_part; 
}

std::istream& operator>>(std::istream& in, Fraction obj)
{
    int integer_part, fractonal_part;
    in >> integer_part >> fractonal_part;
    obj = Fraction(integer_part, fractonal_part);
    return in;
}