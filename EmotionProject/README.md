# 🚗 AI-Based Driver Drowsiness Detection System using ESP32

## 📖 Overview

Driver fatigue and drowsiness are among the leading causes of road accidents worldwide. This project presents an **AI-powered Driver Drowsiness Detection System** that continuously monitors the driver's facial expressions using computer vision techniques and automatically triggers safety mechanisms when sleep is detected.

The system integrates **Artificial Intelligence, Computer Vision, and Embedded Systems** to detect driver emotions in real time. When the system identifies that the driver is sleeping or drowsy, it activates an alert buzzer and automatically stops the motor using a relay module to prevent potential accidents.

This project demonstrates a practical implementation of **AI-based safety systems for intelligent transportation and driver monitoring systems (DMS)**.

---

# 🎯 Objectives

The primary objectives of this project are:

• Detect driver facial expressions in real-time using computer vision
• Identify driver drowsiness or sleep state
• Alert the driver using an audible buzzer warning
• Automatically stop the vehicle motor when sleep is detected
• Display the detected emotion on a graphical TFT display
• Integrate AI-based software with embedded hardware systems

---

# 🧠 System Architecture

The complete system workflow is illustrated below:

Camera (Laptop Webcam)
↓
AI Facial Landmark Detection (MediaPipe)
↓
Emotion Detection Algorithm (Python)
↓
Serial Communication via USB
↓
ESP32 Microcontroller
↓
TFT Display + Buzzer + Relay Motor Control

---

# ⚙️ Working Principle

1. The webcam continuously captures the driver's face.

2. The Python program processes the video stream using **MediaPipe Face Landmarks**, which detects **468 facial key points**.

3. Based on facial landmark movement (eyes, lips, facial geometry), the system estimates the driver's emotional state.

4. The detected emotion is transmitted to the **ESP32 microcontroller** through serial communication.

5. The ESP32 performs the following actions:

   * Displays the emotion on a **TFT LCD display**
   * Activates a **buzzer alarm** if sleep is detected
   * Disables the motor using a **relay module**

6. If the driver returns to a normal state, the motor resumes operation.

---

# 🛠 Hardware Components

| Component                       | Description                                 |
| ------------------------------- | ------------------------------------------- |
| ESP32 Development Board         | Main microcontroller controlling the system |
| 1.8" TFT LCD Display (ST7735)   | Displays detected emotion and emoji         |
| Relay Module                    | Controls motor power                        |
| Buzzer                          | Provides audible alert                      |
| DC Motor                        | Represents vehicle wheel                    |
| L298N Motor Driver *(optional)* | Motor speed control                         |
| Breadboard                      | Circuit prototyping                         |
| Jumper Wires                    | Electrical connections                      |
| Laptop Camera                   | Captures driver facial expressions          |

---

# 💻 Software Technologies

| Technology   | Purpose                         |
| ------------ | ------------------------------- |
| Python       | AI processing                   |
| OpenCV       | Image and video processing      |
| MediaPipe    | Facial landmark detection       |
| PySerial     | Serial communication with ESP32 |
| Arduino IDE  | Programming ESP32               |
| Embedded C++ | Microcontroller logic           |

---

# 📂 Project Directory Structure

```id="structure_block"
Driver-Drowsiness-Detection
│
├── emotion_cam.py
├── face_landmarker.task
├── README.md
│
├── esp32_code
│   └── driver_monitor_system.ino
│
├── assets
│   ├── system_architecture.png
│   └── demo_output.png
│
└── docs
    └── project_report.pdf
```

---

# 📦 Installation Guide

## 1️⃣ Install Python Dependencies

Run the following command:

```id="install_block"
pip install opencv-python mediapipe pyserial
```

---

## 2️⃣ Download MediaPipe Face Landmark Model

Download the following model file:

```
face_landmarker.task
```

Place the file in the main project directory.

---

## 3️⃣ Upload ESP32 Firmware

Open the Arduino IDE and upload the ESP32 code.

Required libraries:

```
Adafruit GFX
Adafruit ST7735
```

---

## 4️⃣ Run the AI Detection Program

