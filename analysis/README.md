## 🧪 Theoretical Framework
To achieve high-fidelity altitude estimation, we implement a **Linear Kalman Filter** for **Sensor Fusion**.

### The Problem
- **BMP280 (Barometer):** Provides absolute altitude but suffers from signal noise and atmospheric lag.
- **MPU6050 (Accelerometer):** Extremely responsive to vertical movement but suffers from integration drift.

### The Solution: Kalman Filter
We use a 1D Kalman Filter to fuse data from both sensors. The state vector is defined as:
$$x = \begin{bmatrix} h \\ v \end{bmatrix}$$
where $h$ is altitude and $v$ is vertical velocity.

The algorithm follows two steps:
1. **Prediction:** Uses the MPU6050's Z-axis acceleration to predict the next state.
2. **Correction:** Uses the BMP280's barometric altitude to correct the prediction.

## 📊 Implementation Results
The Python script `flight_analysis.py` processes the raw CSV data. 
*By fusing acceleration and pressure data, we successfully mitigate barometric noise while maintaining high response frequency.*
