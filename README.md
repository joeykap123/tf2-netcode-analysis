```
Author: Joey Kaplan
```

# Overview
This project seeks to analyze various networking principles in Team Fortress 2, a game by Valve. Within this project, we will explore networking concepts and how they relate to online gaming. We will also explore phenomenons of cheating and how these methods are executed.</br>

> !NOTE
> **Disclaimer**
>
> This project is strictly for educational and research purposes. It is a simulation and study of how network latency, packet loss, and interpolation affect client-side perception of player position in games using UDP.
>
> **No part of this project is intended for cheating or exploitation in live games.** It does not interact with real game servers, and using similar techniques on live servers may violate game terms of service and applicable laws.
>
> The goal is to understand the mathematics and network behavior behind lag compensation and interpolation in a controlled, offline environment.
>
> This repository is strictly for **research and educational purposes**. It **does not** interact with Steam, the Team Fortress 2 client, or live servers, and it must **not** be used to create or distribute cheats or exploits. Running or adapting code in this repo against live game clients or servers may violate Valve's Steam Subscriber Agreement, VAC policies, and applicable laws.


# Overview of Lag Compensation
Lag compensation is "using a snapshot from a previous players position to balance latency issues". This is a common strategy implemented in many online games to ensure players are on equal ground. A server might "rewind" a player to a previous position to balance when the server received a message about interaction with the player.


# Overview of Interpolation
Interpolation, as a general concept, is a mathematical estimation of some set of datas corresponding function. This is extremely useful for smoothing data, analyzing trends, and creating continuous data. This is an important mathematical topic for online video games, since the use of UDP often results in the loss of packets. Thus, the usage of interpolation allows game servers to estimate a players next position based on prior data.</br>

# Associated Files

## Overview of data.json
**data.json** contains JSON style data that can be parsed and given to various mathematical functions to understand lag compensation and interpolation. 

> !NOTE
>
> All datasets in this project are **made-up, synthetic examples** created for testing and visualization.  
> No real network traffic or gameplay data was collected.

## Overview of math.cs
**math.cs** seeks to provide methods to analyze network latency, packet loss, and other factors are used in Team Fortress 2. 



Interpolation/Extrapolation Issues </br>
UDP Based Cheat Issues </br>
Network Attacks on Games </br>
Might want to mention DoS attacks because they relate to UDP </br>
TF2 Interpolation settings/eploit </br> 

Handle simulation of packet loss and interpolation to avoid creating entire server/client model</br>

Handle lag compensation and interpolation mainly. Can reference interp cheating, but that is not primary goal of project.
