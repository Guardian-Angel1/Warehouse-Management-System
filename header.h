#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
//Considering it is a warehouse of containg of 3 sections: Section 1(Beverages Section), Section 2(Grocery Section) and Section 3 (Miscellaneous Section)
//Section 1 has capacity of 500(boxes), Section 2 has capacity of 1000(boxes) and Section 3 has Capacity of 500 (Boxes)
//If either od Section 1 or Section 2 gets full, Items will be stored in Section 3 until it gets full.
    //Global Entities

    string curr_user="xyz";
    string today="01-01-2020";
    int bev_max=500;
    int groc_max=1000;
    int misc_max=500;
    int bev_tot=0;
    int groc_tot=0;
    int misc_tot=0;
    int bev_curr[1000];
    int bev_thresh[1000];
    struct receive
    {
            string cat;
            string prod;
            int quantity;
            string exp_date;
            string suppid;
            int loc;
            string user;
            struct receive* next;

    };
    struct receive* head=NULL;
    struct receive *tail=NULL;
    int rec=0;
    struct dispatch
    {
            string cat;
            string prod;
            int quantity;
            string exp_date;
            string buyerid;
            int loc;
            string user;
            struct dispatch* next;
    };
    struct dispatch *front=NULL;
    struct dispatch *back=NULL;
    int dis=0;
    struct bev
    {
            string bev_prod;
            int bev_quantity;
            string bev_exp;
            string bev_suppid;
            int bev_loc;
            struct bev* next;
    };
    bev **bev_ht;
struct groc
    {
            string groc_prod;
            int groc_quantity;
            string groc_exp;
            string groc_suppid;
            int groc_loc;
            struct groc* next;
    };
    struct user
    {
        struct user *prev;
        string data;
        struct user *next;
    };
  void bev_hash();  
  int bev_hash_key(string str);
void groc_hash();
int groc_hash_key(string str);
void user_base();
int user_hash_key(string str);
void insert_username(string str);
bool search_username(string str);
void display_username();
void default_user();
bool user_authenticator();
int UserBase_Menu(int ch1);
void register_new_prod();
 bool isfine(string curr, string exp);
void insert_bev(string pro,int q,string exp,string supp,int lo);
void insert_groc(string pro,int q,string exp,string supp,int lo);
void make_new_entry();
void all_received();
void receiving_base_menu(int ch2);
void bev_dispatch(string n,string buid,int q );
void groc_dispatch(string n,string buid,int q);
void make_new_dispatch();
void all_dispatched();
void dispatching_base_menu(int ch3);
void renew_base_menu(int ch);



















