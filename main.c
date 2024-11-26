/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:53:40 by lduheron          #+#    #+#             */
/*   Updated: 2024/11/23 16:44:01 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ping.h"

// // // Need to code a checksum
// uint8_t checksum()
// {
// 	uint8_t	sum;
// 	// divide data as a sequence of 2byte
// 	// if data lenght is odd, padding byte of 0
// 	// add each word of sequence to sum
// 	// overflow ???
// 	return(sum);
// }

void	init_icmp_data(t_icmp_header *icmp)
{
	icmp->type = 8;
	icmp->code = 0;
	icmp->id = 0;
	icmp->checksum = 0;
	icmp->sequence = 0;
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[0])
	{
		perror("Usage is ft_ping <destination>");
	}

	t_icmp_header	icmp;
	init_icmp_data(&icmp);
	int sockfd;

	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0)
	{
		perror("socket creation failed.\n");
		exit(ERROR);
	}
	printf("Successfully created raw socket\n");
	close(sockfd);
	return (SUCCESS);
}
