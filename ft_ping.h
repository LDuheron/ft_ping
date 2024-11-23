/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:25:28 by lduheron          #+#    #+#             */
/*   Updated: 2024/11/22 17:44:46 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include <unistd.h>
# include <stdio.h>
# include <arpa/inet.h>
# include <errno.h>
# include <netinet/in.h>

# define ERROR 0
# define SUCCESS 1

// main.c
int	main(int argc, char **argv);

#endif
