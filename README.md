
# Mini-Web Browser  
**Course:** COP701 – Assignment 3 
**Team:** Aditya Narayan & Kailash Mandal  

---

## 📜 Project Overview  
The goal of this project is to develop a **mini web browser** that can:  
1. **Fetch HTML pages** and cache them locally using `libcurl`.  
2. **Parse HTML documents** into a **Document Object Model (DOM)** as an Abstract Syntax Tree (AST).  
3. **Render the DOM** using **Qt Widgets** to display HTML elements (without JavaScript support).  
4. **Support multiple tabs** using **multi-threading** and **multi-processing** techniques.  
5. Bonus Features, **to implement browser history** and **session management** for enhancements in this project  

---

## Features

- **HTML Parsing**: Supports HTML5 elements and attributes, creating an AST representation.
- **Custom Rendering**: Uses `QPainter` for manual rendering of HTML content.
- **Multi-Threading**: Utilizes a thread pool for concurrent HTML parsing.
- **Multi-Process Tabs**: Each tab runs in a separate process for stability and isolation.
- **Advanced Text Formatting**: Supports bold, italic, underline, code blocks, and more.
- **Scrolling Support**: Smooth scrolling for large documents using `QScrollArea`.
- **Error Handling**: Graceful error recovery and user-friendly messages.

### Prerequisites

- **Qt 6**: Ensure you have Qt 6 installed on your system.
- **CMake**: Required for building the project.
- **libcurl**: Used for fetching HTML pages.

## 📂 Repository Structure  
```
Mini-Web-Browser/
│
├── build/                          # Directory for compiled objects and binaries
│
├── data/                           # Data folder containing HTML files and resources
│   ├── fetch_html.cpp              # Fetch HTML file using libcurl
│   └── html_dataset/               # Sample HTML files
│       ├── html_page_1.html
│       ├── html_page_2.html
│       ├── html_page_3.html
│       ├── html_page_4.html
│       └── html_page_5.html
│
├── docs/                           # Documentation folder
│   └── COP701_Assignment3.pdf      # Assignment problem statement
│
├── index.html                      # Sample HTML file for testing
│
├── resources/                      # Directory containing additional resources
│   └── images/
│       └── p2.jpg                  # Sample image used in HTML
│
├── src/                            # Source code folder
│   ├── browser/                    # Browser module for GUI and tab management
│   │   ├── browser_window.cpp
│   │   ├── browser_window.hpp
│   │   ├── tab_manager.cpp
│   │   ├── tab_manager.hpp
│   └── core/                       # Core parsing and AST components
│       ├── ast.cpp
│       ├── ast.hpp
│       ├── lexer.l                 # Lexer file for tokenizing HTML
│       ├── parser.y                # Parser file for generating DOM
│       ├── parser.cpp
│       ├── parser.hpp
│   ├── main.cpp                    # Main entry point of the program
│   ├── network/                    # Network handling for fetching HTML
│   │   ├── network_manager.cpp
│   │   └── network_manager.hpp
│   ├── renderer/                   # Rendering engine using Qt Widgets
│   │   ├── renderer.cpp
│   │   └── renderer.hpp
│   └── utils/                      # Utility functions and helper classes
│       ├── history_manager.cpp
│       ├── history_manager.hpp
│       ├── thread_pool_manager.cpp
│       └── thread_pool_manager.hpp
│
├── test.html                       # HTML test file for the browser
├── Makefile                        # Makefile for building the project
├── README.md                       # Project documentation
└── report.pdf                      # Final project report

```

---

## 🚀 How to Run the Project  

### 1. Install Dependencies  
- **C/C++ Compiler**: GCC, Install Flex, Bison  
- **Qt Framework**: Install the Qt library using:  
  ```bash
  sudo apt-get install qt5-default
  ```
- **libcurl**: Install `libcurl` using:  
  ```bash
  sudo apt-get install libcurl4-openssl-dev
  ```

### 2. Generate HTML Pages  
Run the following command to generate sample HTML pages:  
```bash
python3 gen_html.py
```  
The pages will be saved in the `html_dataset/` directory.  

### 3. Start the HTTP Server  
In the project root directory, launch a server using Python:  
```bash
python3 -m http.server
```  
The server will run at: [http://localhost:8000/](http://localhost:8000/).  

### 4. Build the Project  
Use the provided `Makefile` to compile the code:  
```bash
make
```  

### 5. Run the Browser  
Execute the following command to launch the mini-browser:  
```bash
./html-parser-renderer
```  

---

## 💡 Key Features  

1. **HTML Fetching**  
   - Uses `libcurl` to fetch HTML pages via HTTP.  
   - Caches the pages locally for faster access.  

2. **DOM Conversion**  
   - Parses HTML into a DOM (AST structure) without external libraries.  
   - Supports the following tags:  
     `HTML, head, title, body, nav, ul, li, header, h1-h5, p, section, article, aside, footer, img, a, strong, em, u, small, blockquote, pre, code, ol`

3. **Rendering Engine**  
   - Uses **Qt Widgets** to render text, images, and links from the DOM structure.  
   - Example:  
     ```cpp
     void HTMLTextElement::render(QPainter& painter, int& yPosition) {
         painter.drawText(10, yPosition, text);
         yPosition += 20;
     }
     ```

4. **Multi-Process and Multi-Threading Support**  
   - Each tab runs as a separate process.  
   - Uses **pthreads** or **std::threads** for parallel task handling.  

5. **Bonus Features** (Optional)  
   - **Browser History**: Keep track of visited pages and allow forward/backward navigation.  
   - **Session Management**: Save and restore tabs across sessions.  


---

## 🛠 Development Notes  
- Use **POSIX APIs** or **Qt threads** for process and thread management.  
- Avoid using **QWebEngineView** or **QWebView** to render pages—use native Qt widgets instead.  
- Ensure **regular commits** to the repository for better evaluation.  

---
### 📧Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/kailashmandal13/Mini-Web-Browser.git
   cd html-parser-renderer
   ```

