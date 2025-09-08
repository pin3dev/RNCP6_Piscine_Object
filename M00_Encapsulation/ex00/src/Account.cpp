# include "Bank.hpp"
# include "Account.hpp"

/**************************
 * @brief Methods for the nested Account class within Bank
 **************************/

Bank::Account::Account(): _balance(Money(0)){}
Bank::Account::~Account() {}

const Money &Bank::Account::getBalance() const {
    return this->_balance;
}

const Money &Bank::getLiquidity() const {
    return this->_liquidity;
}
