#include"header.h"
     void bev_hash()
    {
        bev_ht=new bev*[1000];
        for (int i=0;i<1000;i++) 
        bev_ht[i]=NULL;
    }
    int bev_hash_key(string str)
    {
          int s=0;
        for (int i=0;i<str.length();i++)
        {
            if (str[i]>=97) s+=str[i]-96;
            else if (str[i]>=65 && str[i]<97) s+=str[i]-64;
            else if(str[i]==32) s+=0;
        }
        return s%1000;
    }

    int groc_curr[1000];
    int groc_thresh[1000];
    
    groc **groc_ht;

        void groc_hash()
        {
            groc_ht=new groc*[1000];
            for (int i=0;i<1000;i++) 
            groc_ht[i]=NULL;
        }

        int groc_hash_key(string str)
        {
          int s=0;
        for (int i=0;i<str.length();i++)
        {
            if (str[i]>=97) s+=str[i]-96;
            else if (str[i]>=65 && str[i]<97) s+=str[i]-64;
            else if(str[i]==32) s+=0;
        }
        return s%1000;
        }
    





    //User Authentication
    
    //hash table named ht
    user **ht;
    //Default Function to be called to create a database of users
    void user_base()
    {
        ht=new user*[1000];
        for (int i=0;i<1000;i++) 
        ht[i]=NULL;
    }
    //Function to generate hash key to a particular UserName 
    int user_hash_key(string str)
    {
        int s=0;
        for (int i=0;i<str.length();i++)
        {
            if (str[i]>=97) s+=str[i]-96;
            else if (str[i]>=65 && str[i]<97) s+=str[i]-64;
            else if(str[i]==32) s+=0;
        }
        return s;
    }
    //Function to insert a new username and generate its corresponding Password
     void insert_username(string str)
    {
        int key=user_hash_key(str);
        user* temp = new user;
        temp->data=str;
        temp->next=NULL;
        
        user* trav=ht[key];
        if (trav==NULL) 
        {
        temp->prev=NULL; 
        ht[key]=temp; 
        return;
        }
        //ignore 
        while(trav->next != NULL) 
         trav=trav->next;
         temp->prev=trav;
         trav->next=temp;
    }
    //Function to search an existing user
    bool search_username(string str)
    {
       int key=user_hash_key(str);
       user *trav=ht[key];
       if (!trav) 
        {      
         return 0;
        }
       while(trav->data != str && trav->next!= NULL) 
       trav=trav->next;
      if (!trav) 
       {
        return 0;
       }
        return 1;
    }
    //Function to display all the usernames registered
    void display_username()
    {
        cout<<"Password is displayed as ***"<<endl;
        for (int i=1;i<1000;i++)
        {
            user *t = ht[i];
            if (t==NULL) continue;
            cout<<"Password "<<"***"<<": ";
            while (t!=NULL) {
            if (t->next==NULL) cout<<t->data;
            else cout<<t->data<<" -> ";
            t=t->next;
            }
            cout<<endl;
        }
    }
    

    //Default Funtion to create a userbase hash table and a default username
    void default_user()
    {
        user_base();
        insert_username("admin");
        for(int i=0;i<1000;i++)
        {
            bev_curr[i]=-1;
            bev_thresh[i]=-1;
            groc_curr[i]=-1;
            groc_thresh[i]=-1;
        }
    }
    //Validating a user
    bool user_authenticator()
    {
        cout<<"Default User is \"Admin\"\n";
        int f=0;
        int login_ct=0;
        while (f==0 && login_ct<=3)
        {
        login_ct++;
        string x; 
        cout<<"Enter Username: "; 
        cin>>x;
        curr_user=x;
        if (search_username(x)==0) 
        {
            cout<<"Invalid UserName!!!\n";
            cout<<"Try Again!\n";
            continue;
        }  
            int q;
            cout<<"Enter password: ";
            cin>>q;
            if (q==user_hash_key(x))
            { 
            cout<<"Matched !!\n";
            f=1;
            }
            else 
            {
                cout<<"Not Matched !! \n";
            }
            
        }
        if (login_ct>=3 && f==0)
        {
            cout<<"\tToo many unsuccessful attempts.\n\tTerminating the Program\n";
            return 0;
        }
        else if(f==1)
        {
            return 1;
        }
    }
    //UserBase Functions
    int UserBase_Menu(int ch1)
        {
                              if(ch1==0)
                               return 1;
                               else if(ch1==1)
                                {
                                    string x;
                                    cout<<"Enter your User name : "; 
                                    cin>>x;
                                    cout<<"Your Password is: "<<user_hash_key(x)<<endl;
                                    insert_username(x);
                                }
                                else if(ch1==2)
                                {
                                     string x; cout<<"Enter your name: "; cin>>x;
                                    if (search_username(x)==0) 
                                    {
                                        cout<<"Please register first !\n";
                                        return 1;
                                    }
                                    int q;
                                    cout<<"Enter password: ";
                                    cin>>q;
                                    if (q==user_hash_key(x)) 
                                    cout<<"Matched !!\n";
                                    else 
                                    cout<<"Not Matched !! \n";
                                }
                                else if(ch1==3)
                                {
                                    display_username();
                                }
                                return 1;
                                

        }






        //Receiving Functions
        //Registering New Product
        void register_new_prod()
        {
            cout<<"Enter Product category\n1.Beverage\n2.Grocery\n";
            int cat;
            cin>>cat;
            if(cat==1)
            {
                cout<<"Enter Product's Name:\n";
                string n;
                cin>>n;
                int key=bev_hash_key(n);
                bev_curr[key]=0;
                cout<<"Enter Product's Threshold Quantity:\n";
                int th;
                cin>>th;
                bev_thresh[key]=th;
            }
            else if(cat==2)
            {
                cout<<"Enter Product's Name:\n";
                string n;
                cin>>n;
                int key=groc_hash_key(n);
                groc_curr[key]=0;
                cout<<"Enter Product's Threshold Quantity:\n";
                int th;
                cin>>th;
                groc_thresh[key]=th;
            }
        }
        bool isfine(string curr, string exp)
        {
            int curr_y=stoi(curr.substr(6,4));
            int exp_y=stoi(exp.substr(6,4));
            int curr_m=stoi(curr.substr(3,2));
            int exp_m=stoi(exp.substr(3,2));
            int curr_d=stoi(curr.substr(0,2));
            int exp_d=stoi(exp.substr(0,2));
            if(curr_y>exp_y)
            return 0;
            else if(curr_y<exp_y)
            return 1;
            else
            {
                 if(curr_m>exp_m)
                return 0;
                 else if(curr_m<exp_m)
                return 1;
                else 
                {
                    if(curr_m>=exp_m)
                    return 0;
                    else if(curr_m<exp_m)
                    return 1;
                }
            }
        }
        void insert_bev(string pro,int q,string exp,string supp,int lo)
        {
            int hkey=bev_hash_key(pro);
            bev_curr[hkey]+=q;
            if(rec==0)
            {
                rec++;
                struct receive *t=(struct receive *)malloc(sizeof(struct receive));
                t->cat="Beverages";
                t->exp_date=exp;
                t->loc=lo;
                t->next=NULL;
                t->prod=pro;
                t->quantity=q;
                t->suppid=supp;
                t->user=curr_user;
                head=t;
                tail=t;
            }
                else
                {
                    struct receive *t=(struct receive *)malloc(sizeof(struct receive));
                    t->cat="Beverages";
                    t->exp_date=exp;
                    t->loc=lo;
                    t->next=NULL;
                    t->prod=pro;
                    t->quantity=q;
                    t->suppid=supp;
                    t->user=curr_user;
                    tail->next=t;
                    tail=t;
                }

                struct bev *t=(struct bev *)malloc(sizeof(struct bev));
                    t->bev_prod=pro;
                    t->bev_loc=lo;
                    t->bev_exp=exp;
                    t->bev_quantity=q;
                    t->bev_suppid=supp;
                    t->next=NULL;
                    bev* trav=bev_ht[hkey];
                    if (trav==NULL) 
                    { 
                    bev_ht[hkey]=t; 
                    return;
                    }
                    //Placing Logs of a product in order of Expiry Date
                    while(trav->next != NULL && isfine(trav->bev_exp,t->bev_exp)) 
                    {
                     trav=trav->next;
                    }
                     trav->next=t;    
                     cout<<"Entry Done!\n";
            }
        
        void insert_groc(string pro,int q,string exp,string supp,int lo)
        {
            int hkey=groc_hash_key(pro);
            groc_curr[hkey]+=q;
            if(rec==0)
            {
                rec++;
                struct receive *t=(struct receive *)malloc(sizeof(struct receive));
                t->cat="Grocery";
                t->exp_date=exp;
                t->loc=lo;
                t->next=NULL;
                t->prod=pro;
                t->quantity=q;
                t->suppid=supp;
                t->user=curr_user;
                // t->data=num;
                // t->next=NULL;
                head=t;
                tail=t;
            }
                else
                {
                    struct receive *t=(struct receive *)malloc(sizeof(struct receive));
                    t->cat="Grocery";
                    t->exp_date=exp;
                    t->loc=lo;
                    t->next=NULL;
                    t->prod=pro;
                    t->quantity=q;
                    t->suppid=supp;
                    t->user=curr_user;
                    tail->next=t;
                    tail=t;
                }

                struct groc *t=(struct groc *)malloc(sizeof(struct groc));
                    t->groc_prod=pro;
                    t->groc_loc=lo;
                    t->groc_exp=exp;
                    t->groc_quantity=q;
                    t->groc_suppid=supp;
                    t->next=NULL;
                    groc* trav=groc_ht[hkey];
                    if (trav==NULL) 
                    { 
                    groc_ht[hkey]=t; 
                    return;
                    }
                    //Placing Logs of a product in order of Expiry Date
                    while(trav->next!= NULL && isfine(trav->groc_exp,t->groc_exp)) 
                     trav=trav->next;
                     t->next=trav->next;
                     trav->next=t;  
                    cout<<"Entry Done!\n";

        }


        void make_new_entry()
        {
            cout<<"Enter Product category\n1.Beverage\n2.Grocery\n";
            int cat;
            cin>>cat;
            cout<<"Enter Product's Name\n";
            string n;
            cin>>n;
            int hkey=bev_hash_key(n);
            cout<<"Enter Product's Quantity\n";
            int q;
            cin>>q;
            cout<<"Enter Product's Expiry Date(dd-mm-yyyy)\n";
            string exp;
            cin>>exp;
            cout<<"Enter SupplierId:\n";
            string supp;
            cin>>supp;
            if(cat==1 && bev_curr[hkey]==-1||cat==2 && groc_curr[hkey]==-1)
            {
                cout<<"Item Not Registered. First Register it\n";
            register_new_prod();
            }
            if(!isfine(today,exp))
            cout<<"Can't Take Expired Products.\nGoodbye!\nGet Fresh Products\n";
            else
            {
            if(cat==1)
            {
                if((bev_tot+q)<=bev_tot)
                insert_bev(n,q,exp,supp,1);
                else if((bev_max-bev_tot+misc_max-misc_tot)>=q)
                {
                    int q1=bev_max-bev_tot;
                    int q2=q-q1;
                    insert_bev(n,q1,exp,supp,1);
                    insert_bev(n,q2,exp,supp,3);
                }
                else 
                {
                    cout<<"Warehouse Storage Full!!!\n";
                    cout<<"Can take only "<<(bev_max-bev_tot+misc_max-misc_tot)<<" supplies\n";
                    int q1=bev_max-bev_tot;
                    int q2=misc_max-misc_tot;
                    insert_bev(n,q1,exp,supp,1);
                    insert_bev(n,q2,exp,supp,3);
                }
                

            }
            else if(cat==2)
            {
                    if((groc_tot+q)<=groc_tot)
                insert_groc(n,q,exp,supp,1);
                else if((groc_max-groc_tot+misc_max-misc_tot)>=q)
                {
                    int q1=groc_max-groc_tot;
                    int q2=q-q1;
                    insert_groc(n,q1,exp,supp,1);
                    insert_groc(n,q2,exp,supp,3);
                }
                else 
                {
                    cout<<"Warehouse Storage Full!!!\n";
                    cout<<"Can take only "<<(groc_max-groc_tot+misc_max-misc_tot)<<" supplies\n";
                    int q1=groc_max-groc_tot;
                    int q2=misc_max-misc_tot;
                    insert_groc(n,q1,exp,supp,1);
                    insert_groc(n,q2,exp,supp,3);
                }
            }
            
            }
        }
        

        void all_received()
        {
            struct receive *t=head;
            int c=0;
            while(t!=NULL)
            {
                c++;
                    cout<<"Received Supply No. "<<c<<endl;
                    cout<<"-------------------------------------------\n";
                    cout<<"Category :   "<<t->cat<<endl;
                    cout<<"Product :    "<<t->prod<<endl;
                    cout<<"Quantity :   "<<t->quantity<<endl;
                    cout<<"Expiry Date :"<<t->exp_date<<endl;
                    cout<<"Supplier Id :"<<t->suppid<<endl;
                    cout<<"Location :   Section "<<t->loc<<endl;
                    cout<<"Entry By :   "<<t->user<<endl;
                    t=t->next;
            }
        }
    
        void receiving_base_menu(int ch2)
        {
                              if(ch2==0)
                              return ;
                              else if(ch2==1)
                              {
                                    register_new_prod();
                              }
                              else if(ch2==2)
                              {
                                    make_new_entry();
                              }
                              else if(ch2==3)
                              {
                                    all_received();
                              }
                              
        }

        
        
        //Dispatching Functions
        void bev_dispatch(string n,string buid,int q )
        {
                        int hkey=bev_hash_key(n);
                        int s=q;
                        bev* t=bev_ht[hkey];
                        bev_curr[hkey]-=q;
                        while(s-(t->bev_quantity)>=0)
                        {
                            if(dis==0)
                            {
                                dis++;
                                struct dispatch *temp=(struct dispatch *)malloc(sizeof(struct dispatch));
                                temp->cat="Beverage";
                                temp->prod="n";
                                temp->exp_date=t->bev_exp;
                                temp->buyerid=buid;
                                temp->quantity=t->bev_quantity;
                                temp->loc=t->bev_loc;
                                temp->user=curr_user;
                                temp->next=NULL;
                                front=temp;
                                back=temp;
                            }
                            else 
                            {
                                 struct dispatch *temp=(struct dispatch *)malloc(sizeof(struct dispatch));
                                temp->cat="Beverage";
                                temp->prod="n";
                                temp->exp_date=t->bev_exp;
                                temp->buyerid=buid;
                                temp->quantity=t->bev_quantity;
                                temp->loc=t->bev_loc;
                                temp->user=curr_user;
                                temp->next=NULL;
                                back->next=temp;
                                back=temp;
                            }
                            s=s-t->bev_quantity;
                            bev_ht[hkey]=bev_ht[hkey]->next;
                            t=bev_ht[hkey];
                            cout<<"Dispatch Done\n";
                        }

        }
        void groc_dispatch(string n,string buid,int q)
        {
                        int hkey=groc_hash_key(n);
                        int s=q;
                        groc* t=groc_ht[hkey];
                        groc_curr[hkey]-=q;
                        while(s-(t->groc_quantity)>=0)
                        {
                            if(dis==0)
                            {
                                dis++;
                                struct dispatch *temp=(struct dispatch *)malloc(sizeof(struct dispatch));
                                temp->cat="Grocery";
                                temp->prod="n";
                                temp->exp_date=t->groc_exp;
                                temp->buyerid=buid;
                                temp->quantity=t->groc_quantity;
                                temp->loc=t->groc_loc;
                                temp->user=curr_user;
                                temp->next=NULL;
                                front=temp;
                                back=temp;
                            }
                            else 
                            {
                                 struct dispatch *temp=(struct dispatch *)malloc(sizeof(struct dispatch));
                                temp->cat="Grocery";
                                temp->prod="n";
                                temp->exp_date=t->groc_exp;
                                temp->buyerid=buid;
                                temp->quantity=t->groc_quantity;
                                temp->loc=t->groc_loc;
                                temp->user=curr_user;
                                temp->next=NULL;
                                back->next=temp;
                                back=temp;
                            }
                            s=s-t->groc_quantity;
                            groc_ht[hkey]=groc_ht[hkey]->next;
                            t=groc_ht[hkey];
                            cout<<"Dispatch Done\n";
        }
        }
        void make_new_dispatch()
        {
                         cout<<"Enter Product category\n1.Beverage\n2.Grocery\n";
                         int cat;
                         cin>>cat;
                         cout<<"Enter Product name:\n";
                         string n;
                         cin>>n;
                         cout<<"Enter Quantity of Product:\n";
                         int q;
                         cin>>q;
                         cout<<"Enter Buyer ID\n";
                         string buid;
                         cin>>buid;
                         int hkey=bev_hash_key(n);
                         if(cat==1 && bev_curr[hkey]<=0 || cat==2 && groc_curr[hkey]<=0)
                         {
                            cout<<"Item Not Available\n";
                            return;
                         }
                         if(cat==1)
                         {
                            if(bev_curr[hkey]>=q)
                            q=q;
                            else 
                            {
                                cout<<"Maximum quantity available:"<<bev_curr[hkey]<<endl;
                                q=bev_curr[hkey];
                            }
                            bev_dispatch(n,buid,q);
                         }
                         else if(cat==2)
                         {
                            if(groc_curr[hkey]>=q)
                            q=q;
                            else 
                            {
                                cout<<"Maximum quantity available:"<<groc_curr[hkey]<<endl;
                                q=groc_curr[hkey];
                            }
                            groc_dispatch(n,buid,q);
                         }
        }
        void all_dispatched()
        {
                struct dispatch *t=front;
                int c=0;
                while(t!=NULL)
                {
                    c++;
                    cout<<"Dispatch Supply No. "<<c<<endl;
                    cout<<"-------------------------------------------\n";
                    cout<<"Category :   "<<t->cat<<endl;
                    cout<<"Product :    "<<t->prod<<endl;
                    cout<<"Quantity :   "<<t->quantity<<endl;
                    cout<<"Expiry Date :"<<t->exp_date<<endl;
                    cout<<"Buyer Id :   " <<t->buyerid<<endl;
                    cout<<"Location :   Section "<<t->loc<<endl;
                    cout<<"Entry By :   "<<t->user<<endl;
                    t=t->next;
                }
        }
        void dispatching_base_menu(int ch3)
        {
                              if(ch3==0)
                              return;
                              else if(ch3==1)
                              {
                                    make_new_dispatch();
                              }
                              else if(ch3==2)
                              {
                                    all_dispatched();
                              }
        }




        void renew_base_menu(int ch)
        {
            if(ch==0)
            return ;
            else if(ch==1)
            {
                for(int i=1;i<1000;i++)
                {
                    if(bev_curr[i]<bev_thresh[i])
                    {
                        cout<<"Category: Beverage\n";
                        cout<<"Product Name:"<<bev_ht[i]->bev_prod<<endl;
                        cout<<"Threshold Quantity:"<<bev_thresh[i]<<endl;
                        cout<<"Current Quantity:"<<bev_curr[i]<<endl;
                        cout<<"Minimum Required Quantity:"<<(bev_thresh[i]-bev_curr[i])<<endl;
                    }
                }
                for(int i=1;i<1000;i++)
                {
                    if(groc_curr[i]<groc_thresh[i])
                    {
                        cout<<"Category: Grocery\n";
                        cout<<"Product Name:"<<groc_ht[i]->groc_prod<<endl;
                        cout<<"Threshold Quantity:"<<groc_thresh[i]<<endl;
                        cout<<"Current Quantity:"<<groc_curr[i]<<endl;
                        cout<<"Minimum Required Quantity:"<<(groc_thresh[i]-groc_curr[i])<<endl;
                    }
                }
            }
        }


