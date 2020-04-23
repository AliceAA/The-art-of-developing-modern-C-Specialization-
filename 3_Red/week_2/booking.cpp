#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


struct client{
  int64_t time;
  int id;

};


class BookingManager 
{
  private:
	map<string, queue<int64_t> > rooms;
  map<string, vector<client> > clients;
public:
	void Book (int64_t time, string hotel_name, int client_id, int room_count) 	{

    for (int i = 0; i<room_count; i++){
      rooms[hotel_name].push(time);}
    for(auto& item:rooms){
      while(item.second.front()<=(time-86400)){
        item.second.pop();
      }
    }
    

    for(auto& v_item:clients){
      vector<client> v = v_item.second;
      auto it = remove_if(begin(v), end(v), [ time](const client& x){return (x.time<=(time-86400));});
      v.erase(it, end(v));
    }

    auto it2 = remove_if(begin(clients[hotel_name]), end(clients[hotel_name]), 
                [client_id](const client& x){return (x.id==client_id);});
    clients[hotel_name].erase(it2, end(clients[hotel_name]));
    
    clients[hotel_name].push_back(client{time, client_id}); 
	}

	void Clients (string hotel_name)	{
    if (clients.count(hotel_name)){
      cout<<clients.at(hotel_name).size()<<"\n";
    } else{
      cout<<"0\n";
    }
	}

	void Rooms (string hotel_name)	{
    if (rooms.count(hotel_name)){
      cout<<rooms.at(hotel_name).size()<<"\n";
    } else{
      cout<<"0\n";
    }
	}

};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  BookingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;

    if (query_type == "BOOK") {
      int client, room;
      int64_t time;
      string name;
      cin >> time>>name>>client>>room;
      manager.Book(time, name, client, room);
    } else if (query_type == "CLIENTS") {
      string name;
      cin>>name;
      manager.Clients(name);
    } else if  (query_type == "ROOMS") {
      string name;
      cin>>name;
      manager.Rooms(name);
    }
  }

  return 0;
}