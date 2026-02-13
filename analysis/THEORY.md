# 📑 Theoretical Modeling & Mathematical Foundations

This document details the physical laws and mathematical algorithms used to process the flight data of the Nano BlackBox.

---

## 1. Atmospheric Physics: The Barometric Formula

The BMP280 sensor measures static atmospheric pressure ($P$). To convert this into altitude ($h$), we utilize the **International Standard Atmosphere (ISA)** model:

$$
P = P_0 \cdot \left(1 - \frac{L \cdot h}{T_0}\right)^{\frac{g \cdot M}{R \cdot L}}
$$

### Constants:
* **$P_0$**: Sea level pressure ($101325 \text{ Pa}$)
* **$L$**: Lapse rate ($0.0065 \text{ K/m}$)
* **$g$**: Gravity ($9.80665 \text{ m/s}^2$)
* **$M$**: Molar mass of air ($0.0289644 \text{ kg/mol}$)
* **$R$**: Gas constant ($8.31447 \text{ J/mol/K}$)

---

## 2. State-Space Representation

We model the rocket's motion using a discrete-time linear state-space representation. The **State Vector** $x$ is:

$$
x_k = \begin{bmatrix} h \\ v \end{bmatrix}_k
$$

The evolution of the system follows Newtonian kinematics.

### State Transition Matrix ($F$):
Predicts the next state based on current altitude and velocity:

$$F = \begin{bmatrix} 1 & \Delta t \\ 0 & 1 \end{bmatrix}$$

### Control Input Matrix ($B$):
Relates the vertical acceleration ($a$) to the state change:

$$B = \begin{bmatrix} 0.5 \cdot \Delta t^2 \\ \Delta t \end{bmatrix}$$

## 3. Sensor Fusion via Linear Kalman Filter

We implement a **Linear Kalman Filter** to fuse the **MPU6050** (accelerometer) and **BMP280** (barometer) data.

### A. Prediction (Time Update)
Predict the next state and covariance:

$$
\hat{x}_{k|k-1} = F\hat{x}_{k-1|k-1} + Bu_k
$$

$$
P_{k|k-1} = FP_{k-1|k-1}F^T + Q
$$

### B. Correction (Measurement Update)
Adjust the prediction based on the Barometer measurement ($z_k$):

$$
K_k = P_{k|k-1}H^T(HP_{k|k-1}H^T + R)^{-1}
$$

$$
\hat{x}_{k|k} = \hat{x}_{k|k-1} + K_k(z_k - H\hat{x}_{k|k-1})
$$

---

## 4. Conclusion

By fusing high-frequency IMU data with absolute barometric reference, the filter minimizes noise and integration drift, providing optimal telemetry for aerospace applications.
