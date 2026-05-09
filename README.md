# 📋 BST & Heap Task Scheduler

A **task management system** implemented in C++ using two complementary data structures: a **Binary Search Tree (BST)** for active task storage and retrieval, and a **Min-Heap** for tracking completed tasks sorted by duration. Tasks are loaded from a file and managed through an interactive menu.

---

## 📌 About

This project was built as a data structures assignment to demonstrate the practical combined use of a **BST** and a **Min-Heap** in C++. Active tasks live in the BST (keyed by duration), allowing efficient insertion, search, and range queries. When a task is marked as completed, it is removed from the BST and inserted into the Min-Heap, which keeps completed tasks always sorted by duration for reporting.

---

## 🛠️ How It Works

### BST (`BST.h`)
Tasks are stored as nodes keyed on `Duration`. This gives:

| Operation | Description |
|-----------|-------------|
| `INSERT` | Adds a new task in BST order |
| `INORDER` | Displays all tasks sorted by duration (ascending) |
| `SEARCH` | Finds all tasks matching a given duration |
| `REMOVE` | Deletes a task by duration (in-order successor strategy) |
| `DISPLAYMORETHAN` | Lists tasks with duration ≥ threshold |
| `DISPLAYLESSTHAN` | Lists tasks with duration ≤ threshold |

### Min-Heap (`Heap.h`)
Completed tasks are stored in a fixed-size min-heap (max 30 tasks):

| Operation | Description |
|-----------|-------------|
| `Insert` | Adds a completed task and bubbles up to maintain heap order |
| `DisplayCompleteTasks` | Extracts and prints all tasks sorted by duration, then shows a category report |

### Bridge (`main.cpp`)
`Find_And_Remove()` recursively searches the BST for a task matching both a duration and a partial description (case-insensitive). When found, it moves the task to the heap and removes it from the BST.

---

## 📁 Project Structure

```
BST-Heap-TaskScheduler/
│
├── src/
│   ├── BST.h           # Node and BST class definitions
│   ├── Heap.h          # Heap class definition
│   └── main.cpp        # Menu, file loading, Find_And_Remove logic
├── data/
│   └── tasks.txt       # Input file with initial tasks
├── README.md           # Project documentation
├── LICENSE             # MIT License
└── .gitignore          # Ignores compiled binaries
```

---

## 📄 Input File Format (`tasks.txt`)

```
5
Study for Data Structures exam
120
Educational
Morning jog
30
Health
Cook dinner
45
Food
Read research paper
90
Educational
Take vitamins
10
Health
```

- **Line 1**: Number of tasks
- **For each task** (3 lines): Description → Duration (int) → Category

Supported categories: `Educational`, `Health`, `Food`, `Others`

---

## ▶️ How to Run

### Prerequisites
- A C++ compiler (g++, clang++, MSVC, etc.)
- `tasks.txt` placed inside the `data/` folder

### Compile & Run (Linux / macOS)
```bash
g++ -o task_scheduler src/main.cpp
./task_scheduler
```

### Compile & Run (Windows)
```bash
g++ -o task_scheduler.exe src/main.cpp
task_scheduler.exe
```

---

## 🖥️ Sample Session

```
--------- MENU ---------
1. Insert a task (BST)
2. Display all tasks (BST)
3. Search for a task (BST)
4. Remove a task (BST)
5. Display tasks with duration MORE THAN (BST)
6. Display tasks with duration LESS THAN (BST)
7. Mark a task as completed (Heap)
8. Display completed tasks and report (Heap)
0. Exit
Select an option: 2

Description: Take vitamins, Duration: 10, Category: Health
Description: Morning jog, Duration: 30, Category: Health
Description: Cook dinner, Duration: 45, Category: Food
...

Select an option: 7
Enter the Duration of the task to complete: 30
Enter part of the Description: jog
(Morning jog, 30, Health)
Task marked as completed and moved to heap.

Select an option: 8
Completed tasks sorted by duration:
(Morning jog, 30, Health)

REPORT:
Educational = 0
Health      = 1
Food        = 0
Others      = 0
```

---

## 🧠 Concepts Demonstrated

- **Binary Search Tree** — insertion, search, deletion, and range traversal keyed on duration
- **Min-Heap** — bubble-up insertion and heapify-down extraction for sorted output
- **Two-structure pipeline** — BST handles active tasks; heap handles completed ones
- **Case-insensitive partial string matching** — `Find_And_Remove` uses `tolower` + `string::find`
- **File I/O** — initial tasks loaded from a structured text file
- **Dynamic memory management** — manual `new`/`delete` in BST nodes
- **Header guards** — `#ifndef` / `#define` in both `.h` files

---

## 📜 License

This project is open source and available under the [MIT License](LICENSE).
