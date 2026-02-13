import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from filterpy.kalman import KalmanFilter

df = pd.read_csv('flight_log.csv')

df['Time_s'] = (df['Time(ms)'] - df['Time(ms)'].iloc[0]) / 1000.0
dt = df['Time_s'].diff().mean()

kf = KalmanFilter(dim_x=2, dim_z=1)
kf.x = np.array([[df['Altitude(m)'].iloc[0]], [0.0]])
kf.F = np.array([[1.0, dt], [0.0, 1.0]])
kf.H = np.array([[1.0, 0.0]])
kf.P *= 10.0
kf.R = 0.4
kf.Q = 0.05

kalman_estimates = []

for i in range(len(df)):
    accel_z = df['AccelZ'].iloc[i] - 9.81
    kf.predict(u=accel_z)
    kf.update(df['Altitude(m)'].iloc[i])
    kalman_estimates.append(kf.x[0, 0])

df['Filtered_Altitude'] = kalman_estimates

plt.figure(figsize=(10, 6))
plt.plot(df['Time_s'], df['Altitude(m)'], label='Raw BMP280 Data', alpha=0.5)
plt.plot(df['Time_s'], df['Filtered_Altitude'], label='Kalman Filter (Sensor Fusion)', color='red', linewidth=2)
plt.title('Altitude Estimation: Raw vs Kalman Filtered')
plt.xlabel('Time (s)')
plt.ylabel('Altitude (m)')
plt.legend()
plt.grid(True)
plt.savefig('analysis_result.png')
plt.show()
