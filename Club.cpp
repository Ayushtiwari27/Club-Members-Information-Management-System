#include <iostream>
#include <string>
using namespace std;

//A Node class in which the details of the members needed 
class Node
{
public:
    int prn;
    string name;
    Node *next;
    Node()
    {
        prn = 0;
        name = " Ayush ";
        next = NULL;
    }
};


class P_club
{
public:
    Node *start, *head, *temp, *temp1, *temp2;
    P_club()
    {
        start = temp = head = temp1 = NULL;         //initializing the linnked list
    }

    void add_president()        //details of the president of the club is added and is always kept at the top
    {
        temp = new Node();
        cout << "\nAdd President";
        cout << "\nEnter the PRN of President= ";
        cin >> temp->prn;
        cout << "Enter the name of President= ";
        cin >> temp->name;

        if (head == NULL)
        {
            head = start = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }

    void add_secretary()        //details of the secretary of the club is added and is always kept at the last 
    {
        temp = new Node();
        cout << "\nAdd Secretary";
        cout << "\nEnter the PRN of Secretary= ";
        cin >> temp->prn;
        cout << "Enter the name of Secretary= ";
        cin >> temp->name;

        start = head;
        while (start->next != NULL)
        {
            start = start->next;
        }

        start->next = temp;
    }

    void add_member()       //details of the memebers of the club is added and is kept in between the president and secretary
    {
        temp = new Node();
        cout << "\nEnter the PRN of Member= ";
        cin >> temp->prn;
        cout << "Enter the name of Member= ";
        cin >> temp->name;

        start = head;
        if (head == NULL)
        {
            cout << "\nPlease add president first";
            return;
        }
        if (head->next == NULL)
        {
            cout << "\nPlease add Secretary first";
            return;
        }
        start = head;
        temp->next = start->next;
        start->next = temp;
    }

        void delete_member();

        void display();

        int cal_members();

        void Reverseprint(Node *temp);

};

//DISPLAY FUNCTION
void P_club ::display()
{
    if(head==NULL){
        cout << "\n>> No Member in the club \n";
        return;
    }
    temp = head;
    int i = 1;
    while (temp != NULL)
    {
        if (temp == head)       //president's details are shown first
        {
            cout << "\nDetails of President: \n";
            cout << "PRN: " << temp->prn;
            cout << "\nName: " << temp->name;
        }
        else if (temp->next == NULL)         //president's details are shown al last
        {
            cout << "\n\nDetails of Secretary: \n";
            cout << "PRN: " << temp->prn;
            cout << "\nName: " << temp->name;
        }

        else                                         //in between members details are shown
        {
            cout << "\n\nDetails of Member " << i << ": \n";
            cout << "PRN: " << temp->prn;
            cout << "\nName: " << temp->name;
            i++;
        }
        temp = temp->next;
    }
}

//DELETING A MEMBER
void P_club ::delete_member()
{
    int key, flag = 0;
    cout << "\nEnter the PRN of the member you want to delete: \n";
    cin >> key;

    //Searching through the linked list for the members prn
    temp = start = head;
    while (temp != NULL)
    {
        //if the prn of the member to delete matches with the President's prn then a warning pops.
        //if the user continues then the president's details are deleted and 
        //then the details of new president is asked as input and new president is appointed
        if (head->prn == key)
        {
            cout << "\n\nYou are about to change the President\n ";
            temp = start->next;

            temp2 = new Node();
            cout << "\nEnter detail of new President";
            cout << "\nEnter the PRN of President=";
            cin >> temp2->prn;
            cout << "\nEnter the name of President=";
            cin >> temp2->name;
            temp2->next = temp;

            start = temp2;
            head = temp2;
            flag++;             //flag checks if president is deleted
            break;
        }
        //if the prn of the member to delete matches with the Secretary's prn then a warning pops.
        //if the user continues then the secretary's details are deleted and 
        //then the details of new secretary is asked as input and new secretary is appointed
        else if (temp->prn == key && temp->next == NULL)
        {
            cout << "\n\nYou are about to change the Secretary\n ";

            temp2 = new Node();
            cout << "\nEnter detail of new Secretary";
            cout << "\nEnter the PRN of Secretary=";
            cin >> temp2->prn;
            cout << "\nEnter the name of Secretary=";
            cin >> temp2->name;
            temp1->next = temp2;
            flag++;             //flag checks if secretary is deleted
            break;
        }
        //if the prn ofthe member to delete maches with the members's prn then a member is removed
        else if (temp->prn == key)
        {
            cout << "\nMember Removed\n";
            temp = start->next;
            temp1->next = temp;
            flag++;         //flag checks if a member is deleted
            break;
        }
        else
        {
            temp1 = start;
            temp = start->next;
            start = temp;
        }
    }
    //if no member is deleted
    if (flag == 0)
    {
        cout << "\nNo Member with this PRN found\n";
    }
}

//CALCULATING TOTAL NUMBER OF MEMBERS
int P_club ::cal_members()
{
    int cnt = 0;
    start = head;
    //Traversing  the array and counting every element
    while (start != NULL)
    {
        cnt++;
        start = start->next;
    }
    return cnt;
}

//PRINTING IN REVERSE ORDER USING RECURSION
void P_club :: Reverseprint(Node *temp)
{
    //temp=head;
    if (temp == NULL)
    {
        return;
    }
    Reverseprint(temp->next);           //using recurssion
    cout << "\n\nDetails of Member: \n";
    cout << "PRN: " << temp->prn;
    cout << "\nName: " << temp->name;
}

//CONCATENATION OF TWO LINKED LIST
Node *concatenate(Node *president, Node *head, int no)
{
    Node *temp;
    if (president == NULL)
    {
        return head;
    }
    if (head == NULL)
    {
        return president;
    }

    //the other list is added at the end of the previous list, i.e., 
    //the address of head of second list is stored in the tail of the first list
    for (temp = president; temp->next != NULL; temp = temp->next);
    temp->next = head;
    return president;   //returns head node
}

//MAIN FUNCTION
int main()
{
    Node *newll, *temp;
    int n;
    while (1)           // input total number of members excluding president and Secretary
    {
        cout << "\nEnter the number of Members (excluding President and Secretary): \n";
        cin >> n;
        if (n < 0)                  //if totl members added is negative error pops up
        {
            cout << "\n----Wrong Input----\nEnter Valid choice\n";
            continue;
        }
        break;
    }

    P_club p1,p2,p3;
    p1.add_president();     //adding president

    p1.add_secretary();     //adding secretary

    for (int i = 0; i < n; i++)
    {
        cout << "\nAdd Member " << i + 1;       //adding members
        p1.add_member();
    }

    while(1)
    {
        cout << "\n\n-------------------- MENU -------------------\n";
        cout << "\n1. Display Members";
        cout << "\n2. Add a member";
        cout << "\n3. Delete a member";
        cout << "\n4. Total number of members of club";
        cout << "\n5. Display list in reverse order";
        cout << "\n6. Concatenate two lists";
        cout << "\n7. Exit";

        int ch;
        cout << "\n\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1: // PRINTING THE LINKED LIST
                cout << "\nDisplaying the List: \n";
                p1.display();
                continue;

            case 2: // ADDING A MEMBER
                char x;
                cout << "\nPlease Select Option (3) to delete and add new President and Secretary, else continue\n";
                cout << "--> Do you want to continue? (Y/N) : ";
                cin >> x;
                if (x == 'Y' || x == 'y')
                {
                    p1.add_member();
                    continue;
                }
                else
                {
                    continue;
                }

            case 3: // DELETING A MEMBER
                p1.delete_member();
                continue;

            case 4: // TOTAL MEMBERS
                cout << "\nTotal number of members in the club are:  " << p1.cal_members() << endl;
                continue;

            case 5: // PRINTING LIST IN REVERSE ORDER
                cout << "\nReverse list is:";
                p1.Reverseprint(p1.head);
                continue;

            case 6: // CONCATENATING TWO LINKED LIST
                int m;
                while (1)       //creating a new list to be concatenatedd in the first one
                {
                    cout << "\nDetails of Second list to be concatenated\n";
                    cout << "\nEnter the number of Members (excluding President and Secretary): \n";
                    cin >> m;
                    if (m < 0)
                    {
                        cout << "\n----Wrong Input----\nEnter Valid choice\n";
                        continue;
                    }
                    break;
                }
                p2.add_president();

                p2.add_secretary();

                for (int i = 0; i < m; i++)
                {
                    cout << "\nAdd Member " << i + 1;
                    p2.add_member();
                }
                newll = concatenate(p1.head, p2.head, n + m);       //oncatenating two List
                cout << "\nDisplaying the Concatenated List: \n";       //Displaying the Concatenated List
                {
                    temp = newll;
                    cout << "\n";
                    while (temp != NULL)
                    {
                        cout << temp->prn << ": " << temp->name << "  "
                            << "-> ";
                        temp = temp->next;
                    }
                    cout << "NULL";
                }

                continue;

            case 7: // EXIT
                cout << "\n-- Thank You --\n";
                break;

            default: //  if Wrong input is entered in the menu
                cout << "\n----Wrong Input----\nEnter Valid choice\n";
                continue;
        }
        break;
    }
    return 0;
}
