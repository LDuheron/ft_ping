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


	// Should work with an IP address or with a full name.
// Arg : 
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Usage is ft_ping <destination>");
	}



	// Retrieve IP adress by name 
	// struct addrinfo hints, *res, *p;
	// memset(&hints, 0, sizeof(hints));
	// hints.ai_family = AF_UNSPEC;
	// hints.ai_socktype = SOCK_STREAM;
	// int res = getaddrinfo(argv[1], NULL, &hints, &res);
	// if (res != 0)
	// {
	// 	perror("addrinfo creation failed.\n");
	// 	exit(ERROR);
	// }
	// print_debug_messages("DNS succesfully translated.", DEBUG);
	// printf("IPV v4 = %i", &res.);

 // basically i habve tocode afuncetiunthat jsut translate dns o p? can  

	// Create a raw socket
	int sockfd;
	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0)
	{
		perror("socket creation failed.\n");
		exit(ERROR);
	}
	print_debug_messages("Raw socket succesfully created.", DEBUG);



	// Initialize icmp header
	struct icmphdr	icmp_hdr;
	init_icmp_data(&icmp_hdr);
	print_debug_messages("Icmp header succesfully created.", DEBUG);



	// Initialize the destination socket
	struct sockaddr_in sock_addr;
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = htons(0);



	// Send package 
	size_t start_time = get_time();
	send_icmp(sockfd, icmp_hdr, sock_addr);
	while(42)
	{
		receive_icmp(sockfd, sock_addr);
		print_debug_messages("call to receive icmp.", DEBUG);
	}



	size_t time = get_time() - start_time;
	printf("Time elapsed is : %zu\n", time);
	// size_t ttl = 0;
	// print_output(argv[0], icmp.sequence, ttl, time);

	// Exiting properly 
	close(sockfd);
	print_debug_messages("Raw socket succesfully closed.", DEBUG);
	return (SUCCESS);
}