int main()
{
        cout<<"Enter Today's date (dd-mm--yyyy):\n";
        string tdate;
        cin>>tdate;
        today=tdate;
        default_user();
        int x=user_authenticator();
        if(x==0)
        {
        return 0;
        }
        else if(x==1)
        {
            cout<<"\tWelcome to Prakhar's Setup of Warehouse Supply Chain Management\n";
            cout<<"\t--------------------------xxxxxxx--------------------------------\n\n";
            cout<<"\t                            MENU                                \n";
            cout<<"\t                -------------------------------\n";
            cout<<"\t                 1. UserBase\n";
            cout<<"\t                 2. Receiving Logs\n";
            cout<<"\t                 3. Dispatching Logs\n";
            cout<<"\t                 4. Renew Items\n";
            cout<<"\t                 0. Exit\n    ";
            cout<<"\t--------------------------xxxxxxx--------------------------------\n\n";

        
        cout<<"\tEnter your choice! : ";
        int ch=-1;
        cin>>ch;
        while (ch!=0)
        {
                switch(ch)
                {
                    case 1:
                            {
                               int ch1=-1;
                                while(ch1!=0)
                                {
                                cout<<"               UserBase\n\n";
                                cout<<"                 MENU\n";
                                cout<<"-----------------------------------------\n";
                                cout<<"     1. Register New User\n";
                                cout<<"     2. Check Password for Registered User\n";
                                cout<<"     3. Display User DataBase\n";
                                cout<<"     0. Exit\n";
                                cout<<"-----------------------------------------\n\n";
                                cout<<"    Enter Your Choice : ";
                                cin>>ch1;
                                if(ch1<0 || ch1>3)
                                cout<<"Invalid Input!\nRe-Enter your Choice\n";
                                else 
                                {
                                    int k=UserBase_Menu(ch1);
                                }
                                }
                                
                               
                            }
                            break;
                    case 2:
                            {
                                 int ch2=-1;
                               while(ch2!=0)
                               {
                               cout<<"\t         Receiving Logs\n\n";
                               cout<<"\t---------------xxxxxxx-----------------\n";
                               cout<<"\t                MENU\n";
                               cout<<"\t----------------------------------------\n\n";
                               cout<<"\t   1. Register a new Product\n";
                               cout<<"\t   2. Make a new Entry\n";
                               cout<<"\t   3. Show all Received Entries till Now\n";
                               cout<<"\t   0. Exit\n";
                               cout<<"\t----------------------------------------\n\n";
                               cout<<"    Enter Your Choice : ";
                               cin>>ch2;
                               if(ch2<0||ch2>3)
                               cout<<"Invalid Input!\nRe-Enter your Choice\n";
                               else 
                               {
                                    receiving_base_menu(ch2);
                               }
                               }
                            }
                            break;
                    case 3:
                            {
                                int ch3=-1;
                               while(ch3!=0)
                               {
                               cout<<"\t         Dispatching Logs\n\n";
                               cout<<"\t---------------xxxxxxx-----------------\n";
                               cout<<"\t                MENU\n";
                               cout<<"\t----------------------------------------\n\n";
                               cout<<"\t   1. Make a new Exit\n";
                               cout<<"\t   2. Show all Dispatched Entries till Now\n";
                               cout<<"\t   0. Exit\n";
                               cout<<"\t----------------------------------------\n\n";
                               cout<<"    Enter Your Choice : ";
                               cin>>ch3;
                               if(ch3<0||ch3>2)
                               cout<<"Invalid Input!\nRe-Enter your Choice\n";
                               else 
                               {
                                    dispatching_base_menu(ch3);
                               }
                               }
                            }
                            break;
                    case 4:
                            {
                                int ch4=-1;
                                while(ch4!=0)
                                {
                                  cout<<"\t         Renew Items\n\n";
                               cout<<"\t---------------xxxxxxx-----------------\n";
                               cout<<"\t                MENU\n";
                               cout<<"\t----------------------------------------\n\n";
                               cout<<"\t   1. Items to be Renewed\n";
                               cout<<"\t   0. Exit\n";
                               cout<<"\t----------------------------------------\n\n";
                               cout<<"    Enter Your Choice : ";
                               cin>>ch4;
                               if(ch4<0||ch4>2)
                               cout<<"Invalid Input!\nRe-Enter your Choice\n";
                               else 
                               {
                                    renew_base_menu(ch4);
                               }  
                                }
                            }
                            break;
                    default:
                            {
                                cout<<"Invalid Input!\n";
                            }
                            break;
                }
                cout<<"\tWelcome to Prakhar's Setup of Warehouse Supply Chain Management\n";
                cout<<"\t--------------------------xxxxxxx--------------------------------\n\n";
                cout<<"\t                            MENU                                \n";
                cout<<"\t          -----------------------------------\n";
                cout<<"\t                 1. UserBase\n";
                cout<<"\t                 2. Receiving Logs\n";
                cout<<"\t                 3. Dispatching Logs\n";
                cout<<"\t                 4. Renew Items\n";
                cout<<"\t                 0. Exit\n    ";
                cout<<"\t--------------------------xxxxxxx--------------------------------\n\n";
                cout<<"\tEnter your choice! : ";
                cin>>ch;

        }
        cout<<"\tGoodBye!!!\n";
        cout<<"\tTerminating the Program!\n";
        cout<<"\tHave a Nice Day!\n";

        }
}
        
    
