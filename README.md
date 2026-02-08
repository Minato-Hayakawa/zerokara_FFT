# FFT Scratch Implementation in C

This repository contains a from-scratch implementation of the Fast Fourier Transform (FFT) algorithm written in C. The project was developed to gain a deeper understanding of the Cooley–Tukey algorithm and to demonstrate how the computational complexity of the Discrete Fourier Transform (DFT) can be reduced from **O(N²)** to **O(N log N)**.

---

## 1. Project Overview

- **Language:** C  
- **Algorithm:** Cooley–Tukey FFT (recursive approach)  
- **Time Complexity:** O(N log N)  
- **Input:** Complex signals (custom `struct complex` with real and imaginary parts)

---

## 2. Methodology

### 2.1 The Cooley–Tukey Algorithm

The algorithm recursively decomposes a DFT of size **N** into two smaller DFTs of size **N / 2**:
- One for the even-indexed elements  
- One for the odd-indexed elements  

This divide-and-conquer approach significantly reduces the overall computational complexity.

### 2.2 Butterfly Operation

The results of the smaller DFTs are combined using the **butterfly operation**.  
The odd-indexed results are multiplied by the twiddle factors:

$$
W_N^k = e^{-i \frac{2\pi}{N} k}
$$

and then added to or subtracted from the even-indexed results to produce the final FFT output.

---

## 3. Implementation Details

- **DFT function:** Naive O(N²) implementation used for verification  
- **FFT function:** Recursive implementation of the Cooley–Tukey algorithm  
- **Memory Management:** Manual memory allocation (`malloc`) and deallocation (`free`) are used to handle the recursive data structures efficiently  

---

## 4. How to Compile and Run

### 4.1 Prerequisites

- GCC compiler

### 4.2 Build and Execution

```bash
# Compile the code (linking the math library)
gcc -o fft_test main.c FFT.c -lm

# Run the test
./fft_test

```
## 5. Test Results

The following test was performed using a sinusoidal input signal to verify the correctness of the implementation:

**Input:**

The input signal is defined as:

$$
x_n = 100  \sin(\frac{2 \pi  n  }{N})
$$

**Expected Output:**  
Large magnitude components in the frequency domain at **k = 1** and **k = N − 1**.

### Input Data

```bash
data[0]: 0.000000 + 0.000000i
data[1]: 70.710678 + 0.000000i
data[2]: 100.000000 + 0.000000i
data[3]: 70.710678 + 0.000000i
data[4]: 0.000000 + 0.000000i
data[5]: -70.710678 + 0.000000i
data[6]: -100.000000 + 0.000000i
data[7]: -70.710678 + 0.000000i
```

### FFT Result

```bush
result[0]: 0.000000 + 0.000000i
result[1]: 0.000000 + -400.000000i
result[2]: 0.000000 + -0.000000i
result[3]: -0.000000 + 0.000000i
result[4]: 0.000000 + 0.000000i
result[5]: 0.000000 + 0.000000i
result[6]: 0.000000 + 0.000000i
result[7]: -0.000000 + 400.000000i
```
<figure>
<img width="450" height="350" alt="input_and_fft_raw_re_im_fs8" src="https://github.com/user-attachments/assets/db28016c-5aef-43a7-a846-08c1b143ffe0" />
<figcaption>fig 1: FFT Result raw data</figcaption>
</figure>

<figure>
<img width="450" height="350" alt="input_and_fft_fs8" src="https://github.com/user-attachments/assets/9cb89776-60a7-4fd2-95d5-7fbd999f77d2" />
<figcaption>fig 1: FFT Result One-sided Spectrum</figcaption>
<figure>
## 6. Author
Minato Hayakawa - TMCIT
