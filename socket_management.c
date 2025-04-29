/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:30:24 by lisa              #+#    #+#             */
/*   Updated: 2024/11/28 15:00:27 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ping.h"

void    send_icmp(int sockfd, struct icmphdr icmp_hdr, struct sockaddr_in sock_addr)
{
	int result;

    result = 0;
    result = sendto(sockfd, &icmp_hdr, sizeof(icmp_hdr), MSG_WAITALL, (struct sockaddr*)&sock_addr, sizeof(sock_addr));
    if (result < 0)
    {
        perror("Failed to send packet.");
        close(sockfd);
        exit(ERROR);
    }
	print_debug_messages("Packet succesfully sent.", DEBUG);
}

void    receive_icmp(int sockfd, struct sockaddr_in sock_addr)
{

    struct icmphdr rbuffer;
    int result;
    socklen_t sock_addr_len= sizeof(sock_addr);
    result = 0;
    result = recvfrom(sockfd, &rbuffer, sizeof(rbuffer), 0, (struct sockaddr*)&sock_addr, &(sock_addr_len));
    if (result < 0)
    {
        perror("Failed to receive packet.");
        close(sockfd);
        exit(ERROR);
    }
	print_debug_messages("Packet succesfully received.", DEBUG);
	printf("%hhu", rbuffer.type);
    printf("\n");
}
