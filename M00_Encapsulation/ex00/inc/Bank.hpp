# pragma once
# include "_utils.hpp"
# include "Money.hpp"
# include "AccountUUID.hpp"

/**
 * @brief The Bank class manages multiple accounts and handles transactions.
 * @note
 *      - It maintains a map of client Accounts and AccountUUIDs and the bank's liquidity.
 *      - The bank charges a fee for inflows, defined in basis points (bps).
 *      - The Account class is nested within Bank and encapsulates account balance management.
 *      - All methods that modify state perform necessary validations and throw exceptions on errors.
 */
class Bank {
    public:
        Bank();
        ~Bank();

    /**********************************/
    class Account {
        private:
            // Attributes
            Money               _balance;
            
            // Constructor
            Account();
            // Friendship
            friend class Bank;
        public:
            // Destructor
            ~Account();
            // Getter
            const Money &getBalance() const;
    }; 
    /**********************************/

        // APIs about Account
        AccountUUID createAccount();
        void deleteAccount(const AccountUUID &account);
        // APIs about Transactions
        void deposit(const AccountUUID &account, const Money &amount);
        void withdraw(const AccountUUID &account, const Money &amount);
        void giveLoan(const AccountUUID &account, const Money &amount);
        // Getters
        const Money &getLiquidity() const;
        const Account& operator[](const AccountUUID& id) const;
        // Account& operator[](const AccountUUID& id);

    private:
        // Attributes
        std::map<AccountUUID, Account>      _clientAccounts;
        static const unsigned short         _FEEBPS = 500;
        static const unsigned short         _MAXBPS = 10000;
        Money                               _liquidity;

        // Static utils methods (general)
        static Money feeFrom(const Money &amount);
        // Private methods
        Account& getAccountOrThrow(const AccountUUID &id);
        void creditWithInflowFee(Account &acc, const Money &gross);
};