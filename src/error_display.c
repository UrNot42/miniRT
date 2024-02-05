/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:03:47 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 06:22:42 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	p_err_crit(unsigned int error_code)
{
	if (error_code == ERR_MEM)
		ft_fprintf(2, ERM_MEM);
	if (error_code == ERR_OPEN)
		ft_fprintf(2, ERM_OPEN);
	if (error_code == ERR_CLOSE)
		ft_fprintf(2, ERM_CLOSE);
	if (error_code == ERR_FORK)
		ft_fprintf(2, ERM_FORK);
	if (error_code == ERR_READ)
		ft_fprintf(2, ERM_READ);
}

void	p_err_minilibx(unsigned int error_code)
{
	if (error_code == ERR_MLX_INIT)
		ft_fprintf(2, ERM_MLX_INIT);
	if (error_code == ERR_MLX_IMG)
		ft_fprintf(2, ERM_MLX_IMG);
	if (error_code == ERR_MLX_WIN)
		ft_fprintf(2, ERM_MLX_WIN);
}

void	p_err_parsing(unsigned int error_code)
{
	if (error_code == ERR_EMPTY)
		ft_fprintf(2, ERM_EMPTY);
	if (error_code == ERR_NUMBER)
		ft_fprintf(2, ERM_NUMBER);
	if (error_code == ERR_COLOR)
		ft_fprintf(2, ERM_COLOR);
	if (error_code == ERR_IDENTIFIER)
		ft_fprintf(2, ERM_IDENTIFIER);
	if (error_code == ERR_AL)
		ft_fprintf(2, ERM_AL);
	if (error_code == ERR_CAM)
		ft_fprintf(2, ERM_CAM);
	if (error_code == ERR_LIGHT)
		ft_fprintf(2, ERM_LIGHT);
	if (error_code == ERR_SP)
		ft_fprintf(2, ERM_SP);
	if (error_code == ERR_CY)
		ft_fprintf(2, ERM_CY);
	if (error_code == ERR_PL)
		ft_fprintf(2, ERM_PL);
}

void	p_err_engine(unsigned int error_code)
{
	if (error_code == ERR_ENGX)
		ft_fprintf(2, ERM_ENGX);
	if (error_code == ERR_OBJ_MAX_SZ)
		ft_fprintf(2, ERM_OBJ_MAX_SZ);
}

void	p_err_debug(unsigned int error_code)
{
	if (error_code == DB_START)
		ft_fprintf(2, DBM_START);
	if (error_code == DB_END)
		ft_fprintf(2, DBM_END);
	if (error_code == DB_VAL)
		ft_fprintf(2, DBM_VAL);
	if (error_code == DB_FCALL)
		ft_fprintf(2, DBM_FCALL);
	if (error_code == DB_HI)
		ft_fprintf(2, DBM_HI);
	if (error_code == DB_C1)
		ft_fprintf(2, DBM_C1);
	if (error_code == DB_C2)
		ft_fprintf(2, DBM_C2);
	if (error_code == DB_C3)
		ft_fprintf(2, DBM_C3);
}
