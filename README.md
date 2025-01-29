# 5G Ultrasonic Sensor Project 🚀

This project integrates **Arduino, Python, and FastAPI** to build a **real-time ultrasonic sensor system**. It consists of three segments:

1. **Hardware:** Ultrasonic sensor detects objects and controls an LED.
2. **Real-Time Data Processing:** Python fetches data via serial communication and visualizes it with Matplotlib.
3. **API & Deployment:** FastAPI serves real-time data, deployed on a college server.

---

## 📌 Features:
✅ **Arduino Integration** – Ultrasonic sensor + LED control  
✅ **Real-Time Data Visualization** – Dynamic graph plotting  
✅ **FastAPI for Web API** – Fetch sensor data remotely  
✅ **Secure API Key** – Restricted access control  
✅ **Deployment on College Server** – Remote access and monitoring  

---

## 📂 Project Structure:
```
5G-Ultrasonic-Project/
│── Arduino_Code/          # Arduino code
│   └── ultrasonic_sensor.ino
│── Python_Scripts/        # Python scripts
│   ├── real_time_plot.py
│   ├── api.py
│── README.md              # Documentation
│── requirements.txt       # Dependencies
│── .gitignore             # Ignore files
```

---

## 🚀 Installation & Setup

### **1️⃣ Clone the Repository**
```sh
git clone https://github.com/your-username/5G-Ultrasonic-Project.git
cd 5G-Ultrasonic-Project
```

### **2️⃣ Install Dependencies**
```sh
pip install -r requirements.txt
```

### **3️⃣ Upload Arduino Code**
1. Open `ultrasonic_sensor.ino` in Arduino IDE.
2. Select the correct board (Arduino Uno) and port.
3. Click **Upload**.

### **4️⃣ Run Real-Time Plotting**
```sh
python Python_Scripts/real_time_plot.py
```

### **5️⃣ Start FastAPI Server**
```sh
uvicorn Python_Scripts.api:app --reload
```

---

## 🔗 API Endpoints

| Endpoint       | Method | Description                      | Auth Required |
|---------------|--------|--------------------------------|--------------|
| `/`           | GET    | Home Page                     | No           |
| `/distance`   | GET    | Fetch real-time sensor data   | Yes (API Key)|

### **Example API Call (With API Key)**
```sh
curl -H "X-API-KEY: my-secret-key" "http://127.0.0.1:8000/distance"
```
Response:
```json
{
    "distance_cm": 15
}
```

---

## 🚀 Deploying on a College Server
### **1️⃣ Host the API**
```sh
uvicorn Python_Scripts.api:app --host 0.0.0.0 --port 8000 --workers 4
```

### **2️⃣ Configure NGINX (Optional)**
If deploying via NGINX, configure reverse proxy:
```nginx
server {
    listen 80;
    server_name your-server-ip;

    location / {
        proxy_pass http://127.0.0.1:8000/;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
    }
}
```

---

## 👨‍💻 Contributors
- **Suhani Verma** – Developer & Researcher  

---

## 📝 License
This project is licensed under the **MIT License**.

---

## ⭐ Support & Contributions
- Found a bug? Open an [issue](https://github.com/your-username/5G-Ultrasonic-Project/issues)
- Want to contribute? Fork and submit a PR!

🚀 **Happy Coding!** 🎯

