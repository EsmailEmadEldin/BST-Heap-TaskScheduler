/// NAME: Esmail Emad El-Din Mohamed ///

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <string>
using namespace std;

const int NumberOfTask = 30;

// Min-Heap to store and display completed tasks sorted by duration
class Heap
{
public:
    struct task
    {
        string Description;
        int    Duration;
        string Category;
    };

    task heap[NumberOfTask];
    int  Size;

    Heap() : Size(0) {}

    // Swap two task entries
    void Swap(task& a, task& b)
    {
        task temp = a;
        a = b;
        b = temp;
    }

    // Heapify down from index i (min-heap on Duration)
    void MIN_Heapify(int i, int sizee)
    {
        while (i < sizee)
        {
            int left  = 2 * i + 1;
            int right = 2 * i + 2;
            int Min   = i;

            if (left  < sizee && heap[left].Duration  < heap[Min].Duration) Min = left;
            if (right < sizee && heap[right].Duration < heap[Min].Duration) Min = right;

            if (Min != i)
            {
                Swap(heap[i], heap[Min]);
                i = Min;
            }
            else { break; }
        }
    }

    // Insert a completed task into the min-heap
    void Insert(string description, int duration, string category)
    {
        if (Size >= NumberOfTask)
        {
            cout << "Cannot insert more tasks — the heap is full." << endl;
            return;
        }
        if (duration < 0)
        {
            cout << "Invalid duration. It must be a positive number." << endl;
            return;
        }

        heap[Size].Description = description;
        heap[Size].Duration    = duration;
        heap[Size].Category    = category;

        // Bubble up to maintain min-heap property
        int i = Size;
        while (i > 0 && heap[i].Duration < heap[(i - 1) / 2].Duration)
        {
            Swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
        Size++;
    }

    // Display all completed tasks sorted by duration, then print category report
    void DisplayCompleteTasks()
    {
        if (Size == 0)
        {
            cout << "There are no completed tasks." << endl;
            return;
        }

        cout << "Completed tasks sorted by duration:" << endl;

        // Work on a copy so the original heap is preserved
        task temp[NumberOfTask];
        for (int i = 0; i < Size; i++) temp[i] = heap[i];
        int TempSize = Size;

        while (TempSize > 0)
        {
            task T = temp[0];
            cout << "(" << T.Description << ", " << T.Duration << ", " << T.Category << ")" << endl;
            temp[0] = temp[TempSize - 1];
            TempSize--;
            HeapifyTemp(temp, TempSize);
        }

        // Category report
        int educational = 0, health = 0, food = 0, others = 0;
        for (int i = 0; i < Size; i++)
        {
            string cat = heap[i].Category;
            if      (cat == "Educational") educational++;
            else if (cat == "Health")      health++;
            else if (cat == "Food")        food++;
            else                           others++;
        }

        cout << "\nREPORT:" << endl;
        cout << "Educational = " << educational << endl;
        cout << "Health      = " << health      << endl;
        cout << "Food        = " << food        << endl;
        cout << "Others      = " << others      << endl;
    }

private:
    // Heapify down on a temporary array (used during sorted display)
    void HeapifyTemp(task temp[], int sizee)
    {
        int i = 0;
        while (i < sizee)
        {
            int left  = 2 * i + 1;
            int right = 2 * i + 2;
            int Min   = i;

            if (left  < sizee && temp[left].Duration  < temp[Min].Duration) Min = left;
            if (right < sizee && temp[right].Duration < temp[Min].Duration) Min = right;

            if (Min != i)
            {
                Swap(temp[i], temp[Min]);
                i = Min;
            }
            else { break; }
        }
    }
};

#endif
