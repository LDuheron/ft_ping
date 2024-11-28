/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:25:28 by lduheron          #+#    #+#             */
/*   Updated: 2024/11/28 15:32:07 by lisa             ###   ########.fr       */
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

# define LOOP 42

# define ECHO_REQUEST 8
# define ECHO_REPLY 0

typedef struct s_ping_data
{
	struct icmphdr	icmp_hdr;
	int min_rtt;
	int	max_rtt;
	int total_rtt;
} t_ping_data;


// struct for output ? 

// main.c
int	main(int argc, char **argv);

// socket_management.c
void    send_icmp(int socket, const void *buffer, size_t length, int flags);
void    receive_icmp(int socket, const void *buffer, size_t length, int flags);

// icmp_management.c
void	init_icmp_data(t_icmp_header *icmp);
uint16_t checksum(uint16_t* icmp_hdr, size_t len);
size_t	get_time(void);
void	print_output(char* destination, char seq, size_t ttl, size_t time);

#endif
