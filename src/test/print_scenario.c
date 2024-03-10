/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scenario.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:36:21 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/10 16:20:39 by ulevallo         ###   ########.fr       */
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

void	given(char *state, t_unt a)
{
	if (!a)
		ft_printf("> Given %s\n", state);
	else
		ft_printf(">   And %s\n", state);
}

void	when(char *state, t_unt a)
{
	if (a)
		ft_printf(" And");
	else
		ft_printf("When");
	ft_printf(" %s\n", state);
}

bool	then(char *test_name, bool status, t_unt a)
{
	if (a)
		ft_printf(" And");
	else
		ft_printf("Then");
	ft_printf(" %s: ", test_name);
	if (status)
		ft_printf("Passed [OK]\n");
	else
		ft_printf("Failed [KO]\n");
	return (!status);
}
