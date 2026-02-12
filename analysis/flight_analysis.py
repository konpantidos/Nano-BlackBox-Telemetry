import pandas as pd
import matplotlib.pyplot as plt
import sys

# 1. Load Data
print("--- Starting Analysis ---")
try:
    data = pd.read_csv('flight_log.csv')
    print("[OK] Data loaded successfully!")
    print(f"[INFO] Found {len(data)} rows of data.")
except FileNotFoundError:
    print("[ERROR] Could not find 'flight_log.csv'.")
    print("Make sure both files are in the same folder.")
    input("Press Enter to exit...")
    sys.exit()

# 2. Convert Time to Seconds
# Assuming Arduino logs in milliseconds
data['Seconds'] = data['Time'] / 1000.0 

# 3. Create Plots (3 rows, 1 column)
print("[INFO] Generating plots...")
fig, (ax1, ax2, ax3) = plt.subplots(3, 1, figsize=(10, 12), sharex=True)

# Plot 1: Acceleration
ax1.plot(data['Seconds'], data['AccelX'], label='X', color='red', alpha=0.7)
ax1.plot(data['Seconds'], data['AccelY'], label='Y', color='green', alpha=0.7)
ax1.plot(data['Seconds'], data['AccelZ'], label='Z', color='blue', linewidth=2)
ax1.set_ylabel('Accel (m/s^2)')
ax1.set_title('Flight Data Analysis')
ax1.legend(loc='upper right')
ax1.grid(True, linestyle='--', alpha=0.6)

# Plot 2: Gyroscope
ax2.plot(data['Seconds'], data['GyroX'], label='Roll', color='orange')
ax2.plot(data['Seconds'], data['GyroY'], label='Pitch', color='purple')
ax2.plot(data['Seconds'], data['GyroZ'], label='Yaw', color='brown')
ax2.set_ylabel('Gyro (deg/s)')
ax2.legend(loc='upper right')
ax2.grid(True, linestyle='--', alpha=0.6)

# Plot 3: Altitude
ax3.fill_between(data['Seconds'], data['Altitude'], color='skyblue', alpha=0.4)
ax3.plot(data['Seconds'], data['Altitude'], label='Altitude', color='navy', linewidth=2)
ax3.set_ylabel('Altitude (m)')
ax3.set_xlabel('Time (s)')
ax3.legend(loc='upper right')
ax3.grid(True, linestyle='--', alpha=0.6)

# 4. Show Window
print("[SUCCESS] Displaying graphs. Check the new window!")
plt.tight_layout()
plt.show()
