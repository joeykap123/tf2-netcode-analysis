## An Analysis of Networking Principles in Team Fortress 2

```
Author : Joey Kaplan
```

## 1. Introduction

## 2. Overview of Team Fortress 2 (TF2) Networking

## 3. Why is UDP Used and Its Trade-Offs

## 4. What is Lag Compensation and Why is it Important?

Lag compensation is "using a snapshot from a previous players position to balance latency issues". This is a common strategy implemented in many online games to ensure players are on equal ground. A server might "rewind" a player to a previous position to balance when the server received a message about interaction with the player.

---
## 5. What is Interpolation and Why is it Important?

Interpolation, as a general concept, is a mathematical estimation of some set of datas corresponding function. This is extremely useful for smoothing data, analyzing trends, and creating continuous data. This is an important mathematical topic for online video games, since the use of UDP often results in the loss of packets. Thus, the usage of interpolation allows game servers to estimate a players next position based on prior data.
</br>
Notable interpolation strategies include Linear Interpolation, Cubic Interpolation, and Nearest-Neighbor Interpolation. We will explore these interpolation strategies and hypothesize which method TF2 uses. 
</br></br>
Let us define a players position as:</br>
$P(t) = [x(t), y(t), z(t)]$
</br>
Where P(t) indicates a Player's position at a given time, and $[x(t), y(t), z(t)] indicates the 3-D player position vector.

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
Therefore, we predict via linear interpolation that the players position at 0.25 seconds will be $[2.5,3,4]$

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
Appling our tangents:</br>
$P(t) = (2(0.5)^3 - 3(0.5)^2 + 1)\vec{P_0} + (-2(0.5)^3 + 3(0.5)^2)\vec{P_1} + ((0.5)^3 - 2(0.5)^2 + (0.5))[0,0,0] + ((0.5)^3 - (0.5)^2)[0,0,0] = (2(0.5)^3 - 3(0.5)^2 + 1)\vec{P_0} + (-2(0.5)^3 + 3(0.5)^2)\vec{P_1}$ </br>
Therefore, we can compute our remaining terms: </br>
$P(t) = (2(0.5)^3 - 3(0.5)^2 + 1)\vec{P_0} + (-2(0.5)^3 + 3(0.5)^2)\vec{P_1} = (2(0.125) - 3(0.25) + 1)\vec{P_0} + (-2(0.125) + 3(0.25))\vec{P_1} = (0.25 - 0.75 + 1)\vec{P_0} + (-0.25 + 0.75)\vec{P_1} = 0.5\vec{P_0} + 0.5\vec{P_1}$</br>
Thus, we can move onto our final step and substitue $\vec{P_0}$ and $\vec{P_1}$:</br>
$P(t) = 0.5\vec{P_0} + 0.5\vec{P_1} = 0.5[10,20,1] + 0.5[13,23,0] = [11.5, 21.5, 0.5]</br></br>

Therefore, we predict via cubic (Hermite) interpolation that the players position at 0.5 seconds will be $[11.5,21.5,0.5]$
</br>
Cubic Interpolation is often used due to its ability to provide smoother player motion with smooth acceleration/deceleration.

---

### Cubic Spline Interpolation

### Nearest-Neighbor Interpolation

---

## 6. Problems with Usage of UDP and Lag Compensation/Interpolation
However, while lag compensation and interpolation generally result in better gameplay, these concepts can become problematic, noteably when cheating becomes involved. </br>

Team Fortress 2 has a notable command that players can modify within their console, known as **cl_interp**. 
Beyond TF2's specific commands, cheating in online servers is popular and hard to catch. This is due to the nature of UDP; This protocol is built for speed, making packet loss inevitable. Knowing this, cheaters can use strategies such as modification of interpolation to simulate innocent packet loss, leading to difficulty in telling cheaters apart from players with poor connection. 
</br>

Additionally, topics such as Denial of Service (DoS) attacks can be executed on these servers with little difficulty and little risk of being caught. Since DoS attacks leverage sending many requests to a server in a short time period, servers using UDP are at specific risk. Since UDP does not require a three-way handshake to establish connection like TCP, an attacker can easily overwhelm UDP servers. 
</br>

IP Spoofing can also be easily executed over UDP connections. Since UDP has no way to verify identity, attackers can send requests to the server using the victims IP, leading to large amounts of data being sent to the victims system.
</br>

It should be noted that DoS attacks are not as malicious in nature when implemented on gaming servers, as often, they are a means to make the attacker win or gain an upperhand.


## 7. Simulation Design and Methodology

To create the simulation for this project, we must go through various steps:</br>
1. Generate a JSON file of Player objects to parse.
    1. Players are represented as objects with position vectors. 
    2. Position vectors will be 3-dimensional
2. Simulate various network conditions including latency, jitter, and packet losst
3. Apply interpolation and lag compensation algorithms to synthetic positions to predict next position.
4. Compare algorithm results with expected results and predict if the player is cheating or simply suffering packet loss.
    
    

## 8. Results and Observations

Let us analyze our results of this project:

    TODO!!!
    Compare simulated “real” vs “interpolated” positions.
    
    Explore how packet loss and jitter affect interpolation error.
    
    Example visualizations:
    
    Error over time
    
    Hit registration deviation (simulated)
    
    Discuss parameter effects (interpolation delay, buffer size).

## 9. Discussion

    TODO!!! Trade off between smooth visuals and responsiveness
    How ambiguity in UDP networking could be mistaken for cheating.
    Reinforce that the project is analysis-only.
    
    

## 10. Limitations
- No physics engine
- Simplified player model
- Limited tick rates
- Synthetic data only

## 11. Ethical and Educational Context


## 12. Conclusion

## 13. References
See **References.md** for all references.


### Appendix A: Interpolation Formulas
    TODO!!!

Linear Interpolation:

Cubic Interpolation:

Spline Interpolation:

### Appendix B - Simulation Parameters

| Parameter                 | Value       | Description                                 |
|---------------------------|-------------|---------------------------------------------|
| Tick Rate                 | 66 ticks/s  | Server updates per second                   |
| Interpolation Delay       | 100 ms      | Client-side render buffer                   |
| Packet Loss               | 0-10%       | Randomly simulated loss                     |
| Latency                   | 50-200 ms   | Round-trip time applied per simulated player|
| Number of Players         | 5           | Number of simulated entities                |

    TODO!!! NOT YET IMPLEMENTED IN data.json
