# include "AccountUUID.hpp"

/*************************************
 * @brief Static member initialization
 */
unsigned long AccountUUID::_counter = 0;

/******************************************
 * @brief Methods for the AccountUUID class
 */
AccountUUID::AccountUUID() : _uuid(generateUUID()) {}
AccountUUID::~AccountUUID() {}

std::string AccountUUID::base36encoder(unsigned long value) {
    if (value == 0) return "0";
    std::string base36 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string result;
    do {
        result.push_back(base36[value % 36]);
        value /= 36;
    } while (value > 0);
    std::reverse(result.begin(), result.end());
    return result;
}

std::string AccountUUID::generateUUID() {
    unsigned long t = static_cast<unsigned long>(std::time(nullptr));
    ++_counter;
    return base36encoder(t) + "-" + base36encoder(_counter);
}

const std::string &AccountUUID::getUUID() const {
    return this->_uuid;
}

bool AccountUUID::operator<(const AccountUUID& rhs) const {
    return this->_uuid < rhs._uuid;
}