/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:46:35 by ulevallo          #+#    #+#             */
/*   Updated: 2024/02/05 11:00:03 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
0 :
> Default Error
( Unknown )

1 - 10 :
> Standard
( Normal prompts for the use of the program )

11 - 20 :
> MiniLibX Errors
( Graphical Library call Errors )

21 - 30 :
> Parsing Errors
( Badly provided user information )


31 - 40 :
> Engine Errors
( Math related, everything aroung the egine )

41 - 50 :
> File Errors
( File taken from the user )

51 - 60 :
> Debug
( Helpfull prints for debug )

61 - 70
> Critical Errors
( Such as syscall failures, memory allocations etc )

*/

#ifndef RT_ERROR_H
# define RT_ERROR_H

# define ERR_DEF 0
# define ERM_DEF "Error\n"

# define ERR_STD_LR 1
# define ERR_STD_RR 10

enum e_rr_standard
{
	ERR_NO_PROMPT = 1,
	ERR_UNSET
};

# define ERM_NO_PROMPT "Error: No file provided, please give a [name].rt file\n"
# define ERM_UNSET "Error: Unset or NULL Value\n"

# define ERR_MLX_LR 11
# define ERR_MLX_RR 20

enum e_rr_minilibx
{
	ERR_MLX_INIT = 11,
	ERR_MLX_IMG,
	ERR_MLX_WIN
};

# define ERM_MLX_INIT "MinilibX Error: Initialization failure\n"
# define ERM_MLX_IMG "MinilibX Error: Couldn't create image\n"
# define ERM_MLX_WIN "MinilibX Error: Window allocation fail\n"

# define ERR_PARS_LR 21
# define ERR_PARS_RR 30

enum e_rr_parsing
{
	ERR_EMPTY = 21,
	ERR_NUMBER,
	ERR_COLOR,
	ERR_IDENTIFIER,
	ERR_AL,
	ERR_CAM,
	ERR_LIGHT,
	ERR_SP,
	ERR_CY,
	ERR_PL,
};

# define ERM_EMPTY "Error Parsing File: Empty file\n"
# define ERM_NUMBER "Error Parsing File: Number not Valid\n"
# define ERM_COLOR "Error Parsing File: Color not Valid\n"
# define ERM_IDENTIFIER "Error Parsing File: Invalid Identifier\n"
# define ERM_AL "Parsing Object: Ambient lighting couldn't be set\n"
# define ERM_CAM "Parsing Object: Camera couldn't be set\n"
# define ERM_LIGHT "Parsing Object: Light Source couldn't be set\n"
# define ERM_SP "Parsing Object: Sphere couldn't be set\n"
# define ERM_CY "Parsing Object: Cylinder couldn't be set\n"
# define ERM_PL "Parsing Object: Plane couldn't be defined\n"

# define ERR_ENGN_LR 31
# define ERR_ENGN_RR 40

enum e_rr_engine
{
	ERR_ENGX = 31,
	ERR_OBJ_MAX_SZ
};

# define ERM_ENGX "Engine Error\n"
# define ERM_OBJ_MAX_SZ "Error: Max size reached for object\n"

# define ERR_FILE_LR 41
# define ERR_FILE_RR 50

enum e_rr_file
{
	ERR_FILEEXT = 41
};

# define ERM_FILEEXT "File Error: invalid suffix [.rt]\n"

# define DB_LR 51
# define DB_RR 60

enum e_rr_debug
{
	DB_START = 51,
	DB_END,
	DB_VAL,
	DB_FCALL,
	DB_HI,
	DB_C1,
	DB_C2,
	DB_C3,
	DB_FREE,
};

# define DBM_START "======Start======\n"
# define DBM_END   "=======End=======\n"
# define DBM_VAL "Value is:"
# define DBM_FCALL "Function Called\n"
# define DBM_HI "Hello\n"
# define DBM_C1 "Inside Child level 1\n"
# define DBM_C2 "Inside Child level 2\n"
# define DBM_C3 "Inside Child level 3\n"
# define DBM_FREE "Freed\n"

# define ERR_CRIT_LR 61
# define ERR_CRIT_RR 70

enum e_rr_critical
{
	ERR_MEM = 61,
	ERR_OPEN,
	ERR_CLOSE,
	ERR_FORK,
	ERR_READ
};

# define ERM_MEM "Critical: Memory allocation call failed\n"
# define ERM_OPEN "Critical: Open function call failed\n"
# define ERM_CLOSE "Critical: Close function call failed\n"
# define ERM_FORK "Critical: Fork failed\n"
# define ERM_READ "Critical: Couldn't Read from file descriptor\n"

/*
enum e_rr_
{
	ERR_ = 1,
	ERR_,
	ERR_
};
*/

/* Functions */

void	p_err_standard(unsigned int error_code);
void	p_err_minilibx(unsigned int error_code);
void	p_err_parsing(unsigned int error_code);
void	p_err_engine(unsigned int error_code);
void	p_err_debug(unsigned int error_code);
void	p_err_crit(unsigned int error_code);
void	p_err_file(unsigned int error_code);
void	p_error(unsigned int error_code);

#endif
