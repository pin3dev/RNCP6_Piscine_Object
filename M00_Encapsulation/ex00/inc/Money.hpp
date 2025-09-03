# pragma once
# include "_utils.hpp"

/**
 * @brief A simple struct to represent money amounts in cents.
 * @param _value a raw value in cents (can be negative).
 * @note 
 *      - All members and methods are public for simplicity.
 *      - Explicit constructor to avoid implicit conversions.
 */
struct Money {
    cents_t _value; 

    explicit Money(cents_t initValue); 
    ~Money();

    // Getter
    const cents_t& raw() const;
    // Aritmetic Operators
    Money& operator+=(const Money& o);
    Money& operator-=(const Money& o);
    Money operator+(const Money& o) const;
    Money operator-(const Money& o) const;
    // Compare Operators
    bool operator==(const Money& o) const;
    bool operator>(const Money& o) const;
    bool operator>=(const Money& o) const;
    bool operator<=(const Money& o) const;
    bool operator<(const Money& o) const;
    bool operator!=(const Money& o) const;
    // Friendship
    friend std::ostream& operator<<(std::ostream& os, const Money& m);
};
