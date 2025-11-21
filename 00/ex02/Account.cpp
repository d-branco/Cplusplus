/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:07:11 by  #########        #+#    #+#             */
/*   Updated: 2025/11/20 15:20:20 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

int Account::_nbAccounts = 0;

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::_totalAmount = 0;

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::_totalNbDeposits = 0;

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::_totalNbWithdrawals = 0;

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << "\n";
	return;
}

Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_displayTimestamp();
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";created\n";
	_nbAccounts++;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";closed\n";
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();

	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;

	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
	std::cout << ";deposit:" << deposit << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << "\n";
	return;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
				  << ";withdrawal:refused" << "\n";
		return (false);
	}

	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;

	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	_amount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << "\n";
	return (true);
}

int Account::checkAmount() const
{
	std::cout << "checkAmount()\n";
	return (0);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << "\n";
	return;
}

// std::cout << "[19920104_091532] ";
void Account::_displayTimestamp()
{
	char   buffer[20];
	time_t now = time(NULL);

	strftime(buffer, 20, "[%Y%m%d_%H%M%S] ", localtime(&now));
	std::cout << buffer;
}

// Account::Account()
//{
//	_displayTimestamp();
//	_totalAmount = 0;
// }
