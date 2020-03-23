# Module
This module was written in C, it allows for getting user input without the need to constantly confirm every input with enter key

# Install

```
sudo python3 setup.py install
```

# Usage

```python
import dynamic_input as din

s = ""

print("Write some letters!")

for _ in range(6):
    ch = din.get()
    s += ch.decode("utf-8")

print(s)
```
