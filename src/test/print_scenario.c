/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scenario.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:36:21 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/25 15:37:57 by ulevallo         ###   ########.fr       */
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
	{
		ft_printf("=> Failed Scenario with %d Error", errors);
		if (errors > 1)
			ft_printf("s");
		ft_printf("\n\n");
	}
	else
		ft_printf("=> Validated Scenario\n\n");
	return (errors);
}

bool	ex(char *state, bool test)
{
	ft_printf("%s", state);
	if (test)
		ft_printf(" [OK]\n", state);
	else
		ft_printf(" [KO]\n", state);
	return (!test);
}

void	given(char *state, t_unt a)
{
	if (!a)
		ft_printf("  Given %s\n", state);
	else
		ft_printf("    And %s\n", state);
}

void	when(char *state, t_unt a)
{
	if (a)
		ft_printf("    And");
	else
		ft_printf("  When");
	ft_printf(" %s\n", state);
}

bool	then(char *test_name, bool status, t_unt a)
{
	if (a)
		ft_printf("    And");
	else
		ft_printf("  Then");
	ft_printf(" %s: ", test_name);
	if (status)
		ft_printf("Passed [OK]\n");
	else
		ft_printf("Failed [KO]\n");
	return (!status);
}

void	tests_start(char *tests_name, t_unt a)
{
	if (a)
		ft_printf(">");
	ft_printf("Starting %s tests \\/\n\n", tests_name);
}

void	tests_end(char *name, t_unt err)
{
	ft_printf("==> Finished %s tests ", name);
	if (err)
	{
		ft_printf("with %d Error", err);
		if (err > 1)
			ft_printf("s");
	}
}
