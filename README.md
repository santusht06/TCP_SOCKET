# TCP Client–Server Chat Application (C)

This repository contains a simple **TCP IPv4 client–server application written in C**.
The client connects to the server over a TCP socket, sends text messages typed from
the terminal, and terminates the connection gracefully when the user types `exit`.

This project is intended for **learning and understanding low-level socket programming**
using the POSIX socket API.

---

## 📌 What This Project Demonstrates

- Creating TCP IPv4 sockets in C
- Binding and listening on a server socket
- Accepting incoming client connections
- Sending and receiving data using `send()` and `recv()`
- Reading user input from the terminal using `getline()`
- Graceful connection shutdown using `shutdown()`
- Detecting client disconnect on the server side

---

## 📂 Project Structure

```
TCP_SOCKET/
│
├── server.c          # TCP server implementation
├── client.c          # TCP client implementation
├── socketutils.h     # Helper function declarations
├── socketutils.c     # Helper function definitions
├── .gitignore        # Ignored files (.DS_Store, binaries, etc.)
└── README.md         # Project documentation
```

---

## ⚙️ Features

- TCP-based client–server communication
- Interactive messaging from client terminal
- Server continuously receives messages
- Clean session termination using `exit`
- Proper handling of socket shutdown
- Works on Linux and macOS

---

## 🛠 Requirements

Make sure the following are installed:

- GCC or Clang compiler
- Linux or macOS
- POSIX-compliant system

Check compiler:
```bash
gcc --version
```

---

## 🔧 Build Instructions

Compile the server and client separately.

### ✅ Compile Server
```bash
gcc server.c socketutils.c -o server
```

### ✅ Compile Client
```bash
gcc client.c socketutils.c -o client
```

---

## ▶️ How to Run the Application

### 1️⃣ Start the Server
```bash
./server
```

Expected output:
```
BIND RESULT SUCCESS
LISTEN RESULT SUCCESS
```

---

### 2️⃣ Start the Client
```bash
./client
```

Expected output:
```
CONNECTION VALIDATED SUCCESS
type `exit` to terminate
write your message
```

---

## 💬 How to Use

- Type any message and press **Enter**
- The message is immediately sent to the server
- Server prints the received message
- Type `exit` to terminate the client session cleanly

### Example Session

Client:
```
hello server
this is a tcp test
exit
```

Server:
```
SERVER RECEIVED:
hello server
SERVER RECEIVED:
this is a tcp test
SESSION TERMINATED BY CLIENT
```

---

## 🔒 Connection Lifecycle

1. Server creates socket and listens on port `8080`
2. Client connects using TCP
3. Client sends messages
4. Server receives messages using `recv()`
5. Client types `exit`
6. Client calls `shutdown(socketFD, SHUT_WR)`
7. Server detects `recv() == 0`
8. Server shuts down the connection

---

## 🧠 Important Notes

- TCP is stream-oriented — messages may arrive in parts
- `recv()` does not null-terminate buffers
- Always handle return values of socket functions
- `shutdown()` is required for graceful termination
- Use `.gitignore` to avoid committing system files

---

## 🚀 Future Improvements

- Support multiple clients
- Add echo or broadcast functionality
- Use threads or `select()` / `poll()`
- Implement message framing
- Improve error handling and logging

---

## ✅ Adding This Project to GitHub

If you want to push this project to GitHub:

```bash
git init
git add .
git commit -m "Initial TCP client-server application"
gh repo create TCP_SOCKET --public --source=. --remote=origin --push
```

---

## 👨‍💻 Author

**Santusht Kotai**

---

## 📄 License

This project is open-source and free to use for learning and educational purposes.
