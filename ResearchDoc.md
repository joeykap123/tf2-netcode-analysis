## An Analysis of Networking Principles in Team Fortress 2

```
Author : Joey Kaplan
```

## 1. Introduction

## 2. Overview of Team Fortress 2 (TF2) Networking

## 3. Why is UDP Used and Its Trade-Offs

## 4. What is Lag Compensation and Why is it Important?

---
## 5. What is Interpolation and Why is it Important?



Notable interpolation strategies include Linear Interpolation, Cubic Interpolation, and Nearest-Neighbor Interpolation. We will explore these interpolation strategies and hypothesize which method TF2 uses. 

### Linear Interpolation

Linear Interpolation can be defined with the following formula:
</br>
    $lerp(\vec{a},\vec{b},t) = (x_1 + (x_2 - x_1)\times t, y_1 + (y_2 - y_1) \times t, z_1 + (z_2 - z_1) \times t)$.
    </br>
    $\vec{a} =$ Starting Position
    </br>
    $\vec{b} =$ Ending Position
    </br>
    $t =$ Interpolation Factor
</br>
    
### Cubic Interpolation
(Spline?) 

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
      TODO!!!
      Offline simulation using synthetic data:

    Players represented as simple objects with position vectors.

    Network conditions: latency, jitter, packet loss.
    
    Interpolation and lag compensation algorithms applied to synthetic positions.
    
    No live data or TF2 servers are accessed.
    
    Optional Subsections:
    
    Data generation (data/data.json)
    
    Network event simulation
    
    Visualization approach (e.g., matplotlib or C# plotting libraries)
    

## 8. Results and Observations
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


### Appendix A: Interpolation Formulas
    TODO!!!

### Appendix B - Simulation Parameters

| Parameter                 | Value       | Description                                 |
|---------------------------|-------------|---------------------------------------------|
| Tick Rate                 | 66 ticks/s  | Server updates per second                   |
| Interpolation Delay       | 100 ms      | Client-side render buffer                   |
| Packet Loss               | 0-10%       | Randomly simulated loss                     |
| Latency                   | 50-200 ms   | Round-trip time applied per simulated player|
| Number of Players         | 5           | Number of simulated entities                |

    TODO!!! NOT YET IMPLEMENTED IN data.json
