#include <iostream>
#include <vector>

using namespace std;

class Queue{

    private:
        int* arr;
        int maxSize, currSize;
        int front, rear;

    public:
        Queue(int size =100){
            maxSize = size;
            currSize =0;
            front =-1;
            rear =-1;
            arr = new int [maxSize];   
        }

        ~Queue(){
            delete [] arr;
        }

        void push(int x){
            if(currSize == maxSize){
                cout << "The Queue is full\n";
                return;
            }
            else if(rear == -1)
                front = rear = 0;
            else 
                rear = (rear + 1) % maxSize;
            
            arr[rear] = x;
            currSize++;
        }

        void pop(){
            if(isempty()){
                cout << "The array is empty\n"<<endl;
                return;
            }
            else if (currSize == 1)
                front = rear = -1;
            else    
                front = (front +1) % maxSize;

            currSize--;
        }

        bool isempty(){
            return  currSize == 0;
        }

        int peek(){
            if(isempty()){
                cout<<"The Queue is empty\n"<<endl;
                return;
            }
            return arr[front];
        }

};



int main(){

}