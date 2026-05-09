#include <iostream>
using namespace std;
class Job 
{
public:
    int jobId;
    int pages;
    Job* next;
    Job(int id, int p)
    {
        jobId = id;
        pages = p;
        next = nullptr;
    }
};
class Queue 
{
private:
    Job* front;
    Job* rear;
public:
    Queue() 
    {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int jobId, int pages)
    {
        Job* newJob = new Job(jobId, pages);
        if (rear == nullptr)
        {
            front = newJob;
            rear = newJob;
        }
        else 
        {
            rear->next = newJob;
            rear = newJob;
        }
        cout << "Job " << jobId << " added to queue." << endl;
    }
    void dequeue()
    {
        if (front == nullptr) 
        {
            cout << "No jobs to print." << endl;
            return;
        }
        Job* temp = front;
        cout << "Printing Job -> ID: " << temp->jobId
            << " | Pages: " << temp->pages << endl;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
    }
    void peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Next Job -> ID: " << front->jobId
            << " | Pages: " << front->pages << endl;
    }
    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Pending Print Jobs:" << endl;
        Job* temp = front;
        while (temp != nullptr) 
        {
            cout << "  Job ID: " << temp->jobId
                << " | Pages: " << temp->pages << endl;
            temp = temp->next;
        }
    }
    void totalPages() 
    {
        int total = 0;
        Job* temp = front;
        while (temp != nullptr) 
        {
            total += temp->pages;
            temp = temp->next;
        }
        cout << "Total Pending Pages: " << total << endl;
    }
};
int main() 
{
    Queue q;
    cout << "=== Adding Jobs ===" << endl;
    q.enqueue(101, 5);
    q.enqueue(102, 12);
    q.enqueue(103, 3);
    q.enqueue(104, 8);
    q.enqueue(105, 6);
    cout << "\n=== All Jobs ===" << endl;
    q.display();
    cout << "\n=== Printing 2 Jobs ===" << endl;
    q.dequeue();
    q.dequeue();
    cout << "\n=== Next Job ===" << endl;
    q.peek();
    cout << "\n=== Remaining Jobs ===" << endl;
    q.display();
    cout << "\n=== Total Pages ===" << endl;
    q.totalPages();
    return 0;
}