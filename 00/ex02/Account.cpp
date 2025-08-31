/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Account.cpp                          :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 07:08:45      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 07:23:35     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Account.hpp"

#include <ctime>
#include <iostream>

/*class Account
{
  public:
	typedef Account t;

	static int		getNbAccounts(void);
	static int		getTotalAmount(void);
	static int		getNbDeposits(void);
	static int		getNbWithdrawals(void);
	static void		displayAccountsInfos(void);

	Account(int initial_deposit);
	~Account(void);

	void makeDeposit(int deposit);
	bool makeWithdrawal(int withdrawal);
	int	 checkAmount(void) const;
	void displayStatus(void) const;

  private:
	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void _displayTimestamp(void);

	int			_accountIndex;
	int			_amount;
	int			_nbDeposits;
	int			_nbWithdrawals;

	Account(void);
}*/

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	std::cout << "TODO displayAccountsInfos()\n";
	return;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_totalAmount = initial_deposit;
}

Account::~Account()
{
	_displayTimestamp();
}

void Account::makeDeposit(int deposit)
{
	std::cout << "TODO makeDeposit()\n";
	(void) deposit;
	return;
}

bool Account::makeWithdrawal(int withdrawal)
{
	std::cout << "TODO makeWithdrawal()\n";
	(void) withdrawal;
	return (false);
}

int Account::checkAmount(void) const
{
	std::cout << "TODO checkAmount()\n";
	return (0);
}

void Account::displayStatus(void) const
{
	std::cout << "TODO displayStatus()\n";
	return;
}

void Account::_displayTimestamp()
{
	std::cout << "TODO timestamps\n";
	std::cout << "[19920104_091532] ";
}

Account::Account()
{
	_displayTimestamp();
	_totalAmount = 0;
}
