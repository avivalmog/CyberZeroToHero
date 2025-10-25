from multiprocessing import Process
import keyboard
import socket

def run_server() -> None:
    localIP = "127.0.0.1"
    localPort = 20001
    bufferSize = 1024
    msgFromServer = "Hello UDP Client"
    bytesToSend = str.encode(msgFromServer)
    # Create a datagram socket
    UDPServerSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
    # Bind to address and ip
    UDPServerSocket.bind((localIP, localPort))
    print("UDP server up and listening")
    # Listen for incoming datagrams
    while (True):
        bytesAddressPair = UDPServerSocket.recvfrom(bufferSize)
        message = bytesAddressPair[0]
        address = bytesAddressPair[1]
        clientMsg = "Message from Client:{}".format(message)
        clientIP = "Client IP Address:{}".format(address)
        print(clientMsg)
        print(clientIP)
        # Sending a reply to client
        UDPServerSocket.sendto(bytesToSend, address)


if __name__ == '__main__':
    process = Process(target=run_server)
    process.start()
    while process.is_alive():
        if keyboard.is_pressed('q'):
            process.terminate()
            break
