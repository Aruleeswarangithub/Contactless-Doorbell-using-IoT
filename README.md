🚪🔔 Contactless Doorbell Using IoT

Hey, it's **Aruleeswaran**, your **tech buddy**! 👋  
Welcome to my **IoT-powered Contactless Doorbell** – a **smart and hygienic** solution for modern homes. Let's create **safe, touch-free experiences** together! 🏡💡

---

## ✨ Features

✔ **Touchless Detection** – Detect visitors using an **ultrasonic sensor** – no button press needed!  
✔ **Temperature Check** – Auto-measures body temperature using the **LM35 sensor**.  
✔ **LED Alerts** –  
&nbsp;&nbsp;&nbsp;&nbsp;🟢 Green = Normal temperature  
&nbsp;&nbsp;&nbsp;&nbsp;🔴 Red + Buzzer = High temperature alert  
✔ **Live LCD Display** – Show temperature in real-time!  
✔ **GSM Module Support** – (Optional) Send SMS alerts using **SIM900A**.  
✔ **Safety First** – Designed to avoid physical contact and maintain hygiene.  

---

## 🎥 Demo Video

🎬 **See it in action!**  
[![Watch the demo](https://go.screenpal.com/watch/cZQq2NVSbsU ![image](https://github.com/user-attachments/assets/7da4560c-3f76-413d-94f5-972b06e3a810))  


---

## 🧰 What I Used

### 🔌 Hardware Components:
- Arduino UNO R3  
- Ultrasonic Sensor (HC-SR04)  
- LM35 Temperature Sensor  
- 16x2 LCD Display  
- SIM900A GSM Module   
- Buzzer  
- Red and Green LEDs  
- 22 Ohm Resistor  
- Breadboard & Jumper Wires  
- 12V Adapter or USB power  

### 💻 Software Tools:
- Arduino IDE  
- Embedded C/C++  
- Proteus/Tinkercad *(Circuit Design and simulation)*  

---

## 🛠️ How It Works

1. 🚶 **Visitor approaches** – Detected by the ultrasonic sensor.  
2. 🌡️ **Temperature is measured** via LM35 sensor.  
3. 🖥️ **LCD displays** the temperature.  
4. 🟢 If normal → Green LED ON  
   🔴 If high → Red LED ON + Buzzer alerts  
5. 📲 An SMS alert is sent using the GSM module.

---

## 🖼️ Circuit Diagram


![Circuit Diagram](https://ik.imagekit.io/ina6eaq0k/circuit_diagram.png?updatedAt=1747311847201)


---

## 🚀 How to Build It

1. **Clone the Project**

```bash
git clone https://github.com/Aruleeswarangithub/contactless-doorbell-iot.git
cd contactless-doorbell-iot

2. Open the Arduino Code

Launch the Arduino IDE.

Open the .ino file located in the cloned project folder.

3. Connect Your Arduino UNO

Plug the Arduino UNO into your computer via USB.

In Arduino IDE, go to Tools → Board → Select Arduino UNO.

Go to Tools → Port → Select the correct COM port.

4. Upload the Code

Click ✅ Verify to compile the code.

Click 🔼 Upload to flash the code to the board.

5. Build the Circuit

Connect components: Ultrasonic sensor, LM35 sensor, LEDs, LCD, Buzzer, and GSM Module.

Power the circuit using USB or 12V adapter.

6. Test the System

Wave your hand in front of the ultrasonic sensor.

The system will check body temperature using LM35.

Based on temperature, the correct LED will glow.

The buzzer will ring and a message will be sent via GSM.
