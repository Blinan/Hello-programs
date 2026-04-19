#include <httplib.h>
#include <iostream>
#include <vector>

void LoginToServer();
int id_player;
int progress_1 = -1, progress_2 = -1;
std::string str_text;
std::vector<std::string> str_line_list;
int num_total_char = 0;
int main(int argc, char** argv) {

   httplib::Client client("localhost", 25565);

   

   

   //system("pause");
   return 0;
} 

void LoginToServer()
{
   httplib::Client *client = new httplib::Client("localhost", 25565);
   client->set_keep_alive(true);
   httplib::Result result = client->Post("/login");

   if(!result || result->status != 200)
   {

   std::cerr << "result->status = " <<result->status;
    
   }
   std::cout << result->body << std::endl;

   id_player = std::stoi(result->body);

   if(id_player <= 0)
   {
      std::cerr << "The Game is begining\n";
   }

   (id_player == 1) ? (progress_1 = 0) : (progress_2 = 0);

   str_text = client->Post("/query_text")->body;
   std::stringstream str_stream(str_text);
   std::string str_line;
   
   while(std::getline(str_stream, str_line)){
      str_line_list.push_back(str_line);
      num_total_char += int(str_line.length());
   }

   std::thread([&](){
      while(true){

         using namespace std::chrono;

         std::string route = (id_player == 1) ? "/update_1" : "/update_2";
         std::string body = std::to_string((id_player == 1) ? progress_1 : progress_2);
         httplib::Result res = client->Post(route, body, "text/plain");

         if(res && res->status == 200){
            int progress = std::stoi(res->body);
            (id_player == 1) ? (progress_2 = progress) : (progress_1 = progress);
         }

         std::this_thread::sleep_for(nanoseconds(1000000000 /10));
      }
   }).detach();
}