/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:33:51 by lisa              #+#    #+#             */
/*   Updated: 2024/11/28 14:29:50 by lisa             ###   ########.fr       */
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
	// not necessary thanks to c compiler
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

// GET TIME : This function returs the current time stamp in microseconds
// using the gettimeoftheday() fuction which returns time in seconds and 
// miliseconds.

size_t	get_time(void)
{
	struct timeval	tv;
	size_t			milisecondes;
	size_t			secondes;
	size_t			time;

	if (gettimeofday(&tv, NULL) == -1)
		perror("Time error");
	milisecondes = (size_t)tv.tv_usec / 1000;
	secondes = (size_t)tv.tv_sec * 1000;
	time = secondes + milisecondes;
	return (time);
}

void	print_output(char* destination, char seq, size_t ttl, size_t time)
{
	printf("PING %s (IP) (bytes) bytes of data.\n", destination);
	printf("(bytes) bytes from (truc) : icmp_seq=%i ttl=%zu time=%zums\n", seq, ttl, time);
}
