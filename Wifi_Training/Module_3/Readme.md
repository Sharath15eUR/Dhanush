
# Module 3 Assignment

## 1. Different 802.11 PHY Layer Standards and Their Characteristics

| Standard    | Frequency | Max Data Rate | Modulation         | Channel Width      | Year |
|-------------|-----------|----------------|---------------------|---------------------|------|
| 802.11a     | 5 GHz     | 54 Mbps        | OFDM, FHSS                | 20 MHz              | 1999 |
| 802.11b     | 2.4 GHz   | 11 Mbps        | DSSS                | 22 MHz              | 1999 |
| 802.11g     | 2.4 GHz   | 54 Mbps        | OFDM                | 20 MHz              | 2003 |
| 802.11n     | 2.4/5 GHz | 600 Mbps       | OFDM + MIMO         | 20/40 MHz           | 2009 |
| 802.11ac    | 5 GHz     | 6.9 Gbps       | OFDM + MU-MIMO (only downlink)      | 20/40/80/160 MHz    | 2013 |
| 802.11ax    | 2.4/5 GHz | 9.6 Gbps       | OFDMA + MU-MIMO     | 20/40/80/160 MHz    | 2019 |
| 802.11be    | 2.4/5/6 GHz | > 30 Gbps    | OFDMA + MU-MIMO        | Up to 320 MHz       | 2024 (ongoing) |

---

## 2. DSSS and FHSS

### DSSS (Direct Sequence Spread Spectrum)
- Spreads data using a pseudo-random noise (PN) sequence.
- Each bit is represented by multiple chips (bit spreading).
- Increases resistance to interference.
- Used in 802.11b.

![2.1](./images/2.1.avif)

### FHSS (Frequency Hopping Spread Spectrum)
- Data is transmitted by hopping rapidly across multiple frequencies.
- Improves security and reduces interference.
- Used in early versions of 802.11.

![2.2](./images/2.2.avif)

---

## 3. Modulation Schemes in the PHY Layer
| Scheme    | Bits/Symbol | Description                    | Used in        | Performance |
|-----------|--------------|--------------------------------|----------------|-------------|
| BPSK      | 1            | Binary Phase Shift Keying      | 802.11a/b/n    |Robust but low data rate | 
| QPSK      | 2            | Quadrature Phase Shift Keying  | 802.11a/g/n    | Improved throughput | 
| 16-QAM    | 4            |Quadrature Amplitude Modulation | 802.11n/ac     | Higher speed, less robust |
| 64-QAM    | 6            | Quadrature Amplitude Modulation                                | 802.11n/ac     |High throughput | 
| 256-QAM   | 8            | Quadrature Amplitude Modulation                                |802.11ac       | Very high speed, needs high SNR | 
| 1024-QAM  | 10           | Quadrature Amplitude Modulation   | 802.11ax       | Maximum throughput, very sensitive to noise |

---

## 4. Significance of OFDM in WLAN

- **OFDM** splits a wide channel into multiple orthogonal subcarriers.
- Each subcarrier carries a portion of data, reducing interference.
- Resistant to multipath fading and interference.
- Increases data throughput and reliability.
- Used in 802.11a/g/n/ac/ax.
- Each subcarrier in OFDM is mathematically orthogonal to the others.
- This means that at the peak of one subcarrier’s signal, all other subcarriers are zero (no interference).

![4.1](./images/4.1.avif)

---

## 5. Frequency Bands and Channel Division in Wi-Fi

| Band      | Frequency Range   | Channel Range | Used In              |
|-----------|-------------------|---------------|-----------------------|
| 2.4 GHz   | 2.4 – 2.4835 GHz  | 1–14          | 802.11b/g/n/ax       |
| 5 GHz     | 5.15 – 5.825 GHz  | 36–165        | 802.11a/n/ac/ax      |
| 6 GHz     | 5.925 – 7.125 GHz | 1–233         | 802.11ax/be (Wi-Fi 6E/7) |

