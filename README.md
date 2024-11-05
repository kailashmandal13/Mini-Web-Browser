
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

---

## 📂 Repository Structure  
```
mini-web-browser/
│
├── src/
│   ├── main.cpp              # Main entry point of the program
│   ├── html_parser.cpp       # HTML parser to generate DOM
│   ├── rendering_engine.cpp  # Rendering engine using Qt Widgets
│   ├── multi_process.cpp     # Multi-process and thread management
│   └── helpers/              # Utility functions, IPC helpers, etc.
│
├── include/
│   ├── html_parser.h         # Header for the HTML parser
│   ├── rendering_engine.h    # Header for the rendering engine
│   ├── multi_process.h       # Header for multi-threaded support
│   └── helpers/              # Helper function headers
│
├── html_dataset/             # Sample HTML pages (generated using `gen_html.py`)
│
├── gen_html.py               # Script to generate sample HTML pages
├── README.md                 # Project documentation (this file)
├── Makefile                  # Build instructions
└── report.pdf                # Final project report
```

---

## 🚀 How to Run the Project  

### 1. Install Dependencies  
- **C/C++ Compiler**: GCC or Clang  
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
./mini-web-browser
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

## 🛠 Resources  
- Using **POSIX APIs** or **Qt threads** for process and thread management.  
- 
- 

---

# Mini-Web-Browser
# Mini-Web-Browser
