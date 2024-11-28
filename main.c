/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:53:40 by lduheron          #+#    #+#             */
/*   Updated: 2024/11/28 13:35:08 by lisa             ###   ########.fr       */
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
	init_icmp_data(&icmp);
	uint16_t first_checksum = checksum((void*)&icmp, sizeof(icmp));
	printf("\nsum = %hu \n", first_checksum);

	// int sockfd;

	// sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	// if (sockfd < 0)
	// {
	// 	perror("socket creation failed.\n");
	// 	exit(ERROR);
	// }
	// printf("Successfully created raw socket\n");
	// close(sockfd);
	// return (SUCCESS);
}
