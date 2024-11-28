/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:53:40 by lduheron          #+#    #+#             */
/*   Updated: 2024/11/28 15:20:01 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ping.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Usage is ft_ping <destination>");
	}

	struct icmphdr	icmp_hdr;
	init_icmp_data(&icmp);

	size_t start_time = get_time();

	int sockfd;
	struct sockaddr_in sockaddr;

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons();

	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0)
	{
		perror("socket creation failed.\n");
		exit(ERROR);
	}

	bind(sockfd, (struct sockaddr*)sockaddr, sizeof(sockaddr));
	// send_icmp(sockfd, &icmp, sizeof(icmp), MSG_WAITALL);
	// while(LOOP)
	// {

	// }

	size_t time = get_time() - start_time;
	size_t ttl = 0;
	print_output(argv[0], icmp.sequence, ttl, time);
	close(sockfd);
	return (SUCCESS);
}
