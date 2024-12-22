#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;
#include "Node.h"
class LinkedList {

    Node * head;
    int count;
    Node * tail;
    public:
        
        LinkedList() {
            head = NULL;
            tail = NULL;
            count = 0;

          
        }
        ~LinkedList() {}

        void add (int data){
            Node * newNode = new Node(data);
            // 1.creating the first node in the linked list
            count++;
            if (head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }

            // 2.adding nodes to existing linked list

            // A. make the last node in the list points to the newely created node
            tail->next = newNode;
            // B. make the prev pointer in the created node points to the prev node
            newNode->prev = tail; 
            // C. change the tail value to be equal to the address of the last node 
            tail = newNode;
            
        }

        void display () {
            Node * temp  = head;
            if (temp == NULL){
                throw "No Data to display";
            }
            while(temp != NULL){
                cout << temp->data << endl;
                temp = temp->next;
            }

        }

        int getCount(){
            return count;
        }  

        int getDataByIndex(int index){
            if (index >= count || index < 0){
                throw "No such Index in this linkedlist";
            }else {
                Node * temp = head;
                for (int i = 0; i < index; i++){
                    temp = temp->next;
                }
                return temp->data;
            } 
        } 

        void insertDataAfter(int existedData , int insertedData){
            Node * temp = head;
            while(temp != NULL){
                if (temp->data == existedData) break;
                temp = temp->next;
            }
            if (temp == NULL){
                throw "No Data to Insert after";
            }

                Node * newNode = new Node(insertedData);
                newNode->next = temp->next;
                newNode->prev = temp;
            if (temp->next == NULL){
                tail = newNode;
            }else {
                temp->next->prev = newNode;
            }
                temp->next = newNode;
                count++;
        }

        void insertDataBefore(int existedData , int insertedData){
            Node * temp = head;
            while(temp != NULL){
                if (temp->data == existedData) break;
                temp = temp->next;
            }
            if (temp == NULL){
                throw "No Data to Insert after";
            }

                Node * newNode = new Node(insertedData);
                newNode->next = temp;
                newNode->prev = temp->prev;
            if (temp->prev == NULL){
                head = newNode;
            }else {
                temp->prev->next = newNode;
            }
                temp->prev = newNode;
                count++;
        }
    
    protected:

    private:
};

#endif 