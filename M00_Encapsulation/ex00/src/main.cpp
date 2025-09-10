# include "_utils.hpp"
# include "Bank.hpp"
# include "AccountUUID.hpp"
# include "Account.hpp"


int main() {
    try {
        Bank fakeBank;

        // Accounts creation
        std::cout << B_BLACK "CREATING ACCOUNTS" RESET << std::endl;
        AccountUUID accA = fakeBank.createAccount();
        AccountUUID accB = fakeBank.createAccount();
        std::cout << "Account " << accA.getUUID() << " " << B_GREEN "created" RESET << std::endl;
        std::cout << "Account " << accB.getUUID() << " " << B_GREEN "created" RESET << std::endl;

        // Deposits
        std::cout << B_BLACK "DEPOSITS" RESET << std::endl;
        fakeBank.deposit(accA, Money(10000)); // 100 units
        fakeBank.deposit(accB, Money(20000)); // 200 units
        std::cout << "Account " << accA.getUUID() << " balance: " << S_BOLD B_YELLOW << fakeBank[accA].getBalance() << RESET << std::endl;
        std::cout << "Account " << accB.getUUID() << " balance: " << S_BOLD B_YELLOW << fakeBank[accB].getBalance() << RESET << std::endl;
        std::cout << "Bank liquidity: " << S_BOLD B_BRIGHT_MAGENTA << fakeBank.getLiquidity() << RESET << std::endl;
        // Withdrawals
        std::cout << B_BLACK "WITHDRAWALS" RESET << std::endl;
        fakeBank.withdraw(accA, Money(2500)); // 25 units
        fakeBank.withdraw(accB, Money(250)); // 2.5 units
        std::cout << "Account " << accA.getUUID() << " balance: " << S_BOLD B_YELLOW << fakeBank[accA].getBalance() << RESET << std::endl;
        std::cout << "Account " << accB.getUUID() << " balance: " << S_BOLD B_YELLOW << fakeBank[accB].getBalance() << RESET << std::endl;
        std::cout << "Bank liquidity: " << S_BOLD B_BRIGHT_MAGENTA << fakeBank.getLiquidity() << RESET << std::endl;
        // Loans
        std::cout << B_BLACK "LOANS" RESET << std::endl;
        fakeBank.giveLoan(accA, Money(1000)); // 10 units
        fakeBank.giveLoan(accB, Money(500)); // 5 units
        std::cout << "Account " << accA.getUUID() << " balance: " << S_BOLD B_YELLOW << fakeBank[accA].getBalance() << RESET << std::endl;
        std::cout << "Account " << accB.getUUID() << " balance: " << S_BOLD B_YELLOW << fakeBank[accB].getBalance() << RESET << std::endl;
        std::cout << "Bank liquidity: " << S_BOLD B_BRIGHT_MAGENTA << fakeBank.getLiquidity() << RESET << std::endl;
        // Deleting account
        std::cout << B_BLACK "DELETING ACCOUNTS" RESET << std::endl;
        fakeBank.deleteAccount(accA);
        std::cout << "Account " << accA.getUUID() << " " << B_RED "deleted" RESET << std::endl;
        // Accessing deleted account (should throw)
        std::cout << "Account " << accA.getUUID() << " balance: " << F_BRIGHT_RED << fakeBank[accA].getBalance() << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << F_BRIGHT_RED << "[Erro]: "  << e.what() << RESET << "\n";
    }
}
