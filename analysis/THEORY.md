# 📑 Theoretical Modeling & Mathematical Foundations

This document details the physical laws and mathematical algorithms used to process the flight data of the Nano BlackBox. Transitioning from raw sensor readings to accurate flight telemetry requires a robust understanding of atmospheric physics and stochastic estimation.

---

## 1. Atmospheric Physics: The Barometric Formula

The BMP280 sensor measures static atmospheric pressure ($P$). To convert this pressure into altitude ($h$), we utilize the **International Standard Atmosphere (ISA)** model. In the troposphere (up to 11km), the relationship is defined by:

$$P = P_0 \cdot \left(1 - \frac{L \cdot h}{T_0}\right)^{\frac{g \cdot M}{R \cdot L}}$$



### Constants & Variables:
* $P_0$: Sea level standard pressure ($101,325 \text{ Pa}$)
* $L$: Temperature lapse rate ($0.0065 \text{ K/m}$)
* $T_0$: Sea level standard temperature ($288.15 \text{ K}$)
* $g$: Earth's gravitational acceleration ($9.80665 \text{ m/s}^2$)
* $M$: Molar mass of dry air ($0.0289644 \text{ kg/mol}$)
* $R$: Universal gas constant ($8.31447 \text{ J/(mol·K)}$)

In our firmware/analysis, we solve for $h$ to derive the instantaneous altitude relative to sea level.

---

## 2. State-Space Representation

To track the rocket's trajectory, we model the system using a discrete-time linear state-space representation. We define the **State Vector** $x$ as:

$$x_k = \begin{bmatrix} h \\ v \end{bmatrix}_k$$

Where $h$ is altitude and $v$ is vertical velocity. The evolution of the system from time $k-1$ to $k$ follows Newtonian kinematics:

$$x_k = F \cdot x_{k-1} + B \cdot u_k + w_k$$

### Matrices:
* **State Transition Matrix ($F$):** Projects the previous state into the current state.
  $$F = \begin{bmatrix} 1 & \Delta t \\ 0 & 1 \end{bmatrix}$$
* **Control Input Matrix ($B$):** Relates the control input (acceleration $a$) to the state.
  $$B = \begin{bmatrix} \frac{1}{2}\Delta t^2 \\ \Delta t \end{bmatrix}$$
* **Process Noise ($w_k$):** Accounts for model inaccuracies (e.g., wind gusts, vibrations).

---

## 3. Sensor Fusion via Linear Kalman Filter

Raw sensor data suffers from two distinct types of errors:
1. **BMP280 Noise:** Pressure readings are stable but "slow" and noisy due to air turbulence.
2. **MPU6050 Drift:** Accelerometer data is "fast" but integrating it to find altitude leads to exponential error accumulation (drift).

We implement a **Linear Kalman Filter** to find the optimal estimate by recursively minimizing the mean square error.



### The Recursive Loop:

#### A. Prediction (Time Update)
Predict the next state and covariance:
$$\hat{x}_{k|k-1} = F\hat{x}_{k-1|k-1} + Bu_k$$
$$P_{k|k-1} = FP_{k-1|k-1}F^T + Q$$

#### B. Correction (Measurement Update)
Adjust the prediction based on the Barometer's measurement ($z_k$):
$$K_k = P_{k|k-1}H^T(HP_{k|k-1}H^T + R)^{-1}$$
$$\hat{x}_{k|k} = \hat{x}_{k|k-1} + K_k(z_k - H\hat{x}_{k|k-1})$$
$$P_{k|k} = (I - K_kH)P_{k|k-1}$$



---

## 4. Conclusion
By fusing the high-frequency response of the **MPU6050 IMU** with the absolute reference of the **BMP280 Barometer**, the Kalman Filter provides a reliable, low-latency telemetry profile. This methodology is fundamental in aerospace engineering for GNC (Guidance, Navigation, and Control) systems.
