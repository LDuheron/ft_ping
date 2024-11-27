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

// // Need to code a checksum
// IPV4 === INCLURE LE PSEUDO HEADER
uint16_t checksum(void* icmp, size_t len)
{
	uint16_t	sum;
	// divide data as a sequence of 2byte
	uint16_t	*words = (uint16_t *)icmp;

	sum = 0;
	printf("Len before dividing : %zu\n", len);
	// add each word of sequence to sum
	while (len >= 1)
	{
		printf("%hu ", *words);
		sum += *words;
		len -= 2;
		*words += 1;
	}
	printf("\nLen after dividing : %zu\n", len);

	// if data lenght is odd, padding byte of 0
	if (len != 0)
	{
		printf("Is odd !\n");
		uint16_t	padded_word;
		padded_word = *words >> 8;
		sum += padded_word;
	}
	
	// overflow ???
	return(sum);
}

void	init_icmp_data(t_icmp_header *icmp)
{
	icmp->type = ECHO_REQUEST;
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
	return (SUCCESS);
}
