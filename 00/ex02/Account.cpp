/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Account.cpp                          :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/31 06:54:23      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/31 06:55:48     #########  #########  ###      ###      */
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
	std:: cout << "TODO \n";
	return ;
}

void Account::_displayTimestamp()
{
	std::cout << "[19920104_091532] ";
}
