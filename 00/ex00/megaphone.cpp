/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:00:05 by abessa-m          #+#    #+#             */
/*   Updated: 2025/08/24 18:24:25 by abessa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  int i;
  int j;

  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return (EXIT_SUCCESS);
  }

  i = 1;
  while (i < argc) {
    j = 0;
    while (argv[i][j]) {
      std::cout << (char)std::toupper(argv[i][j]);
      j++;
    }
    i++;
  }
  std::cout << '\n';
  return (EXIT_SUCCESS);
}