- **2.4 GHz**: Long range, fewer non-overlapping channels (1, 6, 11).
- **5 GHz**: More bandwidth and less congestion.
- **6 GHz**: Future-focused, high-speed data with less interference.

---

## 6. Role of Guard Intervals in WLAN

- **Guard Interval (GI)** prevents inter-symbol interference (ISI) in multipath environments.
- **Standard GI**: 800 ns  
- **Short GI**: 400 ns

### Benefits of Short GI:
- Reduces time between symbols.
- Increases efficiency (~11% throughput gain).
- Works best with low multipath delay spread.

---

## 7. Structure of 802.11 PHY Layer Frame

### Main Components:
1. **PLCP Preamble** – Helps receiver synchronize.
2. **PLCP Header** – Contains data rate, length, and other info.
3. **PSDU (MAC Frame)** – Actual data payload.

Newer standards (n/ac/ax) include fields for:
- MIMO information
- Channel bandwidth
- Guard Interval and Modulation settings

---

## 8. Difference Between OFDM and OFDMA

| Feature        | OFDM                          | OFDMA                          |
|----------------|-------------------------------|---------------------------------|
| Subcarrier Use | Entire channel per user       | Subcarriers shared among users |
| Efficiency     | Good for single-user          | High for multiple simultaneous users |
| Latency        | Higher                        | Lower                          |
| Standard Used  | 802.11a/g/n/ac                | 802.11ax/be                    |

---

## 9. Difference Between MIMO and MU-MIMO

| Feature       | MIMO                            | MU-MIMO                         |
|---------------|----------------------------------|----------------------------------|
| Users         | One user at a time              | Multiple users simultaneously    |
| Streams       | Multiple spatial streams        | Streams distributed among users  |
| Used In       | 802.11n/ac                      | 802.11ac/ax                      |
| Benefit       | Increases single-user throughput | Improves multi-user performance  |

---

## 10. PPDU, PLCP, and PMD

- **PPDU (PHY Protocol Data Unit)**: Full data unit sent over air, includes preamble, header, and payload.
- **PLCP (Physical Layer Convergence Protocol)**: Prepares MAC frames for transmission, adds headers and preamble.
- **PMD (Physical Medium Dependent)**: Handles actual transmission via hardware (e.g., antennas, RF components).

---

## 11. Types of PPDU and Frame Formats

| **Wi-Fi Generation** | **PPDU Types**           | **Description**                                                                 |
|----------------------|--------------------------|---------------------------------------------------------------------------------|
| **802.11b**          | **Long/Short Preamble**  | Legacy format with simple headers; uses DSSS modulation                        |
| **802.11a/g**        | **Legacy**               | OFDM-based; fields include STF, LTF, Signal, Data (PSDU)                       |
| **802.11n**          | **HT-Mixed, HT-Greenfield** | Adds MIMO support; HT-Mixed is backward-compatible with 802.11a/g           |
| **802.11ac**         | **VHT PPDU**             | Very High Throughput; supports MU-MIMO, wider bandwidth      |
| **802.11ax**         | **HE SU, HE MU, HE EXT** | High Efficiency; introduces OFDMA |
| **802.11be**         | **EHT SU, EHT MU**       | Extremely High Throughput; supports up to 320 MHz channels, 16 spatial streams, enhanced OFDMA and MU-MIMO |

> [!NOTE]
> - HT- Mixed - High Throughput 
> - VHT - Very High Throughput
> - HE SU - High Efficiency Single User
> - HE MU - High Efficiency Multiple User
> - EHT SU - Extremely High Throughput Single User
> - EHT MU - Extremely High Throughput Multiple User


### 802.11b Preamble and Header Fields

![11.1](./images/11.1.png)

#### **Preamble**
- **SYNC (128/56 bits):** Syncs receiver with the signal.  
- **SFD (16 bits):** Marks the start of the frame.

#### **Header**
- **Signal (8 bits):** Indicates data rate.  
- **Service (8 bits):** Reserved for future use.  
- **Length (8 bits):** Frame length in bytes.  
- **CRC (8 bits):** Error check for header.

