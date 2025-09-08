# pragma once
# include "_utils.hpp"
# include "Bank.hpp"

class Bank::Account {
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