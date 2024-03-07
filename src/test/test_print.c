/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:36:21 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/07 12:18:10 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scenario_start(char *scenario_name)
{
	ft_printf("Scenario: %s\n", scenario_name);
}

t_unt	scenario_end(char *scenario_name, t_unt errors)
{
	if (errors)
		ft_printf("=> Finished %s with %d Errors\n\n", scenario_name, errors);
	else
		ft_printf("=> Validated %s\n\n", scenario_name);
	return (errors);
}

void	given(char *state)
{
	ft_printf(">Given %s\n", state);
}

bool	test_print(char *test_name, bool status)
{
	ft_printf(" - Test %s: ", test_name);
	if (status)
		ft_printf("Passed [OK]\n");
	else
		ft_printf("Failed [KO]\n");
	return (status);
}
