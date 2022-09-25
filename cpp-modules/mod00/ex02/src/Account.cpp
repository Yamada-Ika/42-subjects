#include "Account.hpp"

#include <iostream>
#include <time.h>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
  _accountIndex = _nbAccounts++;
  _amount = initial_deposit;
  _nbDeposits = 0;
  _nbWithdrawals = 0;

  _totalAmount += _amount;

  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "created";
  std::cout << std::endl;
}

Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed";
    std::cout << std::endl;
}

// static
int Account::getNbAccounts( void ) {
  return _nbAccounts;
}

int Account::getTotalAmount( void ) {
  return _totalAmount;
}

int Account::getNbDeposits( void ) {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
  _displayTimestamp();

  std::cout << "accounts:" << getNbAccounts() << ";";
  std::cout << "total:" << getTotalAmount() << ";";
  std::cout << "deposits:" << getNbDeposits() << ";";
  std::cout << "withdrawals:" << getNbWithdrawals();
  std::cout << std::endl;
}
// static

void	Account::makeDeposit( int deposit ) {
    _nbDeposits++;
    _totalNbDeposits++;

    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << _amount + deposit << ";";
    std::cout << "nb_deposits:" << 1;
    std::cout << std::endl;

    _amount += deposit;
    _totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _nbWithdrawals++;
    _totalNbWithdrawals++;

    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";

    if (_amount - withdrawal > 0) {
        std::cout << "withdrawal:" << withdrawal << ";";
    } else {
        std::cout << "withdrawal:refused";
        _nbWithdrawals--;
        _totalNbWithdrawals--;
        std::cout << std::endl;
        return false;
    }

    std::cout << "amount:" << _amount - withdrawal << ";";
    std::cout << "nb_withdrawals:" << 1;
    std::cout << std::endl;

    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    return true;
}

int		Account::checkAmount( void ) const {
  return 0;
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals;

    std::cout << std::endl;
}

void	Account::_displayTimestamp( void ) {
  time_t timer;
  struct tm *t_st;

  time(&timer);
  t_st = localtime(&timer);
  std::cout << "[";
  std::cout << std::setfill('0') << std::setw(4)<< t_st->tm_year + 1900;
  std::cout << std::setfill('0') << std::setw(2)<< t_st->tm_mon + 1;
  std::cout << std::setfill('0') << std::setw(2)<< t_st->tm_mday;
  std::cout << "_";
  std::cout <<std::setfill('0') << std::setw(2) <<  t_st->tm_hour;
  std::cout << std::setfill('0') << std::setw(2) << t_st->tm_min;
  std::cout << std::setfill('0') << std::setw(2) << t_st->tm_sec;
  std::cout << "] ";
}
