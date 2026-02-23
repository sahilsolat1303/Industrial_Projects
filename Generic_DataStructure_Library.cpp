///////////////////////////////////////////
//      Generize Datastructure Library
//////////////////////////////////////////

/*
----------------------------------------------------------------------------------------------------
    Type                    Name of class for node                Name of class for Functionality
----------------------------------------------------------------------------------------------------
    Singly Linear           SinglyLLLnode                         SinglyLLL         Done
    Singly Cirular          SinglyCLLnode                         SinglyCLL         Done
    Dobuly Linear           DobulyLLLnode                         DobulyLLL         Done
    Dobuly Cirular          DobulyCLLnode                         DobulyCLL         Done
    Stack                   Stacknode                             Stack             Done
    Queue                   Queuenode                             Queue             Done
----------------------------------------------------------------------------------------------------

*/

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////
//
//         Singly linear likedlist using Generic Apporoach
//
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode * next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }

};

template<class T>
class SinglyLLL
{
    private :                 
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();                   
        
        void InsertFirst(T);
        
        void InsertLast(T);
         
        void DeleteFirst();
        
        void DeleteLast();

        void set(int,T);      
           
        void Display();                         
        
        int Count();
        
        void InsertAtPos(T , int );
        
        void DeleteAtPos(int);

        bool Search(T);

        int Frequency(T);

        int Addition();

        bool ChkSorted();
        

};

