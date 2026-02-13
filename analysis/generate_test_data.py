import pandas as pd
import numpy as np

duration = 20  
fs = 30        
t = np.linspace(0, duration, duration * fs)

altitude = -5 * t**2 + 100 * t
altitude = np.maximum(0, altitude)

accel_z = np.full_like(t, 9.81)
accel_z[0:3*fs] += 25 

altitude_noisy = altitude + np.random.normal(0, 1.5, size=len(t))
accel_z_noisy = accel_z + np.random.normal(0, 0.8, size=len(t))

df = pd.DataFrame({
    'Time(ms)': (t * 1000).astype(int),
    'AccelX': np.random.normal(0, 0.1, size=len(t)),
    'AccelY': np.random.normal(0, 0.1, size=len(t)),
    'AccelZ': accel_z_noisy,
    'GyroX': 0, 'GyroY': 0, 'GyroZ': 0,
    'Altitude(m)': altitude_noisy,
    'Temp(C)': 25
})

df.to_csv('flight_log.csv', index=False)
print("Success: flight_log.csv has been generated.")
