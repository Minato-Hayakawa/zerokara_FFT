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
<div align="center">
<img width="450" height="350" alt="input_and_fft_raw_re_im_fs8" src="https://github.com/user-attachments/assets/db28016c-5aef-43a7-a846-08c1b143ffe0" />
　<br>
<figcaption>fig 1: FFT Result raw data</figcaption>
</div>

<div align="center">
<img width="450" height="350" alt="input_and_fft_fs8" src="https://github.com/user-attachments/assets/9cb89776-60a7-4fd2-95d5-7fbd999f77d2" />
  <br>
<figcaption>fig 2: FFT Result One-sided Spectrum</figcaption>
</div>

### Benchmark Results

Here are the results of comparing the performance of my scratch implementation of the Discrete Fourier Transform (DFT) and the Fast Fourier Transform (FFT).

#### Test Environment

- OS : Windows 11
- Compiler : GCC (MinGW)

#### Results

| N | DFT Time (ms) | FFT Time (ms) | DFT/FFT | Maximam Error |
| ---- | ---- | ---- | ---- | ---- |
| 2 | 0.002 | 0.003 | 1.500 | 0.000 |
| 4 | 0.003 | 0.003 | 0.222 | 0.000 |
| 8 | 0.005 | 0.06 | 0.833 | 0.000 |
| 16 | 0.010 | 0.006 | 0.167 | 0.000 |
| 32 | 0.026 | 0.007 | 3.714 | 0.000 |
| 64 | 0.08 | 0.014 | 5.714 | 0.000 |
| 128 | 0.309 | 0.028 | 11.036 | 0.000 |
| 256 | 1.154 | 0.067 | 17.224 | 0.000 |
| 512 | 4.526 | 0.233 | 19.425 | 0.000 |
| 1024 | 18.637 | 1.416 | 13.162 | 0.000 |


## Philosophy Behind This Project

There were two reasons why I decided to implement FFT from scratch this time.
One was that I wanted to generate the data for next year’s experimental lab report by myself.
The other was that, when I implemented a CNN from scratch, I encountered FFT for the first time and felt a strong desire not to leave this algorithm as a black box, but to implement it from zero and face its structure directly.

My interest lies not so much in the result that “FFT is fast,” but rather in why it becomes fast — in the structure of the algorithm itself.
Fortunately, I did not have much trouble implementing the even–odd decomposition. However, I struggled a lot with the implementation of the butterfly operations. Translating the formulas I had seen on paper into actual code forced me to repeat cycles of implementation and revision many times.

After finally completing the FFT implementation, I ran benchmarks to compare it with DFT. 
In the end, the results showed that from a sample size of 
N=16, the FFT was faster than the DFT.

Even so, I do not think this implementation was in vain. By building the FFT algorithm with my own hands, I was able to deepen my understanding of its structure. In addition, the fact that the maximum error between the results of DFT and FFT was zero confirmed that, at least, my implementation was working correctly.

I seem to be the type of person who feels more joy not when “something is completed,” but when I finally understand the process that leads to it. When fragments of my knowledge come together like pieces of a puzzle and what was once a black box becomes transparent, that feeling is, for me, the true pleasure of engineering. This is, for now, my way of doing engineering.
## 6. Author
Minato Hayakawa - TMCIT
