# Install

'''
sudo python3 setup.py install
'''

# Usage

'''python
import dynamic_input as din

s = ""

print("Write some letters!")

for _ in range(6):
    ch = din.get()
    s += ch.decode("utf-8")

print(s)
'''
