/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:48:59 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 13:50:25 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	p_err_file(t_unt error_code)
{
	if (error_code == ERR_FILEEXT)
		ft_fprintf(2, ERM_FILEEXT);
}

void	p_err_standard(t_unt error_code)
{
	if (error_code == ERR_NO_PROMPT)
		ft_printf(ERM_NO_PROMPT);
	else if (error_code == ERR_UNSET)
		ft_printf(ERM_UNSET);
	else if (error_code == ERR_EMPTY)
		ft_printf(ERM_EMPTY);
	else if (error_code == ERR_BAD_PROMPT)
		ft_printf(ERM_BAD_PROMPT);
}

void	p_err_parsing_rest(unsigned int error_code)
{
	if (error_code == ERR_LIGHT)
		ft_printf(ERM_LIGHT);
	else if (error_code == ERR_SIZE)
		ft_printf(ERM_SIZE);
}

/**
 * @brief ### Main print function for this program
 * @brief #### perror equivalent
 *
 * @brief
 * Using rules detailed inside the rt_error.h header file
* This function mainly checks for error code ranges and pipes the codes to
* the correct printing function
* In this function LR and RR stand for Left Range and Right Range respectively
*/
void	p_error(t_unt error_code)
{
	if (!error_code)
		printf(ERM_DEF);
	else if (ft_inr(error_code, ERR_STD_LR, ERR_STD_RR))
		p_err_standard(error_code);
	else if (ft_inr(error_code, ERR_MLX_LR, ERR_MLX_RR))
		p_err_minilibx(error_code);
	else if (ft_inr(error_code, ERR_PARS_LR, ERR_PARS_RR))
		p_err_parsing(error_code);
	else if (ft_inr(error_code, ERR_ENGN_LR, ERR_ENGN_RR))
		p_err_engine(error_code);
	else if (ft_inr(error_code, ERR_FILE_LR, ERR_FILE_RR))
		p_err_file(error_code);
	else if (ft_inr(error_code, DB_LR, DB_RR))
		p_err_debug(error_code);
	else if (ft_inr(error_code, ERR_CRIT_LR, ERR_CRIT_RR))
		p_err_crit(error_code);
}
