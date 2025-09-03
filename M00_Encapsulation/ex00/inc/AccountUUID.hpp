#pragma once
#include "_utils.hpp"
class Bank; // forward declaration

/**
 * @brief The AccountUUID class generates and manages unique identifiers (UUIDs) for bank accounts.
 * Each UUID is a string representation of a unique number, encoded in base 36.
 * @param _counter A static counter that increments with each new UUID created, ensuring uniqueness.
 * @param _uuid The string representation of the UUID.
 * @note friend class Bank Allows the Bank class to access private members of AccountUUID.
 */
class AccountUUID {
    private:
        // Attributes
        static unsigned long     _counter;
        const std::string        _uuid;
        
        // Friendship
        friend class Bank;

        // Constructor
        AccountUUID();
        
        // Static utils methods
        static std::string generateUUID();
        static std::string base36encoder(unsigned long value);
    public:
        // Destructor
        ~AccountUUID();
        // Getter
        const std::string &getUUID() const;
        // Operator
        bool operator<(const AccountUUID& rhs) const;
};