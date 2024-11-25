/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:25:28 by lduheron          #+#    #+#             */
/*   Updated: 2024/11/23 16:31:47 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include <arpa/inet.h>
# include <errno.h>
# include <netinet/in.h>
# include <netinet/ip_icmp.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# define ERROR 0
# define SUCCESS 1

typedef struct s_icmp_header
{
	int type;  // uint 8 ?
	int code;
	int id;
	int checksum;
	int sequence;
	// int time;
	// int ttl; 
} t_icmp_header;


// main.c
int	main(int argc, char **argv);

#endif
