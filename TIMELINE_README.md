## Project Roadmap & Development Timeline


### Phase 1: Design & Simulation (Completed)
- [x] Define system architecture (Arduino Nano, MPU6050, BMP180, SD Card).
- [x] Develop Python-based telemetry analysis scripts.
- [x] Full circuit simulation using **Wokwi**.
- [x] Establish GitHub repository structure and documentation standards.

### Phase 2: Hardware Prototyping (Breadboard)
- [ ] **Assembly:** Wire sensors and SD module on a breadboard.
- [ ] **Bench Testing:** Verify real-time CSV logging and file I/O operations.
- [ ] **Debugging:** Troubleshoot I2C/SPI bus stability and power distribution.
- [ ] **Initial Ground Test:** Record "hand-held" motion data to verify sensor responsiveness.

### Phase 3: Advanced Engineering (DSP & Theory)
- [x] **Sensor Calibration:** Implement scripts to calculate sensor bias (offsets) for the accelerometer and gyroscope.
- [x] **Digital Signal Processing (DSP):** Implement a **Kalman Filter** in Python to fuse IMU and Barometric data.
- [ ] **Theoretical Modeling:** Document flight physics including the barometric formula:
  $$P = P_0 \cdot \left(1 - \frac{L \cdot h}{T_0}\right)^{\frac{g \cdot M}{R \cdot L}}$$
 
### Phase 4: PCB Design & Manufacturing
- [ ] **Schematic Entry:** Transfer the breadboard circuit to **EasyEDA/KiCad**.
- [ ] **PCB Routing:** Design a compact, high-vibration resistant PCB layout.
- [ ] **Fabrication:** Order custom PCBs (e.g., via JLCPCB/PCBWay).
- [ ] **Soldering:** Final assembly of surface-mount or through-hole components.

### Phase 5: Flight Integration & Launch
- [ ] **System Integration:** Secure the BlackBox into the rocket airframe.
- [ ] **Pre-flight Check:** Verify battery voltage and SD card status.
- [ ] **Launch & Recovery:** Execute flight and retrieve the `datalog.csv`.
- [ ] **Post-flight Analysis:** Process flight data through the analysis pipeline.

### Phase 6: Academic Documentation
- [ ] **Technical Report:** Write a comprehensive project paper (PDF) detailing engineering challenges and results.
- [ ] **Data Visualization:** Finalize plots (Altitude, Velocity, G-Force) for the portfolio.
- [ ] **Final Polish:** Update GitHub Wiki with lessons learned and future improvements.

---

## Development Overview

| Phase | Action | Tools | Objective |
| :--- | :--- | :--- | :--- |
| **1. Simulation** | Circuit & Logic Test | Wokwi, GitHub | Proof of Concept & Virtual Validation |
| **2. Prototyping** | Physical Build | Arduino IDE, Breadboard | Hardware-Software Integration |
| **3. DSP & Math** | Noise Reduction | Python, Kalman Filter | Signal Integrity & Academic Depth |
| **4. Manufacturing**| Hardware Hardening | EasyEDA, Soldering | Flight-Ready Professional Product |
| **5. Launch** | Data Collection | Model Rocket, SD Logger | Real-World Performance Testing |
| **6. Reporting** | Documentation | LaTeX, Markdown | Portfolio & Master's Admissions Prep |

