/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:37:10 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/07 12:04:08 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TEST_H
# define RT_TEST_H

void			test_print(char *test_name, bool state);
void			scenario_start(char *scenario_name);
unsigned int	scenario_end(char *scenario_name, unsigned int errors);

#endif
