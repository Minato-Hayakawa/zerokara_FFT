# FFT Scratch Implementation in C

This repository contains a from-scratch implementation of the **Fast Fourier Transform (FFT)** algorithm in C. It was developed to deeply understand the Cooley-Tukey algorithm and optimize the computational complexity of the Discrete Fourier Transform (DFT) from $O(N^2)$ to $O(N \log N)$.

This project was developed as a technical demonstration for research internship applications.

---

## 1. Project Overview

* **Language**: C
* **Algorithm**: Cooley-Tukey FFT (Recursive approach)
* **Complexity**: $O(N \log N)$
* **Input**: Complex signals (struct `complex` with `real` and `image` parts)



---

## 2. Methodology

### 2.1 The Cooley-Tukey Algorithm
The algorithm recursively breaks down a DFT of size $N$ into two smaller DFTs of size $N/2$: one for the even-indexed elements and one for the odd-indexed elements.

### 2.2 Butterfly Operation
The results of the smaller DFTs are combined using the **butterfly operation**, which multiplies the odd-indexed results by twiddle factors ($W_N^k = e^{-i\frac{2\pi}{N}k}$) before adding/subtracting them from the even-indexed results.



---

## 3. Implementation Details

* **`DFT` function**: Naive implementation ($O(N^2)$) for verification.
* **`FFT` function**: Recursive implementation of Cooley-Tukey.
* **Memory Management**: Manual memory allocation (`malloc`) and deallocation (`free`) are implemented to handle the recursive nature of the algorithm efficiently.

---

## 4. How to Compile and Run

### 4.1 Prerequisites
* GCC Compiler

### 4.2 Build and Execution
```bash
# Compile the code (linking math library)
gcc -o fft_test main.c FFT.c -lm

# Run the test
./fft_test

## 5. Test Results

The following test was performed using a sinusoidal input to verify the algorithm's correctness:
Input: $x_n = 100 \cdot \sin\left(\frac{2\pi \cdot 1 \cdot n}{N}\right)$ where $N=8$.
Expected Output: Large values in the frequency domain at $k=1$ and $k=N-1$.
--- Input Data ---
data[0]: 0.000000 + 0.000000i
data[1]: 70.710678 + 0.000000i
data[2]: 100.000000 + 0.000000i
data[3]: 70.710678 + 0.000000i
data[4]: 0.000000 + 0.000000i
data[5]: -70.710678 + 0.000000i
data[6]: -100.000000 + 0.000000i
data[7]: -70.710678 + 0.000000i

--- FFT Result ---
result[0]: 0.000000 + 0.000000i
result[1]: 0.000000 + -400.000000i
result[2]: 0.000000 + -0.000000i
result[3]: -0.000000 + 0.000000i
result[4]: 0.000000 + 0.000000i
result[5]: 0.000000 + 0.000000i
result[6]: 0.000000 + 0.000000i
result[7]: -0.000000 + 400.000000i

6. Author
[Your Name] - [Your University/Affiliation]
