/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:30:24 by lisa              #+#    #+#             */
/*   Updated: 2024/11/28 14:00:20 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ping.h"

// socket, buffer, length, flags
void    send_icmp(int socket, const void *buffer, size_t length, int flags)
{
    int result;

    result = 0;
    result = send(socket, &buffer, length, flags);
    if (result < 0)
    {
        perror("Failed to send packet.");
        close(socket);
        exit(ERROR);
    }
}

void    receive_icmp(int socket, const void *buffer, size_t length, int flags)
{
    int result;

    result = 0;
    result = recv(socket, &buffer, length, flags);
    if (result < 0)
    {
        perror("Failed to receive packet.");
        close(socket);
        exit(ERROR);
    }
}
