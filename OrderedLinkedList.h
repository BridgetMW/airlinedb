
#ifndef __ORDEREDLINKEDLIST_H__ 
#define __ORDEREDLINKEDLIST_H__ 
#include <iostream> 
#include <fstream> 

using namespace std;

template < class T > class OrderedLinkedList: public LinkedList<T>


{
    protected:
      class Node < T > *head, *last;
      int count;
      void copy_list (LinkedList < T > otherlist);


    public:
      OrderedLinkedList ()  {};
      virtual ~ OrderedLinkedList () {};

      virtual void insert (T &) {
           // Do the ordered insert here
           cerr << "we do ordered insert here" << endl;
      };

      virtual  T *search (T & item)
      {

          class Node < T > *temp = head;
          cerr << " ordered list search here" << endl;
          while (head != NULL && temp->Data() != item)
          {
            temp = temp->Next();
          }

          return &temp->Data();
      }

      virtual void delete_node (T & item)
      {

          class Node < T > *p, *q;
          cerr << " ordered list delete_node here" << endl;
          if (head == NULL)
          cout << "List is empty..." << endl;
          else if (head->Data() == item)
          {

            p = head;
            head = head->Next();
            delete p;
            count--;
            if (head == NULL)
        last = NULL;
          }
          else
          {

            p = head;
            q = head->Next();
            while (q != NULL && q->Data() != item)
            {
    
              p = q;
              q = q->Next();
            }

            if (q == NULL)
                cout << "item is not found";
                    else
                {
        
                  p->Next(q->Next());
                  if (q->Next() == NULL)
                    last = p;
                  delete q;
                  count--;
                }
          }
      }


};

#endif /* __ORDEREDLINKEDLIST_H_ */
