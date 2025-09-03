# include "Bank.hpp"

/**************************
 * @brief Methods for the Bank class
 **************************/

Bank::Bank() : _liquidity(0) {}
Bank::~Bank() {}

// Bank::Account& Bank::operator[](const AccountUUID& id) {
//     return getAccountOrThrow(id);
// }

const Bank::Account& Bank::operator[](const AccountUUID& id) const {
    std::map<AccountUUID, Account>::const_iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end())
        throw std::runtime_error("Account not found");
    return it->second;
}

Money Bank::feeFrom(const Money &amount) {
    const cents_t fee = (amount.raw() * _FEEBPS) / _MAXBPS;
    return Money(fee);
}

Bank::Account& Bank::getAccountOrThrow(const AccountUUID& id) {
    std::map<AccountUUID, Account>::iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end()) {
        std::ostringstream oss;
        oss << "Account not found: " << id.getUUID();
        throw std::runtime_error(oss.str());
    }
    return it->second;
}

void Bank::creditWithInflowFee(Account& acc, const Money& gross) {
    if (gross.raw() <= 0) 
        throw std::runtime_error("Invalid amount");
    Money fee = feeFrom(gross);
    acc._balance += (gross - fee);
    _liquidity   += fee;
}

AccountUUID Bank::createAccount() {
    AccountUUID newUUID;
    Account newAccount;
    // this->_clientAccounts[newUUID] = newAccount;
    this->_clientAccounts.insert(std::make_pair(newUUID, newAccount));
    return newUUID;
}

void Bank::deleteAccount(const AccountUUID& account) {
    std::map<AccountUUID, Account>::iterator it = _clientAccounts.find(account);
    if (it == _clientAccounts.end())
        throw std::runtime_error("Cannot delete: account does not exist");
    this->_clientAccounts.erase(it);
}

void Bank::deposit(const AccountUUID& account, const Money& amount) {
    if (amount.raw() <= 0) 
        throw std::runtime_error("Deposit must be positive");
    Account& acc = getAccountOrThrow(account);
    creditWithInflowFee(acc, amount);
}

void Bank::withdraw(const AccountUUID& account, const Money &amount) {
    if (amount.raw() <= 0) 
        throw std::runtime_error("Withdraw must be positive");
    Account& acc = getAccountOrThrow(account);
    if (acc._balance < amount)
        throw std::runtime_error("Insufficient funds");
    acc._balance -= amount;
}

void Bank::giveLoan(const AccountUUID& account, const Money &amount) {
    if (amount.raw() <= 0) 
        throw std::runtime_error("Loan must be positive");
    if (_liquidity < amount)
        throw std::runtime_error("Bank has insufficient liquidity for loan");
    Account& acc = getAccountOrThrow(account);

    _liquidity -= amount;
    creditWithInflowFee(acc, amount);
}


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
