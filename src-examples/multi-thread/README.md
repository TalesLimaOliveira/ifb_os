## 👨‍💻 Authors

### Original Project:
- Gustavo Xavier Maurmann
- Luan Mateus Duraes Nunes

### Modified and Refactored by:
- [Tales Oliveira](https://github.com/TalesLimaOliveira)

---

# Multi-Threaded Web Crawler

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue" alt="Language">
  <img src="https://img.shields.io/badge/Threads-Multi--Threaded-green" alt="Threads">
  <img src="https://img.shields.io/badge/Status-Active-success" alt="Status">
</p>

## 📖 Overview
A powerful **multi-threaded web crawler** designed to scrape websites efficiently, extracting URLs and PDF files. By leveraging multi-threading, the crawler processes content concurrently, providing fast and effective scraping capabilities.

---

## ⚙️ Functionalities
- **Multi-threaded crawling**: Scrape multiple web pages concurrently using threads.
- **URL and PDF extraction**: Identify and save all URLs and PDF links from HTML content.
- **Console output**: Displays time-stamped, thread-specific activity with color-coded logs.
- **File output**: Stores discovered PDF links in `pdfs_found.txt`.

---

## 📂 Project Structure

| **Directory/File**    | **Description**                             |
|-----------------------|---------------------------------------------|
| `app/`                | Main application directory.                 |
| └── `main.cpp`        | Entry point of the application.             |
| `src/`                | Source code for core functionalities.       |
| └── `utils.cpp`       | Utility functions (HTTP, HTML parsing).     |
| └── `master.cpp`      | Master thread coordination logic.           |
| └── `crawler.cpp`     | Crawler thread function to process URLs.    |
| `inc/`                | Header files for declarations.              |
| └── `utils.h`         | Utilities declaration.                      |
| └── `master.h`        | Master thread declaration.                  |
| └── `crawler.h`       | Crawler thread declaration.                 |
| `Makefile`            | Build automation script.                    |
| `README.md`           | This file, containing project documentation.|

---

## 🚀 How to Run

### 🔨 Build the Project
> make

### ▶️ Run the Application
> make run

### 🧹 Clean Build Files
> make clean

---

## 📦 External Libraries

The project integrates the following libraries to enhance functionality:

- **libcurl**: For efficient HTTP requests.
- **htmlcxx**: For HTML content parsing.

### Installation Instructions

#### On Ubuntu/Debian:
> sudo apt-get install libcurl4-openssl-dev

> sudo apt-get install libhtmlcxx-dev

#### On Windows:
You can download in [official libcurl site](https://curl.se/windows/) and [htmlcxx website](https://htmlcxx.sourceforge.net/).


---

## 📋 Usage Instructions
1. **Initialize**: Ensure `pdfs_found.txt` is writable. The program will save all found PDF links to this file.
2. **Set Limits**: Optionally pass a maximum number of URLs to process as a command-line argument.
3. **Execute**: Run the application to begin the crawling process.

---

## 🖥️ Example Output
**Console Log:**

        2023-10-10 12:34:56 thr#0 accessed https://www.ifb.edu.br
        2023-10-10 12:34:57 thr#1 pdf ---> https://www.ifb.edu.br/sample.pdf

**File Output (`pdfs_found.txt`):**

        https://www.ifb.edu.br/sample.pdf
