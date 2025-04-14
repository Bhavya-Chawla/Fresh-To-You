# include<iostream>
# include<string.h>
# include<cmath>
# include<fstream>
# include<time.h>
# include<cstdlib>
# include<unistd.h>
# include<conio.h>
# include<vector>
using namespace std;
string item[100];
int price[100],discount[100],disPrice[100];
int quantity[100],weight[100];
int count1=0;
int i=0;
struct Node
{
    int dest;
    int weight;
    Node* next;
};
class LinkedList
{
public:
    Node* head;
    LinkedList()
    {
        head = nullptr;
    }
    void addEdge(int dest, int weight) {
        Node* newNode = new Node();
        newNode->dest = dest;
        newNode->weight = weight;
        newNode->next = head;
        head = newNode;
    }
};
class Graph
{

    int V;
    vector<LinkedList> adjList;
    int minDistance(vector<int>& distance, vector<bool>& visited)
    {
        int minDist = INT_MAX, minIndex = -1;
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && distance[v] < minDist) {
                minDist = distance[v];
                minIndex = v;
            }
        }
        return minIndex;
    }
public:
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int src, int dest, int weight)
    {
        adjList[src].addEdge(dest, weight);
         adjList[dest].addEdge(src, weight);
    }

    int dijkstra(int src, int dest)
    {
        vector<int> distance(V, INT_MAX);
        vector<bool> visited(V, false);

        distance[src] = 0;

        for (int count = 0; count < V - 1; ++count)
            {
            int u = minDistance(distance, visited);
            visited[u] = true;

            Node* current = adjList[u].head;
            while (current) {
                int v = current->dest;
                int weight = current->weight;
                if (!visited[v] && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
                current = current->next;
            }
        }
        return distance[dest];
    }
};
void welcome()
{
    cout<<"\t\t*************************************************************\n";
    cout<<"\t\t************** ONLINE DELIVERY SYSTEM ***********************\n";
    cout<<"\t\t*************************************************************\n";
}
class customer
{
    string name;
    string phone_no;
    string email;
    string address;
public:
    void getDetails()
    {
        cout<<"Enter the details of the customer: \n";
        cout<<"Name: ";
        getline(cin,name);
        cout<<"Mobile No.: ";
        getline(cin,phone_no);
        cout<<"Email: ";
        getline(cin,email);
        cout<<"Address: ";
        getline(cin,address);
        cout<<"\nYou can now proceed to shop.\n\n";
    }
    friend class bill;
};
class all
{
public:
    void fruits()
    {
        string str2;
        int x;
        int curr=0;
        char ch[100];
        int num;
        string str3;
        string str;
        ifstream obj2;
        obj2.open("Fruits.txt");
        while(obj2.eof()==0)
            {
                getline(obj2,str2);
                cout<<str2<<endl;
            }
        obj2.close();
        cout<<"Enter your choice:(fruits and vegetables) ";
        cin>>x;

        obj2.open("Fruits.txt");
        if(x>=1&&x<=20)
            {
                cout<<"Enter quantity: ";
                cin>>quantity[count1];
                try
                    {
                        if (quantity[count1]<=0)
                            throw "Wrong choice. Enter again.";
                        i++;
                        while(obj2.eof()==0)
                            {
                                curr++;
                                getline(obj2,str3);
                                if(curr==x+6)
                                    {
                                        for(int i=4; i<=44; i++)
                                            str=str+str3.at(i);
                                        item[count1]=str;
                                        for(int i=45; i<str3.length(); i++)
                                            {
                                                ch[i-45]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        price[count1]=num;
                                        for(int i=60; i<str3.length(); i++)
                                            {
                                                ch[i-60]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        discount[count1]=num;
                                        for(int i=75; i<str3.length(); i++)
                                            {
                                                ch[i-75]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        disPrice[count1]=num;
                                        for(int i=97;i<str3.length();i++)
                                        {
                                            ch[i-97]=str3.at(i);
                                        }
                                        num=stoi(ch);
                                        weight[count1]=num;
                                        break;
                                    }

                            }
                        count1++;
                        fruits();
                    }
                catch(const char*str)
                    {
                        cout<<str<<endl;
                        fruits();
                    }
            }
        else if(x<0||x>20)
            {
                cout<<"Wrong choice. Enter again";
                fruits();
            }
    }
    void dairy()
    {
        string str2;
        int x;
        int curr=0;
        char ch[100];
        int num;
        string str3;
        string str;
        ifstream obj2;
        obj2.open("dairy.txt");
        while(obj2.eof()==0)
            {
                getline(obj2,str2);
                cout<<str2<<endl;
            }
        obj2.close();
        cout<<"Enter your choice:(Dairy, Breads and Eggs) ";
        cin>>x;

        obj2.open("dairy.txt");
        if(x>=1&&x<=12)
            {
                cout<<"Enter quantity: ";
                cin>>quantity[count1];
                try
                    {
                        if (quantity[count1]<=0)
                            throw "Wrong choice. Enter again.";
                        i++;
                        while(obj2.eof()==0)
                            {
                                curr++;
                                getline(obj2,str3);
                                if(curr==x+6)
                                    {
                                        for(int i=4; i<=44; i++)
                                            str=str+str3.at(i);
                                        item[count1]=str;
                                        for(int i=45; i<str3.length(); i++)
                                            {
                                                ch[i-45]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        price[count1]=num;
                                        for(int i=60; i<str3.length(); i++)
                                            {
                                                ch[i-60]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        discount[count1]=num;
                                        for(int i=75; i<str3.length(); i++)
                                            {
                                                ch[i-75]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        disPrice[count1]=num;
                                        for(int i=97;i<str3.length();i++)
                                        {
                                            ch[i-97]=str3.at(i);
                                        }
                                        num=stoi(ch);
                                        weight[count1]=num;
                                        break;
                                    }
                            }
                            count1++;
                            dairy();
                        }
                        catch(const char*str)
                        {
                            cout<<str<<endl;
                            dairy();
                        }
            }
        else if(x<0||x>12)
            {
                cout<<"Wrong choice. Enter again";
                dairy();
            }
    }
    void masalas()
    {
        string str2;
        int x;
        int curr=0;
        char ch[100];
        int num;
        string str3;
        string str;
        ifstream obj2;
        obj2.open("masalas.txt");
        while(obj2.eof()==0)
            {
                getline(obj2,str2);
                cout<<str2<<endl;
            }
        obj2.close();
        cout<<"Enter your choice:(Masalas and Dry fruits) ";
        cin>>x;

        obj2.open("masalas.txt");
        if(x>=1&&x<=12)
            {
                cout<<"Enter quantity: ";
                cin>>quantity[count1];
                try
                    {
                        if (quantity[count1]<=0)
                            throw "Wrong choice. Enter again.";
                        i++;
                        while(obj2.eof()==0)
                            {
                                curr++;
                                getline(obj2,str3);
                                if(curr==x+6)
                                    {
                                        for(int i=4; i<=44; i++)
                                            str=str+str3.at(i);
                                        item[count1]=str;
                                        for(int i=45; i<str3.length(); i++)
                                            {
                                                ch[i-45]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        price[count1]=num;
                                        for(int i=60; i<str3.length(); i++)
                                            {
                                                ch[i-60]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        discount[count1]=num;
                                        for(int i=75; i<str3.length(); i++)
                                            {
                                                ch[i-75]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        disPrice[count1]=num;
                                        for(int i=97;i<str3.length();i++)
                                        {
                                            ch[i-97]=str3.at(i);
                                        }
                                        num=stoi(ch);
                                        weight[count1]=num;
                                        break;
                                    }

                            }
                        count1++;
                        masalas();
                    }
                catch(const char*str)
                    {
                        cout<<str<<endl;
                        masalas();
                    }
            }
        else if(x<0||x>12)
            {
                cout<<"Wrong choice. Enter again";
                masalas();
            }
    }
    void atta()
    {
        string str2;
        int x;
        int curr=0;
        char ch[100];
        int num;
        string str3;
        string str;
        ifstream obj2;
        obj2.open("atta.txt");
        while(obj2.eof()==0)
            {
                getline(obj2,str2);
                cout<<str2<<endl;
            }
        obj2.close();
        cout<<"Enter your choice:(Atta, Rice, Dals, Edible oils and ghee) ";
        cin>>x;

        obj2.open("atta.txt");
        if(x>=1&&x<=20)
            {
                cout<<"Enter quantity: ";
                cin>>quantity[count1];
                try
                    {
                        if (quantity[count1]<=0)
                            throw "Wrong choice. Enter again.";
                        i++;
                        while(obj2.eof()==0)
                            {
                                curr++;
                                getline(obj2,str3);
                                if(curr==x+6)
                                    {
                                        for(int i=4; i<=44; i++)
                                            str=str+str3.at(i);
                                        item[count1]=str;
                                        for(int i=45; i<str3.length(); i++)
                                            {
                                                ch[i-45]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        price[count1]=num;
                                        for(int i=60; i<str3.length(); i++)
                                            {
                                                ch[i-60]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        discount[count1]=num;
                                        for(int i=75; i<str3.length(); i++)
                                            {
                                                ch[i-75]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        disPrice[count1]=num;
                                        for(int i=97;i<str3.length();i++)
                                        {
                                            ch[i-97]=str3.at(i);
                                        }
                                        num=stoi(ch);
                                        weight[count1]=num;
                                        break;
                                    }

                            }
                        count1++;
                        atta();
                    }


                catch(const char*str)
                    {
                        cout<<str<<endl;
                        atta();
                    }
            }
        else if(x<0||x>20)
            {
                cout<<"Wrong choice. Enter again";
                atta();
            }
    }
    void munchies()
    {
        string str2;
        int x;
        int curr=0;
        char ch[100];
        int num;
        string str3;
        string str;
        ifstream obj2;
        obj2.open("munchies.txt");
        while(obj2.eof()==0)
            {
                getline(obj2,str2);
                cout<<str2<<endl;
            }
        obj2.close();
        cout<<"Enter your choice:(Munchies and Soft Drinks) ";
        cin>>x;

        obj2.open("munchies.txt");
        if(x>=1&&x<=16)
            {
                cout<<"Enter quantity: ";
                cin>>quantity[count1];
                try
                    {
                        if (quantity[count1]<=0)
                            throw "Wrong choice. Enter again.";
                        i++;
                        while(obj2.eof()==0)
                            {
                                curr++;
                                getline(obj2,str3);
                                if(curr==x+6)
                                    {
                                        for(int i=4; i<=44; i++)
                                            str=str+str3.at(i);
                                        item[count1]=str;
                                        for(int i=45; i<str3.length(); i++)
                                            {
                                                ch[i-45]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        price[count1]=num;
                                        for(int i=60; i<str3.length(); i++)
                                            {
                                                ch[i-60]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        discount[count1]=num;
                                        for(int i=75; i<str3.length(); i++)
                                            {
                                                ch[i-75]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        disPrice[count1]=num;
                                        for(int i=97;i<str3.length();i++)
                                        {
                                            ch[i-97]=str3.at(i);
                                        }
                                        num=stoi(ch);
                                        weight[count1]=num;
                                        break;
                                    }

                            }
                        count1++;
                        munchies();
                    }
                catch(const char*str)
                    {
                        cout<<"Wrong choice. Enter again"<<endl;
                        munchies();
                    }

            }
        else if(x<0||x>16)
            {
                cout<<"Wrong choice. Enter again";
                munchies();
            }
    }
    void instant()
    {
        string str2;
        int x;
        int curr=0;
        char ch[100];
        int num;
        string str3;
        string str;
        ifstream obj2;
        obj2.open("instant.txt");
        while(obj2.eof()==0)
            {
                getline(obj2,str2);
                cout<<str2<<endl;
            }
        obj2.close();
        cout<<"Enter your choice:(Instant and Frozen Food) ";
        cin>>x;

        obj2.open("instant.txt");
        if(x>=1&&x<=15)
            {
                cout<<"Enter quantity: ";
                cin>>quantity[count1];
                try
                    {
                        if (quantity[count1]<=0)
                            throw "Wrong choice. Enter again.";
                        i++;
                        while(obj2.eof()==0)
                            {
                                curr++;
                                getline(obj2,str3);
                                if(curr==x+6)
                                    {
                                        for(int i=4; i<=44; i++)
                                            str=str+str3.at(i);
                                        item[count1]=str;
                                        for(int i=45; i<str3.length(); i++)
                                            {
                                                ch[i-45]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        price[count1]=num;
                                        for(int i=60; i<str3.length(); i++)
                                            {
                                                ch[i-60]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        discount[count1]=num;
                                        for(int i=75; i<str3.length(); i++)
                                            {
                                                ch[i-75]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        disPrice[count1]=num;
                                        for(int i=97;i<str3.length();i++)
                                        {
                                            ch[i-97]=str3.at(i);
                                        }
                                        num=stoi(ch);
                                        weight[count1]=num;
                                        break;
                                    }

                            }
                        count1++;
                        instant();
                    }
                catch(const char*str)
                    {
                        cout<<str<<endl;
                        instant();
                    }
            }
        else if(x<0||x>15)
            {
                cout<<"Wrong choice. Enter again";
                instant();
            }
    }
    void chocolate()
    {
        string str2;
        int x;
        int curr=0;
        char ch[100];
        int num;
        string str3;
        string str;
        ifstream obj2;
        obj2.open("chocolates.txt");
        while(obj2.eof()==0)
            {
                getline(obj2,str2);
                cout<<str2<<endl;
            }
        obj2.close();
        cout<<"Enter your choice:(Chocolates,Desserts and Ice Creams) ";
        cin>>x;

        obj2.open("chocolates.txt");
        if(x>=1&&x<=12)
            {
                cout<<"Enter quantity: ";
                cin>>quantity[count1];
                try
                    {
                        if (quantity[count1]<=0)
                            throw "Wrong choice. Enter again.";
                        i++;
                        while(obj2.eof()==0)
                            {
                                curr++;
                                getline(obj2,str3);
                                if(curr==x+6)
                                    {
                                        for(int i=4; i<=44; i++)
                                            str=str+str3.at(i);
                                        item[count1]=str;
                                        for(int i=45; i<str3.length(); i++)
                                            {
                                                ch[i-45]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        price[count1]=num;
                                        for(int i=60; i<str3.length(); i++)
                                            {
                                                ch[i-60]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        discount[count1]=num;
                                        for(int i=75; i<str3.length(); i++)
                                            {
                                                ch[i-75]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        disPrice[count1]=num;
                                        for(int i=97;i<str3.length();i++)
                                        {
                                            ch[i-97]=str3.at(i);
                                        }
                                        num=stoi(ch);
                                        weight[count1]=num;
                                        break;
                                    }

                            }
                        count1++;
                        chocolate();

                    }
                catch(const char*str)
                    {
                        cout<<str<<endl;
                        chocolate();
                    }
            }
        else if(x<0||x>12)
            {
                cout<<"Wrong choice. Enter again";
                chocolate();
            }
    }
    void hygiene()
    {
        string str2;
        int x;
        int curr=0;
        char ch[100];
        int num;
        string str3;
        string str;
        ifstream obj2;
        obj2.open("hygiene.txt");
        while(obj2.eof()==0)
            {
                getline(obj2,str2);
                cout<<str2<<endl;
            }
        obj2.close();
        cout<<"Enter your choice:(Hygiene and Wellness) ";
        cin>>x;

        obj2.open("hygiene.txt");
        if(x>=1&&x<=12)
            {
                cout<<"Enter quantity: ";
                cin>>quantity[count1];
                try
                    {
                        if (quantity[count1]<=0)
                            throw "Wrong choice. Enter again.";
                        i++;
                        while(obj2.eof()==0)
                            {
                                curr++;
                                getline(obj2,str3);
                                if(curr==x+6)
                                    {
                                        for(int i=4; i<=44; i++)
                                            str=str+str3.at(i);
                                        item[count1]=str;
                                        for(int i=45; i<str3.length(); i++)
                                            {
                                                ch[i-45]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        price[count1]=num;
                                        for(int i=60; i<str3.length(); i++)
                                            {
                                                ch[i-60]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        discount[count1]=num;
                                        for(int i=75; i<str3.length(); i++)
                                            {
                                                ch[i-75]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        disPrice[count1]=num;
                                        for(int i=97;i<str3.length();i++)
                                        {
                                            ch[i-97]=str3.at(i);
                                        }
                                        num=stoi(ch);
                                        weight[count1]=num;
                                        break;
                                    }

                            }
                        count1++;
                        hygiene();
                    }
                catch(const char*str)
                    {
                        cout<<str<<endl;
                        hygiene();
                    }
            }
        else if(x<0||x>12)
            {
                cout<<"Wrong choice. Enter again";
                hygiene();
            }
    }
    void household()
    {
        string str2;
        int x;
        int curr=0;
        char ch[100];
        int num;
        string str3;
        string str;
        ifstream obj2;
        obj2.open("household.txt");
        while(obj2.eof()==0)
            {
                getline(obj2,str2);
                cout<<str2<<endl;
            }
        obj2.close();
        cout<<"Enter your choice:(HouseHold Needs) ";
        cin>>x;

        obj2.open("household.txt");
        if(x>=1&&x<=12)
            {
                cout<<"Enter quantity: ";
                cin>>quantity[count1];
                try
                    {
                        if (quantity[count1]<=0)
                            throw "Wrong choice. Enter again.";
                        i++;
                        while(obj2.eof()==0)
                            {
                                curr++;
                                getline(obj2,str3);
                                if(curr==x+6)
                                    {
                                        for(int i=4; i<=44; i++)
                                            str=str+str3.at(i);
                                        item[count1]=str;
                                        for(int i=45; i<str3.length(); i++)
                                            {
                                                ch[i-45]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        price[count1]=num;
                                        for(int i=60; i<str3.length(); i++)
                                            {
                                                ch[i-60]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        discount[count1]=num;
                                        for(int i=75; i<str3.length(); i++)
                                            {
                                                ch[i-75]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        disPrice[count1]=num;
                                        for(int i=97;i<str3.length();i++)
                                        {
                                            ch[i-97]=str3.at(i);
                                        }
                                        num=stoi(ch);
                                        weight[count1]=num;
                                        break;
                                    }

                            }
                        count1++;
                        household();
                    }
                catch(const char*str)
                    {
                        cout<<str<<endl;
                        household();
                    }
            }
        else if(x<0||x>12)
            {
                cout<<"Wrong choice. Enter again";
                household();
            }
    }
    void stationary()
    {
        string str2;
        int x;
        int curr=0;
        char ch[100];
        int num;
        string str3;
        string str;
        ifstream obj2;
        obj2.open("Stationary.txt");
        while(obj2.eof()==0)
            {
                getline(obj2,str2);
                cout<<str2<<endl;
            }
        obj2.close();
        cout<<"Enter your choice:(Stationary and Electricals) ";
        cin>>x;

        obj2.open("Stationary.txt");
        if(x>=1&&x<=16)
            {
                cout<<"Enter quantity: ";
                cin>>quantity[count1];
                try
                    {
                        if (quantity[count1]<=0)
                            throw "Wrong choice. Enter again.";
                        i++;
                        while(obj2.eof()==0)
                            {
                                curr++;
                                getline(obj2,str3);
                                if(curr==x+6)
                                    {
                                        for(int i=4; i<=44; i++)
                                            str=str+str3.at(i);
                                        item[count1]=str;
                                        for(int i=45; i<str3.length(); i++)
                                            {
                                                ch[i-45]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        price[count1]=num;
                                        for(int i=60; i<str3.length(); i++)
                                            {
                                                ch[i-60]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        discount[count1]=num;
                                        for(int i=75; i<str3.length(); i++)
                                            {
                                                ch[i-75]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        disPrice[count1]=num;
                                        for(int i=97;i<str3.length();i++)
                                        {
                                            ch[i-97]=str3.at(i);
                                        }
                                        num=stoi(ch);
                                        weight[count1]=num;
                                        break;
                                    }

                            }
                        count1++;
                        stationary();
                    }
                catch(const char*str)
                    {
                        cout<<str<<endl;
                        stationary();
                    }
            }
        else if(x<0||x>16)
            {
                cout<<"Wrong choice. Enter again";
                stationary();
            }
    }
    void gym()
    {
        string str2;
        int x;
        int curr=0;
        char ch[100];
        int num;
        string str3;
        string str;
        ifstream obj2;
        obj2.open("gym.txt");
        while(obj2.eof()==0)
            {
                getline(obj2,str2);
                cout<<str2<<endl;
            }
        obj2.close();
        cout<<"Enter your choice:(Gym and Health) ";
        cin>>x;

        obj2.open("gym.txt");
        if(x>=1&&x<=10)
            {
                cout<<"Enter quantity: ";
                cin>>quantity[count1];
                try
                    {
                        if (quantity[count1]<=0)
                            throw "Wrong choice. Enter again.";
                        i++;
                        while(obj2.eof()==0)
                            {
                                curr++;
                                getline(obj2,str3);
                                if(curr==x+6)
                                    {
                                        for(int i=4; i<=44; i++)
                                            str=str+str3.at(i);
                                        item[count1]=str;
                                        for(int i=45; i<str3.length(); i++)
                                            {
                                                ch[i-45]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        price[count1]=num;
                                        for(int i=60; i<str3.length(); i++)
                                            {
                                                ch[i-60]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        discount[count1]=num;
                                        for(int i=75; i<str3.length(); i++)
                                            {
                                                ch[i-75]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        disPrice[count1]=num;
                                        for(int i=97;i<str3.length();i++)
                                        {
                                            ch[i-97]=str3.at(i);
                                        }
                                        num=stoi(ch);
                                        weight[count1]=num;
                                        break;
                                    }

                            }
                        count1++;
                        gym();
                    }
                catch(const char*str)
                    {
                        cout<<str<<endl;
                        gym();
                    }
            }
        else if(x<0||x>10)
            {
                cout<<"Wrong choice. Enter again";
                gym();
            }
    }
    void paan()
    {
        string str2;
        int x;
        int curr=0;
        char ch[100];
        int num;
        string str3;
        string str;
        ifstream obj2;
        obj2.open("Paan.txt");
        while(obj2.eof()==0)
            {
                getline(obj2,str2);
                cout<<str2<<endl;
            }
        obj2.close();
        cout<<"Enter your choice:(Paan Corner) ";
        cin>>x;

        obj2.open("Paan.txt");
        if(x>=1&&x<=12)
            {
                cout<<"Enter quantity: ";
                cin>>quantity[count1];
                try
                    {
                        if (quantity[count1]<=0)
                            throw "Wrong choice. Enter again.";
                        i++;
                        while(obj2.eof()==0)
                            {
                                curr++;
                                getline(obj2,str3);
                                if(curr==x+6)
                                    {
                                        for(int i=4; i<=44; i++)
                                            str=str+str3.at(i);
                                        item[count1]=str;
                                        for(int i=45; i<str3.length(); i++)
                                            {
                                                ch[i-45]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        price[count1]=num;
                                        for(int i=60; i<str3.length(); i++)
                                            {
                                                ch[i-60]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        discount[count1]=num;
                                        for(int i=75; i<str3.length(); i++)
                                            {
                                                ch[i-75]=str3.at(i);
                                            }
                                        num=stoi(ch);
                                        disPrice[count1]=num;
                                        for(int i=97;i<str3.length();i++)
                                        {
                                            ch[i-97]=str3.at(i);
                                        }
                                        num=stoi(ch);
                                        weight[count1]=num;
                                        break;
                                    }

                            }
                        count1++;
                        paan();
                    }
                catch(const char*str)
                    {
                        cout<<str<<endl;
                        paan();
                    }
            }
        else if(x<0||x>12)
            {
                cout<<"Wrong choice. Enter again";
                paan();
            }
    }
    void choiceAllCategories()
    {
        string str1;
        ifstream obj1;
        obj1.open("AllCategories.txt");
        while(obj1.eof()==0)
            {
                getline(obj1,str1);
                cout<<str1<<endl;
            }
        int x;
        cout<<"Enter your choice:(All categories) ";
        cin>>x;
        switch(x)
            {
            case 1:
                fruits();
                choiceAllCategories();
                break;
            case 2:
                dairy();
                choiceAllCategories();
                break;
            case 3:
                masalas();
                choiceAllCategories();
                break;
            case 4:
                atta();
                choiceAllCategories();
                break;
            case 5:
                munchies();
                choiceAllCategories();
                break;
            case 6:
                instant();
                choiceAllCategories();
                break;
            case 7:
                chocolate();
                choiceAllCategories();
                break;
            case 8:
                hygiene();
                choiceAllCategories();
                break;
            case 9:
                household();
                choiceAllCategories();
                break;
            case 10:
                stationary();
                choiceAllCategories();
                break;
            case 11:
                gym();
                choiceAllCategories();
                break;
            case 12:
                paan();
                choiceAllCategories();
                break;
            case 0:
                //choiceAllCategories();
                break;
            default:
                cout<<"Wrong choice. Enter again.\n";
                choiceAllCategories();
                break;
            }
    }
    //friend class cart;
    //friend class discount1;
    friend class bill;
};
class cart
{
    all obj;
    int A[100];
public:
    void quan()
    {
        for(int j=0; j<i; j++)
            {
                for(int k=j+1; k<i; k++)
                    {
                        if(item[j].compare(item[k])==0)
                            {
                                if(quantity[j]>0&&quantity[k]>0)
                                    {
                                        quantity[j]+=quantity[k];
                                        quantity[k]=0;
                                    }
                            }
                    }
            }
    }
    void cart1()
    {
        cout<<endl<<"**********************************************************************************************************************************************************\n";
        cout<<"S.No:\tItems:\t\t\t\t\tQuantity:\tPrice:\t\tDiscount(%):\tDiscounted Price:\tTotal price:\tTotal Weight\n";
        cout<<"__________________________________________________________________________________________________________________________________________________________\n";
        int y=1;
        for(int k=0; k<i; k++)
            {
                if(quantity[k]>0)
                    {
                        A[k]=y;
                        cout<<A[k]<<"\t"<<item[k]<<quantity[k]<<"\t\t"<<price[k]<<"\t\t"<<discount[k]<<"\t\t"<<disPrice[k]<<"\t\t\t"<<(disPrice[k]*quantity[k])<<"\t\t\t"<<(weight[k]*quantity[k])<<endl;
                        y++;
                    }
            }
        cout<<"__________________________________________________________________________________________________________________________________________________________\n\n";
        cout<<"**********************************************************************************************************************************************************\n";
        change1();
    }
    void change1()
    {
        int x;
        cout<<"Do you wish to make any changes?\n1) Delete an item.\n2) Add an item.\n3) Change the quantity.\n4) None.\n";
        cin>>x;
        switch(x)
            {
            case 1:
                deleteitem();
                cart1();
                break;
            case 2:
                additem();
                cart1();
                break;
            case 3:
                changequantity();
                cart1();
                break;
            case 4:
                break;
            default:
                printf("Wrong Choice.");
                cart1();
                break;
            }
    }
    void deleteitem()
    {
        int a;
        cout<<"Select the serial number of the item you want to delete: ";
        cin>>a;
        for(int k=0; k<i; k++)
            {
                if(A[k]==a)
                    {
                        quantity[k]=0;
                        for(int x=k; x<i; x++)
                            A[k]=A[k]-1;
                    }

            }
    }
    void additem()
    {
        obj.choiceAllCategories();
        quan();
    }
    void changequantity()
    {
        int a;
        int b;
        cout<<"Select the serial number of the item whose quantity you want to change: ";
        cin>>a;
        cout<<"Enter new quantity: ";
        cin>>b;
        for(int k=0; k<i; k++)
            {
                if(A[k]==a)
                    quantity[k]=b;

            }
    }
    //friend class discount1;
    friend class bill;
};
class discount1
{
    float total;
    string card_name,card_num;string upi_id;int upi_pin;
    int card_cvv,card_expiryM,card_expiryY;
    float discounted_price=0;
    int arr[4];float dis[4];
public:
    int payment;
    void printA()
    {
        cout<<endl<<"Total amount: "<<total;
    }
    void total1()
    {
        for(int k=0;k<i;k++)
        {
            if(quantity[k]>0)
            total+=(disPrice[k]*quantity[k]);
        }
    }
    void offers()
    {
        cout<<endl<<"There are some amazing offers for you.\n";
        cout<<"1) Flat Rs.25 off on an order above Rs.199\n";
        cout<<"2) Flat 15% off on an order above Rs.750\n";
        cout<<"3) Flat 20% off on an order above Rs.999\n";
        cout<<"4) 10% off upto Rs.125 on an order above Rs.250 using credit/debit card of HDFC bank.\n";
        cout<<"5) 15% off upto Rs.125 on an order above Rs.250 using credit/debit card of PNB.\n";
        cout<<"6) 20% off upto Rs.200 on an order above Rs.499 using credit/debit card of AU small finance bank.\n\n";
    }
    void payment_method()
    {
        cout<<"Enter your choice of payment: \n";
        cout<<"1) HDFC bank card(credit/debit).\n";
        cout<<"2) PNB card(credit/debit).\n";
        cout<<"3) AU small finance bank card(credit/debit).\n";
        cout<<"4) PayTm.\n";
        cout<<"5) Cash on delivery.\n";
        cin>>payment;
        if(payment<1||payment>5)
            throw "Wrong choice. Enter again.\n";

    }
    void card()
    {
       if(payment>=1&&payment<=3)
       {
           cout<<endl<<"Enter card name: ";
           getline(cin,card_name);
           getline(cin,card_name);
           cout<<"Enter card number: ";
           getline(cin,card_num);
           cout<<"Enter the expiry of card: (month,year) ";
           cin>>card_expiryM>>card_expiryY;
           cout<<"Enter the CVV: ";
           cin>>card_cvv;
       }
       else if(payment==4)
       {
           cout<<endl<<"Enter UPI id: ";
           getline(cin,upi_id);
           getline(cin,upi_id);
           cout<<"Enter the pin: ";
           cin>>upi_pin;
       }
    }
    void calculate1()
    {
        for(int i=0;i<4;i++)
            arr[i]=0;
        if(total>=199&&total<750)
        {
            arr[0]=1;
        }
        else if(total>=750&&total<999)
        {
            arr[0]=1;
            arr[1]=2;
        }
        else if(total>=999)
        {
            arr[0]=1;
            arr[1]=2;
            arr[2]=3;
        }
        if(payment==1&&total>=250)
            arr[3]=4;
        else if(payment==2&&total>=250)
            arr[3]=5;
        else if(payment==3&&total>=499)
            arr[3]=6;

    }
    float calculate2(int a)
    {
        if(a==0)
            discounted_price=0;
        if(a==1)
            discounted_price=25;
        if(a==2)
            discounted_price=.15*total;
        if(a==3)
            discounted_price=.2*total;
        if(a==4)
        {
            if(.1*total>=125)
                discounted_price=125;
            else
                discounted_price=.1*total;
        }
        if(a==5)
        {
            if(.15*total>=125)
                discounted_price=125;
            else
                discounted_price=.15*total;
        }
        if(a==6)
        {
            if(.2*total>=200)
                discounted_price=200;
            else
                discounted_price=.2*total;
        }
        return discounted_price;
    }
    void calculate3()
    {
        for(int i=0;i<4;i++)
        {
            dis[i]=calculate2(arr[i]);
        }
        float temp;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(dis[j]<dis[j+1])
                {
                    temp=dis[j];
                    dis[j]=dis[j+1];
                    dis[j+1]=temp;
                }

            }
        }
    }
    void print()
    {
        cout<<endl<<"Total discount: "<<dis[0]<<endl;
        cout<<"Discounted Price: "<<total-dis[0]<<endl;
    }
    friend class bill;
};
class bill
{
    cart objA;
    int A[100];
    int ship;
public:
    int min_bin()
    {
        int cumulative_quantity;
        int wt[1000];
        for(int k=0; k<i; k++)
            {
                if(quantity[k]>0)
                    {
                       // cout<<y<<"\t"<<item[k]<<quantity[k]<<"\t\t"<<price[k]<<"\t\t"<<discount[k]<<"\t\t"<<disPrice[k]<<"\t\t\t"<<(disPrice[k]*quantity[k])<<"\t\t"<<(weight[k]*quantity[k])<<endl;
                        //y++;
                        for(int m=0;m<quantity[k];m++)
                        {
                            wt[cumulative_quantity]=weight[k];
                            cumulative_quantity++;

                        }
                    }
            }
        int capacity=1000;
        int result=0;
        int bins[cumulative_quantity];
        for(int k=0;k<cumulative_quantity;k++)
        {
            int j;
            int min=capacity+1,bi=0;
            for(j=0;j<result;j++)
            {
                if(bins[j] >= wt[k] && bins[j]-wt[k] < min)
                {
                    bi=j;
                    min=bins[j]-wt[k];
                    //break;
                }
            }
            if(min==capacity+1)
            {
                bins[result]=capacity-wt[k];
                result++;
            }
            else
            {
                bins[bi]=bins[bi]-wt[k];
            }
        }
        //cout<<"Total bags needed are: "<<result;
        return result;
    }
    void bill_print(customer abc,discount1 objB,int delivery_time)
    {
        //system("cls");
        int hr=0,min=0,sec=0;
        min=delivery_time+5;
        char ch;
        cout<<endl<<"Enter y to bill the print: ";
        cin>>ch;
        if(ch=='y')
        {while(!(hr==0&&min==0&&sec==0))
        {
            system("cls");

        cout<<"\n----------------------------------------------------------------------------------------------------------------------\n";
        cout<<"----------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\t\t\t\t\t\tFRESH TO YOU\n\n";
       // cout<<"\n\n\t\t\t\t     Connaught Plaza Restaurants Pvt Ltd.\n\t\t\t\t\tPlot no. H224/I, Sector 63\n\t\t\t\t\t\tNoida-201309\n";
        cout<<"\t\t\t\t----------------TAX INVOICE----------------";
        time_t t;
        time(&t);
        cout<<"\n\t\t\t\tDate and time: "<<ctime(&t);
        cout<<endl;
        cout<<"\t\t\t\t-------------------------------------------\n";
        cout<<"Customer Details: \n";
        cout<<"_________________\n";
        cout<<"Name: "<<abc.name<<endl;
        cout<<"Mobile no.: "<<abc.phone_no<<endl;
        cout<<"Email: "<<abc.email<<endl;
        cout<<"Address: "<<abc.address<<endl;
        if(objB.payment==1)
            cout<<"Payment Method: HDFC Bank."<<endl;
        else if(objB.payment==2)
            cout<<"Payment Method: Punjab National Bank."<<endl;
        else if(objB.payment==3)
            cout<<"Payment Method: AU small finance Bank."<<endl;
        else if(objB.payment==4)
            cout<<"Payment Method: PayTm."<<endl;
        else if(objB.payment==5)
            cout<<"Payment Method: Cash on delivery."<<endl;
        bill_cart();
        //objB.total1();
        //objB.calculate1();
        //objB.calculate3();
        cout<<"Amount: \t\t\t\t"<<objB.total<<endl;
        cout<<"Discount: \t\t\t\t"<<objB.dis[0]<<endl;
        cout<<"Discounted Price: \t\t\t"<<(objB.total-objB.dis[0])<<endl;
        cout<<"No of packages: \t\t\t"<<min_bin()<<endl;
        cout<<"Packaging charges: \t\t\t"<<min_bin()*10<<endl;
        try
        {
            if((objB.total-objB.dis[0])<500)
                throw 35;
            else if((objB.total-objB.dis[0])>=500&&(objB.total-objB.dis[0])<1000)
                throw 25;
            else if((objB.total-objB.dis[0])>=1000)
                throw "FREE";
        }
        catch(int x)
        {
            ship=x;
            cout<<"Shipping Charge: \t\t\t"<<ship<<endl;
        }
        catch(const char*str)
        {
            ship=0;
            cout<<"Shipping Charge: \t\t\tFREE"<<endl;
        }
        cout<<"SGST @2.5%: \t\t\t\t"<<(0.025*(objB.total-objB.dis[0]))<<endl;
        cout<<"CGST @2.5%: \t\t\t\t"<<(0.025*(objB.total-objB.dis[0]))<<endl;
        cout<<"\n----------------------------------------------------------------------------------------------------------------------\n";
        cout<<"GRAND TOTAL: \t\t\t\t"<<(1.05*(objB.total-objB.dis[0])+ship+min_bin()*10)<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\t\t\t\t\t\tTHANK YOU\n";
        cout<<"\t\t\t\t    Your order will be delivered in "<<endl<<"\t\t\t\t\t\t"<<hr<<" : "<<min<<" : "<<sec<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------------------\n";
        if(sec==0)
        {
            if(min>0)
            {
                min--;
                sec=60;
            }
        }
        if(min==0)
        {
            if(hr>0)
            {
                hr--;
                min=60;
            }
        }
        sec--;
        sleep(1);
        }
        cout<<"\t\t\t\t    Your order has been delivered"<<endl;
    }
}
    void bill_cart()
    {

       objA.quan();
       cout<<endl<<"**********************************************************************************************************************************************************\n";
        cout<<"S.No:\tItems:\t\t\t\t\tQuantity:\tPrice:\t\tDiscount(%):\tDiscounted Price:\tTotal price:\tTotal weight:\n";
        cout<<"__________________________________________________________________________________________________________________________________________________________\n";
        int y=1;
        for(int k=0; k<i; k++)
            {
                if(quantity[k]>0)
                    {
                        cout<<y<<"\t"<<item[k]<<quantity[k]<<"\t\t"<<price[k]<<"\t\t"<<discount[k]<<"\t\t"<<disPrice[k]<<"\t\t\t"<<(disPrice[k]*quantity[k])<<"\t\t"<<(weight[k]*quantity[k])<<endl;
                        y++;
                        //for(int m=0;m<quantity[k];m++)
                        //{
                        //    wt[cumulative_quantity]=weight[k];
                        //    cumulative_quantity++;

                        //}
                    }
            }
        cout<<"___________________________________________________________________________________________________________________________________________________________\n\n";
        cout<<"**********************************************************************************************************************************************************\n";
    }
};
int main()
{
    char ch;
    welcome();
    customer person;
    person.getDetails();

    all obj1;
    obj1.choiceAllCategories();

    cart obj2;
    obj2.quan();
    obj2.cart1();

    discount1 obj3;
    obj3.total1();
    obj3.printA();
    obj3.offers();
    while(obj3.payment<1||obj3.payment>5)
    {
        try
        {
            obj3.payment_method();
        }
        catch(const char* str)
        {
            cout<<str;
        }
    }
    obj3.card();
    obj3.calculate1();
    obj3.calculate3();
    obj3.print();

    int V = 9;
    Graph graph(V);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);


    /*int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };*/
    cout<<"**************************************************************************\n";
    int x;
    cout<<"Enter the location you want to deliver your order to: (Choose from 1 to 8) \n\n";
    cout<<"We deliver at different locations: \n1) Sector 59\n2) Sector 61\n3) Sector 62\n4) Sector 52\n5) Sector 50\n6) Sector 76\n7) Sector 81\n8) Sector 101\n";
    cin>>x;
    int delivery_time=graph.dijkstra(0,x);
    bill obj4;
    int res=obj4.min_bin();
    cout<<"******************************************\n";
    cout<<"Total bags needed to deliver are: "<<res;
    cout<<"\nBag Charges: "<<res*10;
    cout<<"\n******************************************\n";
    //cin>>ch;
    //if(kbhit())
    obj4.bill_print(person,obj3,delivery_time);
}
