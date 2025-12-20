# Interpolation Examples Document

## Overview

Going to move interpolation formulas here to declutter Research Doc. (Reader doesn't care about the calculation -> they just want to know how/why it works and if it is a good use for interpolation over another method.

**This document holds examples of calculations found using various interpolation formulas.**


## Interpolation Formulas (Reference)
**Linear Interpolation:**  
$P(t) = $  
**Cubic Hermite Interpolation:**  
$P(t) = $  
**Cubic Spline Interpolation:**  
$P(t) = $  
**Nearest Neighbor Interpolation:**  
$P(t) = $  

## LINEAR INTERPOLATION

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

TODO:: FIX SOME wording to make this sound better and more polished (maybe restructure to: concept -> formula -> example -> result -> note)
## CUBIC HERMITE INTERPOLATION

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

## CUBIC SPLINE INTERPOLATION

## NEAREST NEIGHBOR INTERPOLATION
