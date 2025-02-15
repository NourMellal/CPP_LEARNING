/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:58:33 by nmellal           #+#    #+#             */
/*   Updated: 2025/01/22 15:30:18 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int     Account::_nbAccounts = 0;
int     Account::_totalAmount = 0;
int     Account::_totalNbDeposits = 0;
int     Account::_totalNbWithdrawals = 0;

Account::Account(int initial_depo) : _accountIndex(_nbAccounts), _amount(initial_depo), _nbDeposits(0), _nbWithdrawals(0) {
    
    _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex  << ";amount:" << _amount << ";created" << std::endl ;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

int Account::checkAmount() const {
    return (this->_amount);
}

void    Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{

    time_t curr_time;
    struct tm *date;

    curr_time = time(NULL);
    date = localtime(&curr_time);

    std::cout << "[" << (date->tm_year + 1900);

    if (date->tm_mon + 1 < 10)
    {
        std::cout << "0";
    }
    std::cout << (date->tm_mon + 1);

    if (date->tm_mday < 10)
    {
        std::cout << "0";
    }
    std::cout << date->tm_mday << "_";
    
    if (date->tm_hour < 10)
    {
        std::cout << "0";
    }
    std::cout << date->tm_hour;
    
    if (date->tm_min < 10)
    {
        std::cout << "0";
    }
    std::cout << date->tm_min;
    
    if (date->tm_sec < 10)
    {
        std::cout << "0";
    }
    std::cout << date->tm_sec << "] ";
}

void    Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";" ;
    std::cout << "total:" << _totalAmount << ";" ;
    std::cout << "deposits:" << _totalNbDeposits << ";" ;
    std::cout << "withdrawls:" << _totalNbWithdrawals << std::endl ;   
}

void Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit ;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
    if (withdrawal > this->_amount) {
        std::cout << "refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}