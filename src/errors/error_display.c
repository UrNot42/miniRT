/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:03:47 by ulevallo          #+#    #+#             */
/*   Updated: 2024/04/03 11:15:51 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	p_err_crit(t_unt error_code)
{
	if (error_code == ERR_MEM)
		ft_fprintf(2, ERM_MEM);
	else if (error_code == ERR_OPEN)
		ft_fprintf(2, ERM_OPEN);
	else if (error_code == ERR_CLOSE)
		ft_fprintf(2, ERM_CLOSE);
	else if (error_code == ERR_FORK)
		ft_fprintf(2, ERM_FORK);
	else if (error_code == ERR_READ)
		ft_fprintf(2, ERM_READ);
}

void	p_err_minilibx(t_unt error_code)
{
	if (error_code == ERR_MLX_INIT)
		ft_fprintf(2, ERM_MLX_INIT);
	else if (error_code == ERR_MLX_IMG)
		ft_fprintf(2, ERM_MLX_IMG);
	else if (error_code == ERR_MLX_WIN)
		ft_fprintf(2, ERM_MLX_WIN);
}

void	p_err_parsing(t_unt error_code)
{
	if (error_code == ERR_LINE)
		ft_fprintf(2, ERM_LINE);
	else if (error_code == ERR_NUMBER)
		ft_fprintf(2, ERM_NUMBER);
	else if (error_code == ERR_COLOR)
		ft_fprintf(2, ERM_COLOR);
	else if (error_code == ERR_IDENTIFIER)
		ft_fprintf(2, ERM_IDENTIFIER);
	else if (error_code == ERR_POS)
		ft_fprintf(2, ERM_POS);
	else if (error_code == ERR_FOV)
		ft_fprintf(2, ERM_FOV);
	else if (error_code == ERR_RATIO)
		ft_fprintf(2, ERM_RATIO);
	else if (error_code == ERR_HEIGHT)
		ft_fprintf(2, ERM_HEIGHT);
	else if (error_code == ERR_DIAMETER)
		ft_fprintf(2, ERM_DIAMETER);
	else if (error_code == ERR_NORM)
		ft_fprintf(2, ERM_NORM);
	else if (error_code == ERR_AMB_LIGHT)
		ft_fprintf(2, ERM_AMB_LIGHT);
	else if (error_code == ERR_CAMERA)
		ft_fprintf(2, ERM_CAMERA);
	p_err_parsing_rest(error_code);
}

void	p_err_engine(t_unt error_code)
{
	if (error_code == ERR_ENGX)
		ft_fprintf(2, ERM_ENGX);
	else if (error_code == ERR_OBJ_MAX_SZ)
		ft_fprintf(2, ERM_OBJ_MAX_SZ);
}

void	p_err_debug(t_unt error_code)
{
	if (error_code == DB_START)
		ft_fprintf(2, DBM_START);
	else if (error_code == DB_END)
		ft_fprintf(2, DBM_END);
	else if (error_code == DB_VAL)
		ft_fprintf(2, DBM_VAL);
	else if (error_code == DB_FCALL)
		ft_fprintf(2, DBM_FCALL);
	else if (error_code == DB_HI)
		ft_fprintf(2, DBM_HI);
	else if (error_code == DB_C1)
		ft_fprintf(2, DBM_C1);
	else if (error_code == DB_C2)
		ft_fprintf(2, DBM_C2);
	else if (error_code == DB_C3)
		ft_fprintf(2, DBM_C3);
	else if (error_code == DB_FREE)
		ft_fprintf(2, DBM_FREE);
}
