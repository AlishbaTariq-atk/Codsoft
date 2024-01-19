#include <iostream>

using namespace std;

class node
{
    public:
        string data;
        bool completion_status;
        node *next;
        node *prev;

    node(string value)
    {
        data = value;
        completion_status = false;
        next = NULL;
        prev = NULL;
    }    
};

class list
{
    node *head;
    int length;

    public:
        list()
        {
            head = NULL;
            length = 0;
        }
        ~list()
        {
            node * curr = NULL;
            while(head!=NULL)
            {
                curr = head;
                head = head->next;
                delete curr;
            }
        }
        int getlength()
        {
            return length;
        }
        node* getnode(int pos)
        {
            node *curr = head;
            for(int i =1 ; i<pos; i++)
            {
                curr = curr->next;
            }
            return curr;
        }
        void insert(string value, int pos)
        {
            if(pos < 1 || pos > length+1)
            {
                cout << "Invalid position !" << endl;
                return ;
            }
            node * n = new node(value);

            if(pos == 1)
            {
                n->next = head;
                if(head!=NULL)
                {
                    head->prev = n;
                }
                head = n;
            }
            else
            {
                node *curr = head;
                for(int i=1; i < pos-1; i++)
                {
                    curr = curr-> next;
                }
                n->prev = curr;
                n->next = curr->next;
                if(curr->next=NULL)
                {
                    curr->next->prev = n;
                }
                curr->next =n;
            }
            length++;
        }
        void remove(int pos)
        {
            if(pos < 1 || pos > length+1)
            {
                cout << "Invalid Poaition! "<< endl;
                return ;
            }
            node *curr = head;
            if(pos ==1)
            {
                head = head->next;
                delete curr;
                if(head!= NULL)
                {
                    head->prev = NULL;
                }
            }
            else
            {
                node *slow = NULL;
                for (int i=1; i<pos ; i++)
                {
                    slow = curr;
                    curr = curr->next;
                }
                slow->next = curr->next;
                if(curr->next!=NULL)
                {
                    curr->next->prev = slow;
                }
                delete curr;
            }
            length--;
        }
        void mark_complete(int pos)
        {
            node *curr = head;
            for(int i=1; i< pos ; i++)
            {
                curr = curr->next;
            }
            curr->completion_status = true;
            cout << "Task marked as completed!" << endl;
        }
        void display(int order)
        {
            if(length == 0)
            {
                cout << "No task Added yet!\n" << endl;
                return;
            }
           if(order == 1)
           {
                node *curr = head;
                cout << "\n\nTasks:\n" ;
                for(int i=1 ; i<=length ; i++)
                {
                    cout << i << ". " << curr->data ;
                    if(curr->completion_status == false)
                    {
                        cout << " -Not Completed";
                    }
                    else 
                    {
                        cout << " -Completed";
                    }
                    cout << endl;
                    curr = curr->next;
                }
           }
          else if (order == 2)
          {
                node *curr = head;
                for (int i = 1; i < length; i++)
                {
                    curr = curr->next;
                }
                cout << "\n\nTasks:\n";
                for (int i=1 ; i <=length; i++)
                {
                    cout << i << ". " << curr->data;
                    if (curr->completion_status == false)
                    {
                        cout << " -Not Completed";
                    }
                    else
                    {
                        cout << " -Completed";
                    }
                    cout << endl;
                    if (curr != NULL)
                    {
                        curr = curr->prev;
                    }
                    
                }
          }
           cout << endl;
        }
};


int main()
{

    list to_do_list;
    int option;
    string task;
    int pos;
    
    cout << "---To-Do-List---\n" << endl;
    while(option!= 5)
    {
        cout << "Menu\n"
             << "1. Add Task\n"
             << "2. Mark as completed\n"
             << "3. Remove Completed Tasks\n"
             << "4. Display Tasks\n"
             << "5. Exit" << endl;
        cin  >> option;

        switch(option)
        {
            case 1:
            {
                cout << "Enter task description: ";
                getline(cin >> ws, task);
                cout << "Enter its priorty level: ";
                cin >> pos;
                to_do_list.insert(task, pos);
                break;   
            }
            case 2:
            {
                to_do_list.display(1);
                cout << "Enter the task number to mark as completed: ";
                cin >> pos;
                to_do_list.mark_complete(pos);
                break;
            }
            case 3:
            {
                node* curr = NULL;
                for(int i=1 ; i<= to_do_list.getlength(); i++)
                {
                   curr= to_do_list.getnode(i);
                   if(curr->completion_status == true)
                   {
                    to_do_list.remove(i);
                   }
                }
                break;
            }
            case 4:
            {
                int order;
                cout << "Do you want to dislpay in\n 1. Forward order\n 2. Reverse order" << endl;
                cin >> order;
                if(order == 1)
                {
                    to_do_list.display(1);
                }
                else if(order == 2)
                {
                    to_do_list.display(2);
                }
                else{
                    cout << "Invalid input";
                }
                
                break;
            }
            case 5:
            {
                break;
            }    
            default:
            {
                cout << "Invalid option!" << endl;
                break;
            }    
            
        }     
    }
    return 0;
}
