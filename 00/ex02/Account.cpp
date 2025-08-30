/* ************************************************************************** */
/*                                          ::::::::    ::::::::   :::::::::  */
/*   Account.cpp                          :+:    :+:  :+:    :+:  :+:         */
/*                                             +:+         :+:   :+:          */
/*   github.com/d-branco                    +#+         +#+      +#+#+#+      */
/*                                       +#+         +#+              +#+     */
/*   Created: 2025/08/30 20:20:36      #+#         #+#      +#+        #+#    */
/*   Updated: 2025/08/30 20:24:13     #########  #########  ###      ###      */
/*                                                            ########        */
/* ************************************************************************** */

#include "Account.hpp"

class Account
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
}
