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
	(void)argv;

	if (argc != 2)
	{
		perror("Usage is ft_ping <destination>");
	}


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
	send_icmp(sockfd, &icmp_hdr, sizeof(icmp_hdr), MSG_WAITALL);
	    int result;

    result = 0;
    result = sendto(sockfd, &icmp_hdr, sizeof(icmp_hdr), MSG_WAITALL, (struct sockaddr *)sock_addr, sizeof(*sock_addr));
    if (result < 0)
    {
        perror("Failed to send packet.");
        close(sockfd);
        exit(ERROR);
    }
	print_debug_messages("Packet succesfully sent.", DEBUG);

	// while(LOOP)
	// {

	// }


	size_t time = get_time() - start_time;
	printf("Time elapsed is : %zu\n", time);
	// size_t ttl = 0;
	// print_output(argv[0], icmp.sequence, ttl, time);

	// Exiting properly 
	close(sockfd);
	print_debug_messages("Raw socket succesfully closed.", DEBUG);
	return (SUCCESS);
}