---

### 802.11a/g Preamble and Header Fields

![11.2](./images/11.2.png)

#### **Preamble**
- **STF:** Syncs timing.  
- **LTF:** Estimates channel.

#### **Header (SIGNAL field)**
- **Rate:** Modulation type.  
- **Length:** Packet duration.  
- **Parity:** Error bit.  
- **Tail:** Ensures clean decoding.

---

### 802.11n Preamble and Header Fields

![11.3](./images/11.3.png)

#### **Legacy Preamble**
- **L-STF:** Gain control and timing.  
- **L-LTF:** Channel estimation.  
- **L-SIG:** Info for legacy devices.

#### **HT Preamble**
- **HT-SIG1:** MCS, bandwidth, etc.  
- **HT-STF:** Improves MIMO estimation.  
- **HT-LTF:** MIMO channel estimation.

#### **HT Header**
- **HT-SIG2:** More signal info.  
- **Service:** Reserved/init. bits.  
- **Length:** PSDU length.  
- **Tail:** Decoder reset.  
- **CRC:** Error detection.

---

### 802.11ac Preamble and Header Fields

![11.4](./images/11.4.png)

#### **VHT Preamble**
- **VHT-SIG-A1/A2:** MCS, streams, bandwidth.  
- **VHT-STF:** MIMO estimation.  
- **VHT-LTF:** Channel estimation & beamforming.

#### **VHT Header**
- **VHT-SIG-B:** PSDU length info.  
- **Service:** Reserved/init. bits.  
- **Tail:** Decoder reset.  
- **CRC:** Error detection.

---

### 802.11ax Preamble and Header Fields

![11.5](./images/11.5.png)

#### **Preamble**
- **HE-SIG-A:** MCS, bandwidth, streams.  
- **HE-SIG-B:** MU-MIMO & OFDMA info.  
- **HE-STF:** AGC improvement.  
- **HE-LTF:** Channel estimation.

#### **HE Header**
- **Service:** Reserved/init. bits.  
- **Tail:** Decoder reset.  
- **CRC:** Error detection.

---

## 12. Data Rate Calculation

### Formula:

$$
\text{Data Rate} = \frac{N_{SD} \times N_{BPSCS} \times R \times N_{SS}}{T_{DFT} + T_{GI}}
$$

| Symbol        | Full Form                               | Description                                                                 |
|---------------|------------------------------------------|-----------------------------------------------------------------------------|
| `N_SD`        | Number of Data Subcarriers               | Subcarriers that actually carry data (depends on channel bandwidth)        |
| `N_BPSCS`     | Number of Coded Bits Per Subcarrier      | Based on modulation:<br>BPSK = 1, QPSK = 2, 16-QAM = 4, 64-QAM = 6, 256-QAM = 8 |
| `R`           | Coding Rate                              | Fraction of bits that are useful (e.g., 1/2, 3/4)                           |
| `N_SS`        | Number of Spatial Streams                | Number of data streams sent simultaneously using MIMO                      |
| `T_DFT`       | OFDM Symbol Duration (FFT/DFT Time)      | Base symbol time (e.g., 3.2 µs for 802.11n/ac/ax)                          |
| `T_GI`        | Guard Interval Duration                  | Time gap between symbols to prevent ISI (e.g., 0.4 µs or 0.8 µs)           |

### Calculation for (802.11ac, 20 MHz, 64-QAM, R = 3/4, 1 Stream, GI = 0.8 µs)

- `N_SD = 52`
- `N_BPSCS = 6` (64-QAM)
- `R = 3/4`
- `N_SS = 1`
- `T_DFT = 3.2 µs`
- `T_GI = 0.8 µs`

$$ 
\text{Data Rate} = \frac{52 \times 6 \times \frac{3}{4} \times 1}{3.2 + 0.8} = \frac{234}{4 \times 10^{-6}} = \frac{234 \times 10^6}{4} = \textbf{58.5 Mbps}
$$

---

