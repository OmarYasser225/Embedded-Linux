"""*********************************************************************************************"""
"""                               Serial Communication program                                  """
"""*********************************************************************************************"""
"""*********************************** Author: Omar Yasser *************************************"""
"""***********************************    Version: 1.00    *************************************"""
"""***********************************   Data: 28/7/2024   *************************************"""
"""*********************************************************************************************"""

import os
import time 
import serial
import select
import msvcrt
import pyautogui
import serial.tools.list_ports
from termcolor import colored
import keyboard  # For detecting Ctrl+S


ser = serial.Serial()

def list_serial_ports():
    ports = serial.tools.list_ports.comports()
    if not ports:
        print(colored("No Ports are available.", "light_red"))
        return False
    else:
        for port in ports:
            print(colored("---------------------- Devices ----------------------", "light_magenta"))
            print(colored("Port:", "light_red"), port.device, colored(", Description:", "light_red"), port.description)
            print(colored("-----------------------------------------------------", "light_magenta"))
        return True

def send_data():
    global ser
    data = input(colored("Write the data (or type 'exit' to quit): ", "cyan"))
    if data.lower() == 'exit':
        return False
    ser.write(data.encode())  # Encoding the string to bytes
    print("Data written successfully.")
    return True


def receive_data(timeout=5):
    start_time = time.time()
    while True:
        if ser.in_waiting > 0:
            data = ser.read_all().decode()  # Read all available data
            return data.strip() 
        elif time.time() - start_time > timeout:
            return None
        time.sleep(0.1)  # Prevent high CPU usage


def clear_keyboard_buffer():
    while msvcrt.kbhit():
        msvcrt.getch()

if __name__ == "__main__":

    IsPort = list_serial_ports()
    if not IsPort:
        exit
    else:
        ser.port = input("Enter your com port: ").lower()
        ser.baudrate = int(input("Enter your baud rate: "))
        ser.bytesize = int(input("Enter the data size: "))
        ser.parity = input("Parity check (N for None, E for Even, O for Odd, M for Mark, S for Space): ").upper()
        ser.stopbits = int(input("Stop bits: "))
        os.system("cls")

        try:
            ser.open()
            print("Serial port opened successfully.")
        except serial.SerialException:
            print("Could not open this port")

        if ser.is_open:
            mode = 'receive'  # Initial mode
            print("Press Ctrl+S to switch to send/receive mode.")

            try:
                while True:
                    clear_keyboard_buffer()
                    if mode == 'receive':
                        if ser.in_waiting:
                            received_data = receive_data()
                            if received_data:
                                print(f"Received Data: {received_data}")

                    elif mode == 'send_receive':
                        is_send = send_data()
                        if not is_send:
                            break
                        
                        received_data = receive_data()
                        if received_data:
                            print(f"Received Data: {received_data}")

                    if keyboard.is_pressed('ctrl+s'):
                        mode = 'send_receive' if mode == 'receive' else 'receive'
                        print(f"Mode switched to {mode}.")
                        time.sleep(2)
                        os.system("cls")

            except serial.SerialException as e:
                print(f"Failed to write to serial port: {e}")
            finally:
                ser.close()
                print("Serial port closed.")
        else:
            print("Serial port is not open.")

        ser.close()