template<class T>
SinglyLLL<T> :: SinglyLLL()                   
{
    cout<<"Object of singlyLL get created..\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : InsertFirst
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to insert node at first position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;                  
    this->first = newn;                       
    
    this->iCount++;
    
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : InsertLast
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to insert node at last position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);


    if(this->iCount == 0)                        
    {
        this->first = newn;
    }
    else 
    {
        temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = newn;
                        
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : DeleteFirst
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to delete node at first position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)      
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : DeleteLast
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to delete node at last position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;
    
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }                
        delete temp->next;
        temp->next = NULL;                               
    }
    this->iCount--;
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : set
//      Input :         Data of node
//      Output :        linkedlist
//      Description:    used to replace the values of given position in linkedlist
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: set(int pos, T Value)
{
    SinglyLLLnode<T> *temp = NULL;
    if(pos <= 0 || pos >iCount)
    {
        cout<<"Invalid position..\n";
        return;
    }


    temp = first;
    int i = 0;
    for(i = 1; i< pos; i++)
    {
        temp = temp->next;
    }

    temp->data = Value;
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : Display
//      Input :         Data of node
//      Output :        linkedlist
//      Description:    used to display linkedlist
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: Display()                          
{
    SinglyLLLnode<T> * temp = NULL;
    if(first == NULL)
    {
         return;
    }
    temp = this->first;
    int i = 0;

    for(i = 1; i<=this->iCount; i++)         
    {

        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL\n";            
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Count
//      Input :         Data of node
//      Output :        count of number of node
//      Description:    used to counting nodes
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : InsertAtPos
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to insert node at given position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;
    int i =0 ;

    if((pos<1) || (pos>this->iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);              
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        for(i=1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : DeleteAtPos
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to delete node at given position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * target = NULL;
    SinglyLLLnode<T> * temp = NULL;
    int i =0 ;

    if((pos<1) || (pos>this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        for(i=1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;

        this->iCount--; 
    }
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Search
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to search element present or not
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
bool SinglyLLL<T> :: Search(T no)
{
    SinglyLLLnode<T> * temp = NULL;
    
    temp = first;
    while (temp != NULL)
    {
        if(temp->data == no)
        {
            return true;
        }
        temp = temp->next;
       
    }
    return false;    

}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Frequency
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to Count the Frequency of perticular element
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> :: Frequency(T no)
{
    SinglyLLLnode<T> * temp = NULL;
    temp = first;
    int iCount = 0;

    while (temp != NULL)
    {
        if(temp->data == no)
        {
            iCount ++;
        }
        temp = temp->next;
    }
    return iCount;
    
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : ChkSorted
//      Input :         Data of node
//      Output :        Sorted or not
//      Description:    used to see the data is sorted or not
//      Author :        Sahil Subhash Solat
//      Date :          20/02/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
bool SinglyLLL<T> :: ChkSorted()
{
    bool bFlag = true;
    if(first == NULL || first->next == NULL)
    {
        return true;   
    }

    SinglyLLLnode<T> * temp = NULL;
    
    temp = first;
    
    while(temp->next != NULL)
    {
        if((temp->data) >(temp->next->data))
        {
            bFlag = false;
        }
        temp = temp->next;
    }

    return bFlag;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Addition
//      Input :         Data of node
//      Output :        Addition of data of all node
//      Description:    used to Addition of data
//      Author :        Sahil Subhash Solat
//      Date :          20/02/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> :: Addition()
{
    T iSum = 0;
    SinglyLLLnode<T> * temp = NULL;
    
    temp = first;
    
    while(temp != NULL)
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }

    return iSum;
}

///////////////////////////////////////////////////////////////////////////
//
//      Dobuly Linnera likedlist using Generic Apporoach
//
///////////////////////////////////////////////////////////////////////////


#pragma pack(1)
template<class T>
class DobulyLLLnode                   
{
    public:
        T data;
        DobulyLLLnode * next;
        DobulyLLLnode * pre;

        DobulyLLLnode (T no)
        {
            this->data = no;
            this->next = NULL;
            this->pre = NULL;
        }
};

template<class T>
class DoublyLLL
{

    private:
        DobulyLLLnode<T> * first;          
        int iCount;

    public:
        DoublyLLL();             
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void set(int,T);

        bool search(T);
        void Display();
        int Count();
        int Frequency(T);
        int Addition();
        bool ChkSorted();
};

template<class T>
DoublyLLL<T> :: DoublyLLL()          
{
    cout<<"Likedlist get created..\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : InsertFirst
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to insert node at first position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DobulyLLLnode<T> * newn = NULL;

    newn = new DobulyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->pre = newn;
        this->first = newn;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : InsertLast
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to insert node at last position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DobulyLLLnode<T>  * newn = NULL;
    DobulyLLLnode<T>  * temp = NULL;

    newn = new DobulyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->pre = temp;
        
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : InsertAtPos
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to insert node at given position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    DobulyLLLnode<T>  * newn = NULL;
    DobulyLLLnode<T>  * temp = NULL;
    if((pos<1) || (pos>this->iCount+1))
    {
        cout<<"Invalid position...";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DobulyLLLnode<T>(no);
        temp = this->first;
        int i = 0;
        for(i = 1; i<pos-1;i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->pre = newn;
        temp->next = newn;
        newn->pre = temp;

        this->iCount++;
    }
} 

////////////////////////////////////////////////////////////////////////////
//
//      Function name : DeleteFirst
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to delete node at first position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL) 
    {
        return;
    }
    else if(this->first->next == NULL) 
    {
        delete this->first;
        this->first = NULL;
    }
    else                                
    {
        this->first = this->first->next;
        delete this->first->pre;
        this->first->pre = NULL;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : DeleteLast
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to delete node at last position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    DobulyLLLnode<T>  *temp = NULL;
    if(this->first == NULL) 
    {
        return;
    }
    else if(this->first->next == NULL) 
    {
        delete this->first;
        this->first = NULL;
    }
    else                               
    {
        temp = this->first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        
    }
    this->iCount--;
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : DeleteAtPos
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to delete node at given position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    
    DobulyLLLnode<T>  * temp = NULL;
    if((pos<1) || (pos>this->iCount))
    {
        cout<<"Invalid position...";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;
        int i = 0;
        for(i = 1; i<pos-1;i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->pre;
        temp->next->pre = temp;
        


        this->iCount--;
    }
} 

////////////////////////////////////////////////////////////////////////////
//
//      Function name : set
//      Input :         Data of node
//      Output :        linkedlist
//      Description:    used to replace the values of given position in linkedlist
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: set(int pos, T Value)
{
    DobulyLLLnode<T> *temp = NULL;
    if(pos <= 0 || pos >iCount)
    {
        cout<<"Invalid position..\n";
        return;
    }
    temp = first;
    int i = 0;
    for(i = 1; i< pos; i++)
    {
        temp = temp->next;
    }

    temp->data = Value;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Search
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to search element present or not
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
bool DoublyLLL<T> :: search(T no)
{
    DobulyLLLnode<T> * temp = NULL;
    int iCount = 0;
    
    temp = first;
    while (temp != NULL)
    {
        if(temp->data == no)
        {
            return true;
        }
        temp = temp->next;
       
    }
    return false;    

}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : Display
//      Input :         Data of node
//      Output :        linkedlist
//      Description:    used to display linkedlist
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLLL<T> :: Display()
{
    DobulyLLLnode<T>  * temp = NULL;
    if(first == NULL)
    {
         return;
    }
    temp = this->first;
    cout<<"\nNULL<=>";
    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<"| <=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
    
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Count
//      Input :         Data of node
//      Output :        count of number of node
//      Description:    used to counting nodes
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
} 

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Frequency
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to Count the Frequency of perticular element
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> :: Frequency(T no)
{
    DobulyLLLnode<T> * temp = NULL;
    temp = first;
    int iCount = 0;

    while (temp != NULL)
    {
        if(temp->data == no)
        {
            iCount ++;
        }
        temp = temp->next;
    }
    return iCount;
    
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Addition
//      Input :         Data of node
//      Output :        Addition of data of all node
//      Description:    used to Addition of data
//      Author :        Sahil Subhash Solat
//      Date :          20/02/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> :: Addition()
{
    T iSum = 0;
    DobulyLLLnode<T> * temp = NULL;
    
    temp = first;
    
    while(temp != NULL)
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }

    return iSum;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : ChkSorted
//      Input :         Data of node
//      Output :        Sorted or not
//      Description:    used to see the data is sorted or not
//      Author :        Sahil Subhash Solat
//      Date :          20/02/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
bool DoublyLLL<T> :: ChkSorted()
{
    bool bFlag = true;
    if(first == NULL || first->next == NULL)
    {
        return true;   
    }

    DobulyLLLnode<T> * temp = NULL;
    
    temp = first;
    
    while(temp->next != NULL)
    {
        if((temp->data) >(temp->next->data))
        {
            bFlag = false;
        }
        temp = temp->next;
    }

    return bFlag;
}

////////////////////////////////////////////////////////////////////////////
//
//      Singly Circular likedlist using Generic Apporoach
//
////////////////////////////////////////////////////////////////////////////


#pragma pack(1)
template<class T>
class SinglyCLLnode
{
    public:   
        T data;    
        SinglyCLLnode<T> * next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>

class SinglyCLL
{
    private:
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;
        int iCount;
    
    public:
        SinglyCLL();

        void InsertFirst(T);

        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        

        void DeleteLast();
        void DeleteAtPos(int);
        
        void set(int, T);

        void Display();

        int Count();

        bool Search(T);

        int Frequency(T);
        int Addition();
        bool ChkSorted();

};

template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"Object of singlycLL get created..\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;

}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : InsertFirst
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to insert node at first position
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    this->last->next = this->first;
    
    this->iCount++;
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : InsertLast
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to insert node at last position
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;                
    }
    this->last->next = this->first;
    this->iCount++;
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : InsertAtPos
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to insert node at given position
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * newn = NULL;
    SinglyCLLnode<T> * temp = NULL;

    if((pos<1) || (pos>this->iCount+1))
    {
        cout<<"Invalid Position...";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        InsertLast(no);
    }
    else
    {

        newn = new SinglyCLLnode<T>(no);

        temp = this->first;
        int i = 0;
        for(i=1; i<(pos-1); i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
        
    }
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : DeleteFirst
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to delete node at first position
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
    SinglyCLLnode<T> * temp = NULL;
   
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = first;
        this->first = this->first->next;
        delete temp;
    }
    this->last->next = this->first;
    this->iCount--;
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : DeleteLast
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to delete node at last position
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = first;   
        do
        {
            temp = temp->next;
        }while (temp->next != last);
        delete temp->next;
        this->last = temp;
    }
    this->last->next = this->first;
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : DeleteAtPos
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to delete node at given position
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;

    if((pos<1) || (pos>this->iCount))
    {
        cout<<"Invalid Position...";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;
        int i = 0;
        for(i=1; i<(pos-1); i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;            

        this->iCount--;
        
    }
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : set
//      Input :         Data of node
//      Output :        linkedlist
//      Description:    used to replace the values of given position in linkedlist
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: set(int pos, T Value)
{
    SinglyCLLnode<T> *temp = NULL;
    if(pos <= 0 || pos >iCount)
    {
        cout<<"Invalid position..\n";
        return;
    }
    temp = first;
    int i = 0;
    for(i = 1; i< pos; i++)
    {
        if(temp->next == NULL)
        {
            return;
        }
        temp = temp->next;
    }

    temp->data = Value;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Display
//      Input :         Data of node
//      Output :        linkedlist
//      Description:    used to display linkedlist
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T> * temp = NULL;
    if(first == NULL)
    {
         return;
    }
    temp = this->first;
    do
    {
        cout<<"|"<<temp->data<<"| <->";
        temp = temp->next;
    } while (temp != this->first);
    cout<<"\n";
    
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Count
//      Input :         Data of node
//      Output :        count of number of node
//      Description:    used to counting nodes
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
int SinglyCLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Search
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to search element present or not
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
bool SinglyCLL<T> :: Search(T no)
{
    SinglyCLLnode<T> * temp = NULL;
    int iCount = 0;
    
    temp = first;
    if(temp == NULL)
    {
        return false;
    }
    do
    {
        if(temp->data == no)
        {
            return true;
        }
        temp = temp->next;
    }while(temp != first);

    return false;    

}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Frequency
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to Count the Frequency of perticular element
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T> :: Frequency(T no)
{
    SinglyCLLnode<T> * temp = NULL;
    temp = first;
    int iCount = 0;

    do
    {
        if(temp->data == no)
        {
            iCount ++;
        }
        temp = temp->next;
    }while(temp != first);
    return iCount;
    
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Addition
//      Input :         Data of node
//      Output :        Addition of data of all node
//      Description:    used to Addition of data
//      Author :        Sahil Subhash Solat
//      Date :          20/02/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T> :: Addition()
{
    T iSum = 0;
    SinglyCLLnode<T> * temp = NULL;
    
    temp = first;
    
    do
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }while(temp != first);

    return iSum;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : ChkSorted
//      Input :         Data of node
//      Output :        Sorted or not
//      Description:    used to see the data is sorted or not
//      Author :        Sahil Subhash Solat
//      Date :          20/02/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
bool SinglyCLL<T> :: ChkSorted()
{
    bool bFlag = true;
    if(first == NULL || first->next == NULL)
    {
        return true;   
    }

    SinglyCLLnode<T> * temp = NULL;
    
    temp = first;
    
    do
    {
        if((temp->data) >(temp->next->data))
        {
            bFlag = false;
        }
        temp = temp->next;
    }while(temp->next != first);

    return bFlag;
}


////////////////////////////////////////////////////////////////////////////
//
//      Dobuly Circular likedlist using Generic Apporoach
//
////////////////////////////////////////////////////////////////////////////


#pragma pack(1)
template<class T>
class DobulyCLLnode
{
    public:
        T data;
        DobulyCLLnode<T> * next;
        DobulyCLLnode<T> * prev;

        DobulyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DobulyCLL 
{
    private:
        DobulyCLLnode<T> * first;
        DobulyCLLnode<T> * last;
        int iCount;

    public:
        DobulyCLL();

        void InsertFirst(T);
        
        void InsertLast(T);

        void InsertAtPos(T,int);

        void DeleteFirst();

        void DeleteLast();

        void DeleteAtPos(int);

        void set(int,T);

        void Display();

        int Count();

        bool Search(T);

        int Frequency(T);
        int Addition();
        bool ChkSorted();

};

template<class T>
DobulyCLL<T> :: DobulyCLL()
{
    cout<<"Object of the Dobuly linked list is created...\n";
    this->iCount = 0;
    this->first = NULL;
    this->last = NULL;
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : InsertFirst
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to insert node at first position
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void DobulyCLL<T> :: InsertFirst(T no)
{
    DobulyCLLnode<T> * newn = NULL;

    newn = new DobulyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : InsertLast
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to insert node at last position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void DobulyCLL<T> :: InsertLast(T no)
{
    DobulyCLLnode<T> * newn = NULL;

    newn = new DobulyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : InsertAtPos
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to insert node at given position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void DobulyCLL<T> :: InsertAtPos(T no, int pos)
{
    DobulyCLLnode<T> * temp = NULL;
    DobulyCLLnode<T> * newn = NULL;
    if((pos<1) || (pos>this->iCount+1))
    {
        cout<<"Invaild Position....\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DobulyCLLnode<T>(no);
        temp = this->first;
        int i = 0;
        for(i=1; i<(pos-1); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
        
        this->iCount++;
    }
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : DeleteFirst
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to delete node at first position
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void DobulyCLL<T> :: DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;

    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount--;
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : DeleteLast
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to delete node at last position
//      Author :        Sahil Subhash Solat
//      Date :          06/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void DobulyCLL<T> :: DeleteLast()
{
    DobulyCLLnode<T> * temp = NULL;
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount--;
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : DeleteAtPos
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to delete node at given position
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void DobulyCLL<T> :: DeleteAtPos(int pos)
{
    DobulyCLLnode<T> * temp = NULL;
    DobulyCLLnode<T> * newn = NULL;
    if((pos<1) || (pos>this->iCount))
    {
        cout<<"Invaild Position....";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;
        int i = 0;
        for(i=1; i<(pos-1); i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : set
//      Input :         Data of node
//      Output :        linkedlist
//      Description:    used to replace the values of given position in linkedlist
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DobulyCLL<T> :: set(int pos, T Value)
{
    DobulyCLLnode<T> *temp = NULL;
    if(pos <= 0 || pos >iCount)
    {
        cout<<"Invalid position..\n";
        return;
    }
    temp = first;
    int i = 0;
    for(i = 1; i< pos; i++)
    {
        if(temp->next == NULL)
        {
            return;
        }
        temp = temp->next;
    }

    temp->data = Value;
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : Display
//      Input :         Data of node
//      Output :        linkedlist
//      Description:    used to display linkedlist
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
void DobulyCLL<T> :: Display()
{
    DobulyCLLnode<T> * temp = NULL;
    if(first == NULL)
    {
         return;
    }
    temp = this->first;
    do
    {
        cout<<"|"<<temp->data<<"| <=>";
        temp = temp->next;
    } while (temp != this->first);
    cout<<"\n";
}


////////////////////////////////////////////////////////////////////////////
//
//      Function name : Count
//      Input :         Data of node
//      Output :        count of number of node
//      Description:    used to counting nodes
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////


template<class T>
int DobulyCLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Search
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to search element present or not
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
bool DobulyCLL<T> :: Search(T no)
{
    DobulyCLLnode<T> * temp = NULL;
    int iCount = 0;
    
    temp = first;
    do
    {
        if(temp->data == no)
        {
            return true;
        }
        temp = temp->next;
       
    }while(temp != first);
    return false;    

}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Frequency
//      Input :         Data of node
//      Output :        Nothing
//      Description:    used to Count the Frequency of perticular element
//      Author :        Sahil Subhash Solat
//      Date :          07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int DobulyCLL<T> :: Frequency(T no)
{
    DobulyCLLnode<T> * temp = NULL;
    temp = first;
    int iCount = 0;

    do
    {
        if(temp->data == no)
        {
            iCount ++;
        }
        temp = temp->next;
    }while(temp != first);
    return iCount;
    
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : Addition
//      Input :         Data of node
//      Output :        Addition of data of all node
//      Description:    used to Addition of data
//      Author :        Sahil Subhash Solat
//      Date :          20/02/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int DobulyCLL<T> :: Addition()
{
    T iSum = 0;
    DobulyCLLnode<T> * temp = NULL;
    
    temp = first;
    
    do
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }while(temp != first);

    return iSum;
}

////////////////////////////////////////////////////////////////////////////
//
//      Function name : ChkSorted
//      Input :         Data of node
//      Output :        Sorted or not
//      Description:    used to see the data is sorted or not
//      Author :        Sahil Subhash Solat
//      Date :          20/02/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
bool DobulyCLL<T> :: ChkSorted()
{
    bool bFlag = true;
    if(first == NULL || first->next == NULL)
    {
        return true;   
    }

    DobulyCLLnode<T> * temp = NULL;
    
    temp = first;
    
    do
    {
        if((temp->data) >(temp->next->data))
        {
            bFlag = false;
        }
        temp = temp->next;
    }while(temp->next != first);

    return bFlag;
}


////////////////////////////////////////////////////////////////////////////
//
//                     Stack using Generic Apporoach
//
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> * next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Stack
{
    private:
        Stacknode<T> * first;
        int iCount;

    public:
        Stack();

        void push(T);  

        T pop();   

        T peep();

        void Display();

        int Count();

};

template<class T>
Stack<T> :: Stack()
{
    cout<<"Stack is created successfully....\n";
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> * newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}  

template<class T>
T Stack<T> :: pop()
{
    T value = 0;             
    Stacknode<T>  * temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty....\n";
        return -1;
    }

    value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return value;
}   

template<class T>
T Stack<T> :: peep()
{
    T value = 0;              

    if(this->first == NULL)
    {
        cout<<"Stack is empty....\n";
        return -1;
    }

    value = this->first->data;
    return value;
}

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> * temp = this->first;
    if(this->first == NULL)
    {
        cout<<"Stack is empty...\n";
        return;
    }

    while (temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
    
}

template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////
//
//                  Queue using Generic Apporoach
//
////////////////////////////////////////////////////////////////////////////


#pragma pack(1)
template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode * next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Queue
{
    private:
        Queuenode<T> * first;
        Queuenode<T> * last;
        int iCount;

    public:
        Queue();

        void enqueue(T);  

        T dequeue();   

        void Display();

        int Count();

};

template<class T>
Queue<T> :: Queue()
{
    cout<<"Queue is created successfully....\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> * newn = NULL;
  
    newn = new Queuenode<T>(no);

    
    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }
    this->iCount++;
}  

template<class T>
T Queue<T> :: dequeue()
{
    T value = 0;              
    Queuenode<T>  * temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty....\n";
        return -1;
    }

    value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return value;
}   

template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> * temp = this->first;
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty...\n";
        return;
    }

    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<"\n";
    
}

template<class T>
int Queue<T> :: Count()
{
    return this->iCount;
}


//////////////////////////// End of Library ////////////////////////////////

int main()
{
    
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;
    bool bRet = false;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);
    
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";
    
    obj->Display();

    obj->DeleteFirst();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj->Display();

    cout<<"Before replacing\n";
    obj->Display();
    obj->set(3,60);
    cout<<"After replacing\n";
    obj->Display();
    
    
    obj->Display();

    obj->DeleteLast();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";
    
    obj->Display();  

    obj->InsertAtPos(105,4);
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";
    
    obj->Display();      
    
    obj->DeleteAtPos(3);
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";
    obj->Display(); 

    bRet = obj->Search(51);
    if(bRet == true)
    {
        cout<<"Number is found.....\n";
    }
    else
    {
        cout<<"Number is not found.....\n";
    }

    iRet = obj->Frequency(11);
    cout<<"Frequency of 11 is :"<<iRet<<"\n";

    bRet = obj->ChkSorted();
    if(bRet == true)
    {
        cout<<"List is sorted\n";
    }
    else
    {
        cout<<"List is not sorted\n";
    }

    iRet = obj->Addition();
    cout << "The sum of linked list elements is: " << iRet <<"\n";
    
    delete obj; 

    cout<<"****************************************************************\n";

    DoublyLLL<char> * dobj = new DoublyLLL<char>();
    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();

    cout<<"Number of element are : "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();

    cout<<"Number of element are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();
    dobj->Display();

    cout<<"Number of element are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    dobj->Display();

    cout<<"Number of element are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',4);
    dobj->Display();

    cout<<"Number of element are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);
    dobj->Display();

    cout<<"Number of element are : "<<dobj->Count()<<"\n";

    cout<<"----------------------------------\n";
    dobj->set(3,'Z');
    dobj->Display();
    cout<<"----------------------------------\n";

    bRet = dobj->search('X');
    if(bRet == true)
    {
        cout<<"Number is found.....\n";
    }
    else
    {
        cout<<"Number is not found.....\n";
    }

    iRet = dobj->Frequency('A');
    cout<<"Frequency of A is :"<<iRet<<"\n";

    iRet = dobj->Addition();
    cout << "The sum of linked list elements is: " << iRet <<"\n";

    if(dobj->ChkSorted())
    {
        cout << "List is sorted\n";
    }
    else
    {
        cout << "List is not sorted\n";
    }

    delete dobj;


    cout<<"****************************************************************\n";


    SinglyCLL<double> *sobj = new SinglyCLL<double>();
    

    sobj->InsertFirst(11.22);
    sobj->InsertFirst(21.10);
    sobj->InsertFirst(51.90);

    sobj->Display();
    cout<<"Number of element is :"<<sobj->Count()<<"\n";

    sobj->InsertLast(101.80);
    sobj->InsertLast(121.43);
    sobj->InsertLast(151.67);

    sobj->Display();
    cout<<"Number of element is :"<<sobj->Count()<<"\n";

    sobj->DeleteFirst();
    sobj->Display();
    cout<<"Number of element is :"<<sobj->Count()<<"\n";

    sobj->DeleteLast();
    sobj->Display();
    cout<<"Number of element is :"<<sobj->Count()<<"\n";

    sobj->InsertAtPos(102,4);
    sobj->Display();
    cout<<"Number of element is :"<<sobj->Count()<<"\n";


    sobj->DeleteAtPos(4);
    sobj->Display();
    cout<<"Number of element is :"<<sobj->Count()<<"\n";

    cout<<"----------------------------------\n";
    sobj->set(3,10.00);
    sobj->Display();
    cout<<"----------------------------------\n";


    bRet = sobj->Search(11.11);
    if(bRet == true)
    {
        cout<<"Number is found.....\n";
    }
    else
    {
        cout<<"Number is not found.....\n";
    }

    iRet = sobj->Frequency(102);
    cout<<"Frequency of 102 is :"<<iRet<<"\n";

    iRet = sobj->Addition();
    cout << "The sum of linked list elements is: " << iRet <<"\n";

    if(sobj->ChkSorted())
    {
        cout << "List is sorted\n";
    }
    else
    {
        cout << "List is not sorted\n";
    }
    
    delete sobj;


    cout<<"****************************************************************\n";

    DobulyCLL<int> *dcobj = new DobulyCLL<int>();

    dcobj->InsertFirst(101);
    dcobj->InsertFirst(111);
    dcobj->InsertFirst(121);

    dcobj->Display();
    cout<<"Number of node are:"<<dcobj->Count()<<"\n";

    dcobj->InsertLast(11);
    dcobj->InsertLast(21);
    dcobj->InsertLast(51);

    dcobj->Display();
    cout<<"Number of node are:"<<dcobj->Count()<<"\n";

    dcobj->DeleteFirst();

    dcobj->Display();
    cout<<"Number of node are:"<<dcobj->Count()<<"\n";

    dcobj->DeleteLast();

    dcobj->Display();
    cout<<"Number of node are:"<<dcobj->Count()<<"\n";

    dcobj->InsertAtPos(105,3);

    dcobj->Display();
    cout<<"Number of node are:"<<dcobj->Count()<<"\n";

    dcobj->DeleteAtPos(3);

    dcobj->Display();
    cout<<"Number of node are:"<<dcobj->Count()<<"\n";

    cout<<"----------------------------------\n";
    dcobj->set(3,60);
    dcobj->Display();
    cout<<"----------------------------------\n";

    bRet = dcobj->Search(61);
    if(bRet == true)
    {
        cout<<"Number is found.....\n";
    }
    else
    {
        cout<<"Number is not found.....\n";
    }

    iRet = dcobj->Frequency(105);
    cout<<"Frequency of 102 is :"<<iRet<<"\n";

    iRet = dcobj->Addition();
    cout << "The sum of linked list elements is: " << iRet <<"\n";

    if(dcobj->ChkSorted())
    {
        cout << "List is sorted\n";
    }
    else
    {
        cout << "List is not sorted\n";
    }


    delete dcobj;

    cout<<"****************************************************************\n";

    Stack<char> *stobj = new Stack<char>();  

    stobj->push('a');
    stobj->push('b');
    stobj->push('c');
    stobj->push('d');

    stobj->Display();
    cout<<"Number of element in stack are: "<<stobj->Count()<<"\n";

    cout<<"Return value of peep is : "<<stobj->peep()<<"\n";
    stobj->Display();
    cout<<"Number of element in stack are: "<<stobj->Count()<<"\n";

    cout<<"Poped element is : "<<stobj->pop()<<"\n";
    stobj->Display();
    cout<<"Number of element in stack are: "<<stobj->Count()<<"\n";

    cout<<"Poped element is : "<<stobj->pop()<<"\n";
    stobj->Display();
    cout<<"Number of element in stack are: "<<stobj->Count()<<"\n";

    stobj->push('e');
    stobj->Display();
    cout<<"Number of element in stack are: "<<stobj->Count()<<"\n";

    delete stobj;

    cout<<"****************************************************************\n";


    Queue<double> *qobj = new Queue<double>();  

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);

    qobj->Display();
    cout<<"Number of element in stack are: "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of element in Queue are: "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of element in Queue are: "<<qobj->Count()<<"\n";

    qobj->enqueue(121.56789);
    qobj->Display();
    cout<<"Number of element in Queue are: "<<qobj->Count()<<"\n";

    delete qobj;

    return 0;
}