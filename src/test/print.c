/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:36:21 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/08 14:42:38 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scenario_start(char *scenario_name)
{
	ft_printf("Scenario: %s\n", scenario_name);
}

t_unt	scenario_end(t_unt errors)
{
	if (errors)
		ft_printf("=> Finished Scenario with %d Errors\n\n", errors);
	else
		ft_printf("=> Validated Scenario\n\n");
	return (errors);
}

void	given(char *state)
{
	ft_printf("> Given %s\n", state);
}

bool	test_print(char *test_name, bool status)
{
	ft_printf(" - Test %s: ", test_name);
	if (status)
		ft_printf("Passed [OK]\n");
	else
		ft_printf("Failed [KO]\n");
	return (!status);
}
