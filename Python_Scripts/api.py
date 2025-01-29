from fastapi import FastAPI, Depends, HTTPException
from fastapi.security.api_key import APIKeyHeader
import serial

# Connect to Arduino
arduino = serial.Serial('COM3', 9600)

app = FastAPI()

# API Key for authentication
API_KEY = "my-secret-key"
api_key_header = APIKeyHeader(name="X-API-KEY")

# Validate API Key
def validate_api_key(api_key: str = Depends(api_key_header)):
    if api_key != API_KEY:
        raise HTTPException(status_code=401, detail="Invalid API Key")
    return api_key

@app.get("/")
def home():
    return {"message": "Welcome to the 5G Project API"}

@app.get("/distance")
def get_distance(api_key: str = Depends(validate_api_key)):
    data = arduino.readline().decode().strip()
    if data.isnumeric():
        return {"distance_cm": int(data)}
    return {"error": "Invalid data"}

# Run the API using: uvicorn api:app --reload
