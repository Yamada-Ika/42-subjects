/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:29:36 by iyamada           #+#    #+#             */
/*   Updated: 2022/03/24 00:24:23 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_lock(t_mutex *mtx, t_mutex *mtx_err, t_error *err)
{
	if (pthread_mutex_lock(mtx) != 0)
	{
		pthread_mutex_lock(mtx_err);
		set_err(err, LOCK_MTX);
		pthread_mutex_unlock(mtx_err);
		return (FAIL);
	}
	return (SUCCESS);
}

int	mutex_unlock(t_mutex *mtx, t_mutex *mtx_err, t_error *err)
{
	if (pthread_mutex_unlock(mtx) != 0)
	{
		pthread_mutex_lock(mtx_err);
		set_err(err, UNLOCK_MTX);
		pthread_mutex_unlock(mtx_err);
		return (FAIL);
	}
	return (SUCCESS);
}
