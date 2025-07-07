Huffman Coding: Sender and Receiver

## Overview

This project implements a basic file compression and decompression system using a character frequency-based binary encoding algorithm similar to Huffman coding.

- The **Sender Program** (`sender.cpp`) compresses text from an input file by assigning shorter binary codes to frequently occurring characters, then saves the encoded result and code mapping.
- The **Receiver Program** (`reciever.cpp`) reads the encoded file and code mapping, then decodes the content back to the original text.

## File Structure

```
Assignment-3/
├── sender.cpp        # Encodes a text file using Huffman-like encoding
├── reciever.cpp      # Decodes the encoded text back using the generated codes
├── encoded.txt       # Output from sender: compressed binary string
├── codes.txt         # Output from sender: mapping of characters to codes
├── decoded.txt       # Output from receiver: restored original message
```

## How to Compile and Run

Ensure you're using a C++ compiler like `g++` and that you are **not using any external libraries**.

### Compile

```bash
g++ sender.cpp -o sender
g++ reciever.cpp -o receiver
```

### Run

```bash
./sender
# Enter input file name (without .txt extension) when prompted

./receiver
# No input required; it reads from `encoded.txt` and `codes.txt`
```

> **Note**: The input text file must exist in the same directory. Its name should be provided **without the `.txt` extension**.

## Example

### Input (`input.txt`)
```
Faizan Aziz
```

### Output (`encoded.txt`)
```
01011011101111111110
```

### Output (`decoded.txt`)
```
Faizan Aziz
```

### Output (`codes.txt`) – Example Format
```
0
A
10
Z
110
F
111
N
```

> Each character is preceded by its corresponding binary code on the previous line.

## Features

- Custom `Node` and `Tree` structures used for frequency tracking and tree building.
- Manual sorting and merging (no STL or external libraries).
- Binary encoding is dynamically generated based on character frequency.
- Clean file I/O using standard C++ streams.

## Author

Faizan Aziz
