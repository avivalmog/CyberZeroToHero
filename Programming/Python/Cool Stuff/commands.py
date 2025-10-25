import subprocess

result = subprocess.run(['cmd /c ipconfig'], shell=True, capture_output=True)
print(result.returncode)
print(result.stdout.decode('utf-8'))
