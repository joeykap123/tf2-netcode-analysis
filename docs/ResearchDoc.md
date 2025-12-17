## An Analysis of Networking Principles in Team Fortress 2

```
Author : Joey Kaplan
```

TODO:
- Fix numbering in TOC
- Add missing networking concepts: TCP vs UDP, packet loss, time synchronization
- Add TF2-specific examples for lag compensation
- Proofread results and discussion sections


## 1. Introduction

Team Fortress 2 is a multiplayer first-person shooter game created by Valve in 2007. The game remains popular since its release, maintains  a devoted fanbase, and still receives updates as of 2025. The game was released on Steam, Valve's digital distribution service, providing dedicated servers and a large community. 
</br>
Team Fortress 2 is often notated by the informal name, **TF2**, and as such, I will refer to the game by this name within this document.


## 2. Table of Contents
- [Introduction](#1-introduction)
- [Expected Learning Outcomes](#3-expected-learning-outcome)
- [About UDP](#4-user-datagram-protocol-in-multiplayer-games-benefits-and-trade-offs)
- [Packet Loss and Reliability](#5-packet-loss-and-reliability)
- [Latency, Bandwidth, and Throughput](#6-latency-vs-bandwidth-vs-throughput)
- [About Lag Compensation](#7-lag-compensation-techniques-in-multiplayer-networking)
- [About Interpolation](#8-interpolation-methods-for-networked-player-movement)
- [About Extrapolation](#9-what-is-extrapolation-and-why-is-it-important)
- [Event & State Synchronization](#10-event--state-synchronization-and-consistency-in-tf2)
- [Client Prediction](#11-client-prediction)
- [Tick-Rate and Jitter Handling](#12-tick-rate-and-jitter-handling)
- [Networked Movement Mechanics in Team Fortress 2](#13-networked-movement-mechanics-in-team-fortress-2)
- [Server Architecture](#14-server-architectures-iterative-vs-concurrent-processing)
- [Time Synchronization & Clock Drift](#15-time-synchronization--clock-drift)
- [Quality of Service & Network Prioritization](#16-quality-of-service-qos--network-prioritization)
- [Problems Associated with UDP](#17-challenges-and-security-implications-of-udp-networking)
- [Simulation Design and Methodology](#18-simulation-methodology)
- [Results and Observations](#19-results-and-observations)
- [Discussion](#20-discussion)
- [Limitations](#21-limitations)
- [Ethical and Educational Context](#22-ethical-considerations)
- [Conclusion](#23-conclusion)
- [References](#24-references)
- [Appendix A: Interpolation Formulas](#appendix-a-interpolation-formulas)
- [Appendix B: Simulation Parameters](#appendix-b-simulation-parameters)


## 3. Expected Learning Outcome
This project seeks to provide readers with a thorough understanding of networking principles associated with TF2.

## 4. User Datagram Protocol in Multiplayer Games: Benefits and Trade-Offs
Two major connection protocols are used throughout the world; TCP and UDP. Many online games, streaming services, and video conferencing applications use UDP. Let us examine why TF2 uses UDP.
</br>
A major benefit of using UDP is the protocol's speed. UDP allows data transfer in an efficient and fast manner, ensuring live applications do not suffer from extensive wait time. 
</br>
So what are the benefits of UDP? UDP is notably fast, efficient, and simple. Using UDP allows applications to send data faster, consume less overhead, and be implemented in a straightforward fashion. 
</br>
While UDP is very fast and efficient, there are a few trade-offs that exist by choosing this protocol over Transmission Control Protocol (TCP). Notably, UDP can suffer from packet loss. This means that data arriving to the server or client is not always complete and it has the possiblity of being corrupted. In most cases, this is not a problem since the applications that use UDP rely on fast data transfer and the loss of data is not a major concern. However, this packet loss can lead to stutters and lag during gameplay. Thus, we introduce the topics of lag compensation and interpolation.


## 5. Packet Loss and Reliability

## 6. Latency vs Bandwidth vs Throughput
Latency, bandwidth, and throughput are all distinct, yet related topics that affect network reliability.
</br>
Latency is the time it takes for a packet to travel from a source to a destination, measured in milliseconds (ms). 

Furthermore, server location, network congestion, protocol efficiency, and network infrastructure can lead to changes in latency [12](References.md#ref12).
</br>
Bandwidth is the maximum amount of data that can travel over a network at a given time, measured in bits per second (bps). 
</br>
Throughput is the amount of data successfully transferred within a given network in a given time, measured in bits per second (bps).
</br>

## 7. Lag Compensation Techniques in Multiplayer Networking

Lag compensation is "using a snapshot from a previous player's position to balance latency issues." This is a common strategy implemented in many online games to ensure players are on equal ground. A server might "rewind" a player to a previous position to balance when the server received a message about interaction with the player.

---
## 8. Interpolation Methods for Networked Player Movement

Interpolation, as a general concept, is a mathematical estimation of some set of datas corresponding function. This is extremely useful for smoothing data, analyzing trends, and creating continuous data. This is an important mathematical topic for online video games, since the use of UDP often results in the loss of packets. Thus, the usage of interpolation allows game servers to estimate a player's next position based on prior data.
</br>
Notable interpolation strategies include Linear Interpolation, Cubic Interpolation, and Nearest-Neighbor Interpolation. We will explore these interpolation strategies and hypothesize which method TF2 uses. 
</br></br>
Let us define a player's position as:</br>
$P(t) = [x(t), y(t), z(t)]$
</br>
Where P(t) indicates a Player's position at a given time, and $[x(t), y(t), z(t)] indicates the 3-D player position vector at a given time.

[Go to Appendix A: Interpolation Formulas](#appendix-a-interpolation-formulas)
---
### Linear Interpolation

Linear Interpolation can be defined with the following formula:
</br>
    $lerp(P) = P(t) = (1-\alpha)\vec{a} + \alpha\vec{b}$.
    </br>
    $\vec{a} =$ Starting Position $(\vec{P_i})$
    </br>
    $\vec{b} =$ Ending Position $(\vec{P_{i + 1}})$
    </br>
    $\alpha = \frac{t - t_i}{t_{i + 1} - t_i}$, where $i$ represents the index of the position array corresponding to the interval containing $t$
</br></br>
Thus, let us examine an example: </br></br>
Let $\vec{a} = [2,3,4]$ and let $\vec{b} = [4,3,4]$. We can assume $t_i = 0$ seconds and $t_{i + 1} = 1$ seconds. Let us assume $t = 0.25$, or 0.25 seconds. Thus, applying the LERP formula, we get:</br>
$P(t) = (1 - \alpha)[2,3,4] + \alpha[4,3,4]$
</br>
Therefore, let us solve for alpha: $\alpha = \frac{0.25 - 0}{1 - 0} = 0.25$. </br>
$P(t) = (1 - 0.25)[2,3,4] + 0.25[4,3,4]</br>
Computing this formula gives a position of $[2.5, 3, 4]$. </br>
Therefore, we predict via linear interpolation that the player's position at 0.25 seconds will be $[2.5,3,4]$

Linear Interpolation is often used due to its simple and fast visualization.

---
### Cubic (Hermite) Interpolation

Cubic (Hermite) Interpolation can be defined with the following formula:</br>
</br>
For two points $\vec{P_0}$ and $\vec{P_1}$ with tangents $\vec{M_0}$ and $\vec{M_1}$, the position at time t is:
</br></br>
$P(t) = (2s^3 - 3s^2 + 1)\vec{P_0} + (-2s^3 + 3s^2)\vec{P_1} + (s^3 - 2s^2 + s)\vec{M_0} + (s^3 - s^2)\vec{M_1}$
</br></br>
Where $s = \frac{t - t_0}{t_1 - t_0}$</br>
$\vec{P_0}, \vec{P_1} =$ Start and End Positions</br>
$\vec{M_0}, \vec{M_1} =$ Tangents (Velocities) at Start and End Positions </br>
$t_0, t_1 =$ Start and End times of the interval </br>
$s =$ Normalized time in [0.1]</br>
</br>
We can estimate or calculate the tangents $\vec{M_0}, \vec{M_1}$ using:</br>
$\vec{M_1} = \frac{\vec{P_{i + 1}} - \vec{P_{i - 1}}}{t_{i + 1} - t_{i - 1}}$ (if neighboring points exist)</br></br>
Thus, let us examine an example: </br></br>
Let $\vec{P_0} = [10, 20, 1]$ and $\vec{P_1} = [13,23,0]$. We can assume $t_0 = 0$ and $t_1 = 1$. Let us assume $t = 0.5$, or 0.5 seconds. Let us assume no neighboring points exists, meaing $\vec{M_0}, \vec{M_1} = [0,0,0]$. Thus, applying the Cubic (Hermite) formula, we get:</br>
$P(t) = (2s^3 - 3s^2 + 1)\vec{P_0} + (-2s^3 + 3s^2)\vec{P_1} + (s^3 - 2s^2 + s)\vec{M_0} + (s^3 - s^2)\vec{M_1}$ </br>
We must calculate $s$: </br>
$s = \frac{0.5 - 0}{1 - 0} = 0.5$</br>
Thus, $P(t) = (2(0.5)^3 - 3(0.5)^2 + 1)\vec{P_0} + (-2(0.5)^3 + 3(0.5)^2)\vec{P_1} + ((0.5)^3 - 2(0.5)^2 + (0.5))\vec{M_0} + ((0.5)^3 - (0.5)^2)\vec{M_1}$ </br>
Applying our tangents:</br>
$P(t) = (2(0.5)^3 - 3(0.5)^2 + 1)\vec{P_0} + (-2(0.5)^3 + 3(0.5)^2)\vec{P_1} + ((0.5)^3 - 2(0.5)^2 + (0.5))[0,0,0] + ((0.5)^3 - (0.5)^2)[0,0,0] = (2(0.5)^3 - 3(0.5)^2 + 1)\vec{P_0} + (-2(0.5)^3 + 3(0.5)^2)\vec{P_1}$ </br>
Therefore, we can compute our remaining terms: </br>
$P(t) = (2(0.5)^3 - 3(0.5)^2 + 1)\vec{P_0} + (-2(0.5)^3 + 3(0.5)^2)\vec{P_1} = (2(0.125) - 3(0.25) + 1)\vec{P_0} + (-2(0.125) + 3(0.25))\vec{P_1} = (0.25 - 0.75 + 1)\vec{P_0} + (-0.25 + 0.75)\vec{P_1} = 0.5\vec{P_0} + 0.5\vec{P_1}$</br>
Thus, we can move onto our final step and substitute $\vec{P_0}$ and $\vec{P_1}$:</br>
$P(t) = 0.5\vec{P_0} + 0.5\vec{P_1} = 0.5[10,20,1] + 0.5[13,23,0] = [11.5, 21.5, 0.5]$</br></br>

Therefore, we predict via cubic (Hermite) interpolation that the players position at 0.5 seconds will be $[11.5,21.5,0.5]$
</br>
Cubic Interpolation is often used due to its ability to provide smoother player motion with smooth acceleration/deceleration.

---

### Cubic Spline Interpolation

Cubic Spline interpolation can be defined with the following formula:
</br>
$S_i(x) = a_{i}x^3 + b_{i}x^2 + c_{i}x + d_{i}$
</br>

### Nearest-Neighbor Interpolation
        TODO::::
---

## 9. What is Extrapolation and Why is it Important?
Extrapolation is a concept similar to interpolation, but an important concept nonetheless. Extrapolation allows us to "predict" the next position of an object based on the trend of previous points.

---

## 10. Event & State Synchronization and Consistency in TF2
What is synchronization (1)
What is event v state sync (2)
</br>
Event-based synchronization relies on signals 
State-based synchronization relies on some conditional statement

___ sharing among threads requires sycnhronization. We can avoid the question of machine code atomicity, declaring the need for cache coherence, and 



---


## 11. Client Prediction

---

## 12. Tick-Rate and Jitter Handling

---

## 13. Networked Movement Mechanics in Team Fortress 2

### Baseline Player Movement and Physics
Walking, strafing, jumping

Ground vs airborne control

Deterministic inputs and server authority

Expected behavior under latency
### Client Prediction and Server Reconciliation in TF2
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

## 14. Server Architectures: Iterative vs Concurrent Processing
Servers operate using two common architectures; Iterative and Concurrent. The best server type depends on what usage will be needed. 
</br>
Iterative servers are relatively more simple, have less overhead, and are cheaper. Additionally, Iterative Server Architecture processes one client connection at a time, ___. Thus, Iterative Servers function well when only one client needs to be processed at a time. For instance, an online chess game or a website for buying tickets. Both of these applications need an iterative server structure to ensure data arrives based on when a client connects.
</br>
Concurrent servers are more complex, have more overhead, and tend to be more expensive. This server architecture can accept multiple clients at the same time, allowing multi-client interactions. This server type is extremely useful for online gaming, large websites with constant traffic, and databases.
</br>

TODO:: Discuss thread-based v process-based v event-based. Can also put a short paragraph about atomicity, but not too in depth. 


---


## 15. Time Synchronization & Clock Drift
Different client clocks


## 16. Quality of Service (QoS) / Network Prioritization
Go over how client-side gameplay is prioritized over cosmetics and items.

## 17. Challenges and Security Implications of UDP Networking
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


## 18. Simulation Methodology

To create the simulation for this project, we must go through various steps:</br>
1. Generate a JSON file of Player objects to parse.
    1. Players are represented as objects with position vectors. 
    2. Position vectors will be 3-dimensional
2. Simulate various network conditions, including latency, jitter, and packet loss
3. Apply interpolation and lag compensation algorithms to synthetic positions to predict the next position.
4. Compare algorithm results with expected results and predict if the player is cheating or simply suffering packet loss.
    
    

## 19. Results and Observations

Let us analyze the results of this project:

    TODO!!!
    Compare simulated “real” vs “interpolated” positions.
    
    Explore how packet loss and jitter affect interpolation error.
    
    Example visualizations:
    
    Error over time
    
    Hit registration deviation (simulated)
    
    Discuss parameter effects (interpolation delay, buffer size).

## 20. Discussion

    TODO!!! Trade off between smooth visuals and responsiveness
    How ambiguity in UDP networking could be mistaken for cheating.
    Reinforce that the project is analysis-only.
    
    

## 21. Limitations
- No physics engine
- Simplified player model
- Limited tick rates
- Synthetic data only

## 22. Ethical Considerations
Research on these topics has potential for misuse. Please utilize this project responsibly and **do not** use it to cheat or as inspiration to cheat.

## 23. Conclusion


## 24. References
See **[References.md](References.md)** for all references.

### Appendix A: Interpolation Formulas
Linear Interpolation:  $lerp(P) = P(t) = (1-\alpha)\vec{a} + \alpha\vec{b}$.
</br>
Cubic Interpolation:   $P(t) = (2s^3 - 3s^2 + 1)\vec{P_0} + (-2s^3 + 3s^2)\vec{P_1} + (s^3 - 2s^2 + s)\vec{M_0} + (s^3 - s^2)\vec{M_1}$
</br>
Spline Interpolation:
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
