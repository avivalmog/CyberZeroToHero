import subprocess
import platform
import re
import paramiko


def ping(host):
    # Use the appropriate ping command based on the OS
    param = '-n' if platform.system().lower() == 'windows' else '-c'
    command = ['ping', param, '1', host]  # Sending 4 packets

    try:
        output = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

        # Return the output regardless of success or failure
        return output.stdout
    except Exception as e:
        print(f"An error occurred: {e}")
        return None


def extract_received(ping_output):
    # Check for "Destination host unreachable" message
    if "Destination host unreachable" in ping_output:
        return None  # Indicates the host is unreachable

    # Define a regex pattern to extract the number of received packets
    if platform.system().lower() == 'windows':
        pattern = r'Received = (\d+)'
    else:
        pattern = r'(\d+) packets received'

    match = re.search(pattern, ping_output)
    if match:
        return int(match.group(1))
    return 0



import socket
from concurrent.futures import ThreadPoolExecutor


def scan_port(host, port):
    """Scan a single port on the given host."""
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.settimeout(1)  # Set a timeout for the connection attempt
        result = sock.connect_ex((host, port))  # Returns 0 if the port is open
        return port, result == 0


def scan_ports(target_host):
    """Scan a range of ports on the given host."""
    start_port = int(input("Enter the start port: "))
    end_port = int(input("Enter the end port: "))

    port_range = range(start_port, end_port + 1)
    print(f"Scanning {target_host} from port {start_port} to {end_port}...")

    open_ports = []

    with ThreadPoolExecutor(max_workers=100) as executor:
        futures = {executor.submit(scan_port, target_host, port): port for port in port_range}
        for future in futures:
            port, is_open = future.result()
            if is_open:
                open_ports.append(port)

    return open_ports


def ssh_connect(hostname, port, username, password):
    # Create an SSH client
    client = paramiko.SSHClient()

    # Automatically add the server's host key (not recommended for production)
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())

    try:
        # Connect to the server
        client.connect(hostname, port=port, username=username, password=password)

        # Execute a command
        stdin, stdout, stderr = client.exec_command('ls -l')  # Example command

        # Read the command output
        output = stdout.read().decode('utf-8')
        errors = stderr.read().decode('utf-8')

        # Print the output
        print("Output:")
        print(output)

        if errors:
            print("Errors:")
            print(errors)

    except Exception as e:
        print(f"Error: {e}")
    finally:
        # Close the connection
        client.close()

if __name__ == "__main__":
    target_host = input("Enter the IP address or hostname of the remote PC: ")
    ping_output = ping(target_host)

    if ping_output:
        received_count = extract_received(ping_output)
        if received_count is None:
            print(f"{target_host} is unreachable.")
        else:
            print(f"{target_host} responded. Packets received: {received_count}")
            open_ports = scan_ports(target_host)
            if open_ports:
                print(f"Open ports on {target_host}: {', '.join(map(str, open_ports))}")
                if 22 in open_ports:
                    ssh_connect(hostname=target_host, port=22,username='kali',password='kali')
            else:
                print(f"No open ports found on {target_host}.")

    else:
        print(f"An error occurred while pinging {target_host}.")
