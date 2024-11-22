# ft_ping

## About the project

**Ft_ping** is a 42Network project reproducing the behavior of the ping function.

## Table of contents

- [About the project](#about-the-project)
- [Usage](#usage)
- [What is ping ?](#what-is-ping-?)
- [ICMP protocol](#icmp-protocol)
- [Output](#output)
- [Options](#options)
- [Ressources](#ressources)

## Usage

```
ping <options> <destination>

```

## What is ping ?

From man :
***ping** - send ICMP ECHO_REQUEST to network hosts*

*Ping uses the ICMP protocol's mandatory ECHO_REQUEST datagram to elicit an ICMP ECHO_RESPONSE from a host or gateway. ECHO_REQUEST datagrams (“pings”) have an IP and ICMP header, followed by a struct timeval and then an arbitrary number of “pad” bytes used to fill out the packet.*

Schema from GeeksForGeeks
![Ping_schema_from_GeekForGeeks](/readme_img/ping_schema.png)

When executing a ping, an ICMP “echo request” is sent to the target device. If the target device accept the request, it responds with an “echo reply”.

Ping tests the connection speed between two devices and precisely measures the time it takes for a data packet to reach its destination and return to the sender. 

## ICMP protocol

Ping is based on the Internet Control Message Protocol (ICMP). This protocol is used by devices on a network to detect communication issues within the network. ICMP is a connextionless protocol, meaning it doesn't require establishing a connection before transmitting data.

## Output

The ping output is formatted like this :

```

ping google.com

```

![ping_google_output](/readme_img/ping_google_output.png)

**icmp_seq** : sequence number of the request.

**ttl** (time-to-live value) : representing maximum time before the packet is discard.

**time:** : The time it takes for the packet to travel to the destination and back, in milliseconds.

## Options

## Ressources

- Ping man : http://www.man-linux-magique.net/man8/ping.html
- arpa/inet.h header for internet operations : https://pubs.opengroup.org/onlinepubs/7908799/xns/arpainet.h.html
- netinet/in.h header : https://pubs.opengroup.org/onlinepubs/7908799/xns/netinetin.h.html
- ICMP protocol info : https://www.cloudflare.com/fr-fr/learning/ddos/glossary/internet-control-message-protocol-icmp/