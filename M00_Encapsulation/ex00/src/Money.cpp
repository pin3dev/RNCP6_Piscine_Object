# include "Money.hpp"

/******************************************
 * @brief Methods for the Money class
 */
Money::Money(cents_t initValue) : _value(initValue) {}
Money::~Money() {}

cents_t const& Money::raw() const { return this->_value; }

Money& Money::operator+=(const Money& o) { this->_value += o._value; return *this; }
Money& Money::operator-=(const Money& o) { this->_value -= o._value; return *this; }

Money Money::operator+(const Money& o) const { return Money(this->_value + o._value); }
Money Money::operator-(const Money& o) const { return Money(this->_value - o._value); }

bool Money::operator==(const Money& o) const { return this->_value == o._value; }
bool Money::operator>(const Money& o) const { return this->_value > o._value; }
bool Money::operator<(const Money& o) const { return this->_value < o._value; }
bool Money::operator>=(const Money& o) const { return this->_value >= o._value; }
bool Money::operator<=(const Money& o) const { return this->_value <= o._value; }
bool Money::operator!=(const Money& o) const { return this->_value != o._value; }


#include <ostream>   // std::ostream
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const Money& m) {
    // 1) separa sinal e toma valor absoluto de forma segura
    const cents_t v = m.raw();
    const bool neg = (v < 0);
    // Cuidado: negar o menor inteiro pode estourar; converta antes
    unsigned long long absv = neg ? static_cast<unsigned long long>(-(v)) 
                                  : static_cast<unsigned long long>( v );

    // 2) parte inteira e “centavos”
    unsigned long long major = absv / 100ULL;
    unsigned long long minor = absv % 100ULL;

    // 3) escreve sinal, parte inteira e centavos com 2 dígitos
    if (neg) os << '-';
    os << major << '.';

    // zero-padding sem “grudar” estado no stream
    char oldFill = os.fill();
    std::streamsize oldWidth = os.width();
    os << std::setw(2) << std::setfill('0') << minor;
    os.fill(oldFill);
    os.width(oldWidth);

    return os;
}