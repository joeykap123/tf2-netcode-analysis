## An Analysis of Networking Principles in Team Fortress 2

```
Author : Joey Kaplan
```

TODO:
- Fix numbering in TOC
- Add missing networking concepts: TCP vs UDP, packet loss, time synchronization
- Add TF2-specific examples for lag compensation
- Proofread results and discussion sections
- todo: lowercase src file names to fit naming conventions + ensure cross OS compatability

## Abstract

## Table of Contents
1. [Introduction](#1-introduction)
2. [Expected Learning Outcomes](#2-expected-learning-outcome)
3. [About UDP](#3-user-datagram-protocol-in-multiplayer-games-benefits-and-trade-offs)
4. [Packet Loss and Reliability](#4-packet-loss-and-reliability)
5. [Latency, Bandwidth, and Throughput](#5-latency-vs-bandwidth-vs-throughput)
6. [About Lag Compensation](#6-lag-compensation-techniques-in-multiplayer-networking)
7. [About Interpolation](#7-interpolation-methods-for-networked-player-movement)
8. [About Extrapolation](#8-what-is-extrapolation-and-why-is-it-important)
9. [Event & State Synchronization](#9-event--state-synchronization-and-consistency-in-tf2)
10. [Client Prediction](#10-client-prediction)
11. [Tick-Rate and Jitter Handling](#11-tick-rate-and-jitter-handling)
12. [Networked Movement Mechanics in Team Fortress 2](#12-networked-movement-mechanics-in-team-fortress-2)
13. [Server Architecture](#13-server-architectures-iterative-vs-concurrent-processing)
14. [Time Synchronization & Clock Drift](#14-time-synchronization--clock-drift)
15. [Quality of Service & Network Prioritization](#15-quality-of-service-qos--network-prioritization)
16. [Problems Associated with UDP](#16-challenges-and-security-implications-of-udp-networking)
17. [Simulation Design and Methodology](#17-simulation-methodology)
18. [Results and Observations](#18-results-and-observations)
19. [Discussion](#19-discussion)
20. [Limitations](#20-limitations)
21. [Ethical and Educational Context](#21-ethical-considerations)
22. [Conclusion](#22-conclusion)
23. [References](#23-references)
- [Appendix A: Interpolation Formulas](#appendix-a-interpolation-formulas)
- [Appendix B: Simulation Parameters](#appendix-b-simulation-parameters)


## 1. Introduction

Team Fortress 2 is a multiplayer first-person shooter game created by Valve in 2007. The game remains popular since its release, maintains  a devoted fan base, and continues to receive updates as of 2025. The game was released on Steam, Valve's digital distribution service, providing dedicated servers and a large community. 
</br>
Team Fortress 2 is often reffered to by the informal name, **TF2**, and as such, I will refer to the game by this name within this document.

## 2. Expected Learning Outcome
This project seeks to provide readers with a thorough understanding of networking principles associated with TF2.

## 3. User Datagram Protocol in Multiplayer Games: Benefits and Trade-Offs
Two major connection protocols are used throughout the world: TCP and UDP. Many online games, streaming services, and video conferencing applications use UDP. Let us examine why TF2 uses UDP.
</br>
A major benefit of using UDP is the protocol's speed. UDP allows data transfer in an efficient and fast manner, ensuring live applications do not suffer from extensive wait time. 
</br>
So what are the benefits of UDP? UDP is notably fast, efficient, and simple. Using UDP allows applications to send data faster, consume less overhead, and be implemented in a straightforward fashion. 
</br>
While UDP is very fast and efficient, there are a few trade-offs that exist by choosing this protocol over Transmission Control Protocol (TCP). Notably, UDP can suffer from packet loss. This means that data arriving to the server or client is not always complete and it has the possiblity of being corrupted. In most cases, this is not a problem since the applications that use UDP rely on fast data transfer and the loss of data is not a major concern. However, this packet loss can lead to stutters and lag during gameplay. Thus, we introduce the topics of lag compensation and interpolation.


## 4. Packet Loss and Reliability

## 5. Latency vs Bandwidth vs Throughput
Latency, bandwidth, and throughput are all distinct, yet related topics that affect network reliability.
</br>
Latency is the time it takes for a packet to travel from a source to a destination, measured in milliseconds (ms). 

Furthermore, server location, network congestion, protocol efficiency, and network infrastructure can lead to changes in latency [12](References.md#ref12).
</br>
Bandwidth is the maximum amount of data that can travel over a network at a given time, measured in bits per second (bps). 
</br>
Throughput is the amount of data successfully transferred within a given network in a given time, measured in bits per second (bps).
</br>

## 6. Lag Compensation Techniques in Multiplayer Networking

Lag compensation is "using a snapshot from a previous player's position to balance latency issues." This is a common strategy implemented in many online games to ensure players are on equal ground. A server might "rewind" a player to a previous position to balance when the server received a message about interaction with the player.


### Hit Registration Models
- Hitscan weapons (server rewind)
- Projectile weapons (no rewind)
- Why latency affects classes differently
---
## 7. Interpolation Methods for Networked Player Movement

Interpolation, as a general concept, is a mathematical estimation of some set of datas corresponding function. This is extremely useful for smoothing data, analyzing trends, and creating continuous data. This is an important mathematical topic for online video games, since the use of UDP often results in the loss of packets. Thus, the usage of interpolation allows game servers to estimate a player's next position based on prior data.
</br>
Notable interpolation strategies include Linear Interpolation, Cubic Interpolation, and Nearest-Neighbor Interpolation. We will explore these interpolation strategies and hypothesize which method TF2 uses. 
</br></br>
Let us define a player's position as:</br>
$P(t) = [x(t), y(t), z(t)]$
</br>
Where P(t) indicates a Player's position at a given time, and $[x(t), y(t), z(t)]$ indicates the 3-D player position vector at a given time.

[Go to Appendix A: Interpolation Formulas](#appendix-a-interpolation-formulas)
---
### 7.1 Linear Interpolation


Linear Interpolation is often used due to its simple and fast visualization.

---
### 7.2 Cubic (Hermite) Interpolation  
**7.2.1 Unconstrained Cubic Hermite**  
**7.2.2 Monotonic Cubic Hermite (Slope-Limited)**


Cubic Interpolation is often used due to its ability to provide smoother player motion with smooth acceleration/deceleration.

---

### 7.3 Dead Reckoning Interpolation

### 7.4 Nearest-Neighbor Interpolation
        TODO::::
---

## 8. What is Extrapolation and Why is it Important?
Extrapolation is a concept similar to interpolation, but an important concept nonetheless. Extrapolation allows us to "predict" the next position of an object based on the trend of previous points.

---

## 9. Event & State Synchronization and Consistency in TF2
Synchronization 

What is synchronization (1)
What is event v state sync (2)
</br>
Event-based synchronization relies on signals 
State-based synchronization relies on some conditional statement

___ sharing among threads requires sycnhronization. We can avoid the question of machine code atomicity, declaring the need for cache coherence, and 


### 9.1 Out-of-Order Packets and Sequence Numbers

### 9.2 Snapshot and Delta-Based State Updates

---

## 10. Server Authority

---


## 11. Client Prediction

---


# 12. Server Reconciliation
- Authoritative corrections
- Reapplication of inputs
- Error handling (general)
---


## 11. Tick-Rate and Jitter Handling

Tick rate is a networking principle unique to gaming. 

The Source SDK 2013 code base uses a fixed tick rate for Team Fortress 2 of 66 Hz, or approximately every ~15 ms.

### 11.1 Snapshot Frequency vs Tick Rate

TODO:: 
- Not every tick produces a full snapshot



- Snapshot rate less than or equal to tick rate
  

- Delta vs full updates (mention, don't explain)
Delta compression can be used to reduce network load, essentially only requiring the server to send changes of the game state to clients instead of a whole game snapshot.  
Full snapshots are used less frequently, often being used only when a game begins or a client suffers heavy packet loss.

### 12.1 Fixed Timestep vs Render Rate

i.e., tick is just a unit, tick rate is just unit rate, fixed timestep is how much each tick advances simulation (e.g., 1 tick moves game state forward 15 ms)

TODO::
- server: fixed timestep
- Client: variable render rate
- Why interpolation exists
- Why jitter is visible without buffering 


---

## 12. Networked Movement Mechanics in Team Fortress 2

### Baseline Player Movement and Physics
Walking, strafing, jumping
</br>
Team Fortress 2 has various unique movement mechanics due to the use of Source Engine. (Walking, strafing, jumping)

First, players can walk within the game, allowing traversal across a map.
Second, players can strafe when in the air. (Talk about strafing to change direction or land in a different position)(Talk about how this mechanic is unique to Valve's games/games made with Source Engine)
Finally, players can jump (Put more information)

Ground vs airborne control  
(Talk about strafing more in detail here)

Deterministic inputs and server authority  
(need to handle state sync v determjnsitc lockstep. maybe need to merge the sync section?)

Expected behavior under latency

### Application of Prediction and Reconciliation in TF2 Movement
Input prediction loop

Server corrections

Error smoothing during standard movement

Why movement feels responsive


### Interpolation of Remote Player Movement
Interpolation buffer and delay

Visual smoothing vs accuracy

Minor artifacts under normal play

>NOTE mention cl_interp
### Rocket Jumping as a Case Study in Networked Physics
Server-authoritative explosion physics

Absence of lag compensation for blast forces

High-velocity, non-linear acceleration

Prediction error and reconciliation artifacts

Interpolation breakdown during extreme motion

> !NOTE can mention cl_interp again to explore more

---

## 13. Server Architectures: Iterative vs Concurrent Processing
Servers operate using two common architectures; Iterative and Concurrent. The best server type depends on what usage will be needed. 
</br>
Iterative servers are relatively more simple, have less overhead, and are cheaper. Additionally, Iterative Server Architecture processes one client connection at a time, ___. Thus, Iterative Servers function well when only one client needs to be processed at a time. For instance, an online chess game or a website for buying tickets. Both of these applications need an iterative server structure to ensure data arrives based on when a client connects.
</br>
Concurrent servers are more complex, have more overhead, and tend to be more expensive. This server architecture can accept multiple clients at the same time, allowing multi-client interactions. This server type is extremely useful for online gaming, large websites with constant traffic, and databases.
</br>

TODO:: Discuss thread-based v process-based v event-based. Can also put a short paragraph about atomicity, but not too in depth. 


---


## 14. Time Synchronization & Clock Drift
Different client clocks


## 15. Quality of Service (QoS) / Network Prioritization
Go over how client-side gameplay is prioritized over cosmetics and items.

### Snapshot Frequency vs Tick Rate

## 16. Challenges and Security Implications of UDP Networking
However, while lag compensation and interpolation generally result in better gameplay, these concepts can become problematic, notably when cheating becomes involved. </br>

Team Fortress 2 has a notable command that players can modify within their console, known as **cl_interp**. 
Beyond TF2's specific commands, cheating in online servers is popular and hard to catch. This is due to the nature of UDP; This protocol is built for speed, making packet loss inevitable. Knowing this, cheaters can use strategies such as modification of interpolation to simulate innocent packet loss, leading to difficulty in telling cheaters apart from players with poor connection. 
</br>

Additionally, topics such as Denial of Service (DoS) attacks can be executed on these servers with little difficulty and little risk of being caught. Since DoS attacks leverage sending many requests to a server in a short time period, servers using UDP are at specific risk. Since UDP does not require a three-way handshake to establish a connection like TCP, an attacker can easily overwhelm UDP servers. 
</br>

IP Spoofing can also be easily executed over UDP connections. Since UDP has no way to verify identity, attackers can send requests to the server using the victim's IP, leading to large amounts of data being sent to the victim's system.
</br>

It should be noted that DoS attacks are not as malicious in nature when implemented on gaming servers, as they are often a means to give the attacker an advantage or win.

> !NOTE
> Do not cheat or use this project as inspiration for cheating.

### Emerging Transport Protocols: QUIC
TODO:::


## 17. Simulation Methodology

To create the simulation for this project, we must go through various steps:</br>
1. Generate a JSON file of Player objects to parse.
    1. Players are represented as objects with position vectors. 
    2. Position vectors will be 3-dimensional
2. Simulate various network conditions, including latency, jitter, and packet loss
3. Apply interpolation and lag compensation algorithms to synthetic positions to predict the next position.
4. Compare algorithm results with expected results and predict if the player is cheating or simply suffering packet loss.
    
    

## 18. Results and Observations

Let us analyze the results of this project:

    TODO!!!
    Compare simulated “real” vs “interpolated” positions.
    
    Explore how packet loss and jitter affect interpolation error.
    
    Example visualizations:
    
    Error over time
    
    Hit registration deviation (simulated)
    
    Discuss parameter effects (interpolation delay, buffer size).

## 19. Discussion

    TODO!!! Trade off between smooth visuals and responsiveness
    How ambiguity in UDP networking could be mistaken for cheating.
    Reinforce that the project is analysis-only.
    
    

## 20. Limitations
- No physics engine
- Simplified player model
- Limited tick rates
- Synthetic data only

## 21. Ethical Considerations
Research on these topics has potential for misuse. Please utilize this project responsibly and **do not** use it to cheat or as inspiration to cheat.

## 22. Conclusion


## 23. References
See **[References.md](References.md)** for all references.

### Appendix A: Interpolation Formulas
Linear Interpolation:  $lerp(P) = P(t) = (1-\alpha)\vec{a} + \alpha\vec{b}$.
</br>
Cubic Interpolation:   $P(t) = (2s^3 - 3s^2 + 1)\vec{P_0} + (-2s^3 + 3s^2)\vec{P_1} + (s^3 - 2s^2 + s)\vec{M_0} + (s^3 - s^2)\vec{M_1}$
</br>
TODO:: Add other cubic hermite formula
</br>
Dead Reckoning Interpolation: 
</br>
Nearest-Neighbor Interpolation:

</br>
[Back to Section 6: What is Interpolation and Why is it Important](#6-what-is-interpolation-and-why-is-it-important)


### Appendix B: Simulation Parameters

| Parameter                 | Value       | Description                                 |
|---------------------------|-------------|---------------------------------------------|
| Tick Rate                 | 66 ticks/s  | Server updates per second                   |
| Interpolation Delay       | 100 ms      | Client-side render buffer                   |
| Packet Loss               | 0-10%       | Randomly simulated loss                     |
| Latency                   | 50-200 ms   | Round-trip time applied per simulated player|
| Number of Players         | 5           | Number of simulated entities                |

[Back to Top](#abstract)
