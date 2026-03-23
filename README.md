#  IP Analyzer Tool (C)

> Advanced IP Address Analysis Tool written in C
> Designed for networking learning, cybersecurity practice, and system-level programming.

---

##  Overview

**IP Analyzer** is a command-line tool that takes an IP address as input and performs deep analysis, including validation, classification, and network calculations.

This project demonstrates:

* Low-level string parsing
* Bitwise operations
* Structured programming in C
* Multi-file project architecture

---

##  Features

###  Core Analysis

* ✅ IPv4 validation
* ✅ IPv6 detection (basic)
* ✅ IP version identification
* ✅ Class detection (A, B, C, D, E)

###  Network Intelligence

* ✅ Public vs Private detection
* ✅ Loopback / Broadcast / Multicast detection
* ✅ Default subnet mask calculation
* ✅ Network address calculation
* ✅ Broadcast address calculation

###  Binary & Representation

* ✅ Binary representation of IP address
* ✅ Octet-level breakdown

###  System Design

* ✅ Modular multi-file architecture
* ✅ Custom structs for data handling
* ✅ Clean separation of logic and output

---

## Project Structure

```
ip-analyzer/
│
├── src/
│   ├── main.c
│   ├── analyzer.c
│   ├── ipv4.c
│   ├── ipv6.c
│   ├── utils.c
│
├── include/
│   ├── analyzer.h
│   ├── ipv4.h
│   ├── ipv6.h
│   ├── utils.h
│
├── Makefile
└── README.md
```

---

##  Installation & Compilation

###  Requirements

* GCC compiler
* Linux / macOS / Windows (with MinGW)

---

###  Compile

```bash
make
```

---

###  Run

```bash
./ip-analyzer
```

---

##  Example Usage

```
Enter IP Address: 192.168.1.1
```

###  Output

```
========== IP ANALYSIS ==========

Input Address      : 192.168.1.1
Validity           : Valid
IP Version         : IPv4

Class              : C
Type               : Private

Loopback           : No
Broadcast          : No
Multicast          : No
Usable             : Yes

--- Network Information ---
Subnet Mask        : 255.255.255.0
Network Address    : 192.168.1.0
Broadcast Address  : 192.168.1.255

--- Binary Representation ---
Binary             : 11000000.10101000.00000001.00000001
================================
```

---

##  Key Concepts Used

* Pointers & memory handling
* String tokenization (`strtok`)
* Bitwise operations (`&`, `|`, `>>`)
* Struct-based data modeling
* Multi-file compilation & linking

---

##  Limitations

* IPv6 validation is basic (not full standard)
* No CIDR support yet
* No CLI argument parsing (planned)

---

##  Future Improvements

* [ ] CIDR support (e.g. 192.168.1.1/24)
* [ ] Advanced subnet calculations
* [ ] Full IPv6 parsing and analysis
* [ ] CLI flags (`--verbose`, `--json`)
* [ ] Reverse DNS lookup
* [ ] Colored and interactive output

---

##  Learning Purpose

This project is built as part of a journey into:

* Cybersecurity & networking fundamentals
* Reverse engineering mindset
* Low-level system programming

---

##  Contributing

Contributions, suggestions, and improvements are welcome!

---

## Author

**Kayo yonas**

---

## ⭐ If you like this project

Give it a star and follow for more cybersecurity tools!

