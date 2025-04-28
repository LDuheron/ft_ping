/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:33:51 by lisa              #+#    #+#             */
/*   Updated: 2024/11/28 15:25:33 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ping.h"

static void compare_checksum(struct icmphdr *icmp_hdr, int toggle)
{
	if (toggle == ON)
	{
		// printf("Correct checksum is : %d\n", checksum(icmp_hdr));
		printf("My checksum is : %d\n", icmp_hdr->checksum);
	}
}

void	init_icmp_data(struct icmphdr *icmp_hdr)
{
	// memset(icmp_hdr, 0, sizeof(icmp_hdr));
	icmp_hdr->type = ECHO_REQUEST;
	icmp_hdr->code = 0;
	icmp_hdr->un.echo.id = htons(getpid());
	icmp_hdr->un.echo.sequence = 0;				// ???
	icmp_hdr->checksum = 0;						// ???
	// icmp_hdr->checksum((u_int16_t*)&icmp_hdr, sizeof(icmp_hdr));
	compare_checksum(icmp_hdr, DEBUG);

}

// // Geeks for geeks checksum 
// unsigned short checksum(void *b, int len) {
//     unsigned short *buf = b;
//     unsigned int sum = 0;
//     unsigned short result;

//     for (sum = 0; len > 1; len -= 2)
//         sum += *buf++;
//     if (len == 1)
//         sum += *(unsigned char *)buf;
//     sum = (sum >> 16) + (sum & 0xFFFF);
//     sum += (sum >> 16);
//     result = ~sum;
//     return result;
// }

// // IPV4 === INCLURE LE PSEUDO HEADER
// uint16_t checksum(uint16_t* icmp_hdr, size_t len)
// {
// 	uint16_t	sum;
// 	// divide data as a sequence of 2byte
// 	uint16_t	*words = (uint16_t *)icmp_hdr;

// 	sum = 0;
// 	printf("Len before dividing : %zu\n", len);
// 	// add each word of sequence to sum
// 	while (len >= 1)
// 	{
// 		printf("%hu ", *words);
// 		sum += *words;
// 		len -= 2;
// 		*words += 1;
// 	}
// 	printf("\nLen after dividing : %zu\n", len);

// 	// if data lenght is odd, padding byte of 0
// 	// not necessary thanks to c compiler
// 	if (len != 0)
// 	{
// 		printf("Is odd !\n");
// 		uint16_t	padded_word;
// 		padded_word = *words >> 8;
// 		sum += padded_word;
// 	}
	
// 	// overflow ???
// 	return(sum);
// }

// GET TIME : This function returs the current time stamp in milliseconds
// using the gettimeoftheday() fuction which returns time in seconds and 
// milliseconds.
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

// void	print_output(char* destination, char seq, size_t ttl, size_t time)
// {
// 	printf("PING %s (IP) (bytes) bytes of data.\n", destination);
// 	printf("(bytes) bytes from (truc) : icmp_seq=%i ttl=%zu time=%zums\n", seq, ttl, time);
// }