Navigate to the project directory:

```id="run_block"
cd EmotionProject
```

Start the program:

```id="run2_block"
python emotion_cam.py
```

The webcam will start detecting driver emotions in real time.

---

# 🔌 Hardware Connections

### Circuit Diagram with link : https://app.cirkitdesigner.com/project/261ed2cc-3852-4805-afad-4c0256d3cab4

## Circuit Diagram : 

<img width="1151" height="601" alt="image" src="https://github.com/user-attachments/assets/bd3e07b6-a933-420a-84a7-613ea19a22e2" />

---

## TFT Display (ST7735)

| TFT Pin | ESP32 Pin |
| ------- | --------- |
| VCC     | 3.3V      |
| GND     | GND       |
| SCL     | GPIO18    |
| SDA     | GPIO23    |
| RES     | GPIO4     |
| DC      | GPIO2     |
| CS      | GPIO5     |
| BL      | 3.3V      |

## Display Screen 1.8 128*160 RGB TFT_LCD Output : 

<img width="331.5" height="400" alt="image" src="https://github.com/user-attachments/assets/006429f4-ae3e-4785-a833-e392ff7e4120" />

<img width="331.5" height="400" alt="image" src="https://github.com/user-attachments/assets/30b370e6-6f38-480f-a964-7476312095d0" />

<img width="331.5" height="400" alt="image" src="https://github.com/user-attachments/assets/10ee7222-c042-4e45-9e71-bfa7157561ff" />

<img width="331.5" height="400" alt="image" src="https://github.com/user-attachments/assets/9118ba32-c5c4-4631-bdae-abb2f5d4501f" />

<img width="331.5" height="400" alt="image" src="https://github.com/user-attachments/assets/b4d56c4f-95bb-4000-95c8-d82c23c5b46d" />

---

## Relay Module

| Relay Pin | ESP32  |
| --------- | ------ |
| IN        | GPIO23 |
| VCC       | 5V     |
| GND       | GND    |

---

## Buzzer

| Buzzer Pin | ESP32  |
| ---------- | ------ |
| Positive   | GPIO15 |
| Negative   | GND    |

---

## Motor Power Control

Battery + → Relay COM
Relay NO → Motor +
Motor − → Battery −

----- 

## Laptop Display Input Screen : 

<img width="1151" height="601" alt="image" src="https://github.com/user-attachments/assets/cecaeedd-a7d6-4638-9170-2e0f4028ffd8" />

---

# 🎯 Detected Emotions

The AI system detects multiple driver emotional states:

• 😊 SMILING
• 😐 NEUTRAL
• 😲 SURPRISED
• 😴 SLEEPING
• ☹️ SAD
• 😭 CRYING
• 😡 ANGER
• 👀 SEARCHING

---

# 🚨 Safety Mechanism

When the system detects the driver is sleeping:

1. Buzzer alarm is activated
2. Relay cuts the motor power
3. TFT display shows **SLEEPING** emotion

This ensures immediate driver alert and vehicle safety.

---

# 📊 Advantages

• Real-time driver monitoring
• Low-cost hardware implementation
• High-speed AI emotion detection
• Easy integration with embedded systems
• Suitable for smart vehicle safety systems

---

# 🚀 Future Enhancements

• Integration with **ESP32-CAM**
• Deep learning emotion recognition models
• Mobile app alert system
• IoT cloud-based driver monitoring
• Real vehicle braking integration
• GPS emergency alert system

---

# 📚 Applications

This system can be applied in:

• Smart vehicle safety systems
• Driver monitoring systems (DMS)
• Autonomous vehicle assistance
• Fleet management safety monitoring
• Transportation safety research

---

# 👨‍💻 Author

**Hari Prasad**

Electrical and Electronics Engineering
AI & Embedded Systems Developer

---

# 🤝 Contribution

Contributions are welcome.

1. Fork the repository
2. Create a new branch
3. Commit changes
4. Submit a Pull Request

---

# 📜 License

This project is released under the **MIT License**.

You are free to use, modify, and distribute this project for educational and research purposes.
