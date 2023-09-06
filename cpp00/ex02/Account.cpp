/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 17:03:30 by bhoitzin      #+#    #+#                 */
/*   Updated: 2022/03/23 15:57:25 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

// SETTING STATIC MEMBERS
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//ACCOUNT CLASS FUNCTIONS
//-----------------------
// SIMPLE GET FUNCTIONS
int	Account::getNbAccounts( void ){
	return (_nbAccounts);
};
int	Account::getTotalAmount( void ){
	return(_totalAmount);
};
int	Account::getNbDeposits( void ){
	return(_totalNbDeposits);	
};
int	Account::getNbWithdrawals( void ){
	return(_totalNbWithdrawals);
};

void	Account::_displayTimestamp( void ){

	time_t timestamp = time(nullptr);

	char	buff[16];
	strftime(buff, sizeof(buff), "%Y%m%d_%H%M%S", localtime(&timestamp));
	std::cout << "[" << buff << "]";
};

//DISPLAY INFO FOR ALL ACCOUNTS
void	Account::displayAccountsInfos( void ){

	_displayTimestamp();
	std::cout	<< " accounts:" <<  getNbAccounts()
			  	<< ";total:" << getTotalAmount() << ";deposits:"
			  	<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
};

//MAKE A DEPOSIT
void	Account::makeDeposit( int deposit ){

	_displayTimestamp();
	std::cout	<< " index:" <<  this->_accountIndex
			  	<< ";p_amount:" << this->_amount << ";deposit:"
			  	<< deposit << ";amount:" << this->_amount + deposit
				<< ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;

	this->_nbDeposits++;
	this->_amount = this->_amount + deposit;
	_totalAmount = _totalAmount + deposit;
	_totalNbDeposits++;
};

//MAKE A WITHDRAWAL
bool	Account::makeWithdrawal( int withdrawal ){

	_displayTimestamp();
	if (withdrawal >= this->_amount)
	{
		std::cout	<< " index:" <<  this->_accountIndex
			  		<< ";p_amount:" << this->_amount << ";withdrawal:refused\n";
		return(false);
	}
	std::cout	<< " index:" <<  this->_accountIndex
			  	<< ";p_amount:" << this->_amount << ";withdrawal:"
			  	<< withdrawal << ";amount:" << this->_amount - withdrawal
				<< ";nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
	this->_nbWithdrawals++;
	this->_amount = this->_amount - withdrawal;
	_totalNbWithdrawals++;
	_totalAmount = _totalAmount - withdrawal;
	return (true);
};

// CONSTRUCTOR
Account::Account( int initial_deposit ){

	this->_amount =	initial_deposit;
	static int x = 0;
	
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = x;
	x++;
	
	_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << initial_deposit << ";created\n";
	_totalAmount = _totalAmount + initial_deposit;
	_nbAccounts++;
};

//DESTRUCTOR
Account::~Account( void ){

	_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount << ";closed\n";
	_totalAmount = _totalAmount - this->_amount;
	_totalNbDeposits = _totalNbDeposits - this->_nbDeposits;
	_totalNbWithdrawals = _totalNbWithdrawals - this->_nbWithdrawals;
	_nbAccounts--;
};

//UNUSED ??
int	Account::checkAmount( void ) const{
	return (this->_amount);
};

//DISPLAY ACCOUNT INFO
void	Account::displayStatus( void ) const{

	_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount << ";deposits:"
				<< this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
};
