/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:33:51 by lisa              #+#    #+#             */
/*   Updated: 2024/11/28 13:34:47 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ping.h"

void	init_icmp_data(t_icmp_header *icmp)
{
	icmp->type = ECHO_REQUEST;
	icmp->code = 0;
	icmp->id = 0;
	icmp->checksum = 0;
	icmp->sequence = 0;
}

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
