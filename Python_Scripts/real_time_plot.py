import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Connect to Arduino (Change 'COM3' to the correct port)
arduino = serial.Serial('COM3', 9600)

# Data storage
distances = []

# Function to update plot
def update(frame):
    data = arduino.readline().decode().strip()  # Read distance from Arduino
    if data.isnumeric():
        distance = int(data)
        distances.append(distance)
        if len(distances) > 50:  # Limit data points
            distances.pop(0)

        plt.cla()
        plt.plot(distances, label="Distance (cm)")
        plt.axhline(y=10, color='r', linestyle='--', label="Threshold")
        plt.legend()
        plt.xlabel("Time")
        plt.ylabel("Distance (cm)")
        plt.title("Real-Time Distance Plot")

# Create real-time plot
fig = plt.figure()
ani = animation.FuncAnimation(fig, update, interval=100)
plt.show()
