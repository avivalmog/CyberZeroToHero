from scapy.all import *

target_ip = "8.8.8.8"  # Example: Google's DNS server
my_packet = IP(dst =  "142.251.37.206") / ICMP() / Raw(load="Cool Data")

reply = sr1(my_packet, timeout=2, verbose=0)
if reply:
    print(f"{target_ip} is online. Reply from: {reply.src}")
else:
    print(f"Timeout waiting for reply from {target_ip}")