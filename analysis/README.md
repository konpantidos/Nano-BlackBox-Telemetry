# Flight Data Analysis & Physics

This folder contains the Python tools used to process, visualize, and interpret the telemetry data recorded by the Nano BlackBox.

## Contents
* **`plot_data.py`**: The main Python script to generate flight graphs.
* **`kalman_filter.py`**: Implementation of the sensor fusion algorithm.
* **[`THEORY.md`](./THEORY.md)**: Detailed mathematical derivation of the physics formulas.
* **`flight_sample.csv`**: Sample dataset for testing.

---

## The Physics of Flight (Summary)
To understand the rocket's performance, we analyze three key metrics.
*(For the full mathematical breakdown, please refer to [`THEORY.md`](./THEORY.md))*

### 1. Altitude Estimation ($h$)
We calculate altitude using the barometric formula based on pressure ($P$) and temperature ($T$):
$$h = 44330 \cdot \left( 1 - \left( \frac{P}{P_0} \right)^{\frac{1}{5.255}} \right)$$

### 2. Vertical Acceleration ($a_z$)
Measured by the IMU in G-force.
* **> 1g:** Thrust Phase (Liftoff).
* **~ 0g:** Coasting (Freefall/Drag).
* **Spikes:** Parachute deployment shock.

---

## Sensor Fusion: The Kalman Filter
Raw sensor data is never perfect. To get a precise "Apogee" detection, we cannot rely on a single sensor. We use a **Kalman Filter** to fuse data.



### Why do we need it?
* **Accelerometers** are fast but suffer from high-frequency **noise** (vibration).
* **Barometers** are smooth but suffer from **lag** and low resolution.

The Kalman Filter combines these two inputs to predict the **True State** of the rocket, filtering out noise while maintaining speed.

---

## How to Run the Analysis
Prerequisites: Python 3 with `pandas`, `matplotlib`, and `numpy`.

### 1. Install Libraries
```bash
pip install pandas matplotlib numpy.
