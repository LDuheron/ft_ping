/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:53:40 by lduheron          #+#    #+#             */
/*   Updated: 2024/11/28 14:28:26 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ping.h"

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[0])
	{
		perror("Usage is ft_ping <destination>");
	}

	t_icmp_header	icmp;
	size_t start_time = get_time();
	init_icmp_data(&icmp);
	// uint16_t first_checksum = checksum((void*)&icmp, sizeof(icmp));
	int sockfd;

	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0)
	{
		perror("socket creation failed.\n");
		exit(ERROR);
	}

	// send_icmp(sockfd, &icmp, sizeof(icmp), MSG_WAITALL);
	// while(LOOP)
	// {
	// 	receive_icmp(sockfd, &icmp, sizeof(icmp), MSG_WAITALL);
	// }

	size_t time = get_time() - start_time;
	size_t ttl = 0;
	print_output(argv[0], icmp.sequence, ttl, time);
	close(sockfd);
	return (SUCCESS);
}
