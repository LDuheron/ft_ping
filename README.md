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

Man :
ping - send ICMP ECHO_REQUEST to network hosts

## ICMP protocol

Ping is based on the Internet Control Message Protocol. When executing a ping, an ICMP “echo request” is sent to the target device. If the target device accept the request, it responds with an “echo reply”.

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