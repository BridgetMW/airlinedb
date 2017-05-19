
#ifndef __LINKEDLIST_H__ 
#define __LINKEDLIST_H__ 
#include <iostream> 
#include <fstream> 

using namespace std;
template < class T > class Node
{

   protected:
      T data;
      Node<T> *next;

   public:

      Node<T>(T &d)  {
          data = d;
          next = NULL;
      };

      virtual ~Node<T>() { };

      virtual bool isBefore( class Node<T> &other) { return data < other.data; };
      virtual bool isEqual( T &other)  { return data == other; };

      class Node<T> *Next(class Node<T> *nxt) 
      {
          next = nxt;
          return next;
      }

      class Node<T> *Next() 
      {
          return next;
      }

      T &Data() 
      {
          return data;
      }
};



template < class T > class LinkedList
{

    protected:
      class Node < T > *head, *last;
      int count;
      void copy_list (LinkedList < T > otherlist);
    
    public:

      typedef void (*apply_func)(T &data);

      //initializing the list: constructor
      LinkedList ()
      {
           cout << "Initializing list..." << endl;
           head = NULL;
           last = NULL;
           count = 0;
      }

      //destructor 
      virtual ~LinkedList ()
      {
          cout << "List is destroyed..." << endl;
          destroy_list ();
      }

      //check if list is empty 
      bool is_empty ()
      {
          return head == NULL;
      }

      //get the number of nodes in the list 
      int length ()
      {
          return count;
      }


      virtual void insert_ordered (T &) { cerr << "we don't do ordered" << endl; };
      template < class U > friend ostream & operator<< (ostream & os, LinkedList < U > &list);

       //insert a new ellement to the front 
      virtual void insert_first (T & item)
      {
          class Node < T > *current = new class Node < T >(item);

          cerr << "LinkedListInsertFirst" <<endl;
      
          if (head != NULL)
          {
      
            current->Next(head);
            head = current;
          }
          else
          {
      
            head = last = current;
          }
          count++;
      }
  
      //insert a new item at the end of the list 
  
      void insert_last (T & item)
      {
          class Node < T > *current = new class Node < T >(item);
          if (head != NULL)
          {
      
            last->Next(current);
            last = current;
          }
          else
          {
      
            head = last = current;
          }
          count++;
      }

      friend  ostream & operator<< (ostream & os, LinkedList < T > &list)
      {
      
          class Node < T > *temp = list.head;
          while (temp != NULL)
          {
      
            os << temp->Data() << " ";
            temp = temp->Next();
          }
          return os;
      }

      virtual  T *search (T & item)
      {
      
          class Node < T > *temp = head;
          while (temp != NULL && temp->Data() != item)
          {
      
            temp = temp->Next();
          }
          return &temp->Data();
      }
      
      virtual  void apply (apply_func f)
      {
      
          class Node < T > *temp = head;

          while (temp != NULL)
          {
      
            (*f)(temp->Data());
            temp = temp->Next();
          }
      }

      virtual void delete_node (T & item)
      {
      
          class Node < T > *p, *q;
          if (head == NULL)
          {
              cout << "List is empty..." << endl;
              return;
          }

                p = head;
                q = head->Next();
                while (q != NULL && q->Data() != item)
         	{
       	            p = q;
      	            q = q->Next();
        	}
      
                if (q == NULL)
                {
                   cout << "item is not found";
                }
                else
                {
      
      	           p->Next(q->Next());
      	           if (q->Next() == NULL) 
                   {
      	               last = p;
      	               delete q;
      	               count--;
                   }
               }
      }

      virtual T * back ()
      {
      
          // assert (last != NULL);
          return &last->Data();
      }
      
      virtual T *front ()
      {
          // assert (head != NULL);
          return &head->Data();
      }

      virtual void destroy_list ()
      {

          class Node < T > *p;
          while (head != NULL)
          {

            p = head;
            head = head->Next();
            delete p;
          }
          last = NULL;
          count = 0;
      }
};

#endif /* LINKEDLIST_H_ */
